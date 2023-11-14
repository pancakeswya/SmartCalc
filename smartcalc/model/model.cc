#include "model.h"

#include "basic_calc.h"
#include "credit_calc.h"
#include "deposit_calc.h"
#include "graph_calc.h"

namespace smcalc {

void Model::CalculateBasicExpr(const std::string& expr) {
  basic_data_ = basic::CalculateFromString(expr);
}

void Model::CalculateBasicEquation(const std::string& expr, double x) {
  basic_data_ = basic::CalculateFromStringEquation(expr, x);
}

void Model::CalculateCredit(const credit::Conditions& conds) {
  credit_data_ = credit::Calculate(conds);
}

void Model::CalculateDeposit(const deposit::Conditions& conds) {
  deposit_data_ = deposit::Calculate(conds);
}

void Model::CalculateGraph(const graph::Conditions& conds) {
  graph_data_ = graph::Calculate(conds);
}

double Model::GetBasicData() { return basic_data_; }

const credit::Data& Model::GetCreditData() { return credit_data_; }

const deposit::Data& Model::GetDepositData() { return deposit_data_; }

const graph::Data& Model::GetGraphData() { return graph_data_; }

void Model::Reset() {
  basic_data_ = 0.0;
  credit_data_ = {};
  deposit_data_ = {};
  graph_data_ = {};
}

}  // namespace smcalc
