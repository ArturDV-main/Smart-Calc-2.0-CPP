#ifndef SRC_S21_CALC_VALID_MODEL_H_
#define SRC_S21_CALC_VALID_MODEL_H_

// #include "s21_calc_model.h"
#include <cmath>
#include <cstring>

namespace s21 {

class CalcValid {
 public:
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
  int last_is(char res);
  int char_counter(const char* str_line, char res);
  int PositionCounter(char src_string);
  int in_line_start(const char* str, int str_len);
  int is_simp_oper(char oper);
  int is_nums(char num);
  int smart_bracket(const char* str_line);
  int valid_simp_oper(const char* str_line);
  int valid_func(const char* str_line);
  int valid_nums(const char* str_line);
  int valid_equals(const char* str_line);
  int valid_unar(const char* str_line);
  int valid_dot(const char* str_line);
  int valid_input_line(double maxval, double minval, const char* str_line);
  int valid_dot_line(const char* str_line);
  int super_valid(double maxval, double minval, const char* str_line);

 private:
};

}  // namespace s21

#endif  //  SRC_S21_CALC_VALID_MODEL_H_