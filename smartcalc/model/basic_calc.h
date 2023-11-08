#ifndef SMARTCALC_MODEL_BASIC_CALC_H_
#define SMARTCALC_MODEL_BASIC_CALC_H_

#include <string>

namespace smcalc::basic {

extern double CalculateFromString(std::string expr);
extern double CalculateFromStringEquation(std::string expr, double x);

} // smcalc::basic

#endif // SMARTCALC_MODEL_BASIC_CALC_H_