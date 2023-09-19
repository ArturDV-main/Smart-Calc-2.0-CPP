#ifndef SRC_CALC_MODEL_H_
#define SRC_CALC_MODEL_H_

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

  struct stack_type {
    double val_dub;
    int prio;
    stack_type *next;
  };

 public:
  CalcModel(/* args */);
  ~CalcModel();

 private:
  // std::string expression{};  //  TODO
  double result{};
  //  Metods
  double calc(const char *calculation_src, double X_num);
  stack_type parser_uno(const char *calculation_src, int *position,
                        double X_num);
  int prio_check(char src_string);
  int position_counter(char src_string);
  int buffering_number(const char *src_string, char *out);
  int bracket_finder(stack_type *oper);
  stack_type *del_point(stack_type *stack1);
  int unar_check(char check, const char *oper_st, int position);
  stack_type *push_sta(stack_type *plist, double val_dub, int prio);
  double math_operations(stack_type **num_sta, stack_type **oper_sta);
  void destroy_node(stack_type *stack1);
  double pop_val(stack_type **stack);
  double simple_math(double second_num, double first_num, char operation);
  double trigon_calc(double x, char operation);
  double start_calc(const char *src, double X_num);
  int validator(const char *str);
};
}  // namespace s21

#endif  // SRC_CALC_MODEL_H_