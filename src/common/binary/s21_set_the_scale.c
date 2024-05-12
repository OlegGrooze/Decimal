#include "../s21_add_functions.h"

void s21_set_the_scale(s21_decimal *value, int scale) {
  value->bits[3] = ((value->bits[3] + scale) << 16);
}
