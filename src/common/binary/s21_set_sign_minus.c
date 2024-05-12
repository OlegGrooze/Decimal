#include "../../s21_decimal.h"

void s21_set_bit(s21_decimal* src, int index) {
  if (index >= 0 && index <= 127) {
    int temp = index / 32;
    int shift = index % 32;
    unsigned int marker = 1u;
    unsigned int mask = marker << (shift);
    src->bits[temp] |= mask;
  }
}
int s21_get_bit(s21_decimal src, int index) {
  unsigned int res = 0;
  if (index >= 0 && index <= 127) {
    unsigned int mask = 1u << (index % 32);
    res = src.bits[index / 32] & mask;
  }
  return !!res;
}

void s21_set_sign_minus(s21_decimal* src) {
  if (s21_get_bit(*src, 127) == PLUS_SIGN) {
    s21_set_bit(src, 127);
  }
}