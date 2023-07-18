#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QApplication>
#include <QDialog>

#include "../Controller/data_types.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog {
  Q_OBJECT

 public:
  explicit SecondWindow(QWidget *parent = nullptr);
  ~SecondWindow();

 private:
  Ui::SecondWindow *ui;

 public slots:
  void SlotDeposit(const DepositData &);
  void SlotCredit(const CreditData &);
  void SlotPlot(const GraphData &);
};

#endif  // SECONDWINDOW_H
