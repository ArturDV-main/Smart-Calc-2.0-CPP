#include "s21_calc_controller.h"

#include <stdexcept>

namespace s21 {

double s21::CalcController::StartCalc(const char* a, const double x) {
  try {
    calc_model->StartCalc(a, x);
  } catch (const std::exception& e) {
    throw std::runtime_error(e.what());
  }
  return calc_model->GetData();
}

}  // namespace s21
