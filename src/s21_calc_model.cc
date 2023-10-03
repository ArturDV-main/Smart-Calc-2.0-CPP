#include "s21_calc_model.h"

namespace s21 {

CalcModel::CalcModel(/* args */) {}

CalcModel::~CalcModel() {}

double CalcModel::StartCalc(const std::string &src_str, double X_num) {
  std::setlocale(LC_NUMERIC, "C");
  if (ValidationEqual(src_str)) {
    result_ = Calc(src_str, X_num);
  } else {
    throw std::runtime_error("expression error");
  }
  return result_;
}

bool CalcModel::ValidationEqual(const std::string &str) {
  bool valid(false);
  std::string tmp("+-/*M^@ABCDEFGH)(1234567890.eX");
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

double CalcModel::Calc(const std::string &calc_src, double X_num) {
  int position = 0;
  while (calc_src[position]) {  //  Главный цикл вычисления
    StackType st_buf =
        ParserUno(calc_src, &position, X_num);  //  Парсим одну лексемму
    if (st_buf.prio) {  //  Если получили операцию или скобку
      while (st_buf.oper_val) {
        if (st_buf.oper_val == ')' && BracketFinder()) {
          //  Если пришла скобка закр а в стеке скобка откр
          oper_stack_.pop();
          st_buf.oper_val = 0.0;
        } else if (UnarCheck(st_buf.oper_val, calc_src, position)) {
          oper_stack_.push({0.0, st_buf.oper_val, st_buf.prio});
          num_stack_.push(0.0);  //  Получили унарный знак
          st_buf.oper_val = 0.0;
        } else if (oper_stack_.empty() || oper_stack_.top().oper_val == '(') {
          // Если стэк пуст или в нём скобка
          oper_stack_.push({0.0, st_buf.oper_val, st_buf.prio});
          st_buf.oper_val = 0.0;
        } else if (st_buf.prio >
                   oper_stack_.top().prio) {  //  Если приоритет опреации
          oper_stack_.push({0.0, st_buf.oper_val,  //  больше приоритета
                            st_buf.prio});  //  в стеке
          st_buf.oper_val = 0.0;
        } else {
          double buf_num = MathOperations();  //  Выполнить расчёт
          num_stack_.push(buf_num);
        }  //  т.к. остальные условия не прошли
      }
      position++;
    } else {  //  Если получили число
      num_stack_.push(st_buf.val_dub);
    }
  }
  while (!oper_stack_.empty()) {  //  Расчёт оставшегося содержимого стеков
    if (BracketFinder()) {
      oper_stack_.pop();
      //  Если забыли поставить скобки в конце уравнения
      continue;
    }
    //  Если пришло число, просто отправляем в стек чисел
    num_stack_.push(MathOperations());
  }

  double result = 0.0;
  if (!num_stack_.empty()) {
    result = num_stack_.top();
    num_stack_.pop();
  }
  if (!num_stack_.empty()) throw std::runtime_error("numbers stack invalid");
  return result;
}

CalcModel::StackType CalcModel::ParserUno(
    const std::string &calc_src, int *position,
    double X_num) {  //  Парсер одной лексеммы
  StackType stack1{};
  int prio = PrioCheck(calc_src[*position]);
  if (prio) {
    stack1.prio = prio;
    stack1.oper_val = calc_src[*position];
  } else {
    if (calc_src[*position] == 'X') {
      stack1.prio = 0;
      stack1.val_dub = X_num;
      *position += 1;
    } else {
      std::string buf{};
      *position = *position + BufferingNumber(&calc_src[*position], buf);
      stack1.prio = prio;
      stack1.val_dub = std::stod(buf);
    }
  }
  return stack1;
}

int CalcModel::PrioCheck(
    char src_string) {  //  Определение приоритета опреатора
  int prior{};
  int position_num = PositionCounter(src_string);
  if (position_num > 16)
    prior = 0;
  else if (position_num == 16)
    prior = 5;
  else if (position_num > 6)
    prior = 4;
  else if (position_num == 6)
    prior = 3;
  else if (position_num > 2)
    prior = 2;
  else if (position_num >= 0)  //  Низкий приоритет для закрывающей скобки
    prior = 1;  //  запустит подсчёт
  return prior;
}

int CalcModel::PositionCounter(
    char src_string) {  //  Подсчёт позиции операции строке приоритетов
  const char *operators = OPERATIONS;
  int counter{};
  while (operators[counter]) {
    if (operators[counter] == src_string) {
      break;
    }
    counter++;
  }
  return counter;
}

int CalcModel::BufferingNumber(
    const char *src_string,
    std::string &out) {  //  Сборка числа в строку, возвращает длинну числа
  int i = 0;
  while ((src_string[i] >= '0' && src_string[i] <= '9') ||
         src_string[i] == '.' || src_string[i] == 'e') {
    if (src_string[i] == 'e') {
      out += src_string[i];
      i++;
    }
    out += src_string[i];
    i++;
  }
  return i;
}

int CalcModel::BracketFinder() {
  int finded = 0;
  if (!oper_stack_.empty())
    if (oper_stack_.top().oper_val == '(') finded = 1;
  return finded;
}

int CalcModel::UnarCheck(char check, const std::string &calc_str,
                         int position) {
  int unar_minus_find{};
  if ((check == '-' || check == '+') && !position) unar_minus_find = 1;
  if ((check == '-' || check == '+') && position > 0)
    if (calc_str[position - 1] == '(') unar_minus_find = 1;
  return unar_minus_find;
}

double CalcModel::MathOperations() {
  double buf_num = 0.0;
  if (oper_stack_.empty()) throw std::runtime_error("Math err");
  if (oper_stack_.top().prio < 4) {
    if (num_stack_.size() < 2) throw std::runtime_error("Math err");
    double second = num_stack_.top();
    num_stack_.pop();
    double first = num_stack_.top();
    num_stack_.pop();
    char operat = oper_stack_.top().oper_val;
    oper_stack_.pop();
    buf_num = SimpleMath(second, first, operat);
  } else if (oper_stack_.top().prio < 5) {
    if (num_stack_.empty())
      throw std::runtime_error("Math err, expression error");
    buf_num = num_stack_.top();
    num_stack_.pop();
    char oper_buf = oper_stack_.top().oper_val;
    oper_stack_.pop();
    buf_num = TrigonCalc(buf_num, oper_buf);
  }
  return buf_num;
}

double CalcModel::SimpleMath(double second_num, double first_num,
                             char operation) {
  double out_num = 0.0;
  double epsilon = 0.00000001;
  switch (operation) {
    case '+':
      out_num = first_num + second_num;
      break;
    case '-':
      out_num = first_num - second_num;
      break;
    case '*':
      out_num = first_num * second_num;
      break;
    case '/':
      if (std::abs(second_num - 0.0) < epsilon)
        throw std::runtime_error("Error: /0");
      if (std::abs(first_num - 0.0) < epsilon)
        throw std::runtime_error("Error: 0/");
      out_num = first_num / second_num;
      break;
    case '^':
      out_num = pow(first_num, second_num);
      break;
    case 'M':
      out_num = fmod(first_num, second_num);
      break;
  }
  return out_num;
}

double CalcModel::TrigonCalc(double x, char operation) {
  double buf_num = 0.0;
  switch (operation) {
    case COS:
      buf_num = cos(x);
      break;
    case SIN:
      buf_num = sin(x);
      break;
    case TAN:
      buf_num = tan(x);
      break;
    case ACOS:
      buf_num = acos(x);
      break;
    case ASIN:
      buf_num = asin(x);
      break;
    case ATAN:
      buf_num = atan(x);
      break;
    case SQRT:
      buf_num = sqrt(x);
      break;
    case LN:
      buf_num = log(x);
      break;
    case LOG:
      buf_num = log10(x);
      break;
  }
  return buf_num;
}

}  // namespace s21
