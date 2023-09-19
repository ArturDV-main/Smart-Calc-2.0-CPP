#include "s21_calc_valid_model.h"

namespace s21 {

int CalcValid::PositionCounter(
    char src_string) {  //  Подсчёт позиции операции строке приоритетов
  const char *operators = OPERATIONS;
  int counter = 0;
  while (operators[counter]) {
    if (operators[counter] == src_string) {
      break;
    }
    counter++;
  }
  return counter;
}

int CalcValid::InLineStart(const char *str, int str_len) {
  int in_start = FALSE;
  if (str[0] == '0' && str_len == 1) in_start = TRUE;
  return in_start;
}

int CalcValid::IsSimpOper(char oper) {
  int it_oper = FALSE;
  int oper_string = PositionCounter(oper);
  if (oper_string > 0 && oper_string < 7) it_oper = TRUE;
  return it_oper;
}

int CalcValid::CharCounter(const char *str_line, char res) {
  int counter = 0, i = 0;
  while (str_line[i]) {
    if (str_line[i] == res) counter++;
    i++;
  }
  return counter;
}

int CalcValid::IsNums(char num) {
  int is_num = FALSE;
  if (('0' <= num && num <= '9') || num == '.') is_num = TRUE;
  return is_num;
}

int CalcValid::last_is(char res) {
  int is_number = FALSE;
  if (IsNums(res) || res == '.' || res == ')' || res == 'X') is_number = TRUE;
  return is_number;
}

int CalcValid::SmartBracket(const char *str_line) {
  int closed_bracket = FALSE;
  int len = strlen(str_line);
  int open_bracket_val = CharCounter(str_line, '(');
  int close_bracket_val = CharCounter(str_line, ')');
  int last_sym = last_is(str_line[len - 1]);

  if ((open_bracket_val > close_bracket_val) && last_sym) {
    closed_bracket = TRUE;
  } else if (InLineStart(str_line, len) || IsSimpOper(str_line[len - 1]) ||
             str_line[len - 1] == '(') {
    closed_bracket = FALSE;
  } else {
    closed_bracket = ERROR;
  }
  return closed_bracket;
}

int CalcValid::ValidSimpOper(const char *str_line) {
  int valid_oper = FALSE;
  int len = strlen(str_line);
  char lastch = str_line[len - 1];
  int last = last_is(lastch);
  if (last && !InLineStart(str_line, len)) valid_oper = TRUE;
  return valid_oper;
}

int CalcValid::ValidFunc(const char *str_line) {
  int validfunc = FALSE;
  int len = strlen(str_line);
  if (IsSimpOper(str_line[len - 1]) || str_line[len - 1] == '(' ||
      InLineStart(str_line, len))
    validfunc = TRUE;
  return validfunc;
}

int CalcValid::ValidNums(const char *str_line) {
  int validfunc = FALSE;
  int len = strlen(str_line);
  char lastchar = str_line[len - 1];
  if ((IsSimpOper(lastchar) || lastchar == '(' ||
       InLineStart(str_line, len) || IsNums(lastchar)) &&
      lastchar != 'X')
    validfunc = TRUE;
  return validfunc;
}

int CalcValid::ValidEquals(const char *str_line) {
  int validequals = FALSE;
  int len = strlen(str_line);
  char lastchar = str_line[len - 1];
  if (lastchar == ')' || IsNums(lastchar) || lastchar == 'X')
    validequals = TRUE;
  return validequals;
}

int CalcValid::ValidUnar(const char *str_line) {
  int validunar = FALSE;
  int len = strlen(str_line);
  char lastchar = str_line[len - 1];
  if (lastchar == '(' || InLineStart(str_line, len)) validunar = TRUE;
  return validunar;
}

int CalcValid::ValidDot(const char *str_line) {
  int validdot = TRUE;
  int i = 0;
  int len = strlen(str_line);
  while (IsNums(str_line[len - 1 - i])) {
    if (str_line[len - 1 - i] == '.') {
      validdot = FALSE;
      break;
    }
    i++;
  }
  return validdot;
}

int CalcValid::ValidDotLine(const char *str_line) {
  int validdot = TRUE;
  int i = 0;
  int len = strlen(str_line);
  while (IsNums(str_line[len - 1 - i])) {
    if (str_line[len - 1 - i] == '.') {
      validdot++;
    }
    i++;
  }
  if (validdot > 2) validdot = FALSE;
  return validdot;
}

int CalcValid::ValidInputLine(double maxval, double minval, const char *str_line) {
  int validline = TRUE;
  int len = strlen(str_line);
  char lastchar = str_line[len - 1];
  if (str_line[1] == '\0' && lastchar == '-') {
    validline = TRUE;
  } else if (lastchar == '.') {
    validline = ValidDotLine(str_line);
  } else if (validline) {
    validline = IsNums(lastchar);
  }
  if (validline) {
    double test = atof(str_line);
    if (minval > test || test > maxval) validline = FALSE;
  }
  return validline;
}

int CalcValid::SuperValid(double maxval, double minval, const char *str_line) {
  int validline = TRUE;
  //    int len = strlen(str_line);
  int i = 0;
  if (str_line[0] == '-') i = 1;
  while (str_line[i]) {
    if (IsNums(str_line[i]) != 1) {
      validline = FALSE;
      break;
    }
    i++;
  }
  if (validline) {
    int validdot = ValidDotLine(str_line);
    if (!validdot) validline = FALSE;
  }
  if (validline) {
    double test = atof(str_line);
    if (minval > test || test > maxval) validline = FALSE;
  }
  return validline;
}

}  // namespace s21