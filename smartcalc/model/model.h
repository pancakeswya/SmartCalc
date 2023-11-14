#ifndef SMARTCALC_MODEL_MODEL_H_
#define SMARTCALC_MODEL_MODEL_H_

#include "types/data_types.h"

namespace smcalc {

class Model {
 public:
  void CalculateBasicExpr(const std::string& expr);
  void CalculateBasicEquation(const std::string& expr, double x);
  void CalculateCredit(const credit::Conditions& conds);
  void CalculateDeposit(const deposit::Conditions& conds);
  void CalculateGraph(const graph::Conditions& conds);

  double GetBasicData();
  const credit::Data& GetCreditData();
  const deposit::Data& GetDepositData();
  const graph::Data& GetGraphData();

  void Reset();

 private:
  double basic_data_;
  credit::Data credit_data_;
  deposit::Data deposit_data_;
  graph::Data graph_data_;
};

}  // namespace smcalc

#endif  // SMARTCALC_MODEL_MODEL_H_
