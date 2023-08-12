#include "bank_calc.h"

#include <algorithm>
#include <cmath>

namespace s21 {

void Credit::CalcCredit() {
  short int mp_cnt = (date_is_year) ? period * DatesNum::kMonthInYear : period;
  if (type) {
    double r = int_rate / (DatesNum::kMonthInYear * 100);
    double ann_k =
        (r * std::pow(1 + r, mp_cnt)) / ((std::pow(1 + r, mp_cnt)) - 1);
    double ann_pay = std::round(sum * ann_k * 100.0) / 100.0;
    data_.payment.resize(mp_cnt, ann_pay);
    data_.total = ann_pay * mp_cnt;
  } else {
    double rest = sum, payment;
    double mp_real = sum / (mp_cnt);
    for (; mp_cnt != 0; mp_cnt--) {
      payment = mp_real + (rest * int_rate / (DatesNum::kMonthInYear * 100));
      data_.payment.push_back(payment);
      data_.total += payment;
      rest -= mp_real;
    }
  }
  data_.overpay = data_.total - sum;
}

namespace {

inline void SetValidPayDate(QDate& date, int day) noexcept {
  if (date.day() != day && date.daysInMonth() > date.day()) {
    date.setDate(date.year(), date.month(), day);
  }
}

inline QDate NextPayDate(const QDate& cur_date, short int freq, int payday,
                         int incr) noexcept {
  if (freq < CondPayFreq::kEvMon) {
    return cur_date.addDays(incr);
  } else {
    QDate pay_date;
    pay_date = cur_date.addMonths(incr);
    SetValidPayDate(pay_date, payday);
    return pay_date;
  }
}

inline int GetRealPayFreq(int pay_freq) noexcept {
  if (pay_freq == CondPayFreq::kEvDay) {
    return 1;
  } else if (pay_freq >= CondPayFreq::kEvHalfYear) {
    return pay_freq + 2;
  } else if (pay_freq == CondPayFreq::kEvYear) {
    return 12;
  }
  return pay_freq;
}

}  // namespace

void Deposit::MakeDeposit() {
  int r_pay_freq = GetRealPayFreq(pay_freq);
  auto rep_it = data_.replen.begin();
  int am_days = start_date.daysTo(data_.finish_date), i = 0;
  QDate date = start_date.addDays(1);
  data_.pay_dates.push_back(
      NextPayDate(start_date, pay_freq, start_date.day(), r_pay_freq));
  double tax_perc = 0.0, add_sum = 0.0, cap_sum = 0.0, pay = 0.0;
  while (date <= data_.finish_date) {
    pay += (sum + add_sum + cap_sum) * intr_rate / date.daysInYear();
    if (date == data_.pay_dates[i] || date == data_.finish_date) {
      data_.pay_dates.push_back(
          NextPayDate(date, pay_freq, start_date.day(), r_pay_freq));
      data_.payment.push_back(std::round(pay) / 100.0);
      data_.perc_sum += data_.payment.back();
      pay = 0.0;
      if (cap) {
        cap_sum = data_.perc_sum;
      }
      ++i;
    }
    for (; rep_it != data_.replen.end() && date == rep_it->first; rep_it++) {
      if (sum + add_sum + cap_sum + rep_it->second >= non_taking_rem) {
        add_sum += rep_it->second;
      }
    }
    if ((date.day() == 31 && date.month() == 12) ||
        (date == data_.finish_date && !data_.tax.empty())) {
      double tax_inc = data_.perc_sum - tax_perc - key_rate * 10000.0;
      if (tax_inc > 0.0) {
        data_.tax.push_back(tax_inc * (tax_rate / 100.0));
        data_.tax_sum += data_.tax.back();
      }
      tax_perc = data_.perc_sum;
    }
    date = date.addDays(1);
  }
  if (cap) {
    data_.eff_rate =
        (data_.perc_sum * DatesNum::kAvgDaysInYear * 100.0) / (sum * am_days);
    data_.total += cap_sum;
  }
  data_.total += sum + add_sum;
}

void Deposit::AddReplenishment(const QDate& start_date,
                               const QDate& finish_date,
                               const UserTransaction& u_transaction) {
  QDate transact_date = u_transaction.date;
  while (transact_date <= finish_date) {
    if (transact_date > start_date) {
      data_.replen.push_back({transact_date, u_transaction.sum});
      if (!u_transaction.freq) {
        break;
      }
    }
    transact_date = transact_date.addMonths(GetRealPayFreq(u_transaction.freq));
    SetValidPayDate(transact_date, transact_date.day());
  }
}

void Deposit::CalcDeposit() {
  data_.start_date = start_date;
  if (term_type == DateType::kTypeDay) {
    data_.finish_date = start_date.addDays(term);
  } else if (term_type == DateType::kTypeMonth) {
    data_.finish_date = start_date.addMonths(term);
  } else {
    data_.finish_date = start_date.addYears(term);
  }
  for (auto& single_fund : fund) {
    AddReplenishment(start_date, data_.finish_date, single_fund);
  }
  for (auto& single_wth : wth) {
    single_wth.sum = -single_wth.sum;
    AddReplenishment(start_date, data_.finish_date, single_wth);
  }
  std::sort(data_.replen.begin(), data_.replen.end(),
            [](const std::pair<QDate, double>& rhs,
               const std::pair<QDate, double>& lhs) -> bool {
              return rhs.first < lhs.first;
            });
  MakeDeposit();
}

}  // namespace s21
