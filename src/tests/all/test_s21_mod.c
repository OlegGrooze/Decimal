#include "../test_s21_decimal.h"

START_TEST(s21_mod_1) { ck_assert_int_eq(1, 1); }
END_TEST
Suite *test_s21_mod(void) {
  Suite *s = suite_create("s21_mod");
  TCase *tc = tcase_create("Case from s21_mod");
  tcase_add_test(tc, s21_mod_1);
  suite_add_tcase(s, tc);
  return s;
}