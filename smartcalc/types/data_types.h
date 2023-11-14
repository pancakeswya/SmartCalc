#ifndef SMARTCALC_TYPES_DATA_TYPES_H_
#define SMARTCALC_TYPES_DATA_TYPES_H_

#include <utility>
#include <vector>

#include "datetime.h"

namespace smcalc {

enum DateType { kTypeDay, kTypeMonth, kTypeYear };

enum DateLimits { kYearMax = 50, kMonthMax = 600, kDayMax = 18250 };

enum DatesNum { kMonthInYear = 12, kAvgDaysInMonth = 30, kAvgDaysInYear = 365 };

enum CondPayFreq : short int {
  kEvDay,
  kEvWeek,
  kEvMon,
  kEvQuart,
  kEvHalfYear,
  kEvYear
};

namespace credit {

enum Type : bool { kAnnuit, kDiff };

struct Conditions {
  double sum;
  double int_rate;
  short int period;
  bool date_is_year;
  bool type;
};

struct Data {
  double total;
  double overpay;
  std::vector<double> payment;
};

}  // namespace credit

namespace deposit {

using Date = jed_utils::datetime;

struct Transaction {
  struct Payout {
    Date date;
    double sum;
  } payout;
  int freq;
};

struct Data {
  std::vector<Transaction::Payout> replen;
  std::vector<Date> pay_dates;
  std::vector<double> payment;
  std::vector<double> tax;
  Date start_date;
  Date finish_date;
  double eff_rate;
  double perc_sum;
  double tax_sum;
  double total;
};

struct Conditions {
  bool cap;
  short int term_type;
  short int term;
  int pay_freq;
  double tax_rate;
  double key_rate;
  double sum;
  double intr_rate;
  double non_taking_rem;
  Date start_date;
  std::vector<Transaction> fund;
  std::vector<Transaction> wth;
};

}  // namespace deposit

namespace graph {

struct Conditions {
  std::string expr;
  double x_max;
  double x_min;
  double y_max;
  double y_min;
  bool autoscale;
};

struct Data {
  std::vector<std::vector<std::pair<double, double>>> graphs;
  double x_min;
  double x_max;
  double y_min;
  double y_max;
};

}  // namespace graph

}  // namespace smcalc

#endif  // SMARTCALC_TYPES_DATA_TYPES_H_
