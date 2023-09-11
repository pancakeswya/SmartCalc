#ifndef SMARTCALC_V2_SRC_CONTROLLER_CONTROLLER_H_
#define SMARTCALC_V2_SRC_CONTROLLER_CONTROLLER_H_

#include "model/model.h"

namespace s21 {

class Controller {
 public:
  Controller(Model* model) : model_(model) {}

  const DepositData& CalculateDeposit(const DepositConditions& conds) {
    model_->CalcDeposit(conds);
    return model_->GetDepositData();
  }

  const CreditData& CalculateCredit(const CreditConditions& conds) {
    model_->CalcCredit(conds);
    return model_->GetCreditData();
  }

  const GraphData& CalculateGraph(const GraphConditions& conds) {
    model_->CalcGraph(conds);
    return model_->GetGraphData();
  }

  double CalculateExpression(std::string_view expr) {
    model_->CalcExpression(expr);
    return model_->GetExpressionAns();
  }

  double CalculateEquation(std::string_view expr, double x) {
    model_->CalcEquation(expr, x);
    return model_->GetExpressionAns();
  }

 private:
  Model* model_;
};

}  // namespace s21

#endif  // SMARTCALC_V2_SRC_CONTROLLER_CONTROLLER_H_