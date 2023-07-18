#include "basic_calc.h"

#include <cmath>
#include <stack>
#include <stdexcept>
#include <unordered_map>

namespace s21::BasicCalc {

namespace {

class MathOperation {
 public:
  enum class Type : bool { unary = false, binary = true };

  enum class Priority : short int { brace, simple, complex, function, sign };

  MathOperation() = default;
  ~MathOperation() = default;

  explicit MathOperation(Type type, Priority priority,
                         double (*operation)(double, double)) noexcept
      : m_operation{.binary = operation}, m_priority(priority), m_type(type) {}

  explicit MathOperation(Type type, Priority priority,
                         double (*operation)(double)) noexcept
      : m_operation{.unary = operation}, m_priority(priority), m_type(type) {}

  [[nodiscard]] Priority GetPriority() const noexcept { return m_priority; }
  [[nodiscard]] Type GetType() const noexcept { return m_type; }

  [[nodiscard]] double PerformOperation(double num) const noexcept {
    return m_operation.unary(num);
  }

  [[nodiscard]] double PerformOperation(double num1,
                                        double num2) const noexcept {
    return m_operation.binary(num1, num2);
  }

 private:
  union {
    double (*binary)(double, double);
    double (*unary)(double);
  } m_operation{};
  Priority m_priority{};
  Type m_type{};
};

const std::unordered_map<std::string, MathOperation> op_map = {
    {"--",
     MathOperation(MathOperation::Type::unary, MathOperation::Priority::sign,
                   [](double num) -> double { return -num; })},
    {"++",
     MathOperation(MathOperation::Type::unary, MathOperation::Priority::sign,
                   [](double num) -> double { return num; })},
    {"sqrt", MathOperation(MathOperation::Type::unary,
                           MathOperation::Priority::function, std::sqrt)},
    {"sin", MathOperation(MathOperation::Type::unary,
                          MathOperation::Priority::function, std::sin)},
    {"cos", MathOperation(MathOperation::Type::unary,
                          MathOperation::Priority::function, std::cos)},
    {"tan", MathOperation(MathOperation::Type::unary,
                          MathOperation::Priority::function, std::tan)},
    {"asin", MathOperation(MathOperation::Type::unary,
                           MathOperation::Priority::function, std::asin)},
    {"acos", MathOperation(MathOperation::Type::unary,
                           MathOperation::Priority::function, std::acos)},
    {"atan", MathOperation(MathOperation::Type::unary,
                           MathOperation::Priority::function, std::atan)},
    {"ln", MathOperation(MathOperation::Type::unary,
                         MathOperation::Priority::function, std::log)},
    {"log", MathOperation(MathOperation::Type::unary,
                          MathOperation::Priority::function, std::log10)},
    {"pow", MathOperation(MathOperation::Type::binary,
                          MathOperation::Priority::function, std::pow)},
    {"*", MathOperation(
              MathOperation::Type::binary, MathOperation::Priority::complex,
              [](double num1, double num2) -> double { return num1 * num2; })},
    {"/", MathOperation(
              MathOperation::Type::binary, MathOperation::Priority::complex,
              [](double num1, double num2) -> double { return num1 / num2; })},
    {"fmod", MathOperation(MathOperation::Type::binary,
                           MathOperation::Priority::complex, std::fmod)},
    {"+", MathOperation(
              MathOperation::Type::binary, MathOperation::Priority::simple,
              [](double num1, double num2) -> double { return num1 + num2; })},
    {"-", MathOperation(
              MathOperation::Type::binary, MathOperation::Priority::simple,
              [](double num1, double num2) -> double { return num1 - num2; })},
    {"(", MathOperation(MathOperation::Type::unary,
                        MathOperation::Priority::brace, [](double num) {
                          static_cast<void>(num);
                          return std::numeric_limits<double>::quiet_NaN();
                        })}};

template <typename T>
inline T& StackPull(std::stack<T>& stack) {
  if (stack.empty()) {
    throw std::out_of_range("Invalid syntax exception");
  }
  T& top_val = stack.top();
  stack.pop();
  return top_val;
}

void CalcShuntYard(std::stack<MathOperation>& operations,
                   std::stack<double>& numbers) {
  double res;
  MathOperation& op = StackPull(operations);
  double& num1 = StackPull(numbers);
  if (op.GetType() == MathOperation::Type::unary) {
    res = op.PerformOperation(num1);
  } else {
    double& num2 = StackPull(numbers);
    res = op.PerformOperation(num2, num1);
  }
  numbers.push(res);
}

inline void MakeShuntYardBrace(std::stack<MathOperation>& operations,
                               std::stack<double>& numbers) {
  while (!operations.empty() &&
         operations.top().GetPriority() != MathOperation::Priority::brace) {
    CalcShuntYard(operations, numbers);
  }
  if (operations.empty()) {
    throw std::invalid_argument("Matching brace exception");
  }
  operations.pop();
}

inline void MakeShuntYardOp(const MathOperation& operation,
                            std::stack<MathOperation>& operations,
                            std::stack<double>& numbers) {
  while (!operations.empty() &&
         operation.GetPriority() <= operations.top().GetPriority()) {
    CalcShuntYard(operations, numbers);
  }
  operations.push(operation);
}

void ProcessOperation(char op, bool prev_was_num,
                      std::stack<MathOperation>& operations,
                      std::stack<double>& numbers) {
  auto map_it = op_map.end();
  if (prev_was_num) {
    map_it = op_map.find(std::string(1, op));
  } else if (op == '-') {
    map_it = op_map.find("--");
  } else if (op == '+') {
    map_it = op_map.find("++");
  }
  if (map_it == op_map.end()) {
    throw std::invalid_argument("Invalid operator usage");
  }
  MakeShuntYardOp(map_it->second, operations, numbers);
}

size_t ProcessFunction(const std::string& expr,
                       std::stack<MathOperation>& operations) {
  decltype(op_map.end()) map_it;
  size_t size = 0;
  for (; std::isalpha(expr[size]); size++)
    ;
  map_it = op_map.find(expr.substr(0, size));
  if (map_it == op_map.end()) {
    throw std::invalid_argument("Invalid function naming");
  }
  operations.push(map_it->second);
  return size - 1;
}

size_t ProcessNumber(const std::string& expr, bool prev_was_num,
                     std::stack<double>& numbers) {
  size_t n_size;
  double number = std::stod(&expr[0], &n_size);
  if (prev_was_num || n_size == 0) {
    throw std::invalid_argument("Invalid syntax exception");
  }
  numbers.push(number);
  return n_size - 1;
}

}  // namespace

double CalcMathExpr(const std::string& expr) {
  bool prev_was_num = false;
  std::stack<double> numbers;
  std::stack<MathOperation> operations;
  for (size_t i = 0; i < expr.size(); i++) {
    switch (expr[i]) {
      case ' ':
      case '\n':
      case '\t':
        break;
      case 'm':
        if (!(expr[i + 1] == 'o' && expr[i + 2] == 'd')) {
          throw std::invalid_argument("illegal function naming");
        }
        i += 2;
        [[fallthrough]];
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
        ProcessOperation(expr[i], prev_was_num, operations, numbers);
        prev_was_num = false;
        break;
      case '(':
        operations.push(op_map.at("("));
        break;
      case ')':
        MakeShuntYardBrace(operations, numbers);
        break;
      case '0' ... '9':
        i += ProcessNumber(&expr[i], prev_was_num, numbers);
        prev_was_num = true;
        break;
      case 'a':
      case 's':
      case 'c':
      case 't':
      case 'l':
        i += ProcessFunction(&expr[i], operations);
        break;
      default:
        throw std::invalid_argument("Invalid syntax exception");
    }
  }
  while (!operations.empty()) {
    CalcShuntYard(operations, numbers);
  }
  if (numbers.size() != 1) {
    throw std::out_of_range("Invalid syntax exception");
  }
  return numbers.top();
}

double CalcEquation(const std::string& expr, double x) {
  std::string new_expr = expr;
  for (;;) {
    std::size_t pos = new_expr.find('x');
    if (pos == std::string::npos) {
      break;
    }
    new_expr.replace(pos, 1, std::to_string(x));
  }
  return CalcMathExpr(new_expr);
}

GraphData CalcGraph(const GraphConditions& conds) {
  GraphData data;
  data.x_max = conds.x_max;
  data.x_min = conds.x_min;
  data.xy.emplace_back();
  double res, step = (conds.x_max - conds.x_min) / 1000.0, min_y = 100000.0,
              max_y = -100000.0;
  double i = conds.x_min;
  while (i <= conds.x_max) {
    res = CalcEquation(conds.expr, i);
    if (!std::isnan(res) && !std::isinf(res)) {
      min_y = std::min(res, min_y);
      max_y = std::max(res, max_y);
      data.xy.back().first.push_back(i);
      data.xy.back().second.push_back(res);
    } else {
      data.xy.emplace_back();
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

}  // namespace s21::BasicCalc