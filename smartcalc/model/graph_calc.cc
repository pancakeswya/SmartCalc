#include "graph_calc.h"

#include "basic_calc.h"

namespace smcalc::graph {

Data Calculate(const Conditions& conds) {
  Data data;
  data.x_max = conds.x_max;
  data.x_min = conds.x_min;
  data.graphs.emplace_back();
  double res, step = (conds.x_max - conds.x_min) / 1000.0, min_y = 100000.0,
              max_y = -100000.0;
  double i = conds.x_min;
  while (i <= conds.x_max) {
    res = basic::CalculateFromStringEquation(conds.expr, i);
    if (!std::isnan(res) && !std::isinf(res)) {
      min_y = std::min(res, min_y);
      max_y = std::max(res, max_y);
      data.graphs.back().emplace_back(i, res);
    } else if (!data.graphs.back().empty()) {
      data.graphs.emplace_back();
    }
    i = (std::round(i * 1000.0) / 1000.0) + step;
  }
  if (conds.autoscale) {
    data.y_min = min_y;
    data.y_max = max_y;
  } else {
    data.y_min = conds.y_min;
    data.y_max = conds.y_max;
  }
  return data;
}

}  // namespace smcalc::graph
