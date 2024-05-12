#include "../s21_add_functions.h"

void s21_set_n_bit_true(s21_decimal_long *value, int pos) {
  value->bits[pos / 32] |= (1 << (pos % 32));
}
