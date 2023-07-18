#include "secondwindow.h"

#include <cmath>

#include "../ExtLibs/qcustomplot.h"
#include "ui_secondwindow.h"

enum SecondWinSizes {
  width = 400,
  height = 450,
  heightPlot = 600,
  tableRowMax = 14100,
  maxTableSize = 521732
};

SecondWindow::SecondWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::SecondWindow) {
  ui->setupUi(this);
#ifdef _WIN32
  setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
  setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
#endif
  ui->widget->setVisible(false);
}

SecondWindow::~SecondWindow() { delete ui; }

void SecondWindow::SlotDeposit(const DepositData &data) {
  QModelIndex index;
  QDate date = data.start_date;
  int tax_year = date.year();
  auto repay = data.replen;
  model = new QStandardItemModel(data.payment.size() + repay.size(), 2, this);
  setWindowIcon(QIcon(":/resources/img/money-logo.png"));
  ui->tableView_2->hide();
  ui->tableView->horizontalScrollBar()->setDisabled(true);
  ui->tableView->verticalScrollBar()->setDisabled(true);
  ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setWindowTitle("Расчет вклада");
  if (ui->widget->isVisible()) {
    this->setFixedSize(SecondWinSizes::width, SecondWinSizes::height);
    ui->widget->setVisible(false);
  }
  ui->out_dep->setText("Начисленные проценты\n");
  ui->out_dep_num->setText(QString::number(data.perc_sum, 'f', 2) + "\n");
  ui->out_dep->setText(ui->out_dep->text() + "Налог\n");
  ui->out_dep_num->setText(ui->out_dep_num->text() +
                           QString::number(data.tax_sum, 'f', 2) + "\n");
  if (data.tax_sum > 0.0) {
    ui->out_dep->setText(ui->out_dep->text() + "Доход за вычетом налогов\n");
    ui->out_dep_num->setText(
        ui->out_dep_num->text() +
        QString::number(data.perc_sum - data.tax_sum, 'f', 2) + "\n");
  }
  if (data.eff_rate > 0.0) {
    ui->out_dep->setText(ui->out_dep->text() + "Эффективная ставка\n");
    ui->out_dep_num->setText(ui->out_dep_num->text() +
                             QString::number(data.eff_rate, 'f', 2) + "\n");
  }
  ui->out_dep->setText(ui->out_dep->text() + "Сумма на вкладе к концу срока");
  ui->out_dep_num->setText(ui->out_dep_num->text() +
                           QString::number(data.total, 'f', 2));
  auto it_rep = repay.begin();
  auto it_dep = data.payment.begin();
  for (int row = 0, dep_line = 0, i = 0;
       date != data.finish_date && row < model->rowCount(); row++) {
    for (int col = 0; col < model->columnCount(); col++) {
      index = model->index(row, col);
      if (col == 0) {
        date = data.pay_dates[i++];
        if (it_rep != repay.end() && date >= it_rep->first) {
          double replen = 0;
          model->setHeaderData(row, Qt::Vertical, "");
          model->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
          model->setData(index, it_rep->first.toString("dd-MM-yyyy"));
          for (int cnt = 0; it_rep != repay.end() && date >= it_rep->first;
               cnt++, it_rep++) {
            replen += it_rep->second;
            if (cnt) {
              model->removeRow(model->rowCount() - 1);
            }
          }
          index = model->index(row, 1);
          model->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
          model->setData(index, QString::number(replen, 'f', 2));
          index = model->index(++row, col);
        }
        model->setHeaderData(row, Qt::Vertical, dep_line + 1);
        model->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
        if (date < data.finish_date) {
          model->setData(index, date.toString("dd-MM-yyyy"));
        } else {
          model->setData(index, data.finish_date.toString("dd-MM-yyyy"));
        }

      } else {
        model->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
        model->setData(index, QString::number(*it_dep++, 'f', 2));
        dep_line++;
      }
    }
  }
  model->setHeaderData(0, Qt::Horizontal, "Дата");
  model->setHeaderData(1, Qt::Horizontal, "Вклад\nпополнен");
  ui->tableView->setModel(model);
  ui->tableView->setFixedWidth(ui->tableView->verticalHeader()->width() +
                               ui->tableView->horizontalHeader()->length() +
                               +ui->tableView->frameWidth() * 2);
  if (model->rowCount() < SecondWinSizes::tableRowMax) {
    ui->tableView->setFixedHeight(ui->tableView->horizontalHeader()->height() +
                                  ui->tableView->verticalHeader()->length() +
                                  ui->tableView->frameWidth() * 2);
  } else {
    ui->tableView->setFixedHeight(SecondWinSizes::maxTableSize);
    ui->tableView->verticalScrollBar()->setDisabled(false);
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  }
  if (data.tax.size()) {
    QModelIndex index_tax;
    QStandardItemModel *model_tax =
        new QStandardItemModel(data.tax.size(), 2, this);
    ui->tableView_2->show();
    ui->tableView_2->horizontalScrollBar()->setDisabled(true);
    ui->tableView_2->verticalScrollBar()->setDisabled(true);
    ui->tableView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    model_tax->setHeaderData(0, Qt::Horizontal, "Год");
    model_tax->setHeaderData(1, Qt::Horizontal, "Налог");
    for (unsigned int i = 0; i < data.tax.size(); i++) {
      for (int j = 0; j < model_tax->columnCount(); j++) {
        index_tax = model_tax->index(i, j);
        if (j == 0) {
          model_tax->setData(index_tax, Qt::AlignCenter, Qt::TextAlignmentRole);
          model_tax->setData(index_tax, QString::number(tax_year));
        } else {
          model_tax->setData(index_tax, Qt::AlignCenter, Qt::TextAlignmentRole);
          model_tax->setData(index_tax, QString::number(data.tax[i], 'f', 2));
          tax_year++;
        }
      }
    }
    ui->tableView_2->setModel(model_tax);
    ui->tableView_2->setFixedWidth(
        ui->tableView_2->verticalHeader()->width() +
        ui->tableView_2->horizontalHeader()->length() +
        +ui->tableView_2->frameWidth() * 2);
    ui->tableView_2->setFixedHeight(
        ui->tableView_2->horizontalHeader()->height() +
        ui->tableView_2->verticalHeader()->length() +
        ui->tableView_2->frameWidth() * 2);
  }
}

void SecondWindow::SlotCredit(const CreditData &data) {
  if (ui->widget->isVisible()) {
    this->setFixedSize(SecondWinSizes::width, SecondWinSizes::height);
    ui->widget->setVisible(false);
  }
  if (ui->tableView_2->isVisible()) {
    ui->tableView_2->hide();
  }
  setWindowIcon(QIcon(":/resources/img/money-logo.png"));
  ui->tableView->horizontalScrollBar()->setDisabled(true);
  ui->tableView->verticalScrollBar()->setDisabled(true);
  ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  QStringList months = {"Январь",   "Февраль", "Март",   "Апрель",
                        "Май",      "Июнь",    "Июль",   "Август",
                        "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
  QDate cur_date = cur_date.currentDate();
  model = new QStandardItemModel(data.payment.size(), 2, this);
  QModelIndex index;
  ui->tableView->setModel(model);
  setWindowTitle("Расчет кредита");
  ui->out_dep->setText("Ежемесячный платеж\n");
  {
    double last_payment = (!data.payment.size()) ? 0 : data.payment.back();
    QString dep_out = QString::number(data.payment.front(), 'f', 2);
    if (data.payment.front() != last_payment) {
      dep_out += "  ....   " + QString::number(last_payment, 'f', 2);
    }
    dep_out += "\n";
    ui->out_dep_num->setText(dep_out);
  }
  ui->out_dep->setText("Начисленные проценты\n");
  ui->out_dep_num->setText(ui->out_dep_num->text() +
                           QString::number(data.overpay, 'f', 2) + "\n");
  ui->out_dep->setText(ui->out_dep->text() + "Долг + проценты");
  ui->out_dep_num->setText(ui->out_dep_num->text() +
                           QString::number(data.total, 'f', 2));
  for (int row = 0; row < model->rowCount(); row++) {
    for (int col = 0; col < model->columnCount(); col++) {
      index = model->index(row, col);
      if (col == 0) {
        model->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
        model->setData(index, months[cur_date.month() - 1] + " " +
                                  cur_date.toString("yyyy"));
        cur_date = cur_date.addMonths(1);
      } else {
        model->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
        model->setData(index, QString::number(data.payment[row], 'f', 2));
      }
    }
  }
  model->setHeaderData(0, Qt::Horizontal, "Дата");
  model->setHeaderData(1, Qt::Horizontal, "Платеж");
  ui->tableView->setFixedWidth(ui->tableView->verticalHeader()->width() +
                               ui->tableView->horizontalHeader()->length() +
                               +ui->tableView->frameWidth() * 2);
  ui->tableView->setFixedHeight(ui->tableView->horizontalHeader()->height() +
                                ui->tableView->verticalHeader()->length() +
                                ui->tableView->frameWidth() * 2);
}

void SecondWindow::SlotPlot(const GraphData &data) {
  if (!ui->widget->isVisible()) {
    this->setFixedSize(SecondWinSizes::width * 2, SecondWinSizes::height);
  }
  setWindowTitle("График");
  setWindowIcon(QIcon(":/resources/img/graph-logo.png"));
  ui->widget->xAxis->setRange(data.x_min, data.x_max);
  for (int i = 0; i < ui->widget->graphCount(); i++) {
    ui->widget->graph(i)->data()->clear();
  }
  int graph_i = 0;
  for (auto &xy : data.xy) {
    ui->widget->addGraph();
    ui->widget->graph(graph_i++)->setData(xy.first, xy.second);
  }
  ui->widget->yAxis->setRange(data.y_min, data.y_max);
  ui->widget->replot();

  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  ui->widget->setVisible(true);
}
