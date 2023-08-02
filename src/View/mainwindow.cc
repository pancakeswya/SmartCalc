#include "mainwindow.h"

#include <QMessageBox>

#include "ui_mainwindow.h"

enum WindowSizes { kWidth = 359, kHeight = 453, kHeightGraph = 619 };

MainWindow::MainWindow(Controller* ctrl) : MainWindow() { m_ctrl = ctrl; }

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      sec_win(new SecondWindow(this)),
      m_x_mode(),
      m_click_counter_rep(-1),
      m_click_counter_wth(-1) {
  ui->setupUi(this);
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

MainWindow::~MainWindow() { delete ui; }

void MainWindow::SetSignals() {
  connect(this, &MainWindow::SignalDeposit, sec_win,
          &SecondWindow::SlotDeposit);
  connect(this, &MainWindow::SignalCredit, sec_win, &SecondWindow::SlotCredit);
  connect(this, &MainWindow::SignalPlot, sec_win, &SecondWindow::SlotPlot);
  connect(ui->pushButton_dot, SIGNAL(clicked()), this,
          SLOT(OnPushButtonDotClicked()));
  connect(ui->pushButton_AC, SIGNAL(clicked()), this,
          SLOT(OnPushButtonAcClicked()));
  connect(ui->pushButton_Obrace, SIGNAL(clicked()), this,
          SLOT(OnPushButtonObraceClicked()));
  connect(ui->pushButton_Cbrace, SIGNAL(clicked()), this,
          SLOT(OnPushButtonCbraceClicked()));
  connect(ui->pushButton_eq, SIGNAL(clicked()), this,
          SLOT(OnPushButtonEqClicked()));
  connect(ui->backspace, SIGNAL(clicked()), this, SLOT(OnBackspaceClicked()));
  connect(ui->pushButton_bin, SIGNAL(clicked()), this,
          SLOT(OnPushButtonBinClicked()));
  connect(ui->pushButton_credit, SIGNAL(clicked()), this,
          SLOT(OnPushButtonCreditClicked()));
  connect(ui->pushButton_deposit, SIGNAL(clicked()), this,
          SLOT(OnPushButtonDepositClicked()));
  connect(ui->pushButton_graph, SIGNAL(clicked()), this,
          SLOT(OnPushButtonGraphClicked()));
  connect(ui->tabWidget, SIGNAL(currentChanged(int)), this,
          SLOT(OnTabWidgetCurrentChanged(int)));
  connect(ui->pushButton_plot, SIGNAL(clicked()), this,
          SLOT(OnPushButtonPlotClicked()));
  connect(ui->pushButton_space, SIGNAL(clicked()), this,
          SLOT(OnPushButtonSpaceClicked()));
  connect(ui->pushButton_rep, SIGNAL(clicked()), this,
          SLOT(OnPushButtonRepClicked()));
  connect(ui->pushButton_wth, SIGNAL(clicked()), this,
          SLOT(OnPushButtonWthClicked()));
  connect(ui->pushButton_del_rep, SIGNAL(clicked()), this,
          SLOT(OnPushButtonDelRepClicked()));
  connect(ui->pushButton_del_wth, SIGNAL(clicked()), this,
          SLOT(OnPushButtonDelWthClicked()));
  connect(ui->autoscale, SIGNAL(clicked(bool)), this,
          SLOT(OnAutoscaleStateChanged()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this,
          SLOT(OnPushButtonXclicked()));
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(DigitsNumbers()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(SimpleOperations()));
  connect(ui->pushButton_min, SIGNAL(clicked()), this,
          SLOT(SimpleOperations()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this,
          SLOT(SimpleOperations()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this,
          SLOT(SimpleOperations()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this,
          SLOT(SimpleOperations()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(SimpleOperations()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(ComplexOperations()));
}

void MainWindow::SetWidgets() {
  QLocale doub_lo(QLocale::C);
  doub_lo.setNumberOptions(QLocale::RejectGroupSeparator);
  QLocale::setDefault(doub_lo);
  ui->Srok_cr->setValidator(new QIntValidator(0, 100, this));
  ui->SummaCr->setValidator(new QDoubleValidator(this));
  QDoubleValidator *dbl_val = new QDoubleValidator(0, 100, 1000, this);
  dbl_val->setNotation(QDoubleValidator::StandardNotation);
  ui->int_rate->setValidator(dbl_val);
  ui->srok_dep->setValidator(new QIntValidator(0, 10000, this));
  ui->sum->setValidator(new QDoubleValidator(this));
  ui->wth_rem_2->setValidator(new QDoubleValidator(this));
  ui->int_rate_dep->setValidator(dbl_val);
  ui->label_tax->setValidator(dbl_val);
  ui->label_key_rate->setValidator(dbl_val);
  ui->doubleSpinBoXa->setRange(-std::numeric_limits<double>::max(),
                               std::numeric_limits<double>::max());
  ui->doubleSpinBoXi->setRange(-std::numeric_limits<double>::max(),
                               std::numeric_limits<double>::max());
  ui->doubleSpinBoYa->setRange(-std::numeric_limits<double>::max(),
                               std::numeric_limits<double>::max());
  ui->doubleSpinBoYi->setRange(-std::numeric_limits<double>::max(),
                               std::numeric_limits<double>::max());
  ui->label_tax->setText("13");
  ui->label_key_rate->setText("8.5");
  ui->wth_rem->hide();
  ui->wth_rem_2->hide();
  ui->wth_r_sign->hide();
  ui->doubleSpinBoYa->setDisabled(true);
  ui->doubleSpinBoYi->setDisabled(true);
  ui->autoscale->setCheckState(Qt::Checked);
  ui->dep_date->setDate(QDate::currentDate());
  ui->res_out->setAlignment(Qt::AlignRight);
  ui->wth_rem_2->setText("0");
}

void MainWindow::AddNewLine(QGridLayout* layout, short int& click) {
  QLineEdit *field = new QLineEdit(this);
  QDateEdit *date = new QDateEdit(this);
  QComboBox *box = new QComboBox(this);
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

void MainWindow::ParseUserTransactions(QGridLayout *layout, short int click,
                                       std::vector<UserTransaction> &opt) {
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
  if (ui->res_out->text() == "0") {
    ui->res_out->clear();
  }
}

void MainWindow::OnPushButtonDotClicked() {
  QString tmp = ui->res_out->text();
  for (auto it = tmp.rbegin(); it != tmp.rend(); it++) {
    if (*it == '.') {
      return;
    } else if (!(*it).isDigit()) {
      break;
    }
  }
  if (!tmp.isEmpty() && tmp.back().isDigit()) {
    ui->res_out->setText(ui->res_out->text() + ".");
  }
}

void MainWindow::OnPushButtonXclicked() {
  StartPointClear();
  ui->res_out->setText(ui->res_out->text() + "x");
  m_x_mode = true;
}

void MainWindow::DigitsNumbers() {
  QPushButton* button_num = static_cast<QPushButton*>(sender());
  StartPointClear();
  ui->res_out->setText(ui->res_out->text() + button_num->text());
}

void MainWindow::SimpleOperations() {
  QPushButton* button_op = static_cast<QPushButton*>(sender());
  if (!ui->res_out->text().isEmpty()) {
    QChar ch = ui->res_out->text().back();
    if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '^') {
      if (button_op->text() == "÷") {
        ui->res_out->setText(ui->res_out->text() + "/");
      } else {
        ui->res_out->setText(ui->res_out->text() + button_op->text());
      }
    }
  }
}

void MainWindow::ComplexOperations() {
  QPushButton* button_c_op = static_cast<QPushButton*>(sender());
  StartPointClear();
  if (button_c_op->text() == "√") {
    ui->res_out->setText(ui->res_out->text() + "sqrt(");
  } else {
    ui->res_out->setText(ui->res_out->text() + button_c_op->text() + "(");
  }
}

void MainWindow::OnPushButtonAcClicked() { ui->res_out->setText("0"); }

void MainWindow::OnPushButtonObraceClicked() {
  StartPointClear();
  ui->res_out->setText(ui->res_out->text() + "(");
}

void MainWindow::OnPushButtonCbraceClicked() {
  if (!ui->res_out->text().isEmpty() && ui->res_out->text() != "0" &&
      ui->res_out->text().back() != '(') {
    StartPointClear();
    ui->res_out->setText(ui->res_out->text() + ")");
  }
}

void MainWindow::OnPushButtonEqClicked() {
  QString label = ui->res_out->text();
  if (m_x_mode) {
    if (x_str.isEmpty()) {
      if (ui->res_out->text().contains("x") &&
          !ui->res_out->text().contains("xx")) {
        x_str = ui->res_out->text();
        ui->res_out->setText("x=");
      } else {
        m_x_mode = false;
      }
    } else {
      if (label.contains("x=")) {
        label.remove("x=");
      }
      if (!label.isEmpty()) {
        double x = label.toDouble();
        x_str.replace("x", QString::number(x));
      }
      label = x_str;
      m_x_mode = false;
      x_str.clear();
    }
  }
  if (!m_x_mode) {
    if (label.length() > kMaxInputSize) {
      QMessageBox::warning(this, "Warning", "Превышено количество символов");
    } else {
      try {
        double ans = m_ctrl->CalculateExpression(label.toStdString());
        ui->res_out->setText(QString::number(ans));
      } catch (std::exception &exc) {
        QMessageBox::critical(this, "Error", exc.what());
        ui->res_out->setText("0");
      }
    }
  }
}

void MainWindow::OnPushButtonBinClicked() {
  QString tmp = ui->res_out->text();
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
  ui->res_out->setText(tmp);
}

void MainWindow::OnBackspaceClicked() {
  QString src_str = ui->res_out->text();
  qsizetype index = src_str.length() - 1;
  if (!src_str.isEmpty() && src_str != "0") {
    src_str.remove(index, 1);
    if (src_str.isEmpty()) {
      src_str += '0';
    }
    ui->res_out->setText(src_str);
  }
}

void MainWindow::OnPushButtonCreditClicked() {
  double sum = ui->SummaCr->text().toDouble();
  double int_rate = ui->int_rate->text().toDouble();
  short period = ui->Srok_cr->text().toShort();
  bool is_year = !(ui->type_sr_cr->currentIndex()),
       is_annuit = ui->annuit->isChecked();
  if ((is_year && period > DateLimits::kYearMax) ||
      (!is_year && period > DateLimits::kMonthMax)) {
    QMessageBox::warning(this, "Warning",
                         "Превышено максимальное значение срока кредита");
  } else if (!is_annuit && !ui->diff->isChecked()) {
    QMessageBox::warning(this, "Warning", "Выбирите тип ежемесячных платежей");
  } else {
    CreditConditions conds = {sum, int_rate, period, is_year, is_annuit};
    const CreditData &data = m_ctrl->CalculateCredit(conds);
    sec_win->show();
    emit SignalCredit(data);
  }
}

void MainWindow::OnPushButtonDepositClicked() {
  short int term = ui->srok_dep->text().toShort();
  short int term_type = ui->srok_typed->currentIndex();
  if ((term > DateLimits::kYearMax && term_type == DateType::kTypeYear) ||
      (term > DateLimits::kMonthMax && term_type == DateType::kTypeMonth) ||
      (term > DateLimits::kDayMax && term_type == DateType::kTypeDay)) {
    QMessageBox::warning(
        this, "Warning",
        "Превышено максимальное значение срока размещения вклада");
  } else {
    std::vector<UserTransaction> fund, wth;
    ParseUserTransactions(ui->gridLayout_rep, m_click_counter_rep, fund);
    ParseUserTransactions(ui->gridLayout_wth, m_click_counter_wth, wth);
    DepositConditions conds = {ui->capitalization->isChecked(), term_type, term,
                               ui->rate_pay->currentIndex(), ui->label_tax->text().toDouble(),
                               ui->label_key_rate->text().toDouble(), ui->sum->text().toDouble(),
                               ui->int_rate_dep->text().toDouble(), ui->wth_rem_2->text().toDouble(),
                               ui->dep_date->date(), std::move(fund), std::move(wth)};
    const DepositData &data = m_ctrl->CalculateDeposit(conds);
    sec_win->show();
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
  if (ui->doubleSpinBoXi->value() >= ui->doubleSpinBoXa->value() ||
      (!ui->autoscale->isChecked() &&
       ui->doubleSpinBoYi->value() >= ui->doubleSpinBoYa->value())) {
    QMessageBox::critical(
        this, "Warning",
        "Область значений или область определения функции не определена");
  } else {
    try {
      GraphConditions conds = {ui->res_out->text().toStdString(), ui->doubleSpinBoXa->value(),
                               ui->doubleSpinBoXi->value(), ui->doubleSpinBoYa->value(),
                               ui->doubleSpinBoYi->value(), ui->autoscale->isChecked()};
      const GraphData &data = m_ctrl->CalculateGraph(conds);
      sec_win->show();
      emit SignalPlot(data);
    } catch (std::exception &exc) {
      QMessageBox::critical(this, "Error", exc.what());
    }
  }
}

void MainWindow::OnPushButtonSpaceClicked() {
  ui->res_out->setText(ui->res_out->text() + " ");
}

void MainWindow::OnPushButtonRepClicked() {
  AddNewLine(ui->gridLayout_rep, m_click_counter_rep);
}

void MainWindow::OnPushButtonWthClicked() {
  AddNewLine(ui->gridLayout_wth, m_click_counter_wth);
  if (m_click_counter_wth == 0) {
    ui->wth_rem->show();
    ui->wth_rem_2->show();
    ui->wth_r_sign->show();
  }
}

void MainWindow::OnPushButtonDelRepClicked() {
  DeleteLine(ui->gridLayout_rep, m_click_counter_rep);
}

void MainWindow::OnPushButtonDelWthClicked() {
  DeleteLine(ui->gridLayout_wth, m_click_counter_wth);
  if (m_click_counter_wth == -1) {
    ui->wth_rem->hide();
    ui->wth_rem_2->hide();
    ui->wth_r_sign->hide();
  }
}

void MainWindow::OnAutoscaleStateChanged() {
  ui->doubleSpinBoYa->setDisabled(ui->autoscale->isChecked());
  ui->doubleSpinBoYi->setDisabled(ui->autoscale->isChecked());
}
