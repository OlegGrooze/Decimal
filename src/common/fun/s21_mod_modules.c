#include "../s21_add_functions.h"

void s21_mod_modules(s21_decimal_long value_1, s21_decimal_long value_2,
                     s21_decimal_long *result) {
  s21_decimal_long res = {0};
  s21_div_modules(value_1, value_2, &res);
  s21_mul_modules(res, value_2, result);
  s21_sub_modules(value_1, *result, result);
}
