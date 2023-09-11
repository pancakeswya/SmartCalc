#include "basic_calc.h"

#include <cmath>
#include <stack>
#include <stdexcept>
#include <unordered_map>

namespace s21::BasicCalc {

namespace {

class MathOperation {
 public:
  enum class Type : bool { kUnary = false, kBinary = true };

  enum class Priority : short int {
    kBrace,
    kSimple,
    kComplex,
    kFunction,
    kSign
  };

  MathOperation() = default;
  ~MathOperation() = default;

  explicit MathOperation(Type type, Priority priority,
                         double (*operation)(double, double)) noexcept
      : operation_{.binary = operation}, priority_(priority), type_(type) {}

  explicit MathOperation(Type type, Priority priority,
                         double (*operation)(double)) noexcept
      : operation_{.unary = operation}, priority_(priority), type_(type) {}

  [[nodiscard]] Priority GetPriority() const noexcept { return priority_; }
  [[nodiscard]] Type GetType() const noexcept { return type_; }

  [[nodiscard]] double PerformOperation(double num) const noexcept {
    return operation_.unary(num);
  }

  [[nodiscard]] double PerformOperation(double num1,
                                        double num2) const noexcept {
    return operation_.binary(num1, num2);
  }

 private:
  union {
    double (*binary)(double, double);
    double (*unary)(double);
  } operation_{};
  Priority priority_{};
  Type type_{};
};

const std::unordered_map<std::string_view, MathOperation> op_map = {
    {"--",
     MathOperation(MathOperation::Type::kUnary, MathOperation::Priority::kSign,
                   [](double num) -> double { return -num; })},
    {"++",
     MathOperation(MathOperation::Type::kUnary, MathOperation::Priority::kSign,
                   [](double num) -> double { return num; })},
    {"sqrt", MathOperation(MathOperation::Type::kUnary,
                           MathOperation::Priority::kFunction, std::sqrt)},
    {"sin", MathOperation(MathOperation::Type::kUnary,
                          MathOperation::Priority::kFunction, std::sin)},
    {"cos", MathOperation(MathOperation::Type::kUnary,
                          MathOperation::Priority::kFunction, std::cos)},
    {"tan", MathOperation(MathOperation::Type::kUnary,
                          MathOperation::Priority::kFunction, std::tan)},
    {"asin", MathOperation(MathOperation::Type::kUnary,
                           MathOperation::Priority::kFunction, std::asin)},
    {"acos", MathOperation(MathOperation::Type::kUnary,
                           MathOperation::Priority::kFunction, std::acos)},
    {"atan", MathOperation(MathOperation::Type::kUnary,
                           MathOperation::Priority::kFunction, std::atan)},
    {"ln", MathOperation(MathOperation::Type::kUnary,
                         MathOperation::Priority::kFunction, std::log)},
    {"log", MathOperation(MathOperation::Type::kUnary,
                          MathOperation::Priority::kFunction, std::log10)},
    {"^", MathOperation(MathOperation::Type::kBinary,
                        MathOperation::Priority::kFunction, std::pow)},
    {"*", MathOperation(
              MathOperation::Type::kBinary, MathOperation::Priority::kComplex,
              [](double num1, double num2) -> double { return num1 * num2; })},
    {"/", MathOperation(
              MathOperation::Type::kBinary, MathOperation::Priority::kComplex,
              [](double num1, double num2) -> double { return num1 / num2; })},
    {"d", MathOperation(MathOperation::Type::kBinary,
                        MathOperation::Priority::kComplex, std::fmod)},
    {"+", MathOperation(
              MathOperation::Type::kBinary, MathOperation::Priority::kSimple,
              [](double num1, double num2) -> double { return num1 + num2; })},
    {"-", MathOperation(
              MathOperation::Type::kBinary, MathOperation::Priority::kSimple,
              [](double num1, double num2) -> double { return num1 - num2; })},
    {"(",
     MathOperation(MathOperation::Type::kUnary, MathOperation::Priority::kBrace,
                   (double (*)(double)){})}};

template <typename T>
inline T StackPull(std::stack<T>& stack) {
  if (stack.empty()) {
    throw std::invalid_argument("Invalid syntax exception");
  }
  T top_val = stack.top();
  stack.pop();
  return top_val;
}

void CalcShuntYard(std::stack<MathOperation>& operations,
                   std::stack<double>& numbers) {
  double res;
  MathOperation op = StackPull(operations);
  if (op.GetPriority() == MathOperation::Priority::kBrace) {
    throw std::invalid_argument("Matching brace exception");
  }
  double num1 = StackPull(numbers);
  if (op.GetType() == MathOperation::Type::kUnary) {
    res = op.PerformOperation(num1);
  } else {
    double num2 = StackPull(numbers);
    res = op.PerformOperation(num2, num1);
  }
  numbers.push(res);
}

inline void MakeShuntYardBrace(std::stack<MathOperation>& operations,
                               std::stack<double>& numbers) {
  while (!operations.empty() &&
         operations.top().GetPriority() != MathOperation::Priority::kBrace) {
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

size_t ProcessFunction(std::string_view expr,
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

size_t ProcessNumber(std::string_view expr, bool prev_was_num,
                     std::stack<double>& numbers) {
  size_t n_size;
  double number = std::stod(&expr[0], &n_size);
  if (prev_was_num || n_size == 0) {
    throw std::invalid_argument("Invalid syntax exception");
  }
  numbers.push(number);
  return n_size - 1;
}

void FixPower(std::string& expr, size_t i) noexcept {
  for (; std::isspace(expr[i]); ++i)
    ;
  size_t start = i;
  bool has_pow = false;
  while (std::isalnum(expr[i]) || std::isspace(expr[i]) || expr[i] == '^' ||
         expr[i] == '(' || expr[i] == '.') {
    if (expr[i] == '^') {
      has_pow = true;
    }
    if (expr[i] == '(') {
      for (; expr[i] != ')' && expr[i]; ++i)
        ;
      for (; expr[i] == ')'; ++i)
        ;
      continue;
    }
    ++i;
  }
  if (has_pow) {
    expr.insert(start, "(");
    expr.insert(i + 1, ")");
  }
}

}  // namespace

double CalcMathExpr(std::string expr) {
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
      case '^':
      case '+':
      case '-':
      case '*':
      case '/':
        if (expr[i] == '^') {
          FixPower(expr, i + 1);
        }
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
    throw std::invalid_argument("Invalid syntax exception");
  }
  return numbers.top();
}

double CalcEquation(std::string expr, double x) {
  for (;;) {
    std::size_t pos = expr.find('x');
    if (pos == std::string::npos) {
      break;
    }
    expr.replace(pos, 1, std::to_string(x));
  }
  return CalcMathExpr(std::move(expr));
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
    res = CalcEquation(conds.expr.data(), i);
    if (!std::isnan(res) && !std::isinf(res)) {
      min_y = std::min(res, min_y);
      max_y = std::max(res, max_y);
      data.xy.back().first.push_back(i);
      data.xy.back().second.push_back(res);
    } else if (data.xy.back() !=
               std::pair<QVector<double>, QVector<double>>()) {
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
