#include "s21_view_valid.h"

namespace s21 {

int CalcValid::PositionCounter(
    char src_string) {  //  Подсчёт позиции операции в строке приоритетов
  const char *operators = ")+-/*M^@ABCDEFGH(";
  int counter = 0;
  while (operators[counter]) {
    if (operators[counter] == src_string) {
      break;
    }
    counter++;
  }
  return counter;
}

bool CalcValid::InLineStart(const std::string &str) {
  bool in_start = false;
  if (str.length() == 0) in_start = true;
  return in_start;
}

int CalcValid::IsSimpOper(char oper) {
  int it_oper = false;
  int oper_string = PositionCounter(oper);
  if (oper_string > 0 && oper_string < 7) it_oper = true;
  return it_oper;
}

size_t CalcValid::CharCounter(const std::string &str_line, char res) {
  int counter = 0, i = 0;
  while (str_line[i]) {
    if (str_line[i] == res) counter++;
    i++;
  }
  return counter;
}

int CalcValid::IsNums(char num) {
  int is_num = false;
  if (('0' <= num && num <= '9') || num == '.') is_num = true;
  return is_num;
}

int CalcValid::LastIs(char res) {
  int is_number = false;
  if (IsNums(res) || res == '.' || res == ')' || res == 'X') is_number = true;
  return is_number;
}

int CalcValid::SmartBracket(const std::string &str_line) {
  int bracket = opened;
  int len = str_line.length();
  int open_bracket_val = CharCounter(str_line, '(');
  int close_bracket_val = CharCounter(str_line, ')');
  int last_sym = LastIs(str_line[len - 1]);

  if ((open_bracket_val > close_bracket_val) && last_sym) {
    bracket = closed;
  } else if (InLineStart(str_line) || IsSimpOper(str_line[len - 1]) ||
             str_line[len - 1] == '(') {
    bracket = opened;
  } else {
    bracket = error;
  }
  return bracket;
}

bool CalcValid::ValidFunc(const std::string &str_line) {
  int validfunc = false;
  int len = str_line.length();
  if (IsSimpOper(str_line[len - 1]) || str_line[len - 1] == '(' ||
      InLineStart(str_line))
    validfunc = true;
  return validfunc;
}

}  // namespace s21
