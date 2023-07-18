#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_

#include <QDate>
#include <QVector>
#include <string>
#include <vector>

enum DateType { typeDay, typeMonth, typeYear };

enum DateLimits { yearMax = 50, monthMax = 600, dayMax = 18250 };

enum DatesNum { monthInYear = 12, abgDaysInMonth = 30, avgDaysInYear = 365 };

enum CondPayFreq : short int {
  evDay,
  evWeek,
  evMon,
  evQuart,
  evHalfYear,
  evYear
};

struct CreditConditions {
  double sum;
  double int_rate;
  short int period;
  bool date_is_year;
  bool type;
};

struct CreditData {
  double total;
  double overpay;
  std::vector<double> payment;
};

struct DepositData {
  std::vector<std::pair<QDate, double>> replen;
  std::vector<QDate> pay_dates;
  std::vector<double> payment;
  std::vector<double> tax;
  QDate start_date;
  QDate finish_date;
  double eff_rate;
  double perc_sum;
  double tax_sum;
  double total;
};

struct UserTransaction {
  QDate date;
  double sum;
  short int freq;
};

struct DepositConditions {
  bool cap;
  short int term_type;
  short int term;
  int pay_freq;
  double tax_rate;
  double key_rate;
  double sum;
  double intr_rate;
  double non_taking_rem;
  QDate start_date;
  std::vector<UserTransaction> fund;
  std::vector<UserTransaction> wth;
};

struct GraphConditions {
  std::string expr;
  double x_max;
  double x_min;
  double y_max;
  double y_min;
  bool autoscale;
};

struct GraphData {
  std::vector<std::pair<QVector<double>, QVector<double>>> xy;
  double x_min;
  double x_max;
  double y_min;
  double y_max;
};

#endif  // DATA_TYPES_H_
