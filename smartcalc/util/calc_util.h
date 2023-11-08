#ifndef SMARTCALC_UTIL_CALC_UTIL_H_
#define SMARTCALC_UTIL_CALC_UTIL_H_

#include <stack>
#include <optional>
#include <stdexcept>

namespace smcalc::util {

template<typename T>
inline T StackPop(std::stack<T> &stack) {
  if (stack.empty()) {
    throw std::invalid_argument("Invalid syntax. Invalid expression");
  }
  T top_val = stack.top();
  stack.pop();
  return top_val;
}

} // namespace smcalc::util

#endif // SMARTCALC_UTIL_CALC_UTIL_H_