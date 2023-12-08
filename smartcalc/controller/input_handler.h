#ifndef SMARTCALC_INPUT_CONTROLLER_H_
#define SMARTCALC_INPUT_CONTROLLER_H_

#include <QString>

namespace smcalc::InputHandler {

QString HandleExprDot(QString input);
QString HandleExprNum(QString input, const QString& num);
QString HandleExprOp(QString input, const QString& op);
QString HandleExprFunc(QString input, const QString& func);
QString HandleExprOpenBrace(QString input);
QString HandleExprClosedBrace(QString input);
QString HandleExprBin(QString input);
QString HandleExprBackspace(QString input);
bool HandleExprX(QString& input, QString& x_str);

}  // namespace smcalc::InputHandler

#endif  // SMARTCALC_INPUT_CONTROLLER_H_
