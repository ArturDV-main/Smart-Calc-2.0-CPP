#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include "../s21_calc_controller.h"

enum Choice {
  SUM = 1,
  SUB = 2,
  MUL = 3,
  DIV = 4,
  RES = 5,
  EXIT = 0,
  NONE = -1
};

class ConsoleView {
 private:
  s21::CalcController *calc_controller;

 public:
  ConsoleView(s21::CalcController *c) : calc_controller(c){};
  void displayMenu();
  int performChoice();
  double performNumericInput();
  void startEventLoop();
};
#endif