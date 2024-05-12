#include "../s21_add_functions.h"

int s21_get_bit(s21_decimal src, int index) {
  unsigned int res = 0;
  if (index >= 0 && index <= 127) {
    unsigned int mask = 1u << (index % 32);
    res = src.bits[index / 32] & mask;
  }
  return !!res;
}