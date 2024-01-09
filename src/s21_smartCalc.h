#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/// @brief структура для определения типа лексемы
typedef enum type {
  x_v = 0,
  X_v = 1,      // икс
  num_v = 2,    // число
  plus_v = 3,   // +
  minus_v = 4,  // -
  del_v = 5,    // /
  umn_v = 6,    // *
  step_v = 7,   // ^
  mod_v = 8,
  cos_v = 9,
  sin_v = 10,
  tan_v = 11,
  acos_v = 12,
  asin_v = 13,
  atan_v = 14,
  sqrt_v = 15,
  ln_v = 16,
  log_v = 17,
  l_br_v = 18,
  r_br_v = 19,
  nothing_v = 20,
  exception = 21,  //  ничего
} type_t;

/// @brief структура для определения лексемы, его значенияЮ приоритета,
/// указателя на след. узел и тип
typedef struct N {
  double value;
  int priority;
  type_t type_v;
  struct N *next;
} N;

void process_numbers_and_variables(N **stack, N **stack_ready);

void process_operations_with_stack_helper(N **stack, N **stack_ready,
                                          N **stack_helper, int *count_l_br);

void process_operations_with_lower_priority(N **stack, N **stack_helper,
                                            N **stack_ready, int priority_cor);

void reverse_polish_notation_while(N **stack, int priority_cor, N **stack_ready,
                                   N **stack_helper, int count_l_br);

void process_numbers_and_variables(N **stack, N **stack_ready);

void process_operations_with_stack_helper(N **stack, N **stack_ready,
                                          N **stack_helper, int *count_l_br);

void process_operations_with_lower_priority(N **stack, N **stack_helper,
                                            N **stack_ready, int priority_cor);

void process_closing_bracket(N **stack_helper, N **stack_ready);

// #define S21_NULL (void *)0;

void clear_plus(char *str);
void delete_space(char *str);
int correct_string(char *input_string);
int is_math_oper(char *tmp, int i);
int is_dot(char *tmp, int i);
int is_mod(char *tmp, int i);
int bracket_side(char *tmp, int i);
int is_bracket(char *tmp, int i);
int is_number_or_x(char *tmp, int i);
int is_char_math_opert(char *tmp, int i);
int bracket_side_math(char *input_string, int i);

int is_mod_parse(char *tmp, int i);
int is_math_oper_parser(char *tmp, int i);
int is_char_math_opert_parser(char *tmp, int i, N **stack);
N *create_node(double value, int priority, int type_v);
void push_back(N **list, double value, int priority, int type_v);
void pop(N **stack);
void pop_front(N **stack);
int pick(N **stack);
void plus_push(N **stack, char *str, int i);
int pick_priority(N **stack);
int pick_type(N **stack);

void push_in_stack(N **stack, N **stack_ready);
void push_in_stack_front(N **stack, N **stack_ready);
void pushing_from_helper(N **stack_helper, N **stack_ready);

void del_node_back(N **stack);

void push_front(N **stack, double value, int priority, int type_v);
void revers_stack(N *stack);
int parser_string(N **stack, char *str, double x);
void reverse_polish_notation(N **stack, N **stack_ready);

int calculate(N **stack_ready, double *ansver);
int is_math_oper_one(N **stack_ready);
double calculate_one_elements(double first_element, int math_type);
double calculate_two_elements(double first_element, double second_element,
                              int math_type);
int calcul(char str[255], double x, double *ansver_qt);

int credit_calc_c(double total_payment, int term, int years_or_month,
                  double interest_rate, int type_of_loan,
                  double *separate_payment, double *separate_payment_1,
                  double *overpayment, double *total_payout);

int deposit_calc(double sum_vkald, int srok, double procent_stavka,
                 double nalog_stavka, int period_viplat, int capit_prosentov,
                 double spisok_poplneni, double spisok_cnaty,
                 double *nacislen_prosenty, double *sum_nalog, double *sum_end,
                 int spisok_poplneni_date, int spisok_cnaty_date);
#endif  // SRC_S21_SMARTCALC_H_
