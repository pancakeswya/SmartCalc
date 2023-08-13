#include "secondwindow.h"

#include <QStandardItemModel>
#include <cmath>

#include "../ExtLibs/qcustomplot.h"
#include "ui_secondwindow.h"

namespace s21 {

enum SecondWinSizes {
  kWidth = 400,
  kHeight = 450,
  kTableRowMax = 14100,
  kMaxTableSize = 521732
};

SecondWindow::SecondWindow(QWidget* parent)
    : QDialog(parent), ui_(new Ui::SecondWindow) {
  ui_->setupUi(this);
#ifdef _WIN32
  setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
  setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
#endif
  ui_->widget->setVisible(false);
}

SecondWindow::~SecondWindow() { delete ui_; }

void SecondWindow::SlotDeposit(const DepositData& data) {
  QModelIndex index;
  QDate date = data.start_date;
  int tax_year = date.year();
  auto repay = data.replen;
  auto table_model =
      new QStandardItemModel(data.payment.size() + repay.size(), 2, this);
  setWindowIcon(QIcon(":/resources/img/money-logo.png"));
  ui_->tableView_2->hide();
  ui_->tableView->horizontalScrollBar()->setDisabled(true);
  ui_->tableView->verticalScrollBar()->setDisabled(true);
  ui_->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui_->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setWindowTitle("Расчет вклада");
  if (ui_->widget->isVisible()) {
    this->setFixedSize(SecondWinSizes::kWidth, SecondWinSizes::kHeight);
    ui_->widget->setVisible(false);
  }
  ui_->out_dep->setText("Начисленные проценты\n");
  ui_->out_dep_num->setText(QString::number(data.perc_sum, 'f', 2) + "\n");
  ui_->out_dep->setText(ui_->out_dep->text() + "Налог\n");
  ui_->out_dep_num->setText(ui_->out_dep_num->text() +
                            QString::number(data.tax_sum, 'f', 2) + "\n");
  if (data.tax_sum > 0.0) {
    ui_->out_dep->setText(ui_->out_dep->text() + "Доход за вычетом налогов\n");
    ui_->out_dep_num->setText(
        ui_->out_dep_num->text() +
        QString::number(data.perc_sum - data.tax_sum, 'f', 2) + "\n");
  }
  if (data.eff_rate > 0.0) {
    ui_->out_dep->setText(ui_->out_dep->text() + "Эффективная ставка\n");
    ui_->out_dep_num->setText(ui_->out_dep_num->text() +
                              QString::number(data.eff_rate, 'f', 2) + "\n");
  }
  ui_->out_dep->setText(ui_->out_dep->text() + "Сумма на вкладе к концу срока");
  ui_->out_dep_num->setText(ui_->out_dep_num->text() +
                            QString::number(data.total, 'f', 2));
  auto it_rep = repay.begin();
  auto it_dep = data.payment.begin();
  for (int row = 0, dep_line = 0, i = 0;
       date != data.finish_date && row < table_model->rowCount(); row++) {
    for (int col = 0; col < table_model->columnCount(); col++) {
      index = table_model->index(row, col);
      if (col == 0) {
        date = data.pay_dates[i++];
        if (it_rep != repay.end() && date >= it_rep->first) {
          double replen = 0;
          table_model->setHeaderData(row, Qt::Vertical, "");
          table_model->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
          table_model->setData(index, it_rep->first.toString("dd-MM-yyyy"));
          for (int cnt = 0; it_rep != repay.end() && date >= it_rep->first;
               cnt++, it_rep++) {
            replen += it_rep->second;
            if (cnt) {
              table_model->removeRow(table_model->rowCount() - 1);
            }
          }
          index = table_model->index(row, 1);
          table_model->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
          table_model->setData(index, QString::number(replen, 'f', 2));
          index = table_model->index(++row, col);
        }
        table_model->setHeaderData(row, Qt::Vertical, dep_line + 1);
        table_model->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
        if (date < data.finish_date) {
          table_model->setData(index, date.toString("dd-MM-yyyy"));
        } else {
          table_model->setData(index, data.finish_date.toString("dd-MM-yyyy"));
        }

      } else {
        table_model->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
        table_model->setData(index, QString::number(*it_dep++, 'f', 2));
        dep_line++;
      }
    }
  }
  table_model->setHeaderData(0, Qt::Horizontal, "Дата");
  table_model->setHeaderData(1, Qt::Horizontal, "Вклад\nпополнен");
  ui_->tableView->setModel(table_model);
  ui_->tableView->setFixedWidth(ui_->tableView->verticalHeader()->width() +
                                ui_->tableView->horizontalHeader()->length() +
                                +ui_->tableView->frameWidth() * 2);
  if (table_model->rowCount() < SecondWinSizes::kTableRowMax) {
    ui_->tableView->setFixedHeight(
        ui_->tableView->horizontalHeader()->height() +
        ui_->tableView->verticalHeader()->length() +
        ui_->tableView->frameWidth() * 2);
  } else {
    ui_->tableView->setFixedHeight(SecondWinSizes::kMaxTableSize);
    ui_->tableView->verticalScrollBar()->setDisabled(false);
    ui_->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  }
  if (data.tax.size()) {
    QModelIndex index_tax;
    QStandardItemModel* table_model_tax =
        new QStandardItemModel(data.tax.size(), 2, this);
    ui_->tableView_2->show();
    ui_->tableView_2->horizontalScrollBar()->setDisabled(true);
    ui_->tableView_2->verticalScrollBar()->setDisabled(true);
    ui_->tableView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_->tableView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table_model_tax->setHeaderData(0, Qt::Horizontal, "Год");
    table_model_tax->setHeaderData(1, Qt::Horizontal, "Налог");
    for (unsigned int i = 0; i < data.tax.size(); i++) {
      for (int j = 0; j < table_model_tax->columnCount(); j++) {
        index_tax = table_model_tax->index(i, j);
        if (j == 0) {
          table_model_tax->setData(index_tax, Qt::AlignCenter,
                                   Qt::TextAlignmentRole);
          table_model_tax->setData(index_tax, QString::number(tax_year));
        } else {
          table_model_tax->setData(index_tax, Qt::AlignCenter,
                                   Qt::TextAlignmentRole);
          table_model_tax->setData(index_tax,
                                   QString::number(data.tax[i], 'f', 2));
          tax_year++;
        }
      }
    }
    ui_->tableView_2->setModel(table_model_tax);
    ui_->tableView_2->setFixedWidth(
        ui_->tableView_2->verticalHeader()->width() +
        ui_->tableView_2->horizontalHeader()->length() +
        +ui_->tableView_2->frameWidth() * 2);
    ui_->tableView_2->setFixedHeight(
        ui_->tableView_2->horizontalHeader()->height() +
        ui_->tableView_2->verticalHeader()->length() +
        ui_->tableView_2->frameWidth() * 2);
  }
}

void SecondWindow::SlotCredit(const CreditData& data) {
  if (ui_->widget->isVisible()) {
    this->setFixedSize(SecondWinSizes::kWidth, SecondWinSizes::kHeight);
    ui_->widget->setVisible(false);
  }
  if (ui_->tableView_2->isVisible()) {
    ui_->tableView_2->hide();
  }
  setWindowIcon(QIcon(":/resources/img/money-logo.png"));
  ui_->tableView->horizontalScrollBar()->setDisabled(true);
  ui_->tableView->verticalScrollBar()->setDisabled(true);
  ui_->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui_->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  QStringList months = {"Январь",   "Февраль", "Март",   "Апрель",
                        "Май",      "Июнь",    "Июль",   "Август",
                        "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
  QDate cur_date = cur_date.currentDate();
  auto table_model = new QStandardItemModel(data.payment.size(), 2, this);
  QModelIndex index;
  ui_->tableView->setModel(table_model);
  setWindowTitle("Расчет кредита");
  ui_->out_dep->setText("Ежемесячный платеж\n");
  {
    double last_payment = (!data.payment.size()) ? 0 : data.payment.back();
    QString dep_out = QString::number(data.payment.front(), 'f', 2);
    if (data.payment.front() != last_payment) {
      dep_out += "  ....   " + QString::number(last_payment, 'f', 2);
    }
    dep_out += "\n";
    ui_->out_dep_num->setText(dep_out);
  }
  ui_->out_dep->setText("Начисленные проценты\n");
  ui_->out_dep_num->setText(ui_->out_dep_num->text() +
                            QString::number(data.overpay, 'f', 2) + "\n");
  ui_->out_dep->setText(ui_->out_dep->text() + "Долг + проценты");
  ui_->out_dep_num->setText(ui_->out_dep_num->text() +
                            QString::number(data.total, 'f', 2));
  for (int row = 0; row < table_model->rowCount(); row++) {
    for (int col = 0; col < table_model->columnCount(); col++) {
      index = table_model->index(row, col);
      if (col == 0) {
        table_model->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
        table_model->setData(index, months[cur_date.month() - 1] + " " +
                                        cur_date.toString("yyyy"));
        cur_date = cur_date.addMonths(1);
      } else {
        table_model->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
        table_model->setData(index, QString::number(data.payment[row], 'f', 2));
      }
    }
  }
  table_model->setHeaderData(0, Qt::Horizontal, "Дата");
  table_model->setHeaderData(1, Qt::Horizontal, "Платеж");
  ui_->tableView->setFixedWidth(ui_->tableView->verticalHeader()->width() +
                                ui_->tableView->horizontalHeader()->length() +
                                +ui_->tableView->frameWidth() * 2);
  ui_->tableView->setFixedHeight(ui_->tableView->horizontalHeader()->height() +
                                 ui_->tableView->verticalHeader()->length() +
                                 ui_->tableView->frameWidth() * 2);
}

void SecondWindow::SlotPlot(const GraphData& data) {
  if (!ui_->widget->isVisible()) {
    this->setFixedSize(SecondWinSizes::kWidth * 2, SecondWinSizes::kHeight);
  }
  setWindowTitle("График");
  setWindowIcon(QIcon(":/resources/img/graph-logo.png"));
  ui_->widget->xAxis->setRange(data.x_min, data.x_max);
  for (int i = 0; i < ui_->widget->graphCount(); i++) {
    ui_->widget->graph(i)->data()->clear();
  }
  int graph_i = 0;
  for (auto& xy : data.xy) {
    ui_->widget->addGraph();
    ui_->widget->graph(graph_i++)->setData(xy.first, xy.second);
  }

  ui_->widget->yAxis->setRange(data.y_min, data.y_max);
  ui_->widget->replot();
  ui_->widget->setInteraction(QCP::iRangeZoom, true);
  ui_->widget->setInteraction(QCP::iRangeDrag, true);
  ui_->widget->setVisible(true);
}

}  // namespace s21