#include "controller.h"
#include "model/model.h"

namespace smcalc {

Controller::Controller(Model* model) noexcept : model_(model) {}

double Controller::CalculateExpression(const std::string& expr) {
  model_->CalculateBasicExpr(expr);
  return model_->GetBasicData();
}

double Controller::CalculateEquation(const std::string& expr, double x) {
  model_->CalculateBasicEquation(expr, x);
  return model_->GetBasicData();
}

const credit::Data& Controller::CalculateCredit(const credit::Conditions& conds) {
  model_->CalculateCredit(conds);
  return model_->GetCreditData();
}

const deposit::Data& Controller::CalculateDeposit(const deposit::Conditions& conds) {
  model_->CalculateDeposit(conds);
  return model_->GetDepositData();
}

void Controller::Reset() {
  model_->Reset();
}

} // namespace smcalc
