#include "s21_calc_model.h"

namespace s21 {

CalcModel::CalcModel(/* args */) {}

CalcModel::~CalcModel() {}

double CalcModel::StartCalc(const std::string &src_str, double X_num) {
  // const char *src;
  
  if (s21::CalcValid::ValidationEqual(src_str)) {
    char *cstr = new char[src_str.length() + 1];
    strcpy(cstr, src_str.c_str());  //  Преобразование в str* для СИ
    result_ = Calc(cstr, X_num);
    delete[] cstr;
  } else
    throw std::runtime_error("expression error");
  return result_;
}

double CalcModel::Calc(const char *calculation_src, double X_num) {
  int position = 0;
  while (calculation_src[position]) {  //  Главный цикл вычисления
    StackType st_buf =
        ParserUno(calculation_src, &position, X_num);  //  Парсим одну лексемму
    if (st_buf.prio) {  //  Если получили операцию или скобку
      while (st_buf.oper_val) {
        if (st_buf.oper_val == ')' && BracketFinder()) {
          //  Если пришла скобка закр а в стеке скобка откр
          oper_stack.pop();
          st_buf.oper_val = 0.0;
        } else if (UnarCheck(st_buf.oper_val, calculation_src, position)) {

          
          st_oper = PushSta(st_oper, 0.0, st_buf.oper_val, st_buf.prio);
          st_num = PushSta(st_num, 0.0, '0', 0);  //  Получили унарный знак
          st_buf.oper_val = 0.0;
        } else if (st_oper == NULL || st_oper->oper_val == '(') {
          // Если стэк пуст или в нём скобка
          st_oper = PushSta(st_oper, 0.0, st_buf.oper_val, st_buf.prio);
          st_buf.oper_val = 0.0;
        } else if (st_buf.prio > st_oper->prio) {  //  Если приоритет опреации
          st_oper = PushSta(st_oper, 0.0, st_buf.oper_val,
                            st_buf.prio);  //  больше приоритета
          st_buf.oper_val = 0.0;            //  в стеке
        } else {
          double buf_num = MathOperations(&st_num, &st_oper);
          st_num = PushSta(st_num, buf_num, '0', 0);  //  Выполнить расчёт
        }  //  т.к. остальные условия не прошли
      }
      position++;
    } else {  //  Если получили число
      st_num = PushSta(st_num, st_buf.val_dub, '0', st_buf.prio);
    }
  }
  while (st_oper != NULL) {  //  Расчёт оставшегося содержимого стеков
    if (BracketFinder(st_oper)) {
      st_oper = DelPoint(st_oper);
      //  Если забыли поставить скобки в конце уравнения
      continue;
    }
    //  Если пришло число, просто отправляем в стек чисел
    double buf_num = MathOperations(&st_num, &st_oper);
    st_num = PushSta(st_num, buf_num, '0', 0);
  }

  double result = 0.0;
  if (st_num != NULL) {
    result = st_num->val_dub;
  }
  DestroyNode(st_num);
  return result;
}

CalcModel::StackType CalcModel::ParserUno(
    const char *calculation_src, int *position,
    double X_num) {  //  Парсер одной лексеммы
  StackType stack1{};
  int prio = PrioCheck(calculation_src[*position]);
  if (prio) {
    stack1.prio = prio;
    stack1.oper_val = calculation_src[*position];
  } else {
    if (calculation_src[*position] == 'X') {
      stack1.prio = 0;
      stack1.val_dub = X_num;
      *position += 1;
    } else {
      char buf[256] = {0};
      *position = *position + BufferingNumber(&calculation_src[*position], buf);
      double tess = atof(buf);
      stack1.prio = prio;
      stack1.val_dub = tess;
    }
  }
  return stack1;
}

int CalcModel::PrioCheck(
    char src_string) {  //  Определение приоритета опреатора
  int prior = 0;
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
  int counter = 0;
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
    char *out) {  //  Сборка числа в строку, возвращает длинну числа
  int i = 0;
  while ((src_string[i] >= '0' && src_string[i] <= '9') ||
         src_string[i] == '.' || src_string[i] == 'e') {
    if (src_string[i] == 'e') {
      out[i] = src_string[i];
      i++;
    }
    out[i] = src_string[i];
    i++;
  }
  return i;
}

int CalcModel::BracketFinder() {
  int finded = 0;
  if (!oper_stack.empty())
    if (oper_stack.top().oper_val == '(') finded = 1;
  return finded;
}

CalcModel::StackType *CalcModel::DelPoint(
    StackType *stack1) {  //  Удалит последний элемент списка
  StackType *Ptrack_bac = stack1->next;
  delete (stack1);
  return Ptrack_bac;
}

int CalcModel::UnarCheck(char check, const char *oper_st, int position) {
  int unar_minus_find = 0;
  if ((check == '-' || check == '+') && !position) unar_minus_find = 1;
  if ((check == '-' || check == '+') && position > 0)
    if (oper_st[position - 1] == '(') unar_minus_find = 1;
  return unar_minus_find;
}

CalcModel::StackType *CalcModel::PushSta(StackType *plist, double val_dub, char oper_val,
                                         int prio) {
  StackType *Part = new (StackType);
  if (Part == NULL) {
    exit(1);
  } else {
    Part->next = plist;
    Part->prio = prio;
    Part->oper_val = oper_val;
    Part->val_dub = val_dub;
  }
  return Part;
}

double CalcModel::MathOperations(StackType **num_sta, StackType **oper_sta) {
  double buf_num = 0.0;
  if ((*oper_sta)->prio < 4) {
    StackType tmp = 
    double second = PopVal(num_sta);
    double first = PopVal(num_sta);
    char operat = (char)PopVal(oper_sta);

    buf_num = SimpleMath(second, first, operat);
  } else if ((*oper_sta)->prio < 5) {
    buf_num = PopVal(num_sta);
    char oper_buf = PopVal(oper_sta);
    buf_num = TrigonCalc(buf_num, oper_buf);
  }
  return buf_num;
}

void CalcModel::DestroyNode(StackType *stack1) {
  StackType *Ptrack = stack1;
  while (Ptrack) {
    StackType *Ptrack_bac = Ptrack->next;
    delete (Ptrack);
    Ptrack = Ptrack_bac;
  }
  delete (Ptrack);
}

double CalcModel::PopVal(StackType **stack) {
  StackType *oper_stack = *stack;
  StackType 
  double bufer = 0.0;
  if (oper_stack == NULL) {
    oper_stack = NULL;
  } else {
    bufer = (double)oper_stack->val_dub;
    *stack = oper_stack->next;
    delete (oper_stack);
  }
  return bufer;
}

double CalcModel::SimpleMath(double second_num, double first_num,
                             char operation) {
  double out_num = 0.0;
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
      // if(second_num == 0.0 || first_num == 0.0) throw
      // std::runtime_error("Error: ");
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
