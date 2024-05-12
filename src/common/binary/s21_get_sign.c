#include "../s21_add_functions.h"

int s21_get_sign(s21_decimal value) { return (value.bits[3] & 2147483648); }
