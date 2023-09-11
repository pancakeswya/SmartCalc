#ifndef SMARTCALC_V2_SRC_VIEW_MAINWINDOW_H
#define SMARTCALC_V2_SRC_VIEW_MAINWINDOW_H

#include <QGridLayout>
#include <QMainWindow>

#include "controller/controller.h"
#include "secondwindow.h"

namespace s21 {

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(Controller* ctrl);
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private:
  Controller* controller_{};
  Ui::MainWindow* ui_;
  SecondWindow* sec_win_;
  QString x_str_;
  short int click_count_rep_;
  short int click_count_wth_;
  static constexpr int kMaxInputSize = 255;
  void AddNewLine(QGridLayout*, short int&);
  static void DeleteLine(QGridLayout*, short int&);
  static void ParseUserTransactions(QGridLayout*, short int,
                                    std::vector<UserTransaction>&);
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
 signals:
  void SignalDeposit(const DepositData&);
  void SignalCredit(const CreditData&);
  void SignalPlot(const GraphData&);
};

}  // namespace s21

#endif  // SMARTCALC_V2_SRC_VIEW_MAINWINDOW_H
