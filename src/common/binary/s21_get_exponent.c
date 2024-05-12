#include "../s21_add_functions.h"

int s21_get_exponent(float value) {
  int exp = 0;
  while (value >= 1) {
    value /= 10;
    exp++;
  }
  return (exp - 8);
}
