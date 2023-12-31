#include <QApplication>

#include "controller/controller.h"
#include "model/model.h"
#include "view/mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  smcalc::Model m;
  smcalc::Controller c(&m);
  smcalc::MainWindow w(&c);
  w.show();
  return a.exec();
}
