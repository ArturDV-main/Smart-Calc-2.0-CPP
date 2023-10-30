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
  int IsNums(char num);
  int PositionCounter(char src_string);
  int IsSimpOper(char oper);
  int SmartBracket(const std::string& str_line);
  bool ValidFunc(const std::string& str_line);
  bool InLineStart(const std::string& str);
  size_t CharCounter(const std::string& str_line, char res);

 private:
};

}  // namespace s21

#endif  //  SRC_S21_CALC_VALID_MODEL_H_
