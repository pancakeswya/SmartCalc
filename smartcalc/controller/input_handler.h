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
    bool HandleExprX(QString& input, QString& x_str);
    QString HandleExprBin(QString input);
    QString HandleExprBackspace(QString input);
};

} // namespace smcalc

#endif // SMARTCALC_INPUT_CONTROLLER_H_
