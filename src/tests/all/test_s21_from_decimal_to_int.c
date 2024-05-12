#include "../test_s21_decimal.h"

START_TEST(s21_from_decimal_to_int_1) {
  s21_decimal assert;
  assert.bits[0] = 0b00000000000000000000000000000001;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b00000000000000000000000000000000;
  int equals = 1;
  int result;
  s21_from_decimal_to_int(assert, &result);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_from_decimal_to_int_2) {
  s21_decimal assert;
  assert.bits[0] = 0b00000000000000000000000000000001;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b10000000000000000000000000000000;
  int equals = -1;
  int result;
  s21_from_decimal_to_int(assert, &result);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_from_decimal_to_int_3) {
  s21_decimal assert;
  assert.bits[0] = 70;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b10000000000000010000000000000000;
  int equals = -7;
  int result;
  s21_from_decimal_to_int(assert, &result);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_from_decimal_to_int_4) {
  s21_decimal assert;
  assert.bits[0] = 0b10000000000000000000000000000000;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b10000000000000010000000000000000;
  int equals = 0b10000000000000000000000000000000 / 10 * -1;
  int result;
  s21_from_decimal_to_int(assert, &result);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_from_decimal_to_int_5) {
  s21_decimal assert;
  assert.bits[0] = 0b10000000000000000000000000000000;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b10000000000000010000000000000000;
  int equals = ERROR;
  int result;
  assert.bits[2] = 0b00011000000000000000000000000000;
  result = s21_from_decimal_to_int(assert, &result);
  ck_assert_int_eq(equals, result);
}
END_TEST

Suite *test_s21_from_decimal_to_int(void) {
  Suite *s = suite_create("s21_from_decimal_to_int");
  TCase *tc = tcase_create("Case from s21_from_decimal_to_int");
  tcase_add_test(tc, s21_from_decimal_to_int_1);
  tcase_add_test(tc, s21_from_decimal_to_int_2);
  tcase_add_test(tc, s21_from_decimal_to_int_3);
  tcase_add_test(tc, s21_from_decimal_to_int_4);
  tcase_add_test(tc, s21_from_decimal_to_int_5);
  suite_add_tcase(s, tc);
  return s;
}