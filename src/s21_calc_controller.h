#ifndef SRC_S21_CALC_CONTROLLER_H_
#define SRC_S21_CALC_CONTROLLER_H_
#include <array>

#include "s21_calc_model.h"

namespace s21 {

class CalcController {
 public:
  CalcController(s21::CalcModel *m) : calc_model(m){};
  void Reset() noexcept { calc_model->Reset(); }
  void StartCalc(const std::string &a, const double x);
  double GetResult() const noexcept { return calc_model->GetData(); }
  void CalcCredit(std::array<double, 3> data) { calc_model->CalcCredit(data); }
  std::array<double, 3> GetCredit() { return calc_model->GetCredit(); }
  void DifferenCalc(std::array<double, 3> data) {
    calc_model->DifferenCalc(data);
  }
  std::vector<double> GetDifferent() { return calc_model->GetDifferent(); }

 private:
  s21::CalcModel *calc_model;
};

}  // namespace s21

#endif  //  SRC_S21_CALC_CONTROLLER_H_
