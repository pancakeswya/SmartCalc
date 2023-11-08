#ifndef SMARTCALC_CONTROLLER_CONTROLLER_H_
#define SMARTCALC_CONTROLLER_CONTROLLER_H_

#include "types/data_types.h"

namespace smcalc {

class Model;

class Controller {
 public:
  explicit Controller(Model* model) noexcept;

  double CalculateExpression(const std::string& expr);
  double CalculateEquation(const std::string& expr, double x);
  const credit::Data& CalculateCredit(const credit::Conditions& conds);
  const deposit::Data& CalculateDeposit(const deposit::Conditions& conds);

  void Reset();

 private:
  Model* model_;
};

} // smcalc

#endif // SMARTCALC_CONTROLLER_CONTROLLER_H_
