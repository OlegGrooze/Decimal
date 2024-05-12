#include "../test_s21_decimal.h"

START_TEST(s21_from_decimal_to_float_1) {
  s21_decimal assert;
  s21_init_decimal(&assert);
  assert.bits[0] = 0b00000000000000000000000000000001;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b00000000000000010000000000000000;
  float result;
  s21_from_decimal_to_float(assert, &result);
  float equal = 0.1;
  ck_assert_float_eq(equal, result);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
  s21_decimal assert;
  s21_init_decimal(&assert);
  assert.bits[0] = 0b00000000000000000000000000000001;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b10000000000000010000000000000000;
  float result;
  s21_from_decimal_to_float(assert, &result);
  float equal = -0.1;
  ck_assert_float_eq(equal, result);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
  s21_decimal assert;
  s21_init_decimal(&assert);
  assert.bits[0] = 0b00000000000000000000000000000000;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b00000000000000010000000000000000;
  float result;
  s21_from_decimal_to_float(assert, &result);
  float equal = 0.;
  ck_assert_float_eq(equal, result);
}
END_TEST

START_TEST(s21_from_decimal_to_float_4) {
  s21_decimal assert;
  s21_init_decimal(&assert);
  assert.bits[0] = 9;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b10000000000000010000000000000000;
  float result;
  s21_from_decimal_to_float(assert, &result);
  float equal = -0.9;
  ck_assert_float_eq(equal, result);
}
END_TEST

START_TEST(s21_from_decimal_to_float_5) {
  s21_decimal assert;
  s21_init_decimal(&assert);
  assert.bits[0] = 123;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b10000000000000110000000000000000;
  float result;
  s21_from_decimal_to_float(assert, &result);
  float equal = -0.123;
  ck_assert_float_eq(equal, result);
}
END_TEST

START_TEST(s21_from_decimal_to_float_6) {
  s21_decimal assert;
  s21_init_decimal(&assert);
  assert.bits[0] = 123;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b00000000000000110000000000000000;
  float result;
  s21_from_decimal_to_float(assert, &result);
  float equal = 0.123;
  ck_assert_float_eq(equal, result);
}
END_TEST

Suite *test_s21_from_decimal_to_float(void) {
  Suite *s = suite_create("s21_from_decimal_to_float");
  TCase *tc = tcase_create("Case of s21_from_decimal_to_float");

  tcase_add_test(tc, s21_from_decimal_to_float_1);
  tcase_add_test(tc, s21_from_decimal_to_float_2);
  tcase_add_test(tc, s21_from_decimal_to_float_3);
  tcase_add_test(tc, s21_from_decimal_to_float_4);
  tcase_add_test(tc, s21_from_decimal_to_float_5);
  tcase_add_test(tc, s21_from_decimal_to_float_6);
  suite_add_tcase(s, tc);
  return s;
}