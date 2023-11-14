#include "credit_calc.h"

#include <cmath>

namespace smcalc::credit {

namespace {

Data CalculateAnnuit(const Conditions& conds, int mp_cnt) {
  Data data;
  double r = conds.int_rate / (DatesNum::kMonthInYear * 100);
  double ann_k =
      (r * std::pow(1 + r, mp_cnt)) / ((std::pow(1 + r, mp_cnt)) - 1);
  double ann_pay = std::round(conds.sum * ann_k * 100.0) / 100.0;
  data.payment.resize(mp_cnt, ann_pay);
  data.total = ann_pay * mp_cnt;
  data.overpay = data.total - conds.sum;
  return data;
}

Data CalculateDiff(const Conditions& conds, int mp_cnt) {
  Data data;
  double rest = conds.sum, payment;
  double mp_real = conds.sum / (mp_cnt);
  for (; mp_cnt != 0; mp_cnt--) {
    payment =
        mp_real + (rest * conds.int_rate / (DatesNum::kMonthInYear * 100));
    data.payment.push_back(payment);
    data.total += payment;
    rest -= mp_real;
  }
  data.overpay = data.total - conds.sum;
  return data;
}

}  // namespace

Data Calculate(Conditions conds) {
  int mp_cnt = (conds.date_is_year) ? conds.period * DatesNum::kMonthInYear
                                    : conds.period;
  if (conds.type == Type::kAnnuit) {
    return CalculateAnnuit(conds, mp_cnt);
  }
  return CalculateDiff(conds, mp_cnt);
}

}  // namespace smcalc::credit