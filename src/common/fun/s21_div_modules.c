#include "../s21_add_functions.h"

void s21_div_modules(s21_decimal_long value_1, s21_decimal_long value_2,
                     s21_decimal_long *result) {
  s21_decimal_long temp_1, temp_2;  // вариант_2
  memcpy(temp_1.bits, value_1.bits, sizeof(value_1));
  while (s21_is_greater_or_equal_modules(temp_1, value_2)) {
    int i = 0;
    memcpy(temp_2.bits, value_2.bits, sizeof(value_2));
    while (s21_is_greater_or_equal_modules(temp_1, s21_lshift_out(temp_2))) {
      i++;
      s21_lshift(&temp_2);
    }
    s21_set_n_bit_true(result, i);
    s21_sub_modules(temp_1, temp_2, &temp_1);
  }
}
