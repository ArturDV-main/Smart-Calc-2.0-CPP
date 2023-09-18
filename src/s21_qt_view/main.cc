#include "mainwindow.h"

#include <QApplication>

#include "../s21_smartcalc.h"

int start_view(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("S21 Smart Calculator");
  w.show();
  return a.exec();
}
