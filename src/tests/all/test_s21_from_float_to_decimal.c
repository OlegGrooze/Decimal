#include "../test_s21_decimal.h"

START_TEST(s21_from_float_to_decimal_1) {
  s21_decimal equal;
  equal.bits[0] = 0b00000000000000000000000000000001;
  equal.bits[1] = 0b00000000000000000000000000000000;
  equal.bits[2] = 0b00000000000000000000000000000000;
  equal.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result;
  float assert = 0.1;
  s21_from_float_to_decimal(assert, &result);
  int res_int = s21_is_equal(equal, result);
  int equal_int = TRUE;
  ck_assert_int_eq(equal_int, res_int);
}
END_TEST

START_TEST(s21_from_float_to_decimal_2) {
  s21_decimal equal;
  equal.bits[0] = 0b00000000000000000000000000000000;
  equal.bits[1] = 0b00000000000000000000000000000000;
  equal.bits[2] = 0b00000000000000000000000000000000;
  equal.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result;
  float assert = 0.0;
  s21_from_float_to_decimal(assert, &result);
  int res_int = s21_is_equal(equal, result);
  int equal_int = TRUE;
  ck_assert_int_eq(equal_int, res_int);
}
END_TEST

START_TEST(s21_from_float_to_decimal_3) {
  s21_decimal equal;
  equal.bits[0] = 55;
  equal.bits[1] = 0b00000000000000000000000000000000;
  equal.bits[2] = 0b00000000000000000000000000000000;
  equal.bits[3] = 0b00000000000000100000000000000000;
  s21_decimal result;
  float assert = 0.55;
  s21_from_float_to_decimal(assert, &result);
  int res_int = s21_is_equal(equal, result);
  int equal_int = TRUE;
  ck_assert_int_eq(equal_int, res_int);
}
END_TEST

START_TEST(s21_from_float_to_decimal_4) {
  s21_decimal equal;
  equal.bits[0] = 55;
  equal.bits[1] = 0b00000000000000000000000000000000;
  equal.bits[2] = 0b00000000000000000000000000000000;
  equal.bits[3] = 0b10000000000000100000000000000000;
  s21_decimal result;
  float assert = -0.55;
  s21_from_float_to_decimal(assert, &result);
  int res_int = s21_is_equal(equal, result);
  int equal_int = TRUE;
  ck_assert_int_eq(equal_int, res_int);
}
END_TEST

START_TEST(s21_from_float_to_decimal_5) {
  s21_decimal equal;
  equal.bits[0] = 55;
  equal.bits[1] = 0b00000000000000000000000000000000;
  equal.bits[2] = 0b00000000000000000000000000000000;
  equal.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  float assert = -55;
  s21_from_float_to_decimal(assert, &result);
  int res_int = s21_is_equal(equal, result);
  int equal_int = TRUE;
  ck_assert_int_eq(equal_int, res_int);
}
END_TEST

START_TEST(s21_from_float_to_decimal_6) {
  s21_decimal equal;
  equal.bits[0] = 55;
  equal.bits[1] = 0b00000000000000000000000000000000;
  equal.bits[2] = 0b00000000000000000000000000000000;
  equal.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  float assert = 55;
  s21_from_float_to_decimal(assert, &result);
  int res_int = s21_is_equal(equal, result);
  int equal_int = TRUE;
  ck_assert_int_eq(equal_int, res_int);
}
END_TEST

Suite *test_s21_from_float_to_decimal(void) {
  Suite *s = suite_create("s21_from_float_to_decimal");
  TCase *tc = tcase_create("Case from s21_from_float_to_decimal");
  tcase_add_test(tc, s21_from_float_to_decimal_1);
  tcase_add_test(tc, s21_from_float_to_decimal_2);
  tcase_add_test(tc, s21_from_float_to_decimal_3);
  tcase_add_test(tc, s21_from_float_to_decimal_4);
  tcase_add_test(tc, s21_from_float_to_decimal_5);
  tcase_add_test(tc, s21_from_float_to_decimal_6);
  suite_add_tcase(s, tc);
  return s;
}