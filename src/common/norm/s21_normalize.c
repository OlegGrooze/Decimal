#include "../s21_add_functions.h"

void s21_normalize(s21_decimal_long *value, int scale_diff) {
  s21_decimal_long value_const = {0};
  value_const.bits[0] = 9;

  for (int i = 0; i < scale_diff; i++)
    s21_mul_modules(*value, value_const, value);
}
