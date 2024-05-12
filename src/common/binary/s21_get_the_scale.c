#include "../s21_add_functions.h"

int s21_get_the_scale(s21_decimal value) {
  return ((value.bits[3] << 8) >> 24);
}
