// #include "mainwindow.h"

// #include <QApplication>

#include "s21_calc_model.h"
#include <iostream>

int main(int argc, char *argv[]) {
  if(argc && argv) {
    s21::CalcModel a;
    double result = a.StartCalc("2+2", 0);
    std::cout << result << std::endl;
    return 0;
  }
  return 1;
}
