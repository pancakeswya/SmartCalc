#include "mainwindow.h"

#include <QMessageBox>

#include "ui_mainwindow.h"
#include "util/date_conv_util.h"

namespace smcalc {

namespace {

enum WindowSizes { kWidth = 359, kHeight = 453, kHeightGraph = 619 };

void DeleteLine(QGridLayout* layout, int& click) {
  if (click < 0) {
    return;
  }
  auto date =
      qobject_cast<QDateEdit*>(layout->itemAtPosition(click, 0)->widget());
  auto field =
      qobject_cast<QLineEdit*>(layout->itemAtPosition(click, 1)->widget());
  auto box =
      qobject_cast<QComboBox*>(layout->itemAtPosition(click--, 2)->widget());

  date->hide();
  field->hide();
  box->hide();

  delete date;
  delete field;
  delete box;
}

void AddNewLine(QWidget* parent, QGridLayout* layout, int& click) {
  auto field = new QLineEdit(parent);
  auto date = new QDateEdit(parent);
  auto box = new QComboBox(parent);

  field->setValidator(new QDoubleValidator(parent));
  date->setDate(QDate::currentDate().addDays(1));

  box->addItem("Once", 0);
  box->addItem("Every month", 1);
  box->addItem("Every 2 month", 2);
  box->addItem("Every quart", 3);
  box->addItem("Every half year", 4);
  box->addItem("Every year", 5);

  layout->addWidget(date, ++click, 0);
  layout->addWidget(field, click, 1);
  layout->addWidget(box, click, 2);
}

std::vector<deposit::Transaction> ParseUserTransactions(QGridLayout* layout,
                                                        int click) {
  std::vector<deposit::Transaction> opt;
  for (int i = click; i >= 0; --i) {
    auto date = qobject_cast<QDateEdit*>(layout->itemAtPosition(i, 0)->widget())
                    ->date();
    auto field =
        qobject_cast<QLineEdit*>(layout->itemAtPosition(i, 1)->widget());
    auto box = qobject_cast<QComboBox*>(layout->itemAtPosition(i, 2)->widget());

    opt.push_back({{util::ToDepositDate(date), field->text().toDouble()},
                   box->currentData().toInt()});
  }
  return opt;
}

}  // namespace

MainWindow::MainWindow(Controller* ctrl) : MainWindow() { controller_ = ctrl; }

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui_(new Ui::MainWindow),
      sec_win_(new SecondWindow(this)),
      click_count_rep_(-1),
      click_count_wth_(-1) {
  ui_->setupUi(this);
  SetSignals();
  SetWidgets();
  setWindowTitle("SmartCalc");
  setWindowIcon(QIcon(":/resources/img/calc-logo.png"));
#ifdef _WIN32
  setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
  setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
#endif
  setFixedSize(WindowSizes::kWidth, WindowSizes::kHeight);
}

MainWindow::~MainWindow() { delete ui_; }

void MainWindow::SetSignals() {
  connect(this, &MainWindow::SignalDeposit, sec_win_,
          &SecondWindow::SlotDeposit);
  connect(this, &MainWindow::SignalCredit, sec_win_, &SecondWindow::SlotCredit);
  connect(this, &MainWindow::SignalPlot, sec_win_, &SecondWindow::SlotPlot);
  connect(ui_->pushButton_dot, SIGNAL(clicked()), this,
          SLOT(OnPushButtonDotClicked()));
  connect(ui_->pushButton_AC, SIGNAL(clicked()), this,
          SLOT(OnPushButtonAcClicked()));
  connect(ui_->pushButton_Obrace, SIGNAL(clicked()), this,
          SLOT(OnPushButtonObraceClicked()));
  connect(ui_->pushButton_Cbrace, SIGNAL(clicked()), this,
          SLOT(OnPushButtonCbraceClicked()));
  connect(ui_->pushButton_eq, SIGNAL(clicked()), this,
          SLOT(OnPushButtonEqClicked()));
  connect(ui_->backspace, SIGNAL(clicked()), this, SLOT(OnBackspaceClicked()));
  connect(ui_->pushButton_bin, SIGNAL(clicked()), this,
          SLOT(OnPushButtonBinClicked()));
  connect(ui_->pushButton_credit, SIGNAL(clicked()), this,
          SLOT(OnPushButtonCreditClicked()));
  connect(ui_->pushButton_deposit, SIGNAL(clicked()), this,
          SLOT(OnPushButtonDepositClicked()));
  connect(ui_->pushButton_graph, SIGNAL(clicked()), this,
          SLOT(OnPushButtonGraphClicked()));
  connect(ui_->tabWidget, SIGNAL(currentChanged(int)), this,
          SLOT(OnTabWidgetCurrentChanged(int)));
  connect(ui_->pushButton_plot, SIGNAL(clicked()), this,
          SLOT(OnPushButtonPlotClicked()));
  connect(ui_->pushButton_space, SIGNAL(clicked()), this,
          SLOT(OnPushButtonSpaceClicked()));
  connect(ui_->pushButton_rep, SIGNAL(clicked()), this,
          SLOT(OnPushButtonRepClicked()));
  connect(ui_->pushButton_wth, SIGNAL(clicked()), this,
          SLOT(OnPushButtonWthClicked()));
  connect(ui_->pushButton_del_rep, SIGNAL(clicked()), this,
          SLOT(OnPushButtonDelRepClicked()));
  connect(ui_->pushButton_del_wth, SIGNAL(clicked()), this,
          SLOT(OnPushButtonDelWthClicked()));
  connect(ui_->autoscale, SIGNAL(clicked(bool)), this,
          SLOT(OnAutoscaleStateChanged()));
  connect(ui_->pushButton_x, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui_->pushButton_0, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui_->pushButton_1, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui_->pushButton_2, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui_->pushButton_3, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui_->pushButton_4, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui_->pushButton_5, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui_->pushButton_6, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui_->pushButton_7, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui_->pushButton_8, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui_->pushButton_9, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui_->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(SimpleOperations()));
  connect(ui_->pushButton_min, SIGNAL(clicked()), this,
          SLOT(SimpleOperations()));
  connect(ui_->pushButton_div, SIGNAL(clicked()), this,
          SLOT(SimpleOperations()));
  connect(ui_->pushButton_mul, SIGNAL(clicked()), this,
          SLOT(SimpleOperations()));
  connect(ui_->pushButton_pow, SIGNAL(clicked()), this,
          SLOT(SimpleOperations()));
  connect(ui_->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(SimpleOperations()));
  connect(ui_->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui_->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui_->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui_->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui_->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui_->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui_->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui_->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui_->pushButton_log, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
}

void MainWindow::SetWidgets() {
  QLocale doub_lo(QLocale::C);
  doub_lo.setNumberOptions(QLocale::RejectGroupSeparator);
  QLocale::setDefault(doub_lo);

  ui_->Srok_cr->setValidator(new QIntValidator(0, 100, this));
  ui_->SummaCr->setValidator(new QDoubleValidator(this));
  auto dbl_val = new QDoubleValidator(0, 100, 1000, this);
  dbl_val->setNotation(QDoubleValidator::StandardNotation);
  ui_->int_rate->setValidator(dbl_val);
  ui_->srok_dep->setValidator(new QIntValidator(0, 10000, this));
  ui_->sum->setValidator(new QDoubleValidator(this));
  ui_->wth_rem_2->setValidator(new QDoubleValidator(this));
  ui_->int_rate_dep->setValidator(dbl_val);
  ui_->label_tax->setValidator(dbl_val);
  ui_->label_key_rate->setValidator(dbl_val);

  ui_->doubleSpinBoXa->setRange(-std::numeric_limits<double>::max(),
                                std::numeric_limits<double>::max());
  ui_->doubleSpinBoXi->setRange(-std::numeric_limits<double>::max(),
                                std::numeric_limits<double>::max());
  ui_->doubleSpinBoYa->setRange(-std::numeric_limits<double>::max(),
                                std::numeric_limits<double>::max());
  ui_->doubleSpinBoYi->setRange(-std::numeric_limits<double>::max(),
                                std::numeric_limits<double>::max());

  ui_->label_tax->setText("13");
  ui_->label_key_rate->setText("8.5");

  ui_->wth_rem->hide();
  ui_->wth_rem_2->hide();
  ui_->wth_r_sign->hide();

  ui_->doubleSpinBoYa->setDisabled(true);
  ui_->doubleSpinBoYi->setDisabled(true);

  ui_->autoscale->setCheckState(Qt::Checked);
  ui_->dep_date->setDate(QDate::currentDate());
  ui_->res_out->setAlignment(Qt::AlignRight);
  ui_->wth_rem_2->setText("0");
}

void MainWindow::OnPushButtonDotClicked() {
  QString output = input_handler_.HandleExprDot(ui_->res_out->text());
  ui_->res_out->setText(output);
}

void MainWindow::DigitsNumbers() {
  auto button_num = dynamic_cast<QPushButton*>(sender());
  QString output =
      input_handler_.HandleExprNum(ui_->res_out->text(), button_num->text());
  ui_->res_out->setText(output);
}

void MainWindow::SimpleOperations() {
  auto button_op = dynamic_cast<QPushButton*>(sender());
  QString output =
      input_handler_.HandleExprOp(ui_->res_out->text(), button_op->text());
  ui_->res_out->setText(output);
}

void MainWindow::ComplexOperations() {
  auto button_func = dynamic_cast<QPushButton*>(sender());
  QString output =
      input_handler_.HandleExprFunc(ui_->res_out->text(), button_func->text());
  ui_->res_out->setText(output);
}

void MainWindow::OnPushButtonAcClicked() { ui_->res_out->setText("0"); }

void MainWindow::OnPushButtonObraceClicked() {
  QString output = input_handler_.HandleExprOpenBrace(ui_->res_out->text());
  ui_->res_out->setText(output);
}

void MainWindow::OnPushButtonCbraceClicked() {
  QString output = input_handler_.HandleExprClosedBrace(ui_->res_out->text());
  ui_->res_out->setText(output);
}

void MainWindow::OnPushButtonEqClicked() {
  QString label = ui_->res_out->text();
  if (label.length() > kMaxInputSize) {
    QMessageBox::warning(this, "Warning", "Exceeded the number of characters");
    return;
  }
  double ans = 0;
  if (label.contains("x")) {
    bool ready_to_calc = input_handler_.HandleExprX(label, x_str_);
    if (!ready_to_calc) {
      ui_->res_out->setText(label);
      return;
    }
    try {
      ans = controller_->CalculateEquation(x_str_.toStdString(),
                                           label.toDouble());
    } catch (std::invalid_argument& exc) {
      QMessageBox::critical(this, "Error", exc.what());
    }
    x_str_.clear();
  } else {
    try {
      ans = controller_->CalculateExpression(label.toStdString());
    } catch (std::invalid_argument& exc) {
      QMessageBox::critical(this, "Error", exc.what());
    }
  }
  ui_->res_out->setText(QString::number(ans));
}

void MainWindow::OnPushButtonBinClicked() {
  QString output = input_handler_.HandleExprBin(ui_->res_out->text());
  ui_->res_out->setText(output);
}

void MainWindow::OnBackspaceClicked() {
  QString output = input_handler_.HandleExprBackspace(ui_->res_out->text());
  ui_->res_out->setText(output);
}

void MainWindow::OnPushButtonCreditClicked() {
  double sum = ui_->SummaCr->text().toDouble();
  double int_rate = ui_->int_rate->text().toDouble();
  short period = ui_->Srok_cr->text().toShort();
  bool is_year = !(ui_->type_sr_cr->currentIndex()),
       is_annuit = ui_->annuit->isChecked();
  if ((is_year && period > DateLimits::kYearMax) ||
      (!is_year && period > DateLimits::kMonthMax)) {
    QMessageBox::warning(
        this, "Warning",
        "The maximum value of the loan term has been exceeded");
  } else if (!is_annuit && !ui_->diff->isChecked()) {
    QMessageBox::warning(this, "Warning",
                         "Choose the type of monthly payments");
  } else {
    credit::Conditions conds = {sum, int_rate, period, is_year, is_annuit};
    const credit::Data& data = controller_->CalculateCredit(conds);
    sec_win_->show();
    emit SignalCredit(data);
  }
}

void MainWindow::OnPushButtonDepositClicked() {
  short int term = ui_->srok_dep->text().toShort();
  short int term_type = ui_->srok_typed->currentIndex();
  if ((term > DateLimits::kYearMax && term_type == DateType::kTypeYear) ||
      (term > DateLimits::kMonthMax && term_type == DateType::kTypeMonth) ||
      (term > DateLimits::kDayMax && term_type == DateType::kTypeDay)) {
    QMessageBox::warning(
        this, "Warning",
        "The maximum value of the deposit placement period has been exceeded");
  } else {
    deposit::Conditions conds = {
        ui_->capitalization->isChecked(),
        term_type,
        term,
        ui_->rate_pay->currentIndex(),
        ui_->label_tax->text().toDouble(),
        ui_->label_key_rate->text().toDouble(),
        ui_->sum->text().toDouble(),
        ui_->int_rate_dep->text().toDouble(),
        ui_->wth_rem_2->text().toDouble(),
        util::ToDepositDate(ui_->dep_date->date()),
        ParseUserTransactions(ui_->gridLayout_rep, click_count_rep_),
        ParseUserTransactions(ui_->gridLayout_wth, click_count_wth_)};
    const deposit::Data& data = controller_->CalculateDeposit(conds);
    sec_win_->show();
    emit SignalDeposit(data);
  }
}

void MainWindow::OnPushButtonGraphClicked() {
  if (MainWindow::window()->geometry().height() == WindowSizes::kHeight) {
    setFixedSize(WindowSizes::kWidth, WindowSizes::kHeightGraph);
  } else {
    setFixedSize(WindowSizes::kWidth, WindowSizes::kHeight);
  }
}

void MainWindow::OnTabWidgetCurrentChanged(int index) {
  if (index &&
      MainWindow::window()->geometry().height() == WindowSizes::kHeightGraph) {
    setFixedSize(MainWindow::window()->geometry().width(),
                 WindowSizes::kHeight);
  }
}

void MainWindow::OnPushButtonPlotClicked() {
  if (ui_->doubleSpinBoXi->value() >= ui_->doubleSpinBoXa->value() ||
      (!ui_->autoscale->isChecked() &&
       ui_->doubleSpinBoYi->value() >= ui_->doubleSpinBoYa->value())) {
    QMessageBox::critical(this, "Warning",
                          "The scope of values or the scope of the function "
                          "definition is not defined");
  } else {
    graph::Conditions conds = {
        ui_->res_out->text().toStdString(), ui_->doubleSpinBoXa->value(),
        ui_->doubleSpinBoXi->value(),       ui_->doubleSpinBoYa->value(),
        ui_->doubleSpinBoYi->value(),       ui_->autoscale->isChecked()};
    try {
      const graph::Data& data = controller_->CalculateGraph(conds);
      sec_win_->show();
      emit SignalPlot(data);
    } catch (std::invalid_argument& exc) {
      QMessageBox::critical(this, "Error", exc.what());
    }
  }
}

void MainWindow::OnPushButtonSpaceClicked() {
  ui_->res_out->setText(ui_->res_out->text() + " ");
}

void MainWindow::OnPushButtonRepClicked() {
  AddNewLine(this, ui_->gridLayout_rep, click_count_rep_);
}

void MainWindow::OnPushButtonWthClicked() {
  AddNewLine(this, ui_->gridLayout_wth, click_count_wth_);
  if (click_count_wth_ == 0) {
    ui_->wth_rem->show();
    ui_->wth_rem_2->show();
    ui_->wth_r_sign->show();
  }
}

void MainWindow::OnPushButtonDelRepClicked() {
  DeleteLine(ui_->gridLayout_rep, click_count_rep_);
}

void MainWindow::OnPushButtonDelWthClicked() {
  DeleteLine(ui_->gridLayout_wth, click_count_wth_);
  if (click_count_wth_ == -1) {
    ui_->wth_rem->hide();
    ui_->wth_rem_2->hide();
    ui_->wth_r_sign->hide();
  }
}

void MainWindow::OnAutoscaleStateChanged() {
  ui_->doubleSpinBoYa->setDisabled(ui_->autoscale->isChecked());
  ui_->doubleSpinBoYi->setDisabled(ui_->autoscale->isChecked());
}

}  // namespace smcalc
