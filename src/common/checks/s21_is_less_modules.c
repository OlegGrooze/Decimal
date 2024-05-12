#include "../s21_add_functions.h"

int s21_is_less_modules(s21_decimal_long value_1, s21_decimal_long value_2) {
  return (!(s21_is_greater_modules(value_1, value_2) ||
            s21_is_equal_modules(value_1, value_2)));
}
