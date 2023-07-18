#ifndef BASIC_CALC_H_
#define BASIC_CALC_H_

#include <string>

#include "../Controller/data_types.h"

namespace s21::BasicCalc {

double CalcMathExpr(const std::string& expr);
double CalcEquation(std::string& expr, double x);
GraphData CalcGraph(const GraphConditions& conds);

}  // namespace s21::BasicCalc

#endif  // BASIC_CALC_H_
