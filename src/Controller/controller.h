#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../Model/model.h"

class Controller {
 public:
  Controller(Model* model) : m_model(model) {}

  const DepositData& CalculateDeposit(DepositConditions& conds) {
    m_model->CalcDeposit(conds);
    return m_model->GetDepositData();
  }

  const CreditData& CalculateCredit(CreditConditions& conds) {
    m_model->CalcCredit(conds);
    return m_model->GetCreditData();
  }

  const GraphData& CalculateGraph(GraphConditions& conds) {
    m_model->CalcGraph(conds);
    return m_model->GetGraphData();
  }

  double CalculateExpression(const std::string expr) {
    m_model->CalcExpression(expr);
    return m_model->GetExpressionAns();
  }

 private:
  Model* m_model;
};

#endif  // CONTROLLER_H_