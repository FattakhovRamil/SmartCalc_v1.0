#include "s21_smartCalc.h"

int deposit_calc(double sum_vkald, int srok, double procent_stavka,
                 double nalog_stavka, int period_viplat, int capit_prosentov,
                 double spisok_poplneni, double spisok_cnaty,
                 double *nacislen_prosenty, double *sum_nalog, double *sum_end,
                 int spisok_poplneni_date, int spisok_cnaty_date) {
  double tmp = sum_vkald;
  double tmp_scet = 0;
  double capit_prosentov_tmp = 0;
  double period_viplat_sum = 0;
  *sum_nalog = 0;
  for (int i = 1; i <= srok; i++) {
    if (capit_prosentov == 1) {  // Капитализация процентов
      *nacislen_prosenty += tmp * procent_stavka / 100. / 12.;  // считаем доход
      *sum_nalog += tmp * (procent_stavka / 100. / 12.) *
                    (nalog_stavka / 100. / 12.);  // считаем налог
      tmp += tmp * procent_stavka / 100. / 12. -
             tmp * (procent_stavka / 100. / 12.) * (nalog_stavka / 100. / 12.);

      if (spisok_poplneni && fmod(i, spisok_poplneni_date) == 0) {
        tmp += spisok_poplneni;
      }

      if (spisok_cnaty && fmod(i, spisok_cnaty_date) == 0) {
        tmp -= spisok_cnaty;
      }
      if (fmod(i, period_viplat) == 0) {
        period_viplat_sum += tmp - sum_vkald;
        tmp = sum_vkald;
      }
    } else {
      // Простые проценты
      tmp_scet = sum_vkald * (procent_stavka / 100.) / 12.;  // доход процентый
      *sum_nalog += tmp_scet * (nalog_stavka / 100. / 12.);  // налог на доход
      if (spisok_poplneni) {
        sum_vkald += spisok_poplneni;
      }
      if (spisok_cnaty) {
        sum_vkald -= spisok_cnaty;
      }
      capit_prosentov_tmp += tmp_scet;
    }
  }
  if (capit_prosentov == 1) {
    if (period_viplat == 1 || period_viplat == 2 || period_viplat == 3) {
      *sum_end = tmp + period_viplat_sum;
    } else {
      *sum_end = tmp;
    }
  } else {
    *sum_end = sum_vkald + capit_prosentov_tmp - *sum_nalog;  // вычесть налог
    *nacislen_prosenty = capit_prosentov_tmp;
  }
  return 1;
}

int credit_calc_c(double total_payment, int term, int years_or_month,
                  double interest_rate, int type_of_loan,
                  double *separate_payment, double *separate_payment_1,
                  double *overpayment, double *total_payout) {
  // int flag = 0;
  double KA1 = 0;
  double KA2 = 0;
  double KA = 0;
  double EPS = 0;
  double b = 0;
  double total_payment_tmp = total_payment;
  EPS = interest_rate / 12 / 100;
  if (!years_or_month) {
    term = 12 * term;
  }
  if (type_of_loan) {                  // Диф
    b = total_payment / (term * 1.0);  // ежем часть платежа базовая
    for (int i = 0; i < term; i++) {
      if (i == 0) {
        *separate_payment = total_payment_tmp * EPS + b;
      }
      if (i + 1 == term) {
        *separate_payment_1 = total_payment_tmp * EPS + b;
      }
      *total_payout += b + (total_payment_tmp * EPS);  // общая выплата
      total_payment_tmp -= b;
    }
    *overpayment = *total_payout - total_payment;
  } else {  // aнну
    KA1 = EPS * pow((1 + EPS), term);
    KA2 = pow(1 + EPS, term) - 1;
    KA = KA1 / KA2;
    *separate_payment = (total_payment * KA);
    *separate_payment = round(*separate_payment * 100) / 100;
    *total_payout = *separate_payment * term;
    *total_payout = round(*total_payout * 100) / 100;
    *overpayment = *total_payout - total_payment;
    //*overpayment = round(*overpayment * 100) / 100;
  }
  *separate_payment = round(*separate_payment * 100) / 100;
  *total_payout = round(*total_payout * 100) / 100;
  //*overpayment = round(*overpayment * 100) / 100;
  return 1;
}

/// @brief проверка мат.выражения на корректность синтаксически (первичная
/// проверка)
/// @param input_string проверяемая строка
/// @return 0 - корректно, 1 - ошибка
int correct_string(char *input_string) {
  int flag = 0;
  int count_scobka_l = 0;
  int count_scobka_r = 0;

  int len = strlen(input_string);  // получаем длину строки
  if (len < 255) {
    for (int i = 0; i < len; i++) {
      if (is_number_or_x(input_string, i)) {  // проверка на число
        continue;
      } else if (is_char_math_opert(input_string, i)) {  // проверка на cos
                                                         // count_scobka_l++;
        i += is_char_math_opert(input_string, i);
        continue;
      } else if (is_bracket(input_string, i)) {  // проверка на скобки
        if (bracket_side(input_string, i)) {
          count_scobka_l += bracket_side_math(input_string, i + 1);
        } else {
          count_scobka_r += bracket_side_math(input_string, i + 1);
          if (is_number_or_x(input_string, i + 1)) {
            flag = 1;
          }
        }
        continue;
      } else if (is_mod(input_string, i)) {
        i += 2;
        continue;
      } else if (is_dot(input_string, i)) {
        continue;
      } else if (is_math_oper(input_string, i)) {  // проверка на  *, /, +, -
        continue;
      } else {
        flag = 1;
      }
    }
  }
  if (count_scobka_l != count_scobka_r) {
    flag = 1;
  }
  return flag;
}

/// @brief  проверка, является ли данный симовол мат оперцией '-' перед скобкой
/// или скобка '()' или '((' или '))'
/// @param input_string проверяемая строка
/// @param i начальная позиция проверяемой строки
/// @return 0 - не является, 1 - является
int bracket_side_math(char *input_string, int i) {
  int flag = 0;
  if ((int)strlen(input_string) != i || i != 0) {
    if (is_math_oper(input_string, i) || is_mod(input_string, i)) {
      if (!(bracket_side(input_string, i - 1))) {
        flag = 1;
      } else {
        if (input_string[i] == '-') {
          flag = 1;
        }
      }
    } else if (is_bracket(input_string, i)) {
      if (bracket_side(input_string, i - 1)) {
        if ((bracket_side(input_string, i - 1))) {
          flag = 1;
        }
      } else if (!(bracket_side(input_string, i - 1))) {
        if (!(bracket_side(input_string, i - 1))) {
          flag = 1;
        }
      } else {
        flag = 0;
      }
    } else {
      flag = 1;
    }
  }
  return flag;
}

/// @brief Удаляет пробелы в строке
/// @param str строка
void delete_space(char *str) {
  int i = 0;
  int j = 0;
  while (str[i]) {
    if (str[i] != ' ') {
      str[j++] = str[i];
    }
    i++;
  }
  str[j] = '\0';
}

/// @brief проверка, является ли данный симовол мат оперцией '*', '/', '+', '-',
/// '^'
/// @param tmp проверяемая строка
/// @param i начальная позиция проверяемой строки
/// @return 0 - не является, 1 - является
int is_math_oper(char *tmp, int i) {
  int flag = 0;
  if (tmp[i] == '*' || tmp[i] == '/' || tmp[i] == '+' || tmp[i] == '-' ||
      tmp[i] == '^') {
    if ((is_number_or_x(tmp, i + 1) || tmp[i + 1] == '(' ||
         is_char_math_opert(tmp, i + 1))) {
      flag = 1;
    }
  }
  return flag;
}

/// @brief проверка, является ли данный символ точкой '.'
/// @param tmp проверяемая строка
/// @param i начальная позиция проверяемой строки
/// @return 0 - не является, 1 - является
int is_dot(char *tmp, int i) {
  int flag = 0;
  if (tmp[i] == '.' && is_number_or_x(tmp, i - 1)) {
    flag = 1;
  }
  return flag;
}

/// @brief проверка, является ли данный отрезок строкой 'mod'
/// @param tmp проверяемая строка
/// @param i начальная позиция проверяемой строки
/// @return 0 - не является, 1 - является
int is_mod(char *tmp, int i) {
  int flag = 0;
  if (tmp[i] == 'm' && tmp[i + 1] == 'o' && tmp[i + 2] == 'd') {
    if ((is_number_or_x(tmp, i - 1) || tmp[i - 1] == ')' ||
         is_mod(tmp, i - 1)) &&
        (is_char_math_opert(tmp, i + 3) || is_number_or_x(tmp, i + 3) ||
         tmp[i + 3] == '(')) {
      flag = 1;
    }
  }
  return flag;
}

int is_mod_parse(char *tmp, int i) {
  int flag = 0;
  if (tmp[i] == 'm' && tmp[i + 1] == 'o' && tmp[i + 2] == 'd') {
    flag = 1;
  }
  return flag;
}

/// @brief  проверка, является ли данный символ '(' или ')'
/// @param tmp проверяемая строка
/// @param i позиция проверяемой строки
/// @return 0 - ')', 1 - '('
int bracket_side(char *tmp, int i) {
  int flag = 0;
  if (tmp[i] == '(') {
    flag = 1;
  }
  return flag;
}

/// @brief  проверка, является ли данный символ скобкой
/// @param tmp проверяемая строка
/// @param i позиция проверяемой строки
/// @return 0 - является, 1 - не является
int is_bracket(char *tmp, int i) {
  int flag = 0;
  if (tmp[i] == '(' || tmp[i] == ')') {
    flag = 1;
  }
  return flag;
}

/// @brief проверка, является ли данный символ цифрой, x, X
/// @param tmp проверяемая строка
/// @param i позиция проверяемой строки
/// @return 1 - является, 0 - не является
int is_number_or_x(char *tmp, int i) {
  int flag = 1;
  if (!((48 <= tmp[i] && tmp[i] <= 57) || tmp[i] == 'x' || tmp[i] == 'X')) {
    flag = 0;
  }
  if (flag == 1 && (tmp[i] == 'x' || tmp[i] == 'X')) {
    if ((48 <= tmp[i + 1] && tmp[i + 1] <= 57) ||
        (48 <= tmp[i - 1] && tmp[i - 1] <= 57)) {
      flag = 0;
    }
  }
  if (i > 0) {
    if (tmp[i - 1] == ')' && flag == 1) {
      flag = 0;
    }
  }
  return flag;
}

/// @brief проверка, является ли данный отрезок sin(, sqrt(, cos(, tan(, ln(,
/// log(
/// @param tmp проверяемая строка
/// @param i начальная позиция проверяемой строки
/// @return 0 - не является,  N -  является и кол-во символов сдвига
int is_char_math_opert(char *tmp, int i) {
  int flag = 0;
  if (tmp[i] == 's') {
    if (tmp[i + 1] == 'i' && tmp[i + 2] == 'n' && tmp[i + 3] == '(') {  // sin(
      flag += 2;
    } else if (tmp[i + 1] == 'q' && tmp[i + 2] == 'r' && tmp[i + 3] == 't' &&
               tmp[i + 4] == '(') {  // sqrt(
      flag += 3;
    }
  } else if (tmp[i] == 'c' && tmp[i + 1] == 'o' && tmp[i + 2] == 's' &&
             tmp[i + 3] == '(') {  // cos(
    flag += 2;
  } else if (tmp[i] == 't' && tmp[i + 1] == 'a' && tmp[i + 2] == 'n' &&
             tmp[i + 3] == '(') {  // tan(
    flag += 2;
  } else if (tmp[i] == 'l') {
    if (tmp[i + 1] == 'n' && tmp[i + 2] == '(') {  // ln(
      flag += 1;
    } else if (tmp[i + 1] == 'o' && tmp[i + 2] == 'g' &&
               tmp[i + 3] == '(') {  // log(
      flag += 2;
    }
  } else if (tmp[i] == 'a') {
    flag += (is_char_math_opert(tmp, i + 1)) + 1;
  }
  if (flag == 1 && tmp[i] != 'l') {
    flag = 0;
  }
  return flag;
}

/// @brief получает строку и заполняет стек элементами мат.функциями
/// @param tmp строка, в которой ищутся
/// @param i порядковый номер символа
/// @param stack заполняемый стек
/// @return смещение i
int is_char_math_opert_parser(char *tmp, int i, N **stack) {
  int flag = 0;
  if (tmp[i] == 's' && tmp[i + 1] == 'i' && tmp[i + 2] == 'n') {  // sin(
    push_back(stack, 0, 4, sin_v);
    flag += 3;
  } else if (tmp[i] == 's' && tmp[i + 1] == 'q' && tmp[i + 2] == 'r' &&
             tmp[i + 3] == 't') {  // sqrt
    push_back(stack, 0, 4, sqrt_v);
    flag += 4;
  } else if (tmp[i] == 'c' && tmp[i + 1] == 'o' && tmp[i + 2] == 's') {  // cos(
    push_back(stack, 0, 4, cos_v);
    flag += 3;
  } else if (tmp[i] == 't' && tmp[i + 1] == 'a' && tmp[i + 2] == 'n') {  // tan(
    push_back(stack, 0, 4, tan_v);
    flag += 3;
  } else if (tmp[i] == 'l') {
    if (tmp[i + 1] == 'n') {  // ln(
      push_back(stack, 0, 4, ln_v);
      flag += 2;
    } else if (tmp[i + 1] == 'o' && tmp[i + 2] == 'g') {  // log(
      push_back(stack, 0, 4, log_v);
      flag += 3;
    }
  } else if (tmp[i] == 'a' && tmp[i + 1] == 's' && tmp[i + 2] == 'i' &&
             tmp[i + 3] == 'n') {  // asin
    push_back(stack, 0, 4, asin_v);
    flag += 4;
  } else if (tmp[i] == 'a' && tmp[i + 1] == 'c' && tmp[i + 2] == 'o' &&
             tmp[i + 3] == 's') {  // acos
    push_back(stack, 0, 4, acos_v);
    flag += 4;
  } else if (tmp[i] == 'a' && tmp[i + 1] == 't' && tmp[i + 2] == 'a' &&
             tmp[i + 3] == 'n') {
    push_back(stack, 0, 4, atan_v);
    flag += 4;
  }
  return flag;
}

/// @brief  Создает узел/элемент списка
/// @param value значение
/// @param priority приоритет
/// @param type_v тип
/// @return созданный, заполненный узел
N *create_node(double value, int priority, int type_v) {
  N *node = (N *)malloc(sizeof(N));
  if (node != NULL) {
    node->value = value;
    node->priority = priority;
    node->type_v = type_v;
    node->next = NULL;
  } else {
  }

  return node;
}

/// @brief Добавляет элемент в конец стека
/// @param stack стек, в который добавляем элемент
/// @param value значение
/// @param priority приоритет
/// @param type_v тип
void push_back(N **stack, double value, int priority, int type_v) {
  N *new_node = create_node(value, priority, type_v);

  N *tmp =
      *stack;  // копия на указатель, чтоб не потерять оригинальный указатель

  while (tmp->next != NULL) {
    tmp = tmp->next;
  }

  tmp->next = new_node;
}

/// @brief
/// @param stack
/// @param value
/// @param priority
/// @param type_v
void push_front(N **stack, double value, int priority,
                int type_v) {  // добавляет элемент в начало стека
  N *new_node = create_node(value, priority, type_v);
  new_node->next = *stack;
  *stack = new_node;
}

/// @brief разделение строки на лексемы
/// @param stack запись в стек
/// @param str строка, с которой ведётся запись
/// @param x подставляет x вместо нуля
/// @return 0 - корректно выполнено, 1 - ошибка
int parser_string(N **stack, char *str, double x) {  //  записываю в очередь
  int flag = 0, j = 0, count_br_l = 0, count_br_r = 0, dot_counter = 0;
  char num[255] = "";
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_number_or_x(str, i)) {
      if (str[i] == 'X' || str[i] == 'x') {
        push_back(stack, x, 0, num_v);
      } else {
        while (is_number_or_x(str, i) || is_dot(str, i)) {
          dot_counter += is_dot(str, i);
          num[j] = str[i];
          i++, j++;
        }
        if (dot_counter > 1) {
          flag = 1;
        }
        j = 0, i--;
        push_back(stack, atof(num), 0, num_v);
        memset(num, 0, sizeof(num));
        dot_counter = 0;
      }
    } else if (is_math_oper(str, i)) {
      plus_push(stack, str, i);
    } else if (is_mod_parse(str, i)) {
      push_back(stack, 0, 2, mod_v);
      i += 2;
    } else if (is_char_math_opert(str, i)) {
      i += is_char_math_opert_parser(str, i, stack);
      i--;
    } else if (is_bracket(str, i)) {  // скобки
      if (str[i] == '(') {
        push_back(stack, 0, 5, l_br_v);
        count_br_l++;
      } else {
        push_back(stack, 0, 5, r_br_v);
        count_br_l--;
      }
    } else {
      continue;
    }
  }
  if (count_br_l != count_br_r) {
    flag = 1;
  }
  return flag;
}

/// @brief Добавляет элементы в структуру мат. операции
/// @param stack запись в стек
/// @param str строка, с которой ведётся запись
/// @param i номер элемента строки
void plus_push(N **stack, char *str, int i) {
  if (str[i] == '+') {
    push_back(stack, 0, 1, plus_v);
  } else if (str[i] == '-') {
    push_back(stack, 0, 1, minus_v);
  } else if (str[i] == '*') {
    push_back(stack, 0, 2, umn_v);
  } else if (str[i] == '/') {
    push_back(stack, 0, 2, del_v);
  } else if (str[i] == '^') {  // исправить на степень
    push_back(stack, 0, 3, step_v);
  }
}

/// @brief удаляет элемент из стека в начале
/// @param stack стек
void pop_front(N **stack) {
  N *tmp = {0};
  if (*stack != NULL) {
    tmp = (*stack)->next;
    free(*stack);
    *stack = tmp;
  }
}

/// @brief смотрит тип элемента структуры
/// @param stack структура на которую смотрим
/// @return значение типа
int pick_type(N **stack) { return (*stack)->type_v; }
int pick_type_next(N **stack) { return (*stack)->next->type_v; }

int pick_type_back(N **stack) {
  int type = 0;
  N *tmp = (*stack);
  while ((*stack)->next != NULL) {
    *stack = (*stack)->next;
  }
  type = pick_type(stack);
  (*stack) = tmp;
  return type;
}
/// @brief смотрит приоритет элемента структуры
/// @param stack структура на которую смотрим
/// @return значение приоритет
int pick_priority(N **stack) { return (*stack)->priority; }

/// @brief пушит элемент из одной структуры в другую
/// @param stack из этой струкутры пушим
/// @param stack_ready добавляем элемент в конец
void push_in_stack(N **stack, N **stack_ready) {
  push_back(stack_ready, (*stack)->value, (*stack)->priority, (*stack)->type_v);
}

/// @brief пушит элемент из одной структуры в другую
/// @param stack из этой струкутры пушим
/// @param stack_ready добавляем элемент в начало
void push_in_stack_front(N **stack, N **stack_ready) {
  push_front(stack_ready, (*stack)->value, (*stack)->priority,
             (*stack)->type_v);
}

// /// @brief Реализует логику перевода в ОПН
// /// @param stack считываемая структура
// /// @param priority_cor приоритет
// /// @param stack_ready запись в эту структуру
// /// @param stack_helper вспомагательная структура для мат.выражений
// /// @param count_l_br счетчик левых скобок
// void reverse_polish_notation_while(N **stack, int priority_cor, N
// **stack_ready,
//                                    N **stack_helper, int count_l_br) {
//   while ((*stack) != NULL) {
//     priority_cor = pick_priority(stack);  // берем приоритет в стеке
//     if (priority_cor == 0 &&
//         pick_type(stack) != nothing_v) {  // добавляем числа и x в ready
//       push_in_stack(stack, stack_ready);
//     } else if ((((priority_cor >= pick_priority(stack_helper) &&
//                   pick_type(stack) != nothing_v &&
//                   pick_type(stack) != r_br_v) ||
//                  (pick_type(stack_helper) == l_br_v)) &&
//                 pick_type(stack) !=
//                     r_br_v)) {  // если приоритет в helper меньше
//       // равно, то добавляю
//       if (pick_type(stack) == l_br_v) {
//         count_l_br++;
//       }
//       if (pick_priority(stack_helper) == pick_priority(stack) &&
//           pick_priority(stack) != 5 && pick_priority(stack_helper) != 3) {
//         push_in_stack(stack_helper, stack_ready);
//         pop_front(stack_helper);
//       }
//       if (pick_type(stack_helper) == l_br_v && pick_type(stack) == minus_v &&
//           pick_type_next(stack) == num_v &&
//           !(pick_type_back(stack_ready) == 1 ||
//             pick_type_back(stack_ready) == 2 ||
//             pick_type_back(stack_ready) == 3)) {
//         pop_front(stack);
//         (*stack)->value = -(*stack)->value;
//         continue;
//       } else if (pick_type(stack_helper) == l_br_v &&
//                  pick_type(stack) == plus_v && pick_type_next(stack) == num_v
//                  &&
//                  !(pick_type_back(stack_ready) == 1 ||
//                    pick_type_back(stack_ready) == 2 ||
//                    pick_type_back(stack_ready) == 3)) {
//         pop_front(stack);
//       }
//       push_in_stack_front(stack, stack_helper);
//     } else if (priority_cor < pick_priority(stack_helper) &&
//                stack_helper != NULL &&
//                pick_priority(stack_helper) !=
//                    5) {  // если текущий элемент ниже по приоритету то,
//       while (priority_cor < pick_priority(stack_helper) &&
//              (*stack_helper)->next != NULL &&
//              (*stack_helper)->type_v != nothing_v &&
//              pick_priority(stack_helper) !=
//                  5) {  // добавить случай, приоритет != 5 и дописать доп
//                        // условие, если 5,
//         push_in_stack(stack_helper, stack_ready);  // перекидываем в ready
//         pop_front(stack_helper);  //  удалеяем из helper
//       }
//       push_in_stack_front(stack, stack_helper);  // добавляем в helper
//     } else if (pick_type(stack) == r_br_v) {
//       while (pick_priority(stack_helper) < 5 &&
//              (*stack_helper)->next != NULL &&  // мбм ьуь ошибка с л скобкой
//              (*stack_helper)->type_v !=
//                  nothing_v) {  // добавить случай, приоритет != 5 и дописать
//                  доп
//                                // условие, если 5,
//         push_in_stack(stack_helper, stack_ready);  // перекидываем в ready
//         pop_front(stack_helper);  //  удалеяем из helper
//       }
//       pop_front(stack_helper);  //  удалеяем из helper
//     }

//     pop_front(stack);
//   }
// }

void reverse_polish_notation_while(N **stack, int priority_cor, N **stack_ready,
                                   N **stack_helper, int count_l_br) {
  while ((*stack) != NULL) {
    priority_cor = pick_priority(stack);

    if (priority_cor == 0 && pick_type(stack) != nothing_v) {
      process_numbers_and_variables(stack, stack_ready);
    }

    else if ((((priority_cor >= pick_priority(stack_helper) &&
                pick_type(stack) != nothing_v && pick_type(stack) != r_br_v) ||
               (pick_type(stack_helper) == l_br_v)) &&
              pick_type(stack) != r_br_v)) {
      process_operations_with_stack_helper(stack, stack_ready, stack_helper,
                                           &count_l_br);
    }

    else if (priority_cor < pick_priority(stack_helper) &&
             stack_helper != NULL && pick_priority(stack_helper) != 5) {
      process_operations_with_lower_priority(stack, stack_helper, stack_ready,
                                             priority_cor);
    }

    else if (pick_type(stack) == r_br_v) {
      process_closing_bracket(stack_helper, stack_ready);
    }

    pop_front(stack);
  }
}

void process_numbers_and_variables(N **stack, N **stack_ready) {
  push_in_stack(stack, stack_ready);
}

void process_operations_with_stack_helper(N **stack, N **stack_ready,
                                          N **stack_helper, int *count_l_br) {
  if (pick_type(stack) == l_br_v) {
    (*count_l_br)++;
  }

  if (pick_priority(stack_helper) == pick_priority(stack) &&
      pick_priority(stack) != 5 && pick_priority(stack_helper) != 3) {
    push_in_stack(stack_helper, stack_ready);
    pop_front(stack_helper);
  }

  if (pick_type(stack_helper) == l_br_v && pick_type(stack) == minus_v &&
      pick_type_next(stack) == num_v &&
      !(pick_type_back(stack_ready) == 1 || pick_type_back(stack_ready) == 2 ||
        pick_type_back(stack_ready) == 3)) {
    pop_front(stack);
    (*stack)->value = -(*stack)->value;
    return;
  }

  else if (pick_type(stack_helper) == l_br_v && pick_type(stack) == plus_v &&
           pick_type_next(stack) == num_v &&
           !(pick_type_back(stack_ready) == 1 ||
             pick_type_back(stack_ready) == 2 ||
             pick_type_back(stack_ready) == 3)) {
    pop_front(stack);
  }

  push_in_stack_front(stack, stack_helper);
}

void process_operations_with_lower_priority(N **stack, N **stack_helper,
                                            N **stack_ready, int priority_cor) {
  while (priority_cor < pick_priority(stack_helper) &&
         (*stack_helper)->next != NULL &&
         (*stack_helper)->type_v != nothing_v &&
         pick_priority(stack_helper) != 5) {
    push_in_stack(stack_helper, stack_ready);
    pop_front(stack_helper);
  }

  push_in_stack_front(stack, stack_helper);
}

void process_closing_bracket(N **stack_helper, N **stack_ready) {
  while (pick_priority(stack_helper) < 5 && (*stack_helper)->next != NULL &&
         (*stack_helper)->type_v != nothing_v) {
    push_in_stack(stack_helper, stack_ready);
    pop_front(stack_helper);
  }

  pop_front(stack_helper);
}

/// @brief исходя из stack формирует обратную польскую нотацию и записывает в
/// stack_ready
/// @param stack считываемый стек
/// @param stack_ready стек, в который записывается ОПН
void reverse_polish_notation(N **stack, N **stack_ready) {
  int priority_cor = 0;
  N *stack_helper = create_node(0, -7, nothing_v);
  int count_l_br = 0;

  push_front(stack_ready, 0, 0, exception);

  reverse_polish_notation_while(stack, priority_cor, stack_ready, &stack_helper,
                                count_l_br);

  pushing_from_helper(&stack_helper, stack_ready);
}

void pushing_from_helper(N **stack_helper, N **stack_ready) {
  while ((*stack_helper) != NULL) {
    if (pick_type(stack_helper) != 20) {
      push_in_stack(stack_helper, stack_ready);  // утечка
    }
    pop_front(stack_helper);
  }
  // pop_front(stack_helper);
}

double calculate_two_elements(double first_element, double second_element,
                              int math_type) {
  double ansver = 0;

  if (math_type == plus_v) {
    ansver = first_element + second_element;
  } else if (math_type == minus_v) {
    ansver = first_element - second_element;
  } else if (math_type == del_v) {
    ansver = first_element / second_element;
  } else if (math_type == umn_v) {
    ansver = first_element * second_element;
  } else if (math_type == step_v) {
    ansver = pow(first_element, second_element);
  } else if (math_type == mod_v) {
    ansver = fmod(first_element, second_element);
  } else if (math_type == nothing_v) {
  } else {
  }
  return ansver;
}

double calculate_one_elements(double first_element, int math_type) {
  double ansver = 0;
  if (math_type == cos_v) {
    ansver = cos(first_element);
  } else if (math_type == sin_v) {
    ansver = sin(first_element);
  } else if (math_type == tan_v) {
    ansver = tan(first_element);
  } else if (math_type == acos_v) {
    ansver = acos(first_element);  // убрал градусы
  } else if (math_type == asin_v) {
    ansver = asin(first_element);
  } else if (math_type == atan_v) {
    ansver = atan(first_element);
  } else if (math_type == sqrt_v) {
    ansver = sqrt(first_element);
  } else if (math_type == ln_v) {
    ansver = log(first_element);
  } else if (math_type == log_v) {
    ansver = log10(first_element);
  } else if (math_type == minus_v) {
    ansver = -(first_element);
  } else if (math_type == plus_v) {
    ansver = (first_element);
  }
  return ansver;
}

int is_math_oper_one(N **stack_ready) {
  int flag = 0;
  if ((*stack_ready)->type_v > 8) {
    flag = 1;
  }
  return flag;
}

int calculate(N **stack_ready, double *ansver) {
  N *tmp = (*stack_ready);
  double first_element = 0, second_element = 0;
  int math_type = 0, flag_break = 0, flag = 1;
  while ((flag_break == 0 && (*stack_ready)->next != NULL)) {
    if ((*stack_ready)->next->type_v != 0 &&
        (*stack_ready)->next->type_v != 1 &&
        (*stack_ready)->next->type_v != 2) {
      if ((is_math_oper_one(&(*stack_ready)->next) &&
           ((*stack_ready)->next->type_v) != 21)) {
        first_element = (*stack_ready)->value;
        math_type = (*stack_ready)->next->type_v;
        *ansver = calculate_one_elements(first_element, math_type);
        pop_front(&(*stack_ready)->next);
        (*stack_ready)->value = *ansver;
        continue;
      } else {
        (*stack_ready) = tmp;
        continue;
      }
    } else if ((*stack_ready)->type_v == exception &&
               (*stack_ready)->next->next == NULL) {
      *ansver = (*stack_ready)->next->value;
      (*stack_ready) = (*stack_ready)->next->next;
      flag_break++;
      continue;
    } else if ((*stack_ready)->type_v == exception &&
               (*stack_ready)->next->priority == 0 &&
               (*stack_ready)->next->next->priority == 0 &&
               (*stack_ready)->next->next->next == NULL) {
      flag = 0;
      flag_break++;
    } else if ((*stack_ready)->next->next->type_v != 0 &&
               (*stack_ready)->next->next->type_v != 1 &&
               (*stack_ready)->next->next->type_v != 2) {
      if (is_math_oper_one(&(*stack_ready)->next->next)) {
        first_element = (*stack_ready)->next->value;
        math_type = (*stack_ready)->next->next->type_v;
        *ansver = calculate_one_elements(first_element, math_type);
        pop_front(&(*stack_ready)->next->next);
        (*stack_ready)->next->value = *ansver;
        continue;
      } else {
        first_element = (*stack_ready)->value;
        second_element = (*stack_ready)->next->value;
        math_type = (*stack_ready)->next->next->type_v;
        *ansver =
            calculate_two_elements(first_element, second_element, math_type);
        pop_front(&(*stack_ready)->next);
        pop_front(&(*stack_ready)->next);
        (*stack_ready)->value = *ansver;
        continue;
      }
    } else {
      (*stack_ready) = (*stack_ready)->next;
    }
  }
  while (tmp->next != NULL) {
    *stack_ready = tmp->next;
    free(tmp);
    tmp = *stack_ready;
  }
  free(tmp);
  return flag;
}

void clear_plus(char *str) {
  int i = 0;
  int j = 0;
  int k = 1;
  while (str[i]) {
    if (str[i + 1] == '+' && str[i] == '(') {
      str[j + k] = str[i];
      i += 1;
      k++;
      continue;
    }
    str[j++] = str[i];
    i++;
  }
  str[j] = '\0';
}

int calcul(char str[255], double x, double *ansver_qt) {
  int flag = 0;
  clear_plus(str);
  delete_space(str);
  N *stack = create_node(0, 0, 20);
  N *stack_ready = create_node(0, 0, 20);
  double ansver = 0;
  if (correct_string(str)) {
    flag = 1;
    free(stack);
    free(stack_ready);
  } else {
    if (!(parser_string(&stack, str, x))) {
      reverse_polish_notation(&stack, &stack_ready);
      if (calculate(&stack_ready, &ansver)) {
      } else {
        flag = 1;
      }
    } else {
      N *tmp = stack;
      while (tmp->next != NULL) {
        stack = tmp->next;
        free(tmp);
        tmp = stack;
      }
      free(tmp);
      N *tmp_1 = stack_ready;
      while (tmp_1->next != NULL) {
        stack_ready = tmp_1->next;
        free(tmp_1);
        tmp_1 = stack_ready;
      }
      free(tmp_1);
      flag = 1;
    }
  }
  *ansver_qt = ansver;
  return flag;
}