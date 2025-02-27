#include "../s21_add_functions.h"

void s21_normalize_div_modules(s21_decimal_long *value_1,
                               s21_decimal_long *value_2, s21_decimal *result,
                               int scale_1, int scale_2) {
  if (scale_1 >= scale_2) {
    if (!s21_is_greater_or_equal_modules(*value_1, *value_2)) {
      s21_set_the_scale(result, scale_1);
    }
    s21_normalize(value_2, (scale_1 - scale_2));
    s21_decimal_long mod = {0}, null = {0};
    s21_mod_modules(*value_1, *value_2, &mod);
    if (!s21_is_equal_modules(mod, null)) {
      s21_set_the_scale(result, 0);
    }
  } else {
    s21_set_the_scale(result, 0);
    s21_normalize(value_1, (scale_2 - scale_1));
  }
}
