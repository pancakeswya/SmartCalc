#ifndef SMARTCALC_V2_SRC_VIEW_SECONDWINDOW_H
#define SMARTCALC_V2_SRC_VIEW_SECONDWINDOW_H

#include <QApplication>
#include <QDialog>

#include "types/data_types.h"

namespace smcalc {

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog {
  Q_OBJECT

 public:
  explicit SecondWindow(QWidget* parent = nullptr);
  ~SecondWindow();

 private:
  Ui::SecondWindow* ui_;

 public slots:
  void SlotDeposit(const deposit::Data&);
  void SlotCredit(const credit::Data&);
  void SlotPlot(const graph::Data&);
};

}  // namespace smcalc

#endif  // SMARTCALC_V2_SRC_VIEW_SECONDWINDOW_H
