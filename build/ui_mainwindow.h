/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *basic;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_1;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_3;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_graph;
    QPushButton *pushButton_9;
    QPushButton *pushButton_0;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_x;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_eq;
    QPushButton *pushButton_log;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_div;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_min;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_7;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_Obrace;
    QPushButton *pushButton_Cbrace;
    QPushButton *pushButton_2;
    QPushButton *pushButton_bin;
    QLineEdit *res_out;
    QPushButton *backspace;
    QPushButton *pushButton_space;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBoXa;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_18;
    QDoubleSpinBox *doubleSpinBoYi;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBoYa;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_16;
    QDoubleSpinBox *doubleSpinBoXi;
    QCheckBox *autoscale;
    QPushButton *pushButton_plot;
    QWidget *credit;
    QPushButton *pushButton_credit;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QRadioButton *annuit;
    QRadioButton *diff;
    QHBoxLayout *horizontalLayout;
    QLineEdit *int_rate;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *Srok_cr;
    QComboBox *type_sr_cr;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *SummaCr;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_6;
    QWidget *deposit;
    QPushButton *pushButton_deposit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label_13;
    QLabel *wth_rem;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton_wth;
    QPushButton *pushButton_del_wth;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *gridLayout_wth;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_rep;
    QPushButton *pushButton_del_rep;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout_rep;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *wth_rem_2;
    QLabel *wth_r_sign;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_14;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_2;
    QCheckBox *capitalization;
    QComboBox *rate_pay;
    QLabel *label_8;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *sum;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *srok_dep;
    QComboBox *srok_typed;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_9;
    QDateEdit *dep_date;
    QLabel *label_10;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *int_rate_dep;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer;
    QLabel *label_20;
    QGridLayout *gridLayout_6;
    QLineEdit *label_key_rate;
    QSpacerItem *horizontalSpacer_12;
    QLineEdit *label_tax;
    QLabel *label_21;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(360, 453);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-2, 0, 361, 622));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::tab-bar {\n"
"  alignment: center;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"  border: none; }\n"
"\n"
" QTabBar::tab {\n"
"  font: 9pt \"Microsoft YaHei\";\n"
"  Width: 70px;\n"
"  Height: 22px;\n"
"  background-color: rgb(215, 215, 215);\n"
"  color: black;  \n"
"  padding: 5px;\n"
" }\n"
"\n"
" QTabBar::tab:selected {\n"
"   background: transparent;\n"
" }\n"
" "));
        basic = new QWidget();
        basic->setObjectName(QString::fromUtf8("basic"));
        pushButton_sqrt = new QPushButton(basic);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(1, 61, 61, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_sqrt->sizePolicy().hasHeightForWidth());
        pushButton_sqrt->setSizePolicy(sizePolicy1);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font-size: 18px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_1 = new QPushButton(basic);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(121, 121, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy1);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font: 16pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_mod = new QPushButton(basic);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(61, 61, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_mod->sizePolicy().hasHeightForWidth());
        pushButton_mod->setSizePolicy(sizePolicy1);
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font: 12pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_pow = new QPushButton(basic);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        pushButton_pow->setGeometry(QRect(1, 361, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_pow->sizePolicy().hasHeightForWidth());
        pushButton_pow->setSizePolicy(sizePolicy1);
        pushButton_pow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font-size: 18px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_cos = new QPushButton(basic);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(61, 181, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_cos->sizePolicy().hasHeightForWidth());
        pushButton_cos->setSizePolicy(sizePolicy1);
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font: 12pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_asin = new QPushButton(basic);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(1, 121, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_asin->sizePolicy().hasHeightForWidth());
        pushButton_asin->setSizePolicy(sizePolicy1);
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font: 12pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_3 = new QPushButton(basic);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(241, 121, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font: 16pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_tan = new QPushButton(basic);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(61, 241, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_tan->sizePolicy().hasHeightForWidth());
        pushButton_tan->setSizePolicy(sizePolicy1);
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font: 12pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_6 = new QPushButton(basic);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(241, 181, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font: 16pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_4 = new QPushButton(basic);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(121, 181, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font: 16pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_graph = new QPushButton(basic);
        pushButton_graph->setObjectName(QString::fromUtf8("pushButton_graph"));
        pushButton_graph->setGeometry(QRect(181, 361, 121, 61));
        sizePolicy1.setHeightForWidth(pushButton_graph->sizePolicy().hasHeightForWidth());
        pushButton_graph->setSizePolicy(sizePolicy1);
        pushButton_graph->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font: 12pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_9 = new QPushButton(basic);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(241, 241, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font: 16pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_0 = new QPushButton(basic);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(181, 301, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy1);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font: 16pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_atan = new QPushButton(basic);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setGeometry(QRect(1, 241, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_atan->sizePolicy().hasHeightForWidth());
        pushButton_atan->setSizePolicy(sizePolicy1);
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font: 12pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_mul = new QPushButton(basic);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setGeometry(QRect(301, 181, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_mul->sizePolicy().hasHeightForWidth());
        pushButton_mul->setSizePolicy(sizePolicy1);
        pushButton_mul->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"  font-size: 18px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_8 = new QPushButton(basic);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(181, 241, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font: 16pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_5 = new QPushButton(basic);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(181, 181, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font: 16pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_x = new QPushButton(basic);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setGeometry(QRect(61, 361, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_x->sizePolicy().hasHeightForWidth());
        pushButton_x->setSizePolicy(sizePolicy1);
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font: 12pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_acos = new QPushButton(basic);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(1, 181, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_acos->sizePolicy().hasHeightForWidth());
        pushButton_acos->setSizePolicy(sizePolicy1);
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font: 12pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_eq = new QPushButton(basic);
        pushButton_eq->setObjectName(QString::fromUtf8("pushButton_eq"));
        pushButton_eq->setGeometry(QRect(301, 361, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_eq->sizePolicy().hasHeightForWidth());
        pushButton_eq->setSizePolicy(sizePolicy1);
        pushButton_eq->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font-size: 18px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_log = new QPushButton(basic);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(61, 301, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_log->sizePolicy().hasHeightForWidth());
        pushButton_log->setSizePolicy(sizePolicy1);
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font: 12pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_dot = new QPushButton(basic);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(121, 301, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_dot->sizePolicy().hasHeightForWidth());
        pushButton_dot->setSizePolicy(sizePolicy1);
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font-size: 18px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_div = new QPushButton(basic);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(301, 121, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_div->sizePolicy().hasHeightForWidth());
        pushButton_div->setSizePolicy(sizePolicy1);
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"  font-size: 18px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_ln = new QPushButton(basic);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(1, 301, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_ln->sizePolicy().hasHeightForWidth());
        pushButton_ln->setSizePolicy(sizePolicy1);
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font: 12pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_min = new QPushButton(basic);
        pushButton_min->setObjectName(QString::fromUtf8("pushButton_min"));
        pushButton_min->setGeometry(QRect(301, 241, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_min->sizePolicy().hasHeightForWidth());
        pushButton_min->setSizePolicy(sizePolicy1);
        pushButton_min->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"  font-size: 18px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_plus = new QPushButton(basic);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(301, 301, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_plus->sizePolicy().hasHeightForWidth());
        pushButton_plus->setSizePolicy(sizePolicy1);
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"  font-size: 18px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_7 = new QPushButton(basic);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(121, 241, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font: 16pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_sin = new QPushButton(basic);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(61, 121, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_sin->sizePolicy().hasHeightForWidth());
        pushButton_sin->setSizePolicy(sizePolicy1);
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font: 12pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_AC = new QPushButton(basic);
        pushButton_AC->setObjectName(QString::fromUtf8("pushButton_AC"));
        pushButton_AC->setGeometry(QRect(121, 61, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_AC->sizePolicy().hasHeightForWidth());
        pushButton_AC->setSizePolicy(sizePolicy1);
        pushButton_AC->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font: 12pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_Obrace = new QPushButton(basic);
        pushButton_Obrace->setObjectName(QString::fromUtf8("pushButton_Obrace"));
        pushButton_Obrace->setGeometry(QRect(181, 61, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_Obrace->sizePolicy().hasHeightForWidth());
        pushButton_Obrace->setSizePolicy(sizePolicy1);
        pushButton_Obrace->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font-size: 18px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_Cbrace = new QPushButton(basic);
        pushButton_Cbrace->setObjectName(QString::fromUtf8("pushButton_Cbrace"));
        pushButton_Cbrace->setGeometry(QRect(241, 61, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_Cbrace->sizePolicy().hasHeightForWidth());
        pushButton_Cbrace->setSizePolicy(sizePolicy1);
        pushButton_Cbrace->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font-size: 18px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_2 = new QPushButton(basic);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(181, 121, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font: 16pt \"Segoe UI\";\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_bin = new QPushButton(basic);
        pushButton_bin->setObjectName(QString::fromUtf8("pushButton_bin"));
        pushButton_bin->setGeometry(QRect(241, 301, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_bin->sizePolicy().hasHeightForWidth());
        pushButton_bin->setSizePolicy(sizePolicy1);
        pushButton_bin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"   font-size: 18px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        res_out = new QLineEdit(basic);
        res_out->setObjectName(QString::fromUtf8("res_out"));
        res_out->setGeometry(QRect(1, 0, 361, 62));
        res_out->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"  border: 1px solid gray;\n"
"  background-color: rgba(0, 0, 0, 0);\n"
"  font: 20pt \"Segoe UI\";\n"
"}"));
        backspace = new QPushButton(basic);
        backspace->setObjectName(QString::fromUtf8("backspace"));
        backspace->setGeometry(QRect(301, 61, 61, 61));
        sizePolicy1.setHeightForWidth(backspace->sizePolicy().hasHeightForWidth());
        backspace->setSizePolicy(sizePolicy1);
        backspace->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"  font-size: 16px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_space = new QPushButton(basic);
        pushButton_space->setObjectName(QString::fromUtf8("pushButton_space"));
        pushButton_space->setGeometry(QRect(121, 361, 61, 61));
        sizePolicy1.setHeightForWidth(pushButton_space->sizePolicy().hasHeightForWidth());
        pushButton_space->setSizePolicy(sizePolicy1);
        pushButton_space->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"  font-size: 24px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        layoutWidget = new QWidget(basic);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(62, 442, 251, 92));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_4->addWidget(label_17);

        doubleSpinBoXa = new QDoubleSpinBox(layoutWidget);
        doubleSpinBoXa->setObjectName(QString::fromUtf8("doubleSpinBoXa"));
        doubleSpinBoXa->setMinimumSize(QSize(65, 0));
        doubleSpinBoXa->setMaximumSize(QSize(65, 16777215));
        doubleSpinBoXa->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_4->addWidget(doubleSpinBoXa);


        gridLayout_3->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_10->addWidget(label_18);

        doubleSpinBoYi = new QDoubleSpinBox(layoutWidget);
        doubleSpinBoYi->setObjectName(QString::fromUtf8("doubleSpinBoYi"));
        doubleSpinBoYi->setMinimumSize(QSize(65, 0));
        doubleSpinBoYi->setMaximumSize(QSize(65, 16777215));
        doubleSpinBoYi->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_10->addWidget(doubleSpinBoYi);


        gridLayout_3->addLayout(horizontalLayout_10, 0, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 0, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_9->addWidget(label_19);

        doubleSpinBoYa = new QDoubleSpinBox(layoutWidget);
        doubleSpinBoYa->setObjectName(QString::fromUtf8("doubleSpinBoYa"));
        doubleSpinBoYa->setMinimumSize(QSize(65, 0));
        doubleSpinBoYa->setMaximumSize(QSize(65, 16777215));
        doubleSpinBoYa->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_9->addWidget(doubleSpinBoYa);


        gridLayout_3->addLayout(horizontalLayout_9, 1, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_3->addWidget(label_16);

        doubleSpinBoXi = new QDoubleSpinBox(layoutWidget);
        doubleSpinBoXi->setObjectName(QString::fromUtf8("doubleSpinBoXi"));
        doubleSpinBoXi->setMinimumSize(QSize(65, 0));
        doubleSpinBoXi->setMaximumSize(QSize(65, 16777215));
        doubleSpinBoXi->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_3->addWidget(doubleSpinBoXi);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        autoscale = new QCheckBox(layoutWidget);
        autoscale->setObjectName(QString::fromUtf8("autoscale"));

        gridLayout_3->addWidget(autoscale, 2, 2, 1, 1);

        pushButton_plot = new QPushButton(basic);
        pushButton_plot->setObjectName(QString::fromUtf8("pushButton_plot"));
        pushButton_plot->setGeometry(QRect(120, 540, 131, 31));
        pushButton_plot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 5px;\n"
"  font-size: 1.2 em;\n"
"  background-color:rgb(215, 215, 215);;\n"
"  border-bottom: 4px solid rgb(165, 165, 165);\n"
"  font-family: 'Microsoft YaHei';\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"  background-color :rgb(197, 223, 255);\n"
"  border-bottom-color: rgb(153, 173, 198);\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgba(151, 170, 195, 255), stop: 1 rgba(255, 255, 255, 255));\n"
"}"));
        tabWidget->addTab(basic, QString());
        credit = new QWidget();
        credit->setObjectName(QString::fromUtf8("credit"));
        pushButton_credit = new QPushButton(credit);
        pushButton_credit->setObjectName(QString::fromUtf8("pushButton_credit"));
        pushButton_credit->setGeometry(QRect(144, 200, 93, 31));
        pushButton_credit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 5px;\n"
"  font-size: 1.2 em;\n"
"  background-color:rgb(215, 215, 215);\n"
"  border-bottom: 4px solid rgb(165, 165, 165);\n"
"  font-family: 'Microsoft YaHei';\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"  background-color :rgb(197, 223, 255);\n"
"  border-bottom-color: rgb(153, 173, 198);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgba(151, 170, 195, 255), stop: 1 rgba(255, 255, 255, 255));\n"
"}"));
        layoutWidget_2 = new QWidget(credit);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(50, 10, 356, 181));
        gridLayout_5 = new QGridLayout(layoutWidget_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 22));
        label->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 22));
        label_2->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_5->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 22));
        label_3->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_5->addWidget(label_3, 2, 0, 1, 1);

        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_5->addWidget(label_5, 3, 0, 2, 1);

        annuit = new QRadioButton(layoutWidget_2);
        annuit->setObjectName(QString::fromUtf8("annuit"));
        annuit->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_5->addWidget(annuit, 3, 1, 1, 2);

        diff = new QRadioButton(layoutWidget_2);
        diff->setObjectName(QString::fromUtf8("diff"));
        diff->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_5->addWidget(diff, 4, 1, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        int_rate = new QLineEdit(layoutWidget_2);
        int_rate->setObjectName(QString::fromUtf8("int_rate"));
        int_rate->setMinimumSize(QSize(50, 0));
        int_rate->setMaximumSize(QSize(16777215, 16777215));
        int_rate->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout->addWidget(int_rate);

        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(250, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_5->addLayout(horizontalLayout, 2, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        Srok_cr = new QLineEdit(layoutWidget_2);
        Srok_cr->setObjectName(QString::fromUtf8("Srok_cr"));
        Srok_cr->setMinimumSize(QSize(50, 0));
        Srok_cr->setMaximumSize(QSize(16777215, 16777215));
        Srok_cr->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_7->addWidget(Srok_cr);

        type_sr_cr = new QComboBox(layoutWidget_2);
        type_sr_cr->addItem(QString());
        type_sr_cr->addItem(QString());
        type_sr_cr->setObjectName(QString::fromUtf8("type_sr_cr"));
        type_sr_cr->setMaximumSize(QSize(80, 16777215));
        type_sr_cr->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_7->addWidget(type_sr_cr);

        horizontalSpacer_5 = new QSpacerItem(140, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        gridLayout_5->addLayout(horizontalLayout_7, 1, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        SummaCr = new QLineEdit(layoutWidget_2);
        SummaCr->setObjectName(QString::fromUtf8("SummaCr"));
        SummaCr->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_8->addWidget(SummaCr);

        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_8->addWidget(label_6);

        horizontalSpacer_6 = new QSpacerItem(37, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        gridLayout_5->addLayout(horizontalLayout_8, 0, 1, 1, 1);

        tabWidget->addTab(credit, QString());
        deposit = new QWidget();
        deposit->setObjectName(QString::fromUtf8("deposit"));
        pushButton_deposit = new QPushButton(deposit);
        pushButton_deposit->setObjectName(QString::fromUtf8("pushButton_deposit"));
        pushButton_deposit->setGeometry(QRect(137, 387, 93, 31));
        pushButton_deposit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 5px;\n"
"  font-size: 1.2 em;\n"
"  background-color:rgb(215, 215, 215);;\n"
"  border-bottom: 4px solid rgb(165, 165, 165);\n"
"  font-family: 'Microsoft YaHei';\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"  background-color :rgb(197, 223, 255);\n"
"  border-bottom-color: rgb(153, 173, 198);\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 rgba(151, 170, 195, 255), stop: 1 rgba(255, 255, 255, 255));\n"
"}"));
        scrollArea = new QScrollArea(deposit);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(6, 240, 351, 141));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollBar:vertical \n"
"{\n"
"     width: 20px;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 329, 209));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout->addWidget(label_13, 0, 0, 1, 1);

        wth_rem = new QLabel(scrollAreaWidgetContents);
        wth_rem->setObjectName(QString::fromUtf8("wth_rem"));
        wth_rem->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout->addWidget(wth_rem, 7, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        pushButton_wth = new QPushButton(scrollAreaWidgetContents);
        pushButton_wth->setObjectName(QString::fromUtf8("pushButton_wth"));
        sizePolicy.setHeightForWidth(pushButton_wth->sizePolicy().hasHeightForWidth());
        pushButton_wth->setSizePolicy(sizePolicy);
        pushButton_wth->setMaximumSize(QSize(21, 21));
        pushButton_wth->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_13->addWidget(pushButton_wth);

        pushButton_del_wth = new QPushButton(scrollAreaWidgetContents);
        pushButton_del_wth->setObjectName(QString::fromUtf8("pushButton_del_wth"));
        sizePolicy.setHeightForWidth(pushButton_del_wth->sizePolicy().hasHeightForWidth());
        pushButton_del_wth->setSizePolicy(sizePolicy);
        pushButton_del_wth->setMaximumSize(QSize(21, 21));
        pushButton_del_wth->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_13->addWidget(pushButton_del_wth);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_9);


        gridLayout->addLayout(horizontalLayout_13, 6, 0, 1, 1);

        gridLayout_wth = new QGridLayout();
        gridLayout_wth->setSpacing(6);
        gridLayout_wth->setObjectName(QString::fromUtf8("gridLayout_wth"));

        gridLayout->addLayout(gridLayout_wth, 5, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        pushButton_rep = new QPushButton(scrollAreaWidgetContents);
        pushButton_rep->setObjectName(QString::fromUtf8("pushButton_rep"));
        sizePolicy.setHeightForWidth(pushButton_rep->sizePolicy().hasHeightForWidth());
        pushButton_rep->setSizePolicy(sizePolicy);
        pushButton_rep->setMaximumSize(QSize(21, 21));
        pushButton_rep->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_12->addWidget(pushButton_rep);

        pushButton_del_rep = new QPushButton(scrollAreaWidgetContents);
        pushButton_del_rep->setObjectName(QString::fromUtf8("pushButton_del_rep"));
        sizePolicy.setHeightForWidth(pushButton_del_rep->sizePolicy().hasHeightForWidth());
        pushButton_del_rep->setSizePolicy(sizePolicy);
        pushButton_del_rep->setMaximumSize(QSize(21, 21));
        pushButton_del_rep->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_12->addWidget(pushButton_del_rep);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_8);


        gridLayout->addLayout(horizontalLayout_12, 2, 0, 1, 1);

        gridLayout_rep = new QGridLayout();
        gridLayout_rep->setSpacing(6);
        gridLayout_rep->setObjectName(QString::fromUtf8("gridLayout_rep"));

        gridLayout->addLayout(gridLayout_rep, 1, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        wth_rem_2 = new QLineEdit(scrollAreaWidgetContents);
        wth_rem_2->setObjectName(QString::fromUtf8("wth_rem_2"));
        wth_rem_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_11->addWidget(wth_rem_2);

        wth_r_sign = new QLabel(scrollAreaWidgetContents);
        wth_r_sign->setObjectName(QString::fromUtf8("wth_r_sign"));
        wth_r_sign->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_11->addWidget(wth_r_sign);

        horizontalSpacer_10 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_10);


        gridLayout->addLayout(horizontalLayout_11, 8, 0, 1, 1);

        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout->addWidget(label_14, 3, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        layoutWidget_3 = new QWidget(deposit);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 10, 391, 242));
        gridLayout_2 = new QGridLayout(layoutWidget_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(7);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        capitalization = new QCheckBox(layoutWidget_3);
        capitalization->setObjectName(QString::fromUtf8("capitalization"));
        capitalization->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';\n"
"  font-size:13px"));

        gridLayout_2->addWidget(capitalization, 6, 2, 1, 1);

        rate_pay = new QComboBox(layoutWidget_3);
        rate_pay->addItem(QString());
        rate_pay->addItem(QString());
        rate_pay->addItem(QString());
        rate_pay->addItem(QString());
        rate_pay->addItem(QString());
        rate_pay->addItem(QString());
        rate_pay->setObjectName(QString::fromUtf8("rate_pay"));
        rate_pay->setMaximumSize(QSize(135, 16777215));
        rate_pay->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_2->addWidget(rate_pay, 4, 2, 1, 2);

        label_8 = new QLabel(layoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(16777215, 22));
        label_8->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 2);

        label_11 = new QLabel(layoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_2->addWidget(label_11, 4, 0, 1, 2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        sum = new QLineEdit(layoutWidget_3);
        sum->setObjectName(QString::fromUtf8("sum"));
        sum->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_6->addWidget(sum);

        label_12 = new QLabel(layoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_6->addWidget(label_12);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        srok_dep = new QLineEdit(layoutWidget_3);
        srok_dep->setObjectName(QString::fromUtf8("srok_dep"));
        srok_dep->setMinimumSize(QSize(50, 0));
        srok_dep->setMaximumSize(QSize(16777215, 16777215));
        srok_dep->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_2->addWidget(srok_dep);

        srok_typed = new QComboBox(layoutWidget_3);
        srok_typed->addItem(QString());
        srok_typed->addItem(QString());
        srok_typed->addItem(QString());
        srok_typed->setObjectName(QString::fromUtf8("srok_typed"));
        srok_typed->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_2->addWidget(srok_typed);

        horizontalSpacer_3 = new QSpacerItem(180, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 2, 1, 1);

        label_9 = new QLabel(layoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_2->addWidget(label_9, 2, 0, 1, 2);

        dep_date = new QDateEdit(layoutWidget_3);
        dep_date->setObjectName(QString::fromUtf8("dep_date"));
        dep_date->setMaximumSize(QSize(93, 16777215));
        dep_date->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_2->addWidget(dep_date, 2, 2, 1, 1);

        label_10 = new QLabel(layoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(16777215, 22));
        label_10->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_2->addWidget(label_10, 3, 0, 1, 2);

        label_7 = new QLabel(layoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(16777215, 22));
        label_7->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        int_rate_dep = new QLineEdit(layoutWidget_3);
        int_rate_dep->setObjectName(QString::fromUtf8("int_rate_dep"));
        int_rate_dep->setMinimumSize(QSize(58, 0));
        int_rate_dep->setMaximumSize(QSize(16777215, 16777215));
        int_rate_dep->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_5->addWidget(int_rate_dep);

        label_15 = new QLabel(layoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        horizontalLayout_5->addWidget(label_15);

        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_5, 3, 2, 1, 2);

        label_20 = new QLabel(layoutWidget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMaximumSize(QSize(16777215, 22));
        label_20->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_2->addWidget(label_20, 5, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_key_rate = new QLineEdit(layoutWidget_3);
        label_key_rate->setObjectName(QString::fromUtf8("label_key_rate"));
        label_key_rate->setMinimumSize(QSize(50, 0));
        label_key_rate->setMaximumSize(QSize(30, 16777215));
        label_key_rate->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_6->addWidget(label_key_rate, 0, 3, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_12, 0, 4, 1, 1);

        label_tax = new QLineEdit(layoutWidget_3);
        label_tax->setObjectName(QString::fromUtf8("label_tax"));
        label_tax->setMinimumSize(QSize(50, 0));
        label_tax->setMaximumSize(QSize(30, 16777215));
        label_tax->setStyleSheet(QString::fromUtf8("  font-family: 'Microsoft YaHei';"));

        gridLayout_6->addWidget(label_tax, 0, 1, 1, 1);

        label_21 = new QLabel(layoutWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_6->addWidget(label_21, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout_6, 5, 2, 1, 1);

        tabWidget->addTab(deposit, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_graph->setText(QCoreApplication::translate("MainWindow", "graph", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_eq->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_min->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_Obrace->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_Cbrace->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_bin->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        res_out->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        backspace->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        pushButton_space->setText(QCoreApplication::translate("MainWindow", "\342\220\243", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "x max", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "y min", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "y max", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "x min", nullptr));
        autoscale->setText(QCoreApplication::translate("MainWindow", "Autoscale", nullptr));
        pushButton_plot->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(basic), QCoreApplication::translate("MainWindow", "Basic", nullptr));
        pushButton_credit->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\276\320\272 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\265\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\321\205\n"
"\320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271", nullptr));
        annuit->setText(QCoreApplication::translate("MainWindow", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\265", nullptr));
        diff->setText(QCoreApplication::translate("MainWindow", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        type_sr_cr->setItemText(0, QCoreApplication::translate("MainWindow", "\320\233\320\265\321\202", nullptr));
        type_sr_cr->setItemText(1, QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "\342\202\275", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(credit), QCoreApplication::translate("MainWindow", "Credit", nullptr));
        pushButton_deposit->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", " \320\237\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217", nullptr));
        wth_rem->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\321\201\320\275\320\270\320\266\320\260\320\265\320\274\321\213\320\271 \320\276\321\201\321\202\320\260\321\202\320\276\320\272", nullptr));
        pushButton_wth->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_del_wth->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_rep->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_del_rep->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        wth_r_sign->setText(QCoreApplication::translate("MainWindow", "\342\202\275", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", " \320\241\320\277\320\270\321\201\320\260\320\275\320\270\321\217", nullptr));
        capitalization->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        rate_pay->setItemText(0, QCoreApplication::translate("MainWindow", "\320\232\320\260\320\266\320\264\321\213\320\271 \320\264\320\265\320\275\321\214", nullptr));
        rate_pay->setItemText(1, QCoreApplication::translate("MainWindow", "\320\232\320\260\320\266\320\264\321\203\321\216 \320\275\320\265\320\264\320\265\320\273\321\216", nullptr));
        rate_pay->setItemText(2, QCoreApplication::translate("MainWindow", "\320\232\320\260\320\266\320\264\321\213\320\271 \320\274\320\265\321\201\321\217\321\206", nullptr));
        rate_pay->setItemText(3, QCoreApplication::translate("MainWindow", "\320\232\320\260\320\266\320\264\321\213\320\271 \320\272\320\262\320\260\321\200\321\202\320\260\320\273", nullptr));
        rate_pay->setItemText(4, QCoreApplication::translate("MainWindow", "\320\232\320\260\320\266\320\264\321\213\320\265 \320\277\320\276\320\273\320\263\320\276\320\264\320\260", nullptr));
        rate_pay->setItemText(5, QCoreApplication::translate("MainWindow", "\320\232\320\260\320\266\320\264\321\213\320\271 \320\263\320\276\320\264", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\276\320\272 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\260\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214\n"
"\320\262\321\213\320\277\320\273\320\260\321\202", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\342\202\275", nullptr));
        srok_typed->setItemText(0, QCoreApplication::translate("MainWindow", "\320\264\320\275\320\265\320\271", nullptr));
        srok_typed->setItemText(1, QCoreApplication::translate("MainWindow", "\320\274\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        srok_typed->setItemText(2, QCoreApplication::translate("MainWindow", "\320\273\320\265\321\202", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\320\276 \321\201\321\200\320\276\320\272\320\260", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\241\321\203\320\274\320\274\320\260 \320\262\320\272\320\273\320\260\320\264\320\260", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\273\320\276\320\263 & \320\232\320\273\321\216\321\207\320\265\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "&", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(deposit), QCoreApplication::translate("MainWindow", "Deposit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
