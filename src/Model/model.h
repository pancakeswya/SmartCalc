#ifndef MODEL_H_
#define MODEL_H_

#include "bank_calc.h"
#include "basic_calc.h"

class Model {
 public:
  void CalcCredit(CreditConditions& conds) {
    cred_.SetConditions(std::move(conds));
    cred_.CalcCredit();
  }

  void CalcDeposit(DepositConditions& conds) {
    dep_.SetConditions(std::move(conds));
    dep_.CalcDeposit();
  }

  void CalcGraph(GraphConditions& conds) {
    graph_ = s21::BasicCalc::CalcGraph(conds);
  }

  void CalcExpression(const std::string& expr) {
    ans_ = s21::BasicCalc::CalcMathExpr(expr);
  }

  void CalcEquation(std::string expr, double x) {
    ans_ = s21::BasicCalc::CalcEquation(expr, x);
  }

  double& GetExpressionAns() noexcept { return ans_; }

  const GraphData& GetGraphData() noexcept { return graph_; }

  const DepositData& GetDepositData() noexcept { return dep_.GetData(); }

  const CreditData& GetCreditData() noexcept { return cred_.GetData(); }

 private:
  s21::Deposit dep_{};
  GraphData graph_{};
  s21::Credit cred_{};
  double ans_{};
};

#endif  // MODEL_H_
