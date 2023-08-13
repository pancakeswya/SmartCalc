#include "mainwindow.h"

#include <QMessageBox>

#include "ui_mainwindow.h"

namespace s21 {

enum WindowSizes { kWidth = 359, kHeight = 453, kHeightGraph = 619 };

MainWindow::MainWindow(Controller* ctrl) : MainWindow() { controller_ = ctrl; }

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui_(new Ui::MainWindow),
      sec_win_(new SecondWindow(this)),
      x_mode_(),
      click_count_rep_(-1),
      click_count_wth_(-1) {
  ui_->setupUi(this);
  SetSignals();
  SetWidgets();
  setWindowTitle("SmartCalc_v2.0");
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
  connect(ui_->pushButton_x, SIGNAL(clicked()), this,
          SLOT(OnPushButtonXclicked()));
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
  QDoubleValidator* dbl_val = new QDoubleValidator(0, 100, 1000, this);
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

void MainWindow::AddNewLine(QGridLayout* layout, short int& click) {
  QLineEdit* field = new QLineEdit(this);
  QDateEdit* date = new QDateEdit(this);
  QComboBox* box = new QComboBox(this);
  field->setValidator(new QDoubleValidator(this));
  date->setDate(QDate::currentDate().addDays(1));
  box->addItem("Разовое", 0);
  box->addItem("Раз в месяц", 1);
  box->addItem("Раз в 2 месяца", 2);
  box->addItem("Раз в квартал", 3);
  box->addItem("Раз в пол года", 4);
  box->addItem("Раз в год", 5);
  layout->addWidget(date, ++click, 0);
  layout->addWidget(field, click, 1);
  layout->addWidget(box, click, 2);
}

void MainWindow::DeleteLine(QGridLayout* layout, short int& click) {
  if (click >= 0) {
    QDateEdit* date =
        qobject_cast<QDateEdit*>(layout->itemAtPosition(click, 0)->widget());
    date->hide();
    delete date;
    QLineEdit* field =
        qobject_cast<QLineEdit*>(layout->itemAtPosition(click, 1)->widget());
    field->hide();
    delete field;
    QComboBox* box =
        qobject_cast<QComboBox*>(layout->itemAtPosition(click--, 2)->widget());
    box->hide();
    delete box;
  }
}

void MainWindow::ParseUserTransactions(QGridLayout* layout, short int click,
                                       std::vector<UserTransaction>& opt) {
  for (int i = click; i >= 0; i--) {
    QDateEdit* date =
        qobject_cast<QDateEdit*>(layout->itemAtPosition(i, 0)->widget());
    QLineEdit* field =
        qobject_cast<QLineEdit*>(layout->itemAtPosition(i, 1)->widget());
    QComboBox* box =
        qobject_cast<QComboBox*>(layout->itemAtPosition(i, 2)->widget());
    opt.push_back({date->date(), field->text().toDouble(),
                   static_cast<short int>(box->currentData().toInt())});
  }
}

void MainWindow::StartPointClear() {
  if (ui_->res_out->text() == "0") {
    ui_->res_out->clear();
  }
}

void MainWindow::OnPushButtonDotClicked() {
  QString tmp = ui_->res_out->text();
  for (auto it = tmp.rbegin(); it != tmp.rend(); it++) {
    if (*it == '.') {
      return;
    } else if (!(*it).isDigit()) {
      break;
    }
  }
  if (!tmp.isEmpty() && tmp.back().isDigit()) {
    ui_->res_out->setText(ui_->res_out->text() + ".");
  }
}

void MainWindow::OnPushButtonXclicked() {
  StartPointClear();
  ui_->res_out->setText(ui_->res_out->text() + "x");
  x_mode_ = true;
}

void MainWindow::DigitsNumbers() {
  QPushButton* button_num = static_cast<QPushButton*>(sender());
  StartPointClear();
  ui_->res_out->setText(ui_->res_out->text() + button_num->text());
}

void MainWindow::SimpleOperations() {
  QPushButton* button_op = static_cast<QPushButton*>(sender());
  if (!ui_->res_out->text().isEmpty()) {
    QChar ch = ui_->res_out->text().back();
    if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '^') {
      if (button_op->text() == "÷") {
        ui_->res_out->setText(ui_->res_out->text() + "/");
      } else {
        ui_->res_out->setText(ui_->res_out->text() + button_op->text());
      }
    }
  }
}

void MainWindow::ComplexOperations() {
  QPushButton* button_c_op = static_cast<QPushButton*>(sender());
  StartPointClear();
  if (button_c_op->text() == "√") {
    ui_->res_out->setText(ui_->res_out->text() + "sqrt(");
  } else {
    ui_->res_out->setText(ui_->res_out->text() + button_c_op->text() + "(");
  }
}

void MainWindow::OnPushButtonAcClicked() { ui_->res_out->setText("0"); }

void MainWindow::OnPushButtonObraceClicked() {
  StartPointClear();
  ui_->res_out->setText(ui_->res_out->text() + "(");
}

void MainWindow::OnPushButtonCbraceClicked() {
  if (!ui_->res_out->text().isEmpty() && ui_->res_out->text() != "0" &&
      ui_->res_out->text().back() != '(') {
    StartPointClear();
    ui_->res_out->setText(ui_->res_out->text() + ")");
  }
}

void MainWindow::OnPushButtonEqClicked() {
  QString label = ui_->res_out->text();
  if (x_mode_) {
    if (x_str_.isEmpty()) {
      if (ui_->res_out->text().contains("x") &&
          !ui_->res_out->text().contains("xx")) {
        x_str_ = ui_->res_out->text();
        ui_->res_out->setText("x=");
      } else {
        x_mode_ = false;
      }
    } else {
      if (label.contains("x=")) {
        label.remove("x=");
      }
      if (!label.isEmpty()) {
        double x = label.toDouble();
        x_str_.replace("x", QString::number(x));
      }
      label = x_str_;
      x_mode_ = false;
      x_str_.clear();
    }
  }
  if (!x_mode_) {
    if (label.length() > kMaxInputSize) {
      QMessageBox::warning(this, "Warning", "Превышено количество символов");
    } else {
      try {
        double ans = controller_->CalculateExpression(label.toStdString());
        ui_->res_out->setText(QString::number(ans));
      } catch (std::exception& exc) {
        QMessageBox::critical(this, "Error", exc.what());
        ui_->res_out->setText("0");
      }
    }
  }
}

void MainWindow::OnPushButtonBinClicked() {
  QString tmp = ui_->res_out->text();
  int i = tmp.length() - 1;
  for (; i >= 0; i--) {
    if (tmp[i] != '.') {
      if (tmp[i] == '(' || !tmp[i].isDigit()) {
        break;
      }
      if (tmp[i] == '0') {
        return;
      }
    }
  }
  if (i == -1 || tmp[i] == '(') {
    tmp.insert(++i, '-');
  } else if (tmp[i] == '-') {
    tmp.replace(i, 1, "+");
  } else if (tmp[i] == '+') {
    tmp.replace(i, 1, "-");
  }
  ui_->res_out->setText(tmp);
}

void MainWindow::OnBackspaceClicked() {
  QString src_str = ui_->res_out->text();
  qsizetype index = src_str.length() - 1;
  if (!src_str.isEmpty() && src_str != "0") {
    src_str.remove(index, 1);
    if (src_str.isEmpty()) {
      src_str += '0';
    }
    ui_->res_out->setText(src_str);
  }
}

void MainWindow::OnPushButtonCreditClicked() {
  double sum = ui_->SummaCr->text().toDouble();
  double int_rate = ui_->int_rate->text().toDouble();
  short period = ui_->Srok_cr->text().toShort();
  bool is_year = !(ui_->type_sr_cr->currentIndex()),
       is_annuit = ui_->annuit->isChecked();
  if ((is_year && period > DateLimits::kYearMax) ||
      (!is_year && period > DateLimits::kMonthMax)) {
    QMessageBox::warning(this, "Warning",
                         "Превышено максимальное значение срока кредита");
  } else if (!is_annuit && !ui_->diff->isChecked()) {
    QMessageBox::warning(this, "Warning", "Выбирите тип ежемесячных платежей");
  } else {
    CreditConditions conds = {sum, int_rate, period, is_year, is_annuit};
    const CreditData& data = controller_->CalculateCredit(conds);
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
        "Превышено максимальное значение срока размещения вклада");
  } else {
    std::vector<UserTransaction> fund, wth;
    ParseUserTransactions(ui_->gridLayout_rep, click_count_rep_, fund);
    ParseUserTransactions(ui_->gridLayout_wth, click_count_wth_, wth);
    DepositConditions conds = {ui_->capitalization->isChecked(),
                               term_type,
                               term,
                               ui_->rate_pay->currentIndex(),
                               ui_->label_tax->text().toDouble(),
                               ui_->label_key_rate->text().toDouble(),
                               ui_->sum->text().toDouble(),
                               ui_->int_rate_dep->text().toDouble(),
                               ui_->wth_rem_2->text().toDouble(),
                               ui_->dep_date->date(),
                               std::move(fund),
                               std::move(wth)};
    const DepositData& data = controller_->CalculateDeposit(conds);
    sec_win_->show();
    emit SignalDeposit(data);
  }
}

void MainWindow::OnPushButtonGraphClicked() {
  if (MainWindow::window()->geometry().height() == WindowSizes::kHeight) {
    this->setFixedSize(WindowSizes::kWidth, WindowSizes::kHeightGraph);
  } else {
    this->setFixedSize(WindowSizes::kWidth, WindowSizes::kHeight);
  }
}

void MainWindow::OnTabWidgetCurrentChanged(int index) {
  if (index &&
      MainWindow::window()->geometry().height() == WindowSizes::kHeightGraph) {
    this->setFixedSize(MainWindow::window()->geometry().width(),
                       WindowSizes::kHeight);
  }
}

void MainWindow::OnPushButtonPlotClicked() {
  if (ui_->doubleSpinBoXi->value() >= ui_->doubleSpinBoXa->value() ||
      (!ui_->autoscale->isChecked() &&
       ui_->doubleSpinBoYi->value() >= ui_->doubleSpinBoYa->value())) {
    QMessageBox::critical(
        this, "Warning",
        "Область значений или область определения функции не определена");
  } else {
    try {
      GraphConditions conds = {
          ui_->res_out->text().toStdString(), ui_->doubleSpinBoXa->value(),
          ui_->doubleSpinBoXi->value(),       ui_->doubleSpinBoYa->value(),
          ui_->doubleSpinBoYi->value(),       ui_->autoscale->isChecked()};
      const GraphData& data = controller_->CalculateGraph(conds);
      sec_win_->show();
      emit SignalPlot(data);
    } catch (std::exception& exc) {
      QMessageBox::critical(this, "Error", exc.what());
    }
  }
}

void MainWindow::OnPushButtonSpaceClicked() {
  ui_->res_out->setText(ui_->res_out->text() + " ");
}

void MainWindow::OnPushButtonRepClicked() {
  AddNewLine(ui_->gridLayout_rep, click_count_rep_);
}

void MainWindow::OnPushButtonWthClicked() {
  AddNewLine(ui_->gridLayout_wth, click_count_wth_);
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

}  // namespace s21