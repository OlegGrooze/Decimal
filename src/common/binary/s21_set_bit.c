#include "../s21_add_functions.h"

void s21_set_bit(s21_decimal* src, int index) {
  if (index >= 0 && index <= 127) {
    int temp = index / 32;
    int shift = index % 32;
    unsigned int marker = 1u;
    unsigned int mask = marker << (shift);
    src->bits[temp] |= mask;
  }
}