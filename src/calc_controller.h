#ifndef SRC_CALC_CONTROLLER_H_
#define SRC_CALC_CONTROLLER_H_

#include "calc_model.h"

namespace s21 {
class CalcController {
 public:
  CalcController(s21::CalcModel *m) : model(m){};

 private:
  s21::CalcModel *model;
};
}  // namespace s21

#endif  //  SRC_CALC_CONTROLLER_H_