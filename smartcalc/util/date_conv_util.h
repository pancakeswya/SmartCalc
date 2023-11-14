#ifndef DATE_CONV_UTIL_H_
#define DATE_CONV_UTIL_H_

#include <QDate>

#include "types/data_types.h"

namespace smcalc::util {

inline deposit::Date ToDepositDate(const QDate &date) noexcept {
  return {date.year(), date.month(), date.day()};
}

}  // namespace smcalc::util

#endif  // DATE_CONV_UTIL_H_