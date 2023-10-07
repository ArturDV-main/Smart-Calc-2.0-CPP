#ifndef SRC_S21_CALC_VALID_MODEL_H_
#define SRC_S21_CALC_VALID_MODEL_H_

#include <cmath>
#include <cstring>
#include <string>

namespace s21 {

class CalcValid {
 public:
  enum CodeSamples {
    opened,
    closed,
    error,
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
  int LastIs(char res);
  int CharCounter(const char* str_line, char res);
  static bool ValidationEqual(const std::string& str);
  int PositionCounter(char src_string);
  int IsSimpOper(char oper);
  int IsNums(char num);
  int SmartBracket(const char* str_line);
  int ValidSimpOper(const char* str_line);
  int ValidNums(const char* str_line);
  int ValidEquals(const char* str_line);
  int ValidUnar(const char* str_line);
  int ValidDot(const char* str_line);
  int ValidInputLine(double maxval, double minval, const char* str_line);
  int ValidDotLine(const char* str_line);
  int SuperValid(double maxval, double minval, const char* str_line);

  int ValidFunc(const std::string str_line);
  int InLineStart(const std::string &str);
private:
};

}  // namespace s21

#endif  //  SRC_S21_CALC_VALID_MODEL_H_
