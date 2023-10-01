#ifndef SRC_S21_CALC_MODEL_H_
#define SRC_S21_CALC_MODEL_H_

#include <cmath>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <iostream>
#include "./s21_calc_valid_model.h"

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
    int prio{};
    StackType *next{};
  };

 public:
  CalcModel(/* args */);
  ~CalcModel();
  double StartCalc(const std::string &src_str, double X_num);
  double GetData() { return result_; }
  void Reset() { result_ = 0.0; }

 private:
  // std::string expression{};  //  TODO
  double result_{};
  //  Metods
  double Calc(const char *calculation_src, double X_num);
  StackType ParserUno(const char *calculation_src, int *position, double X_num);
  int PrioCheck(char src_string);
  int PositionCounter(char src_string);
  int BufferingNumber(const char *src_string, char *out);
  int BracketFinder(StackType *oper);
  StackType *DelPoint(StackType *stack1);
  int UnarCheck(char check, const char *oper_st, int position);
  StackType *PushSta(StackType *plist, double val_dub, int prio);
  double MathOperations(StackType **num_sta, StackType **oper_sta);
  void DestroyNode(StackType *stack1);
  double PopVal(StackType **stack);
  double SimpleMath(double second_num, double first_num, char operation);
  double TrigonCalc(double x, char operation);
};

}  // namespace s21

#endif  // SRC_CALC_MODEL_H_
