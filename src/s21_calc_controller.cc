#include "s21_calc_controller.h"
#include <stdexcept>

void s21::CalcController::Reset() {}

double s21::CalcController::StartCalc(const char * a, const double x) { 
    try
    {
        calc_model->StartCalc(a, x);
    }
    catch(const std::exception& e)
    {
        throw std::runtime_error(e.what());
    }
    return calc_model->getData();
}
