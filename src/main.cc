#include "s21_view_qt/s21_view_qt.h"
#include <QApplication>
#include "s21_calc_controller.h"
#include "s21_calc_model.h"
// #include "s21_view_qt/console_view.h"
#include <iostream>

int viewStart(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  if(argc && argv) {
    s21::CalcModel calc_model;
    s21::CalcController calc_controller(&calc_model);
    // ConsoleView console_view(&calc_controller);
    // console_view.StartEventLoop();
    return viewStart(argc, argv);
  }
  return 1;
}

int viewStart(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("S21 Smart Calculator");
  w.show();
  return a.exec();
}
