// #include "mainwindow.h"

// #include <QApplication>
#include "s21_calc_controller.h"
#include "s21_calc_model.h"
#include "s21_view_qt/console_view.h"
#include <iostream>

int main(int argc, char *argv[]) {
  if(argc && argv) {
    s21::CalcModel calc_model;
    s21::CalcController calc_controller(&calc_model);
    ConsoleView console_view(&calc_controller);
    console_view.StartEventLoop();
    return 0;
  }
  return 1;
}
