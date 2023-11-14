#include <cmath>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <variant>

#include "util/calc_util.h"

namespace smcalc::basic {

namespace {

class Operation final {
 public:
  enum class Type : bool { kUnary, kBinary };

  enum class Priority : short int {
    kBrace,
    kSimple,
    kComplex,
    kFunction,
    kSign
  };

  Operation() = delete;
  ~Operation() = default;

  explicit Operation(Type type, Priority priority,
                     double (*operation)(double, double)) noexcept
      : operation_(operation), priority_(priority), type_(type) {}

  explicit Operation(Type type, Priority priority,
                     double (*operation)(double)) noexcept
      : operation_(operation), priority_(priority), type_(type) {}

  [[nodiscard]] Priority get_priority() const noexcept { return priority_; }
  [[nodiscard]] Type get_type() const noexcept { return type_; }

  [[nodiscard]] double Perform(double num) const {
    return std::get<double (*)(double)>(operation_)(num);
  }

  [[nodiscard]] double Perform(double num1, double num2) const {
    return std::get<double (*)(double, double)>(operation_)(num1, num2);
  }

 private:
  std::variant<double (*)(double, double), double (*)(double)> operation_;
  Priority priority_;
  Type type_;
};

const std::unordered_map<std::string_view, Operation> operations_map = {
    {"--", Operation(Operation::Type::kUnary, Operation::Priority::kSign,
                     [](double num) -> double { return -num; })},
    {"++", Operation(Operation::Type::kUnary, Operation::Priority::kSign,
                     [](double num) -> double { return num; })},
    {"sqrt", Operation(Operation::Type::kUnary, Operation::Priority::kFunction,
                       std::sqrt)},
    {"sin", Operation(Operation::Type::kUnary, Operation::Priority::kFunction,
                      std::sin)},
    {"cos", Operation(Operation::Type::kUnary, Operation::Priority::kFunction,
                      std::cos)},
    {"tan", Operation(Operation::Type::kUnary, Operation::Priority::kFunction,
                      std::tan)},
    {"asin", Operation(Operation::Type::kUnary, Operation::Priority::kFunction,
                       std::asin)},
    {"acos", Operation(Operation::Type::kUnary, Operation::Priority::kFunction,
                       std::acos)},
    {"atan", Operation(Operation::Type::kUnary, Operation::Priority::kFunction,
                       std::atan)},
    {"ln", Operation(Operation::Type::kUnary, Operation::Priority::kFunction,
                     std::log)},
    {"log", Operation(Operation::Type::kUnary, Operation::Priority::kFunction,
                      std::log10)},
    {"^", Operation(Operation::Type::kBinary, Operation::Priority::kFunction,
                    std::pow)},
    {"*",
     Operation(Operation::Type::kBinary, Operation::Priority::kComplex,
               [](double num1, double num2) -> double { return num1 * num2; })},
    {"/",
     Operation(Operation::Type::kBinary, Operation::Priority::kComplex,
               [](double num1, double num2) -> double { return num1 / num2; })},
    {"d", Operation(Operation::Type::kBinary, Operation::Priority::kComplex,
                    std::fmod)},
    {"+",
     Operation(Operation::Type::kBinary, Operation::Priority::kSimple,
               [](double num1, double num2) -> double { return num1 + num2; })},
    {"-",
     Operation(Operation::Type::kBinary, Operation::Priority::kSimple,
               [](double num1, double num2) -> double { return num1 - num2; })},
    {"(", Operation(Operation::Type::kUnary, Operation::Priority::kBrace,
                    (double (*)(double)){})}};

void ShuntYardAlgo(std::stack<Operation>& operations,
                   std::stack<double>& numbers) {
  Operation operation = util::StackPop(operations);
  double number1 = util::StackPop(numbers);
  if (operation.get_priority() == Operation::Priority::kBrace) {
    throw std::invalid_argument("Invalid syntax. Braces not matching");
  }
  double res_number;
  if (operation.get_type() == Operation::Type::kUnary) {
    res_number = operation.Perform(number1);
  } else {
    double number2 = util::StackPop(numbers);
    res_number = operation.Perform(number2, number1);
  }
  numbers.push(res_number);
}

inline void ShuntYardBrace(std::stack<Operation>& operations,
                           std::stack<double>& numbers) {
  while (!operations.empty() &&
         operations.top().get_priority() != Operation::Priority::kBrace) {
    ShuntYardAlgo(operations, numbers);
  }
  if (operations.empty()) {
    throw std::invalid_argument("Invalid syntax. Braces not matching");
  }
  operations.pop();
}

inline void ShuntYardOperation(const Operation& operation,
                               std::stack<Operation>& operations,
                               std::stack<double>& numbers) {
  while (!operations.empty() &&
         operation.get_priority() <= operations.top().get_priority()) {
    ShuntYardAlgo(operations, numbers);
  }
  operations.push(operation);
}

void ProcessOperation(char op, bool prev_was_num,
                      std::stack<Operation>& operations,
                      std::stack<double>& numbers) {
  auto map_it = operations_map.end();
  if (prev_was_num) {
    map_it = operations_map.find(std::string(1, op));
  } else if (op == '-') {
    map_it = operations_map.find("--");
  } else if (op == '+') {
    map_it = operations_map.find("++");
  }
  if (map_it == operations_map.end()) {
    throw std::invalid_argument("Invalid syntax. Incorrect operation usage");
  }
  ShuntYardOperation(map_it->second, operations, numbers);
}

size_t ProcessFunction(const std::string& expr,
                       std::stack<Operation>& operations) {
  std::unordered_map<std::string_view, Operation>::const_iterator map_it;
  size_t size = 0;
  for (; std::isalpha(expr[size]); size++)
    ;
  map_it = operations_map.find(expr.substr(0, size));
  if (map_it == operations_map.end()) {
    throw std::invalid_argument("Invalid syntax. Incorrect function usage");
  }
  operations.push(map_it->second);
  return size - 1;
}

size_t ProcessNumber(const std::string& expr, bool prev_was_num,
                     std::stack<double>& numbers) {
  size_t n_size;
  double number = std::stod(&expr[0], &n_size);
  if (prev_was_num || n_size == 0) {
    throw std::invalid_argument("Invalid syntax. Incorrect number usage");
  }
  numbers.push(number);
  return n_size - 1;
}

void FixPower(std::string& expr, size_t i) {
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

inline bool ReplaceXInString(std::string& expr, std::string number) {
  char prev = '\0';
  for (int i = 0; i < expr.size(); ++i) {
    if (expr[i] == 'x') {
      if (i > 0 && (std::isdigit(prev) || prev == 'x')) {
        return false;
      }
      std::string tail = expr.substr(i + 1);
      expr.replace(i, number.size(), number);
      expr += tail;
    }
    if (!std::isspace(expr[i])) {
      prev = expr[i];
    }
  }
  return true;
}

}  // namespace

double CalculateFromString(std::string expr) {
  bool prev_was_num = false;
  std::stack<double> numbers;
  std::stack<Operation> operations;
  for (size_t i = 0; i < expr.size(); ++i) {
    switch (expr[i]) {
      case ' ':
      case '\n':
      case '\t':
        break;
      case 'm':
        if (!(expr[i + 1] == 'o' && expr[i + 2] == 'd')) {
          throw std::invalid_argument(
              "Invalid syntax. Incorrect function usage");
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
        operations.push(operations_map.at("("));
        break;
      case ')':
        ShuntYardBrace(operations, numbers);
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
        throw std::invalid_argument("Invalid syntax. Incorrect expression");
    }
  }
  while (!operations.empty()) {
    ShuntYardAlgo(operations, numbers);
  }
  if (numbers.size() != 1) {
    throw std::invalid_argument("Invalid syntax. Incorrect expression");
  }
  return numbers.top();
}

double CalculateFromStringEquation(std::string expr, double x) {
  if (!ReplaceXInString(expr, std::to_string(x))) {
    throw std::invalid_argument("Invalid syntax. Invalid x placement");
  }
  return CalculateFromString(std::move(expr));
}

}  // namespace smcalc::basic
