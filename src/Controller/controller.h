#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../Model/model.h"

class Controller {
 public:
  Controller(Model* model) : model_(model) {}

  const DepositData& CalculateDeposit(DepositConditions& conds) {
    model_->CalcDeposit(conds);
    return model_->GetDepositData();
  }

  const CreditData& CalculateCredit(CreditConditions& conds) {
    model_->CalcCredit(conds);
    return model_->GetCreditData();
  }

  const GraphData& CalculateGraph(GraphConditions& conds) {
    model_->CalcGraph(conds);
    return model_->GetGraphData();
  }

  double CalculateExpression(const std::string expr) {
    model_->CalcExpression(expr);
    return model_->GetExpressionAns();
  }

 private:
  Model* model_;
};

#endif  // CONTROLLER_H_