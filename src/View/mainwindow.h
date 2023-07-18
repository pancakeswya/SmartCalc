#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QMainWindow>

#include "../Controller/controller.h"
#include "secondwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(Controller *ctrl);
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Controller *m_ctrl{};
  Ui::MainWindow *ui;
  SecondWindow *sec_win;
  bool m_x_mode;
  short int m_click_counter_rep;
  short int m_click_counter_wth;
  static constexpr int maxInputSize = 255;
  void AddNewLine(QGridLayout *, short int &);
  static void DeleteLine(QGridLayout *, short int &);
  static void ParseUserTransactions(QGridLayout *, short int,
                                    std::vector<UserTransaction> &opt);
  void SetSignals();
  void SetWidgets();
  void StartPointClear();
 private slots:
  void DigitsNumbers();
  void SimpleOperations();
  void ComplexOperations();
  void OnPushButtonDotClicked();
  void OnPushButtonAcClicked();
  void OnPushButtonObraceClicked();
  void OnPushButtonCbraceClicked();
  void OnPushButtonEqClicked();
  void OnPushButtonBinClicked();
  void OnBackspaceClicked();
  void OnPushButtonCreditClicked();
  void OnPushButtonDepositClicked();
  void OnPushButtonGraphClicked();
  void OnTabWidgetCurrentChanged(int);
  void OnPushButtonPlotClicked();
  void OnPushButtonSpaceClicked();
  void OnPushButtonRepClicked();
  void OnPushButtonWthClicked();
  void OnPushButtonDelRepClicked();
  void OnPushButtonDelWthClicked();
  void OnAutoscaleStateChanged();
  void OnPushButtonXclicked();
 signals:
  void SignalDeposit(const DepositData &);
  void SignalCredit(const CreditData &);
  void SignalPlot(const GraphData &);
};

#endif  // MAINWINDOW_H
