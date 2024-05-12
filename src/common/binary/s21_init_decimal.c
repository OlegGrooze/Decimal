#include "../../s21_decimal.h"

void s21_init_decimal(s21_decimal* src) {
  src->bits[0] = 0;
  src->bits[1] = 0;
  src->bits[2] = 0;
  src->bits[3] = 0;
}