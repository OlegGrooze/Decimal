#include "../s21_add_functions.h"

s21_decimal_long s21_lshift_out(s21_decimal_long value) {
  s21_decimal_long tmp;
  memcpy(tmp.bits, value.bits, sizeof(value));
  s21_lshift(&tmp);
  return tmp;
}
