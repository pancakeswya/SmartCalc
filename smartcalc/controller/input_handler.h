#ifndef SMARTCALC_INPUT_CONTROLLER_H_
#define SMARTCALC_INPUT_CONTROLLER_H_

#include <QString>

namespace smcalc {

class InputHandler {
 public:
  QString HandleExprDot(QString input);
  QString HandleExprNum(QString input, QString num);
  QString HandleExprOp(QString input, QString op);
  QString HandleExprFunc(QString input, QString func);
  QString HandleExprOpenBrace(QString input);
  QString HandleExprClosedBrace(QString input);
  QString HandleExprBin(QString input);
  QString HandleExprBackspace(QString input);
  bool HandleExprX(QString& input, QString& x_str);
};

}  // namespace smcalc

#endif  // SMARTCALC_INPUT_CONTROLLER_H_
