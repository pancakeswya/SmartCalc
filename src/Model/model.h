#ifndef MODEL_H_
#define MODEL_H_

#include "bank_calc.h"
#include "basic_calc.h"

class Model {
 public:
  void CalcCredit(CreditConditions& conds) {
    m_cred.SetConditions(std::move(conds));
    m_cred.CalcCredit();
  }

  void CalcDeposit(DepositConditions& conds) {
    m_dep.SetConditions(std::move(conds));
    m_dep.CalcDeposit();
  }

  void CalcGraph(GraphConditions& conds) {
    m_graph = s21::BasicCalc::CalcGraph(conds);
  }

  void CalcExpression(const std::string& expr) {
    m_ans = s21::BasicCalc::CalcMathExpr(expr);
  }

  void CalcEquation(std::string expr, double x) {
    m_ans = s21::BasicCalc::CalcEquation(expr, x);
  }

  double& GetExpressionAns() noexcept { return m_ans; }

  const GraphData& GetGraphData() noexcept { return m_graph; }

  const DepositData& GetDepositData() noexcept { return m_dep.GetData(); }

  const CreditData& GetCreditData() noexcept { return m_cred.GetData(); }

 private:
  s21::Deposit m_dep{};
  GraphData m_graph{};
  s21::Credit m_cred{};
  double m_ans{};
};

#endif  // MODEL_H_
