#include "input_handler.h"

#include "util/calc_util.h"

namespace smcalc {

namespace {

inline void ClearOnZero(QString& input) {
  if (input == "0") {
    input.clear();
  }
}

}  // namespace

QString InputHandler::HandleExprDot(QString input) {
  if (input.isEmpty() || !input.back().isDigit()) {
    return input;
  }
  for (auto it_text = input.rbegin();
       it_text != input.rend() && it_text->isDigit(); ++it_text) {
    if (*it_text == '.') {
      return input;
    }
  }
  return input + '.';
}

QString InputHandler::HandleExprNum(QString input, QString num) {
  ClearOnZero(input);
  return input + num;
}

QString InputHandler::HandleExprOp(QString input, QString op) {
  if (input.isEmpty() || util::IsOperator(input.back().toLatin1())) {
    return input;
  }
  return input + op;
}

QString InputHandler::HandleExprFunc(QString input, QString func) {
  ClearOnZero(input);
  return input + func + '(';
}

QString InputHandler::HandleExprOpenBrace(QString input) {
  ClearOnZero(input);
  return input + '(';
}

QString InputHandler::HandleExprClosedBrace(QString input) {
  if (input.isEmpty() || input == "0" || input.back() == '(') {
    return input;
  }
  ClearOnZero(input);
  return input + ')';
}

bool InputHandler::HandleExprX(QString& input, QString& x_str) {
  if (x_str.isEmpty()) {
    x_str = std::move(input);
    input = "x=";
    return false;
  }
  if (input.contains("x=")) {
    input.remove("x=");
  }
  return true;
}

QString InputHandler::HandleExprBin(QString input) {
  QChar prev = input.back();
  int i = input.length() - 2;
  for (; i >= 0 && (!prev.isDigit() || input[i].isDigit()); prev = input[i--])
    ;
  if (prev == '0') {
    return input;
  }
  if (i == -1) {
    if (prev.isDigit()) {
      input.insert(0, '-');
    }
  } else if (input[i] == '-') {
    input[i] = '+';
  } else if (input[i] == '+') {
    input[i] = '-';
  }
  return input;
}

QString InputHandler::HandleExprBackspace(QString input) {
  if (input.isEmpty() || input == "0") {
    return input;
  }
  input.chop(1);
  if (input.isEmpty()) {
    input += '0';
  }
  return input;
}

}  // namespace smcalc
