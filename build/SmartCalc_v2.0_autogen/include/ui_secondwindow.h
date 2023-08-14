/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include "src/ExtLibs/qcustomplot.h"

namespace s21 {

class Ui_SecondWindow
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *out_dep;
    QLabel *out_dep_num;
    QTableView *tableView;
    QTableView *tableView_2;
    QCustomPlot *widget;

    void setupUi(QDialog *s21__SecondWindow)
    {
        if (s21__SecondWindow->objectName().isEmpty())
            s21__SecondWindow->setObjectName(QString::fromUtf8("s21__SecondWindow"));
        s21__SecondWindow->resize(400, 450);
        s21__SecondWindow->setMaximumSize(QSize(16777215, 16777215));
        scrollArea = new QScrollArea(s21__SecondWindow);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(9, 10, 381, 431));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 379, 429));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        out_dep = new QLabel(scrollAreaWidgetContents);
        out_dep->setObjectName(QString::fromUtf8("out_dep"));
        out_dep->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';\n"
"  font-size: 14px;"));

        horizontalLayout->addWidget(out_dep);

        out_dep_num = new QLabel(scrollAreaWidgetContents);
        out_dep_num->setObjectName(QString::fromUtf8("out_dep_num"));
        out_dep_num->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';\n"
"  font-size: 14px;"));

        horizontalLayout->addWidget(out_dep_num);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableView = new QTableView(scrollAreaWidgetContents);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setMaximumSize(QSize(16777215, 16777215));
        tableView->setStyleSheet(QString::fromUtf8("QHeaderView { \n"
"  font-size: 15px;\n"
"qproperty-defaultAlignment: AlignHCenter;  \n"
"}"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        tableView_2 = new QTableView(scrollAreaWidgetContents);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setStyleSheet(QString::fromUtf8("QHeaderView { \n"
"  font-size: 15px;\n"
"qproperty-defaultAlignment: AlignHCenter; \n"
"}"));

        gridLayout->addWidget(tableView_2, 2, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        widget = new QCustomPlot(s21__SecondWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-1, 0, 800, 600));

        retranslateUi(s21__SecondWindow);

        QMetaObject::connectSlotsByName(s21__SecondWindow);
    } // setupUi

    void retranslateUi(QDialog *s21__SecondWindow)
    {
        s21__SecondWindow->setWindowTitle(QCoreApplication::translate("s21::SecondWindow", "Dialog", nullptr));
        out_dep->setText(QString());
        out_dep_num->setText(QString());
    } // retranslateUi

};

} // namespace s21

namespace s21 {
namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui
} // namespace s21

#endif // UI_SECONDWINDOW_H
