#ifndef SRC_S21_CALC_MODEL_H_
#define SRC_S21_CALC_MODEL_H_

#include <cmath>
#include <cstring>
#include <iostream>
#include <memory>
#include <stack>
#include <stdexcept>

namespace s21 {

class CalcModel {
#define OPERATIONS ")+-/*M^@ABCDEFGH("
  enum truefalse {
    FALSE,
    TRUE,
    ERROR,
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

  struct StackType {
    double val_dub{};
    char oper_val{};
    int prio{};
  };

 public:
  CalcModel(/* args */);
  ~CalcModel();
  double StartCalc(const std::string &src_str, double X_num);
  bool ValidationEqual(const std::string &str);
  double GetData() { return result_; }
  void Reset() { result_ = 0.0; }

 private:
  // std::string expression{};  //  TODO
  std::stack<StackType> oper_stack_{};
  std::stack<double> num_stack_{};
  double result_{};
  //  Metods
  double Calc(const std::string &calc_src, double X_num);
  StackType ParserUno(const std::string &calc_src, int *position, double X_num);
  int PrioCheck(char src_string);
  int PositionCounter(char src_string);
  int BufferingNumber(const char *src_string, std::string &out);
  int BracketFinder();
  int UnarCheck(char check, const std::string &calc_str, int position);
  double MathOperations();
  double SimpleMath(double second_num, double first_num, char operation);
  double TrigonCalc(double x, char operation);
};

}  // namespace s21

#endif  // SRC_CALC_MODEL_H_
