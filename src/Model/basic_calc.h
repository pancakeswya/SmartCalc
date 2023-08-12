#ifndef SMARTCALC_V2_SRC_MODEL_BASIC_CALC_H_
#define SMARTCALC_V2_SRC_MODEL_BASIC_CALC_H_

#include "../Controller/data_types.h"

#include <string>

namespace s21::BasicCalc {

double CalcMathExpr(const std::string& expr);
double CalcEquation(std::string& expr, double x);
GraphData CalcGraph(const GraphConditions& conds);

}  // namespace s21::BasicCalc

#endif  // SMARTCALC_V2_SRC_MODEL_BASIC_CALC_H_
