#include "s21_calc_valid_model.h"

namespace s21 {

bool CalcValid::ValidationEqual(const std::string &str) {
  bool valid(false);
  std::string tmp("+-/*M^@ABCDEFGH)(1234567890.e");
  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    const char c = *it;
    if (tmp.find(c) == tmp.npos) {
      valid = false;
      break;
    }
    valid = true;
  }
  return valid;
}

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
  if (str.length() == 2) in_start = true;
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

int CalcValid::ValidSimpOper(const char *str_line) {
  int valid_oper = false;
  int len = strlen(str_line);
  char lastch = str_line[len - 1];
  int last = LastIs(lastch);
  if (last && !InLineStart(str_line)) valid_oper = true;
  return valid_oper;
}

bool CalcValid::ValidFunc(const std::string str_line) {
  int validfunc = false;
  int len = str_line.length();
  if (IsSimpOper(str_line[len - 1]) || str_line[len - 1] == '(' ||
      InLineStart(str_line))
    validfunc = true;
  return validfunc;
}

int CalcValid::ValidNums(const char *str_line) {
  int validfunc = false;
  int len = strlen(str_line);
  char lastchar = str_line[len - 1];
  if ((IsSimpOper(lastchar) || lastchar == '(' || InLineStart(str_line) ||
       IsNums(lastchar)) &&
      lastchar != 'X')
    validfunc = true;
  return validfunc;
}

int CalcValid::ValidEquals(const char *str_line) {
  int validequals = false;
  int len = strlen(str_line);
  char lastchar = str_line[len - 1];
  if (lastchar == ')' || IsNums(lastchar) || lastchar == 'X')
    validequals = true;
  return validequals;
}

int CalcValid::ValidUnar(const char *str_line) {
  int validunar = false;
  int len = strlen(str_line);
  char lastchar = str_line[len - 1];
  if (lastchar == '(' || InLineStart(str_line)) validunar = true;
  return validunar;
}

int CalcValid::ValidDot(const char *str_line) {
  int validdot = true;
  int i = 0;
  int len = strlen(str_line);
  while (IsNums(str_line[len - 1 - i])) {
    if (str_line[len - 1 - i] == '.') {
      validdot = false;
      break;
    }
    i++;
  }
  return validdot;
}

int CalcValid::ValidDotLine(const char *str_line) {
  int validdot = true;
  int i = 0;
  int len = strlen(str_line);
  while (IsNums(str_line[len - 1 - i])) {
    if (str_line[len - 1 - i] == '.') {
      validdot++;
    }
    i++;
  }
  if (validdot > 2) validdot = false;
  return validdot;
}

int CalcValid::ValidInputLine(double maxval, double minval,
                              const char *str_line) {
  int validline = true;
  int len = strlen(str_line);
  char lastchar = str_line[len - 1];
  if (str_line[1] == '\0' && lastchar == '-') {
    validline = true;
  } else if (lastchar == '.') {
    validline = ValidDotLine(str_line);
  } else if (validline) {
    validline = IsNums(lastchar);
  }
  if (validline) {
    double test = atof(str_line);
    if (minval > test || test > maxval) validline = false;
  }
  return validline;
}

int CalcValid::SuperValid(double maxval, double minval, const char *str_line) {
  int validline = true;
  //    int len = strlen(str_line);
  int i = 0;
  if (str_line[0] == '-') i = 1;
  while (str_line[i]) {
    if (IsNums(str_line[i]) != 1) {
      validline = false;
      break;
    }
    i++;
  }
  if (validline) {
    int validdot = ValidDotLine(str_line);
    if (!validdot) validline = false;
  }
  if (validline) {
    double test = atof(str_line);
    if (minval > test || test > maxval) validline = false;
  }
  return validline;
}

}  // namespace s21
