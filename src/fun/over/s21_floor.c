#include "../../common/s21_add_functions.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int output = 1;
  if (result != NULL) {
    memcpy(result->bits, value.bits, sizeof(value.bits));
    output = s21_parse_rounding(result, -1);
  }

  return output;
}
