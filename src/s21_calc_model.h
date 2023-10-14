#ifndef SRC_S21_CALC_MODEL_H_
#define SRC_S21_CALC_MODEL_H_

#include <array>
#include <cmath>
#include <cstring>
#include <iostream>
#include <memory>
#include <stack>
#include <stdexcept>

namespace s21 {

class CalcModel {
  // #define OPERATIONS ")+-/*M^@ABCDEFGH("
  enum TrigonCode {
    COS = '@',
    SIN = 'A',
    TAN = 'B',
    ACOS = 'C',
    ASIN = 'D',
    ATAN = 'E',
    SQRT = 'F',
    LN = 'G',
    LOG = 'H'
  };

  enum ForData { summa = 0, srok, percent };
  enum ForItog { monthly = 0, itog, pereplata };

  struct StackType {
    double val_dub{};
    char oper_val{};
    int prio{};
  };

 public:
  CalcModel();
  ~CalcModel();
  void StartCalc(const std::string &src_str, double X_num);
  void CalcCredit(std::array<double, 3> data);
  bool ValidationEqual(const std::string &str) const noexcept;
  double GetData() const noexcept { return result_; }
  std::array<double, 3> GetCredit() { return credit_data_; }
  void Reset() noexcept { result_ = 0.0; }

 private:
  std::stack<StackType> oper_stack_{};
  std::stack<double> num_stack_{};
  double result_{};
  std::array<double, 3> credit_data_;
  //  Metods
  double Calc(const std::string &calc_src, double X_num);
  StackType ParserUno(const std::string &calc_src, int *position, double X_num);
  int PrioCheck(char src_string) const noexcept;
  int PositionCounter(char src_string) const noexcept;
  int BufferingNumber(const char *src_string, std::string &out);
  int BracketFinder();
  int UnarCheck(char check, const std::string &calc_str, int position);
  double MathOperations();
  void CleanStacks();
  void PushError(std::string error);
  double SimpleMath(double second_num, double first_num, char operation);
  double TrigonCalc(double x, char operation);
};

}  // namespace s21

#endif  // SRC_CALC_MODEL_H_
