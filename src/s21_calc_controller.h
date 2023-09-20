#ifndef SRC_S21_CALC_CONTROLLER_H_
#define SRC_S21_CALC_CONTROLLER_H_

#include "s21_calc_model.h"

namespace s21 {

class CalcController {
 public:
  CalcController(s21::CalcModel *m) : calc_model(m){};
  void Reset() { calc_model->Reset(); }
  double StartCalc(const char *a, const double x);
  double GetResult() {return calc_model->GetData();}
 private:
  s21::CalcModel *calc_model;
};

}  // namespace s21

#endif  //  SRC_S21_CALC_CONTROLLER_H_
