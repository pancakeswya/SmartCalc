#ifndef SMARTCALC_V2_SRC_VIEW_SECONDWINDOW_H
#define SMARTCALC_V2_SRC_VIEW_SECONDWINDOW_H

#include "../Controller/data_types.h"

#include <QApplication>
#include <QDialog>

namespace s21 {

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog {
  Q_OBJECT

 public:
  explicit SecondWindow(QWidget* parent = nullptr);
  ~SecondWindow();

 private:
  Ui::SecondWindow *ui_;

 public slots:
  void SlotDeposit(const DepositData&);
  void SlotCredit(const CreditData&);
  void SlotPlot(const GraphData&);
};

}  // namespace s21

#endif  // SMARTCALC_V2_SRC_VIEW_SECONDWINDOW_H
