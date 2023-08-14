#ifndef SMARTCALC_V2_SRC_MODEL_MODEL_H_
#define SMARTCALC_V2_SRC_MODEL_MODEL_H_

#include "bank_calc.h"
#include "basic_calc.h"

namespace s21 {

class Model {
 public:
  void CalcCredit(const CreditConditions& conds) {
    cred_.SetConditions(conds);
    cred_.CalcCredit();
  }

  void CalcDeposit(const DepositConditions& conds) {
    dep_.SetConditions(conds);
    dep_.CalcDeposit();
  }

  void CalcGraph(const GraphConditions& conds) {
    graph_ = BasicCalc::CalcGraph(conds);
  }

  void CalcExpression(const std::string_view& expr) {
    ans_ = BasicCalc::CalcMathExpr(expr.data());
  }

  void CalcEquation(const std::string_view& expr, double x) {
    ans_ = BasicCalc::CalcEquation(expr.data(), x);
  }

  double GetExpressionAns() noexcept { return ans_; }

  const GraphData& GetGraphData() noexcept { return graph_; }

  const DepositData& GetDepositData() noexcept { return dep_.GetData(); }

  const CreditData& GetCreditData() noexcept { return cred_.GetData(); }

 private:
  Deposit dep_{};
  GraphData graph_{};
  Credit cred_{};
  double ans_{};
};

}  // namespace s21

#endif  // SMARTCALC_V2_SRC_MODEL_MODEL_H_
