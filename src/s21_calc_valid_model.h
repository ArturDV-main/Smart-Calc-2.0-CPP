#ifndef SRC_S21_CALC_VALID_MODEL_H_
#define SRC_S21_CALC_VALID_MODEL_H_

#include <cmath>
#include <cstring>
#include <string>

namespace s21 {

class CalcValid {
 public:
  enum CodeSamples { opened, closed, error };
  int LastIs(char res);
  static bool ValidationEqual(const std::string& str);
  int PositionCounter(char src_string);
  int IsSimpOper(char oper);
  int IsNums(char num);
  int ValidSimpOper(const char* str_line);
  int ValidNums(const char* str_line);
  int ValidEquals(const char* str_line);
  int ValidUnar(const char* str_line);
  int ValidDot(const char* str_line);
  int ValidInputLine(double maxval, double minval, const char* str_line);
  int ValidDotLine(const char* str_line);
  int SuperValid(double maxval, double minval, const char* str_line);

  int SmartBracket(const std::string& str_line);
  bool ValidFunc(const std::string& str_line);
  bool InLineStart(const std::string& str);
  size_t CharCounter(const std::string& str_line, char res);

 private:
};

}  // namespace s21

#endif  //  SRC_S21_CALC_VALID_MODEL_H_
