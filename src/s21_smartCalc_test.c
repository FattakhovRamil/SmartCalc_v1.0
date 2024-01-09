// #include "s21_smartCalc_1.h"
#include "s21_smartCalc.h"

#include <check.h>

START_TEST(is_char_math_opert_0) {
  char *str = "1+2*10^30+ln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_char_math_opert(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 1);
}

START_TEST(is_char_math_opert_1) {
  char *str = "1+2*10^30-cos(3)-ln(";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_char_math_opert(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 2);
}

START_TEST(is_char_math_opert_2) {
  char *str = "1sin(20) + sin(30)+ln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_char_math_opert(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 3);
}

START_TEST(is_char_math_opert_3) {
  char *str = "1+2*1*log(10)0^30+ln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_char_math_opert(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 2);
}

START_TEST(is_char_math_opert_4) {
  char *str = "1+2*10^sqrt(2)+ln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_char_math_opert(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 2);
}

START_TEST(is_char_math_opert_5) {
  char *str = "15 + acos(30)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_char_math_opert(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 2);
}

START_TEST(is_char_math_opert_6) {
  char *str = "1+acos(30)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_char_math_opert(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 2);
}
END_TEST

START_TEST(is_number_or_x_0) {
  char *str = "1+2*10^30+ln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_number_or_x(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 8);
}

START_TEST(is_number_or_x_1) {
  char *str = "1+2*10^30-cos(3)-ln(";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_number_or_x(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 7);
}

START_TEST(is_number_or_x_2) {
  char *str = "1sin(20) + sin(30)+ln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_number_or_x(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 7);
}

START_TEST(is_number_or_x_3) {
  char *str = "1+2*1*x*log(10)0^30+ln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_number_or_x(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 10);
}

START_TEST(is_number_or_x_4) {
  char *str = "sqrt(2)+ln(10)*X";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_number_or_x(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 4);
}

START_TEST(is_number_or_x_5) {
  char *str = "15 + acos(30)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_number_or_x(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 4);
}

START_TEST(is_number_or_x_6) {
  char *str = "1+acos(30)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_number_or_x(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 3);
}
END_TEST

START_TEST(is_bracket_0) {
  char *str = "1+2*10^30+ln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_bracket(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 2);
}

START_TEST(is_bracket_1) {
  char *str = "1+2*10^30-cos(3)-ln(";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_bracket(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 3);
}

START_TEST(is_bracket_2) {
  char *str = "1sin(20) + sin(30)+ln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_bracket(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 6);
}

START_TEST(is_bracket_3) {
  char *str = "1+2*1*x*log(10)0^30+ln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_bracket(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 4);
}

START_TEST(is_bracket_4) {
  char *str = "sqrt(2)+ln(10)*X";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_bracket(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 4);
}

START_TEST(is_bracket_5) {
  char *str = "15 + acos(30)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_bracket(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 2);
}

START_TEST(is_bracket_6) {
  char *str = "1+acos(30)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_bracket(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 2);
}
END_TEST

START_TEST(is_mod_0) {
  char *str = "1+2*10mod30+ln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_mod(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 1);
}

START_TEST(is_mod_1) {
  char *str = "1+2*10^30-cos(3)-ln(";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_mod(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 0);
}

START_TEST(is_mod_2) {
  char *str = "1sin(20)mod + sin(30)+ln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_mod(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 0);
}

START_TEST(is_mod_3) {
  char *str = "1+2*1*x*log(10)0^30modln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_mod(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 1);
}

START_TEST(is_mod_4) {
  char *str = "sqrt(2)mod3+4modln(10)*X";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_mod(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 2);
}

START_TEST(is_mod_5) {
  char *str = "15mod + acos(30)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_mod(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 0);
}

START_TEST(is_mod_6) {
  char *str = "1+acos(30)modmod5";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_mod(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 0);
}
END_TEST

START_TEST(is_dot_0) {
  char *str = "1+2*10mod30+ln(1.0)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_dot(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 1);
}

START_TEST(is_dot_1) {
  char *str = "1+2.*1/0^30-cos(3)-ln(";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_dot(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 1);
}

START_TEST(is_dot_2) {
  char *str = "1sin(20)mod + sin(30)+10.5+ln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_dot(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 1);
}

START_TEST(is_dot_3) {
  char *str = "1+2*1*x*log(10)0^30modln(10)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_dot(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 0);
}

START_TEST(is_dot_4) {
  char *str = "sqrt(2).mod3+4modln(10)*X";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_dot(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 0);
}

START_TEST(is_dot_5) {
  char *str = "15mod + acos(30.)";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_dot(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 1);
}

START_TEST(is_dot_6) {
  char *str = "1+.acos(30)modmod5";
  int flag = 0;
  for (int i = 0; i < (int)(strlen(str)); i++) {
    if (is_dot(str, i)) {
      flag += 1;
    }
  }
  ck_assert_int_eq(flag, 0);
}
END_TEST

// TODO delete_space_tests

START_TEST(delete_space_0) {
  char str[255] = "1+2*1 0mod30+ln(1.0)";
  char str1[255] = "1+2*10mod30+ln(1.0)";
  int flag = 0;

  delete_space(str);
  flag = strcmp(str, str1);
  ck_assert_int_eq(flag, 0);
}

START_TEST(delete_space_1) {
  char str[255] = "1 + 2 * 10 mod30 + ln(1.0) ";
  char str1[255] = "1+2*10mod30+ln(1.0)";
  int flag = 0;

  delete_space(str);
  flag = strcmp(str, str1);
  ck_assert_int_eq(flag, 0);
}

START_TEST(delete_space_2) {
  char str[255] = "1+2* 10 mod 30+ln(1.0) ";
  char str1[255] = "1+2*10mod30+ln(1.0)";
  int flag = 0;

  delete_space(str);
  flag = strcmp(str, str1);
  ck_assert_int_eq(flag, 0);
}

START_TEST(delete_space_3) {
  char str[255] = " 1+2*1 0mod30+l n ( 1 . 0) ";
  char str1[255] = "1+2*10mod30+ln(1.0)";
  int flag = 0;

  delete_space(str);
  flag = strcmp(str, str1);
  ck_assert_int_eq(flag, 0);
}

START_TEST(delete_space_4) {
  char str[255] = "1+2*1 0mod30 +ln(1.0)";
  char str1[255] = "1+2*10mod30+ln(1.0)";
  int flag = 0;

  delete_space(str);
  flag = strcmp(str, str1);
  ck_assert_int_eq(flag, 0);
}

START_TEST(delete_space_5) {
  char str[255] = "1+2*1 0 mod30 +l n    (1.0)";
  char str1[255] = "1+2*10mod30+ln(1.0)";
  int flag = 0;

  delete_space(str);

  flag = strcmp(str, str1);
  ck_assert_int_eq(flag, 0);
}

START_TEST(delete_space_6) {
  char str[255] = "1+ 2*1 0m o   d30+l    n( 1.0 )";
  char str1[255] = "1+2*10mod30+ln(1.0)";
  int flag = 0;

  delete_space(str);
  flag = strcmp(str, str1);
  ck_assert_int_eq(flag, 0);
}
END_TEST

// TODO is_math_oper_test

START_TEST(is_math_oper_0) {
  char *str = "1+2*10mod30+ln(1.0)";
  int flag = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_math_oper(str, i)) {
      flag++;
    }
  }
  ck_assert_int_eq(flag, 3);
}

START_TEST(is_math_oper_1) {
  char *str = "1+2-*10mod30+ln(1.0)";
  int flag = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_math_oper(str, i)) {
      flag++;
    }
  }
  ck_assert_int_eq(flag, 3);
}

START_TEST(is_math_oper_2) {
  char *str = "1+2*10mod30+ln(1.0)";
  int flag = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_math_oper(str, i)) {
      flag++;
    }
  }
  ck_assert_int_eq(flag, 3);
}

START_TEST(is_math_oper_3) {
  char *str = "1+2+3";
  int flag = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_math_oper(str, i)) {
      flag++;
    }
  }
  ck_assert_int_eq(flag, 2);
}

START_TEST(is_math_oper_4) {
  char *str = "10^3";
  int flag = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_math_oper(str, i)) {
      flag++;
    }
  }
  ck_assert_int_eq(flag, 1);
}

START_TEST(is_math_oper_5) {
  char *str = "(10+20)*30*x*x*x^cos(30)";
  int flag = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_math_oper(str, i)) {
      flag++;
    }
  }
  ck_assert_int_eq(flag, 6);
}

START_TEST(is_math_oper_6) {
  char *str = "x**x^cos(30)";
  int flag = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_math_oper(str, i)) {
      flag++;
    }
  }
  ck_assert_int_eq(flag, 2);
}
END_TEST

// TODO correct_string_tests

START_TEST(correct_string_0) {
  char *str = "1+2*10mod30+ln(1.0)";
  ck_assert_int_eq(correct_string(str), 0);
}

START_TEST(correct_string_1) {
  char *str = "1+2+3*x";
  ck_assert_int_eq(correct_string(str), 0);
}

START_TEST(correct_string_2) {
  char *str = "1+2*10mod30+ln(1.0)";
  ck_assert_int_eq(correct_string(str), 0);
}

START_TEST(correct_string_3) {
  char *str = "1+2*10mod30+ln(1.0)";
  ck_assert_int_eq(correct_string(str), 0);
}

START_TEST(correct_string_4) {
  char *str = "1+2*10mod30+ln(1.0)";
  ck_assert_int_eq(correct_string(str), 0);
}

START_TEST(correct_string_5) {
  char *str = "1+2*10mod30+ln(1.0)";
  ck_assert_int_eq(correct_string(str), 0);
}

START_TEST(correct_string_6) {
  char *str = "-1";
  ck_assert_int_eq(correct_string(str), 0);
}
END_TEST
///  Доп.тесты
START_TEST(correct_string_7) {  // некорректный символ
  char *str = "p+10 - 10";
  ck_assert_int_eq(correct_string(str), 1);
}
END_TEST

START_TEST(correct_string_8) {
  char *str = "son(50)+5";
  ck_assert_int_eq(correct_string(str), 1);
}
END_TEST

START_TEST(correct_string_9) {
  char *str = "sin()";
  ck_assert_int_eq(correct_string(str), 0);
}
END_TEST

START_TEST(correct_string_10) {
  char *str = "-1";
  ck_assert_int_eq(correct_string(str), 0);
}
END_TEST

START_TEST(correct_string_11) {
  char *str = "-1";
  ck_assert_int_eq(correct_string(str), 0);
}
END_TEST

START_TEST(correct_string_12) {
  char *str = "-1";
  ck_assert_int_eq(correct_string(str), 0);
}
END_TEST

// TODO bracket_side_tests

START_TEST(bracket_side_0) {
  char *str = "1+2*10mod30+ln(1.0)";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (bracket_side(str, i)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 1);
}

START_TEST(bracket_side_1) {
  char *str = "((1+2+3)*x)";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (bracket_side(str, i)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 2);
}

START_TEST(bracket_side_2) {
  char *str = "1+2*10mod30";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (bracket_side(str, 0)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 0);
}

START_TEST(bracket_side_3) {
  char *str = ")1+2*))";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_bracket(str, i)) {
      if (!(bracket_side(str, i))) {
        flag_r++;
      }
    }
  }
  ck_assert_int_eq(flag_r, 3);
}

START_TEST(bracket_side_4) {
  char *str = "(1+2)*(10mod30)+ln(1.0)";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (bracket_side(str, i)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 3);
}

// bracket_side_math

START_TEST(bracket_side_math_0) {
  char *str = "(1+2)*(*10mod30)+ln(1.0)";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_bracket(str, i)) {
      if (bracket_side_math(str, i)) {
        flag_r++;
      }
    }
  }
  ck_assert_int_eq(flag_r, 6);
}

START_TEST(bracket_side_math_1) {
  char *str = "(1+2)-(-1)";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_bracket(str, i)) {
      if (bracket_side_math(str, i)) {
        flag_r++;
      }
    }
  }
  ck_assert_int_eq(flag_r, 4);
}

START_TEST(bracket_side_math_2) {
  char *str = "(10mod30)";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_bracket(str, i)) {
      if (bracket_side_math(str, i)) {
        flag_r++;
      }
    }
  }
  ck_assert_int_eq(flag_r, 2);
}

START_TEST(bracket_side_math_3) {
  char *str = "ln(1.0)";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_bracket(str, i)) {
      if (bracket_side_math(str, i)) {
        flag_r++;
      }
    }
  }
  ck_assert_int_eq(flag_r, 2);
}

START_TEST(bracket_side_math_4) {
  char *str = "(5)cos(3mod5)";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_bracket(str, i)) {
      if (bracket_side_math(str, i)) {
        flag_r++;
      }
    }
  }
  ck_assert_int_eq(flag_r, 4);
}

// TODO is_mod_parse

START_TEST(is_mod_parse_0) {
  char *str = "(5)cos(3mod5)";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_mod_parse(str, i)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 1);
}

START_TEST(is_mod_parse_1) {
  char *str = "(5mod10)cos(3mod5)";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_mod_parse(str, i)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 2);
}

START_TEST(is_mod_parse_2) {
  char *str = "(5)cos(3*5)";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_mod_parse(str, i)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 0);
}

START_TEST(is_mod_parse_3) {
  char *str = "(5*16)-10";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_mod_parse(str, i)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 0);
}

START_TEST(is_mod_parse_4) {
  char *str = "(5)cos(35)";
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_mod_parse(str, i)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 0);
}

// TODO is_char_math_opert_parser

START_TEST(is_char_math_opert_parser_0) {
  char *str = "(5)cos(35)";
  N *stack = create_node(0, 0, 20);
  N *tmp = stack;
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_char_math_opert_parser(str, i, &stack)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 1);

  while (stack != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
}

START_TEST(is_char_math_opert_parser_1) {
  char *str = "(5)cos(-180)";
  N *stack = create_node(0, 0, 20);
  N *tmp = stack;

  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_char_math_opert_parser(str, i, &stack)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 1);
  while (stack != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
}

START_TEST(is_char_math_opert_parser_2) {
  char *str = "(5)cos(35)+tan(0.4)-10";
  N *stack = create_node(0, 0, 20);
  N *tmp = stack;
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_char_math_opert_parser(str, i, &stack)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 2);
  while (stack != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
}

START_TEST(is_char_math_opert_parser_3) {
  char *str = "(5)-cos(35)+log(100)";
  N *stack = create_node(0, 0, 20);
  N *tmp = stack;
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_char_math_opert_parser(str, i, &stack)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 2);
  while (stack != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
}

START_TEST(is_char_math_opert_parser_4) {
  char *str = "(5)cos(35)sin";
  N *stack = create_node(0, 0, 20);
  N *tmp = stack;
  int flag_r = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (is_char_math_opert_parser(str, i, &stack)) {
      flag_r++;
    }
  }
  ck_assert_int_eq(flag_r, 2);
  while (stack != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
}

// TODO create_node

START_TEST(create_node_0) {
  N *stack = create_node(0, 0, 20);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->value == 0 && stack->priority == 0) {
    flag = 1;
  }
  ck_assert_int_eq(flag, 1);
  while (stack != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
}

START_TEST(create_node_1) {
  N *stack = create_node(5, 10, 20);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->value == 5 && stack->priority == 10 && stack->type_v == 20 &&
      stack->next == NULL) {
    flag = 1;
  }
  ck_assert_int_eq(flag, 1);
  while (stack != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
}

START_TEST(create_node_2) {
  N *stack = create_node(1, 70, -5);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->value == 1 && stack->priority == 70 &&
      (int)stack->type_v == -5 && stack->next == NULL) {
    flag = 1;
  }
  ck_assert_int_eq(flag, 1);
  while (stack != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
}

START_TEST(create_node_3) {
  N *stack = create_node(37, -100, 20);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->value == 37 && stack->priority == -100 && stack->type_v == 20 &&
      stack->next == NULL) {
    flag = 1;
  }
  ck_assert_int_eq(flag, 1);
  while (stack != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
}

START_TEST(create_node_4) {
  N *stack = create_node(88, 0, 20);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->value == 88 && stack->priority == 0 && stack->type_v == 20 &&
      stack->next == NULL) {
    flag = 1;
  }
  ck_assert_int_eq(flag, 1);
  while (stack != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
}

// TODO push_back

START_TEST(push_back_0) {
  N *stack = create_node(88, 0, 20);
  push_back(&stack, 5, 5, 10);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->next->value == 5 && stack->next->priority == 5 &&
      stack->next->type_v == 10) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

START_TEST(push_back_1) {
  N *stack = create_node(88, 0, 20);
  push_back(&stack, -6, 99, 0);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->next->value == -6 && stack->next->priority == 99 &&
      stack->next->type_v == 0) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

START_TEST(push_back_2) {
  N *stack = create_node(88, 0, 20);
  push_back(&stack, 0, 0, 0);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->next->value == 0 && stack->next->priority == 0 &&
      stack->next->type_v == 0) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

START_TEST(push_back_3) {
  N *stack = create_node(88, 0, 20);
  push_back(&stack, 0, 1, 2);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->next->value == 1 && stack->next->priority == 2 &&
      stack->next->type_v == 1) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 0);
}

START_TEST(push_back_4) {
  N *stack = create_node(88, 0, 20);
  push_back(&stack, 5, 5, 10);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->next->value == 1 && stack->next->priority == 2 &&
      stack->next->type_v == 3) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 0);
}

// TODO push_front

START_TEST(push_front_0) {
  N *stack = create_node(88, 0, 20);
  push_front(&stack, 5, 5, 10);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->value == 5 && stack->priority == 5 && stack->type_v == 10) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

START_TEST(push_front_1) {
  N *stack = create_node(88, 0, 20);
  push_front(&stack, -6, 99, 0);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->value == -6 && stack->priority == 99 && stack->type_v == 0) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

START_TEST(push_front_2) {
  N *stack = create_node(88, 0, 20);
  push_front(&stack, 0, 0, 0);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->value == 0 && stack->priority == 0 && stack->type_v == 0) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

START_TEST(push_front_3) {
  N *stack = create_node(88, 0, 20);
  push_front(&stack, 0, 1, 2);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->value == 1 && stack->priority == 2 && stack->type_v == 1) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 0);
}

START_TEST(push_front_4) {
  N *stack = create_node(88, 0, 20);
  push_front(&stack, 5, 5, 10);
  N *tmp = stack;
  int flag = 0;
  if ((stack)->value == 1 && stack->priority == 2 && stack->type_v == 3) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 0);
}

// TODO parser_string

START_TEST(parser_string_0) {
  N *stack = create_node(0, 0, 20);
  int x = 10;
  char *string = "1+5+10*cos(3)";
  int flag = parser_string(&stack, string, x);
  N *tmp = stack;

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 0);
}

START_TEST(parser_string_1) {
  N *stack = create_node(88, 0, 20);
  int x = 10;
  char *string = "cos(-180)";
  int flag = parser_string(&stack, string, x);
  N *tmp = stack;

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 0);
}

START_TEST(parser_string_2) {
  N *stack = create_node(88, 0, 20);
  int x = 10;
  char *string = "(1+5)";
  int flag = parser_string(&stack, string, x);
  N *tmp = stack;

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 0);
}

START_TEST(parser_string_3) {
  N *stack = create_node(88, 0, 20);
  int x = 10;
  char *string = "1.5.+5";
  int flag = parser_string(&stack, string, x);
  N *tmp = stack;

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

START_TEST(parser_string_4) {
  N *stack = create_node(88, 0, 20);
  int x = 10;
  char *string = "1+)5";
  int flag = parser_string(&stack, string, x);
  N *tmp = stack;

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

// TODO plus_push

START_TEST(plus_push_0) {
  N *stack = create_node(88, 0, 20);
  char *string = "1+5+10*cos(3)";
  int flag = 0;
  N *tmp = stack;
  for (int i = 0; i < (int)strlen(string); i++) {
    if (is_math_oper(string, i)) {
      plus_push(&stack, string, i);
    }
  }
  if (stack->next->type_v == plus_v && stack->next->next->type_v == plus_v &&
      stack->next->next->next->type_v == umn_v) {
    flag = 1;
  }
  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

START_TEST(plus_push_1) {
  N *stack = create_node(88, 0, 20);
  char *string = "1+5+10";
  int flag = 0;
  N *tmp = stack;
  for (int i = 0; i < (int)strlen(string); i++) {
    if (is_math_oper(string, i)) {
      plus_push(&stack, string, i);
    }
  }
  if (stack->next->type_v == plus_v && stack->next->next->type_v == plus_v) {
    flag = 1;
  }
  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

START_TEST(plus_push_2) {
  N *stack = create_node(88, 0, 20);
  char *string = "1+5+10^cos(3)";
  int flag = 0;
  N *tmp = stack;
  for (int i = 0; i < (int)strlen(string); i++) {
    if (is_math_oper(string, i)) {
      plus_push(&stack, string, i);
    }
  }
  if (stack->next->type_v == plus_v && stack->next->next->type_v == plus_v &&
      stack->next->next->next->type_v == step_v) {
    flag = 1;
  }
  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

START_TEST(plus_push_3) {
  N *stack = create_node(88, 0, 20);
  char *string = "1+5+10-cos(3)";
  int flag = 0;
  N *tmp = stack;
  for (int i = 0; i < (int)strlen(string); i++) {
    if (is_math_oper(string, i)) {
      plus_push(&stack, string, i);
    }
  }
  if (stack->next->type_v == plus_v && stack->next->next->type_v == plus_v &&
      stack->next->next->next->type_v == minus_v) {
    flag = 1;
  }
  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

START_TEST(plus_push_4) {
  N *stack = create_node(88, 0, 20);
  char *string = "1/5+10*cos(3)";
  int flag = 0;
  N *tmp = stack;
  for (int i = 0; i < (int)strlen(string); i++) {
    if (is_math_oper(string, i)) {
      plus_push(&stack, string, i);
    }
  }
  if (stack->next->type_v == del_v && stack->next->next->type_v == plus_v &&
      stack->next->next->next->type_v == umn_v) {
    flag = 1;
  }
  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

// TODO pop_front

START_TEST(pop_front_0) {
  N *stack = create_node(88, 0, 20);
  int flag = 0;
  pop_front(&stack);
  if (stack == NULL) {
    flag = 1;
  }
  ck_assert_int_eq(flag, 1);
}

START_TEST(pop_front_1) {
  N *stack = create_node(88, 0, 20);
  int flag = 0;
  push_front(&stack, 1, 1, 1);
  pop_front(&stack);
  pop_front(&stack);
  if (stack == NULL) {
    flag = 1;
  }
  ck_assert_int_eq(flag, 1);
}

// TODO pick_type

START_TEST(pick_type_0) {
  N *stack = create_node(88, 0, 20);
  int flag = 0;

  if (20 == pick_type(&stack)) {
    flag = 1;
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

START_TEST(pick_type_1) {
  N *stack = create_node(88, 0, nothing_v);
  int flag = 0;

  if (nothing_v == pick_type(&stack)) {
    flag = 1;
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

// TODO pick_priority

START_TEST(pick_priority_0) {
  N *stack = create_node(88, 5, nothing_v);
  int flag = 0;

  if (5 == pick_priority(&stack)) {
    flag = 1;
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

START_TEST(pick_priority_1) {
  N *stack = create_node(88, 0, nothing_v);
  int flag = 0;

  if (0 == pick_priority(&stack)) {
    flag = 1;
  }
  free(stack);
  ck_assert_int_eq(flag, 1);
}

// TODO push_in_stack

START_TEST(push_in_stack_0) {
  N *stack = create_node(88, 5, nothing_v);
  int flag = 0;
  N *stack_ready = create_node(10, 0, 2);
  push_in_stack(&stack, &stack_ready);
  N *tmp = stack;

  if (stack_ready->next->value == 88 && stack_ready->next->priority == 5 &&
      stack_ready->next->type_v == nothing_v) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);

  while (stack_ready->next != NULL) {
    tmp = stack_ready;
    stack_ready = stack_ready->next;
    free(tmp);
  }
  free(stack_ready);

  ck_assert_int_eq(flag, 1);
}

START_TEST(push_in_stack_1) {
  N *stack = create_node(5, 10, 1);
  int flag = 0;
  N *stack_ready = create_node(10, 0, 2);
  push_in_stack(&stack, &stack_ready);
  N *tmp = stack;

  if (stack_ready->next->value == 5 && stack_ready->next->priority == 10 &&
      stack_ready->next->type_v == 1) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);

  while (stack_ready->next != NULL) {
    tmp = stack_ready;
    stack_ready = stack_ready->next;
    free(tmp);
  }
  free(stack_ready);

  ck_assert_int_eq(flag, 1);
}

// TODO push_in_stack

START_TEST(push_in_stack_front_0) {
  N *stack = create_node(88, 5, nothing_v);
  int flag = 0;
  N *stack_ready = create_node(10, 0, 2);
  push_in_stack_front(&stack, &stack_ready);
  N *tmp = stack;

  if (stack_ready->value == 88 && stack_ready->priority == 5 &&
      stack_ready->type_v == nothing_v) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);

  while (stack_ready->next != NULL) {
    tmp = stack_ready;
    stack_ready = stack_ready->next;
    free(tmp);
  }
  free(stack_ready);

  ck_assert_int_eq(flag, 1);
}

START_TEST(push_in_stack_front_1) {
  N *stack = create_node(5, 10, 1);
  int flag = 0;
  N *stack_ready = create_node(10, 0, 2);
  push_in_stack_front(&stack, &stack_ready);
  N *tmp = stack;

  if (stack_ready->value == 5 && stack_ready->priority == 10 &&
      stack_ready->type_v == 1) {
    flag = 1;
  }

  while (stack->next != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
  free(stack);

  while (stack_ready->next != NULL) {
    tmp = stack_ready;
    stack_ready = stack_ready->next;
    free(tmp);
  }
  free(stack_ready);

  ck_assert_int_eq(flag, 1);
}

// TODO reverse_polish_notation

START_TEST(reverse_polish_notation_0) {
  char str[255] = "1+5";
  N *stack = create_node(0, 0, 20);
  N *stack_ready = create_node(0, 0, 20);
  N *tmp = stack_ready;
  int flag = 0;
  double x = 90;
  parser_string(&stack, str, x);
  reverse_polish_notation(&stack, &stack_ready);
  if (stack_ready->next != NULL &&
      stack_ready->next->next->value == (double)1 &&
      stack_ready->next->next->next->value == (double)5 &&
      stack_ready->next->next->next->next->value == (double)0) {
    flag = 1;
  }
  tmp = stack_ready;
  while (tmp->next != NULL) {
    stack_ready = tmp->next;
    free(tmp);
    tmp = stack_ready;
  }
  free(tmp);
  ck_assert_int_eq(flag, 1);
}

START_TEST(reverse_polish_notation_1) {
  char str[255] = "6+5";
  N *stack = create_node(0, 0, 20);
  N *stack_ready = create_node(0, 0, 20);
  N *tmp = stack_ready;
  int flag = 0;
  double x = 90;
  parser_string(&stack, str, x);
  reverse_polish_notation(&stack, &stack_ready);
  if (stack_ready->next != NULL &&
      stack_ready->next->next->value == (double)6 &&
      stack_ready->next->next->next->value == (double)5 &&
      stack_ready->next->next->next->next->value == (double)0) {
    flag = 1;
  }
  tmp = stack_ready;
  while (tmp->next != NULL) {
    stack_ready = tmp->next;
    free(tmp);
    tmp = stack_ready;
  }
  free(tmp);
  ck_assert_int_eq(flag, 1);
}

// TODO calculate

START_TEST(calculate_0) {
  char str[255] = "6-5+x*10";
  double ansver = 0;
  N *stack = create_node(0, 0, 20);
  N *stack_ready = create_node(0, 0, 20);
  // N *tmp = stack_ready;
  int flag = 0;
  double x = 90;
  parser_string(&stack, str, x);
  reverse_polish_notation(&stack, &stack_ready);
  if (calculate(&stack_ready, &ansver) && ansver == 901) {
    flag = 1;
  }

  // tmp = stack_ready;

  ck_assert_int_eq(flag, 1);
}

START_TEST(calculate_1) {
  char str[255] = "6+5+x";
  double ansver = 0;
  N *stack = create_node(0, 0, 20);
  N *stack_ready = create_node(0, 0, 20);
  // N *tmp = stack_ready;
  int flag = 0;
  double x = 90;
  parser_string(&stack, str, x);
  reverse_polish_notation(&stack, &stack_ready);
  if (calculate(&stack_ready, &ansver) && ansver == 101) {
    flag = 1;
  }

  // tmp = stack_ready;

  ck_assert_int_eq(flag, 1);
}

START_TEST(creditCalc_0) {
  double sum_credit = 100;
  int srok_credit = 1;
  double prosent_stavka = 10;
  int year_or_month = 1;
  int type_of_loan = 0;
  type_of_loan = 0;
  double separate_payment = 0;
  double separate_payment_1 = 0;  //  платеж в месяц/год
  double overpayment = 0;         // переплата по кредиту
  double total_payout = 0;        // общая выплатаÎ
  int flag = credit_calc_c(sum_credit, srok_credit, year_or_month,
                           prosent_stavka, type_of_loan, &separate_payment,
                           &separate_payment_1, &overpayment, &total_payout);

  ck_assert_int_eq(flag, 1);
}

START_TEST(creditCalc_1) {
  double sum_credit = 100;
  int srok_credit = 1;
  double prosent_stavka = 10;
  int year_or_month = 0;
  int type_of_loan = 1;
  type_of_loan = 1;
  double separate_payment = 0;
  double separate_payment_1 = 0;  //  платеж в месяц/год
  double overpayment = 0;         // переплата по кредиту
  double total_payout = 0;        // общая выплатаÎ
  int flag = credit_calc_c(sum_credit, srok_credit, year_or_month,
                           prosent_stavka, type_of_loan, &separate_payment,
                           &separate_payment_1, &overpayment, &total_payout);

  ck_assert_int_eq(flag, 1);
}

START_TEST(creditCalc_2) {
  double sum_credit = 100;
  int srok_credit = 1;
  double prosent_stavka = 10;
  int year_or_month = 0;
  int type_of_loan = 1;
  type_of_loan = 0;
  double separate_payment = 1;
  double separate_payment_1 = 1;  //  платеж в месяц/год
  double overpayment = 1;         // переплата по кредиту
  double total_payout = 1;        // общая выплатаÎ
  int flag = credit_calc_c(sum_credit, srok_credit, year_or_month,
                           prosent_stavka, type_of_loan, &separate_payment,
                           &separate_payment_1, &overpayment, &total_payout);

  ck_assert_int_eq(flag, 1);
}

START_TEST(calcul_0) {
  char str[255] = "(--1)";
  double x = 1;
  double ansver_qt = 0;
  int flag = 0;
  if (!calcul(str, x, &ansver_qt)) {
  } else {
    flag = 1;
  }
  ck_assert_int_eq(flag, 1);
}

START_TEST(calcul_1) {
  char str[255] = "cos(30) + 10 * 5 - 10 * ln(5)+(+5)";
  double x = 1;
  double ansver_qt = 0;
  int flag = 0;
  if (!calcul(str, x, &ansver_qt)) {
  } else {
    flag = 1;
  }
  ck_assert_int_eq(flag, 0);
}

START_TEST(depisit_calc_0) {
  double sum_vkald = 19090;
  int srok = 1;
  double prosent_stavka = 5;
  double nalog_stavka = 2;
  int period_viplat = 1;  // через какое время выплатить в месяцах
  if (period_viplat != 2) {
    if (period_viplat == 0) {
      period_viplat = 1;
    } else {
      period_viplat = 3;
    }
  }
  int capit_prosentov =
      0;  // добавление дохода в основную сумму, 0 - вкл, 1 - выкл
  int year_or_month = 2;
  if (year_or_month == 0) {
    srok *= 12;
  }
  capit_prosentov = 1;

  int spisok_poplneni_date = 0 + 1;
  int spisok_cnaty_date = 0 + 1;
  if (spisok_poplneni_date != 1) {
    spisok_poplneni_date = 0 * 3;
  }
  if (spisok_cnaty_date != 1) {
    spisok_cnaty_date = 0 * 3;
  }
  double spisok_poplneni = 100;  // сколько пополняю ежемесяечно;
  double spisok_cnaty = 100;  // сколько снимаю ежемесяечно;
  double nacislen_prosenty = 0;
  double sum_nalog = 0;
  double sum_end = 0;
  int flag = deposit_calc(sum_vkald, srok, prosent_stavka, nalog_stavka,
                          period_viplat, capit_prosentov, spisok_poplneni,
                          spisok_cnaty, &nacislen_prosenty, &sum_nalog,
                          &sum_end, spisok_poplneni_date, spisok_cnaty_date);
  ck_assert_int_eq(flag, 1);
}

START_TEST(depisit_calc_1) {
  double sum_vkald = 19090;
  int srok = 1;
  double prosent_stavka = 5;
  double nalog_stavka = 2;
  int period_viplat = 1;  // через какое время выплатить в месяцах
  if (period_viplat != 2) {
    if (period_viplat == 0) {
      period_viplat = 1;
    } else {
      period_viplat = 3;
    }
  }
  int capit_prosentov =
      0;  // добавление дохода в основную сумму, 0 - вкл, 1 - выкл
  int year_or_month = 2;
  if (year_or_month == 0) {
    srok *= 12;
  }
  capit_prosentov = 1;

  int spisok_poplneni_date = 0 + 1;
  int spisok_cnaty_date = 0 + 1;
  if (spisok_poplneni_date != 1) {
    spisok_poplneni_date = 0 * 3;
  }
  if (spisok_cnaty_date != 1) {
    spisok_cnaty_date = 0 * 3;
  }
  double spisok_poplneni = 100;  // сколько пополняю ежемесяечно;
  double spisok_cnaty = 100;  // сколько снимаю ежемесяечно;
  double nacislen_prosenty = 0;
  double sum_nalog = 0;
  double sum_end = 0;
  int flag = deposit_calc(sum_vkald, srok, prosent_stavka, nalog_stavka,
                          period_viplat, capit_prosentov, spisok_poplneni,
                          spisok_cnaty, &nacislen_prosenty, &sum_nalog,
                          &sum_end, spisok_poplneni_date, spisok_cnaty_date);
  ck_assert_int_eq(flag, 1);
}
int main(void) {
  Suite *suite = suite_create("S21_Debuger");
  SRunner *srunner = srunner_create(suite);

  TCase *is_char_math_opert_f = tcase_create("is_char_math_opert");

  suite_add_tcase(suite, is_char_math_opert_f);
  tcase_add_test(is_char_math_opert_f, is_char_math_opert_0);
  tcase_add_test(is_char_math_opert_f, is_char_math_opert_1);
  tcase_add_test(is_char_math_opert_f, is_char_math_opert_2);
  tcase_add_test(is_char_math_opert_f, is_char_math_opert_3);
  tcase_add_test(is_char_math_opert_f, is_char_math_opert_4);
  tcase_add_test(is_char_math_opert_f, is_char_math_opert_5);
  tcase_add_test(is_char_math_opert_f, is_char_math_opert_6);

  TCase *is_number_or_x_f = tcase_create("is_number_or_x");

  suite_add_tcase(suite, is_number_or_x_f);
  tcase_add_test(is_number_or_x_f, is_number_or_x_0);
  tcase_add_test(is_number_or_x_f, is_number_or_x_1);
  tcase_add_test(is_number_or_x_f, is_number_or_x_2);
  tcase_add_test(is_number_or_x_f, is_number_or_x_3);
  tcase_add_test(is_number_or_x_f, is_number_or_x_4);
  tcase_add_test(is_number_or_x_f, is_number_or_x_5);
  tcase_add_test(is_number_or_x_f, is_number_or_x_6);

  TCase *is_bracket_f = tcase_create("is_bracket");

  suite_add_tcase(suite, is_bracket_f);
  tcase_add_test(is_bracket_f, is_bracket_0);
  tcase_add_test(is_bracket_f, is_bracket_1);
  tcase_add_test(is_bracket_f, is_bracket_2);
  tcase_add_test(is_bracket_f, is_bracket_3);
  tcase_add_test(is_bracket_f, is_bracket_4);
  tcase_add_test(is_bracket_f, is_bracket_5);
  tcase_add_test(is_bracket_f, is_bracket_6);

  TCase *is_mod_f = tcase_create("is_mod");

  suite_add_tcase(suite, is_mod_f);
  tcase_add_test(is_mod_f, is_mod_0);
  tcase_add_test(is_mod_f, is_mod_1);
  tcase_add_test(is_mod_f, is_mod_2);
  tcase_add_test(is_mod_f, is_mod_3);
  tcase_add_test(is_mod_f, is_mod_4);
  tcase_add_test(is_mod_f, is_mod_5);
  tcase_add_test(is_mod_f, is_mod_6);

  TCase *is_dot_f = tcase_create("is_dot");

  suite_add_tcase(suite, is_dot_f);
  tcase_add_test(is_dot_f, is_dot_0);
  tcase_add_test(is_dot_f, is_dot_1);
  tcase_add_test(is_dot_f, is_dot_2);
  tcase_add_test(is_dot_f, is_dot_3);
  tcase_add_test(is_dot_f, is_dot_4);
  tcase_add_test(is_dot_f, is_dot_5);
  tcase_add_test(is_dot_f, is_dot_6);

  TCase *delete_space_f = tcase_create("delete_space");

  suite_add_tcase(suite, delete_space_f);
  tcase_add_test(delete_space_f, delete_space_0);
  tcase_add_test(delete_space_f, delete_space_1);
  tcase_add_test(delete_space_f, delete_space_2);
  tcase_add_test(delete_space_f, delete_space_3);
  tcase_add_test(delete_space_f, delete_space_4);
  tcase_add_test(delete_space_f, delete_space_5);
  tcase_add_test(delete_space_f, delete_space_6);

  TCase *is_math_oper_f = tcase_create("is_math_oper");

  suite_add_tcase(suite, is_math_oper_f);
  tcase_add_test(is_math_oper_f, is_math_oper_0);
  tcase_add_test(is_math_oper_f, is_math_oper_1);
  tcase_add_test(is_math_oper_f, is_math_oper_2);
  tcase_add_test(is_math_oper_f, is_math_oper_3);
  tcase_add_test(is_math_oper_f, is_math_oper_4);
  tcase_add_test(is_math_oper_f, is_math_oper_5);
  tcase_add_test(is_math_oper_f, is_math_oper_6);

  TCase *correct_string_f = tcase_create("correct_string");

  suite_add_tcase(suite, correct_string_f);
  tcase_add_test(correct_string_f, correct_string_0);
  tcase_add_test(correct_string_f, correct_string_1);
  tcase_add_test(correct_string_f, correct_string_2);
  tcase_add_test(correct_string_f, correct_string_3);
  tcase_add_test(correct_string_f, correct_string_4);
  tcase_add_test(correct_string_f, correct_string_5);
  tcase_add_test(correct_string_f, correct_string_6);
  tcase_add_test(correct_string_f, correct_string_7);
  tcase_add_test(correct_string_f, correct_string_8);
  tcase_add_test(correct_string_f, correct_string_9);
  tcase_add_test(correct_string_f, correct_string_10);
  tcase_add_test(correct_string_f, correct_string_11);
  tcase_add_test(correct_string_f, correct_string_12);

  TCase *bracket_side_f = tcase_create("bracket_side");

  suite_add_tcase(suite, bracket_side_f);
  tcase_add_test(bracket_side_f, bracket_side_0);
  tcase_add_test(bracket_side_f, bracket_side_1);
  tcase_add_test(bracket_side_f, bracket_side_2);
  tcase_add_test(bracket_side_f, bracket_side_3);
  tcase_add_test(bracket_side_f, bracket_side_4);

  TCase *bracket_side_math_f = tcase_create("bracket_side_math");

  suite_add_tcase(suite, bracket_side_math_f);
  tcase_add_test(bracket_side_math_f, bracket_side_math_0);
  tcase_add_test(bracket_side_math_f, bracket_side_math_1);
  tcase_add_test(bracket_side_math_f, bracket_side_math_2);
  tcase_add_test(bracket_side_math_f, bracket_side_math_3);
  tcase_add_test(bracket_side_math_f, bracket_side_math_4);

  TCase *is_mod_parse_f = tcase_create("is_mod_parse");

  suite_add_tcase(suite, is_mod_parse_f);
  tcase_add_test(is_mod_parse_f, is_mod_parse_0);
  tcase_add_test(is_mod_parse_f, is_mod_parse_1);
  tcase_add_test(is_mod_parse_f, is_mod_parse_2);
  tcase_add_test(is_mod_parse_f, is_mod_parse_3);
  tcase_add_test(is_mod_parse_f, is_mod_parse_4);

  TCase *is_char_math_opert_parser_f =
      tcase_create("is_char_math_opert_parser");

  suite_add_tcase(suite, is_char_math_opert_parser_f);
  tcase_add_test(is_char_math_opert_parser_f, is_char_math_opert_parser_0);
  tcase_add_test(is_char_math_opert_parser_f, is_char_math_opert_parser_1);
  tcase_add_test(is_char_math_opert_parser_f, is_char_math_opert_parser_2);
  tcase_add_test(is_char_math_opert_parser_f, is_char_math_opert_parser_3);
  tcase_add_test(is_char_math_opert_parser_f, is_char_math_opert_parser_4);

  TCase *create_node_f = tcase_create("create_node");

  suite_add_tcase(suite, create_node_f);
  tcase_add_test(create_node_f, create_node_0);
  tcase_add_test(create_node_f, create_node_1);
  tcase_add_test(create_node_f, create_node_2);
  tcase_add_test(create_node_f, create_node_3);
  tcase_add_test(create_node_f, create_node_4);

  TCase *push_back_f = tcase_create("push_back");

  suite_add_tcase(suite, push_back_f);
  tcase_add_test(push_back_f, push_back_0);
  tcase_add_test(push_back_f, push_back_1);
  tcase_add_test(push_back_f, push_back_2);
  tcase_add_test(push_back_f, push_back_3);
  tcase_add_test(push_back_f, push_back_4);

  TCase *push_front_f = tcase_create("push_front");

  suite_add_tcase(suite, push_front_f);
  tcase_add_test(push_front_f, push_front_0);
  tcase_add_test(push_front_f, push_front_1);
  tcase_add_test(push_front_f, push_front_2);
  tcase_add_test(push_front_f, push_front_3);
  tcase_add_test(push_front_f, push_front_4);

  TCase *parser_string_f = tcase_create("parser_string");

  suite_add_tcase(suite, parser_string_f);
  tcase_add_test(parser_string_f, parser_string_0);
  tcase_add_test(parser_string_f, parser_string_1);
  tcase_add_test(parser_string_f, parser_string_2);
  tcase_add_test(parser_string_f, parser_string_3);
  tcase_add_test(parser_string_f, parser_string_4);

  TCase *plus_push_f = tcase_create("plus_push");

  suite_add_tcase(suite, plus_push_f);
  tcase_add_test(plus_push_f, plus_push_0);
  tcase_add_test(plus_push_f, plus_push_1);
  tcase_add_test(plus_push_f, plus_push_2);
  tcase_add_test(plus_push_f, plus_push_3);
  tcase_add_test(plus_push_f, plus_push_4);

  TCase *pop_front_f = tcase_create("pop_front");

  suite_add_tcase(suite, pop_front_f);
  tcase_add_test(pop_front_f, pop_front_0);
  tcase_add_test(pop_front_f, pop_front_1);

  TCase *pick_type_f = tcase_create("pick_type");

  suite_add_tcase(suite, pick_type_f);
  tcase_add_test(pick_type_f, pick_type_0);
  tcase_add_test(pick_type_f, pick_type_1);

  TCase *pick_priority_f = tcase_create("pick_priority");

  suite_add_tcase(suite, pick_priority_f);
  tcase_add_test(pick_priority_f, pick_priority_0);
  tcase_add_test(pick_priority_f, pick_priority_1);

  TCase *push_in_stack_f = tcase_create("push_in_stack");

  suite_add_tcase(suite, push_in_stack_f);
  tcase_add_test(push_in_stack_f, push_in_stack_0);
  tcase_add_test(push_in_stack_f, push_in_stack_1);

  TCase *push_in_stack_front_f = tcase_create("push_in_stack_front");

  suite_add_tcase(suite, push_in_stack_front_f);
  tcase_add_test(push_in_stack_front_f, push_in_stack_front_0);
  tcase_add_test(push_in_stack_front_f, push_in_stack_front_1);

  TCase *reverse_polish_notation_f = tcase_create("reverse_polish_notation");

  suite_add_tcase(suite, reverse_polish_notation_f);
  tcase_add_test(reverse_polish_notation_f, reverse_polish_notation_0);
  tcase_add_test(reverse_polish_notation_f, reverse_polish_notation_1);

  TCase *calculate_f = tcase_create("calculate");

  suite_add_tcase(suite, calculate_f);
  tcase_add_test(calculate_f, calculate_0);
  tcase_add_test(calculate_f, calculate_1);

  TCase *creditCalc_f = tcase_create("creditCalc");

  suite_add_tcase(suite, creditCalc_f);
  tcase_add_test(creditCalc_f, creditCalc_0);
  tcase_add_test(creditCalc_f, creditCalc_1);
  tcase_add_test(creditCalc_f, creditCalc_2);

  TCase *calcul_f = tcase_create("calcul");

  suite_add_tcase(suite, calcul_f);
  tcase_add_test(calcul_f, calcul_0);
  tcase_add_test(calcul_f, calcul_1);

  TCase *depisit_calc_f = tcase_create("depisit_calc");

  suite_add_tcase(suite, depisit_calc_f);
  tcase_add_test(depisit_calc_f, depisit_calc_0);
  tcase_add_test(depisit_calc_f, depisit_calc_1);

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
