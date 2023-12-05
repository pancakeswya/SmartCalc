#include "deposit_calc.h"

#include <algorithm>

namespace smcalc::deposit {

namespace {

inline void SetValidPayDate(Date& date, int day) noexcept {
  if (date.get_day() != day && date.days_in_month() > date.get_day()) {
    date = Date(date.get_year(), date.get_month(), day);
  }
}

inline Date NextPayDate(const Date& cur_date, int freq, int payday,
                        int incr) noexcept {
  Date pay_date = cur_date;
  if (freq < CondPayFreq::kEvMon) {
    pay_date.add_days(incr);
  } else {
    pay_date.add_months(incr);
    SetValidPayDate(pay_date, payday);
  }
  return pay_date;
}

inline int ReplenFreq(int pay_freq) noexcept {
  if (pay_freq == CondPayFreq::kEvHalfYear) {
    return 6;
  } else if (pay_freq == CondPayFreq::kEvYear) {
    return 12;
  }
  return pay_freq;
}

int PayFreq(int pay_freq) noexcept {
  static int real_freq[] = {1, 7, 1, 3, 6, 12};
  return real_freq[pay_freq];
}

void AddReplenishment(Data& data, const Date& start_date,
                      const Date& finish_date, const Transaction& transaction) {
  Date transact_date = transaction.payout.date;
  while (transact_date <= finish_date) {
    if (transact_date > start_date) {
      data.replen.push_back({transact_date, transaction.payout.sum});
      if (transaction.freq == CondPayFreq::kEvDay) {
        break;
      }
    }
    transact_date.add_months(ReplenFreq(transaction.freq));
    SetValidPayDate(transact_date, transact_date.get_day());
  }
}

void CalculateDeposit(Data& data, const Conditions& conds) {
  int pay_freq = PayFreq(conds.pay_freq);
  int am_days = conds.start_date.days_to(data.finish_date);

  double tax_perc = 0.0, add_sum = 0.0, cap_sum = 0.0, pay = 0.0;

  Date date = conds.start_date;
  date.add_days(1);

  data.pay_dates.push_back(NextPayDate(conds.start_date, conds.pay_freq,
                                       conds.start_date.get_day(), pay_freq));

  int i = 0, j = 0;
  while (date <= data.finish_date) {
    pay +=
        (conds.sum + add_sum + cap_sum) * conds.intr_rate / date.days_in_year();
    if (date == data.pay_dates[i] || date == data.finish_date) {
      data.pay_dates.push_back(NextPayDate(
          date, conds.pay_freq, conds.start_date.get_day(), pay_freq));
      data.payment.push_back(std::round(pay) / 100.0);
      data.perc_sum += data.payment.back();
      pay = 0.0;
      if (conds.cap) {
        cap_sum = data.perc_sum;
      }
      ++i;
    }
    for (; j < data.replen.size() && date == data.replen[j].date; ++j) {
      if (conds.sum + data.replen[j].sum + add_sum + cap_sum >=
          conds.non_taking_rem) {
        add_sum += data.replen[j].sum;
      }
    }
    if ((date.get_day() == 31 && date.get_month() == 12) ||
        (date == data.finish_date && !data.tax.empty())) {
      double tax_inc = data.perc_sum - tax_perc - conds.key_rate * 10000.0;
      if (tax_inc > 0.0) {
        data.tax.push_back(tax_inc * (conds.tax_rate / 100.0));
        data.tax_sum += data.tax.back();
      }
      tax_perc = data.perc_sum;
    }
    date.add_days(1);
  }
  if (conds.cap) {
    data.eff_rate = (data.perc_sum * DatesNum::kAvgDaysInYear * 100.0) /
                    (conds.sum * am_days);
    data.total += cap_sum;
  }
  data.total += conds.sum + add_sum;
}

Date FinishDate(const Conditions& conds) noexcept {
  Date finish_date = conds.start_date;
  if (conds.term_type == DateType::kTypeDay) {
    finish_date.add_days(conds.term);
  } else if (conds.term_type == DateType::kTypeMonth) {
    finish_date.add_months(conds.term);
  } else {
    finish_date.add_years(conds.term);
  }
  return finish_date;
}

void SetReplanishments(Data& data, Conditions& conds) {
  for (const Transaction& single_fund : conds.fund) {
    AddReplenishment(data, conds.start_date, data.finish_date, single_fund);
  }
  for (Transaction& single_wth : conds.wth) {
    single_wth.payout.sum = -single_wth.payout.sum;
    AddReplenishment(data, conds.start_date, data.finish_date, single_wth);
  }
  std::sort(data.replen.begin(), data.replen.end(),
            [](const Transaction::Payout& rhs, const Transaction::Payout& lhs) {
              return rhs.date < lhs.date;
            });
}

}  // namespace

Data Calculate(Conditions conds) {
  Data data{};
  data.start_date = conds.start_date;
  data.finish_date = FinishDate(conds);
  SetReplanishments(data, conds);
  CalculateDeposit(data, conds);
  return data;
}

}  // namespace smcalc::deposit