#include "../test_s21_decimal.h"

START_TEST(s21_negate_1) {
  s21_decimal assert;
  s21_decimal equal;
  s21_decimal result;
  assert.bits[0] = 1;
  assert.bits[1] = 1;
  assert.bits[2] = 1;
  assert.bits[3] = 0b10000000000000000000000000000000;
  equal.bits[0] = 1;
  equal.bits[1] = 1;
  equal.bits[2] = 1;
  equal.bits[3] = 0b00000000000000000000000000000000;
  s21_negate(assert, &result);
  ck_assert_int_eq(equal.bits[0], result.bits[0]);
  ck_assert_int_eq(equal.bits[1], result.bits[1]);
  ck_assert_int_eq(equal.bits[2], result.bits[2]);
  ck_assert_int_eq(equal.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal assert;
  s21_decimal equal;
  s21_decimal result;
  assert.bits[0] = 0b00000000000000000000000000000000;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b00000000000000000000000000000000;
  equal.bits[0] = 0b00000000000000000000000000000000;
  equal.bits[1] = 0b00000000000000000000000000000000;
  equal.bits[2] = 0b00000000000000000000000000000000;
  equal.bits[3] = 0b00000000000000000000000000000000;
  s21_negate(assert, &result);
  ck_assert_int_eq(equal.bits[0], result.bits[0]);
  ck_assert_int_eq(equal.bits[1], result.bits[1]);
  ck_assert_int_eq(equal.bits[2], result.bits[2]);
}
END_TEST

START_TEST(s21_negate_3) {
  s21_decimal assert;
  s21_decimal equal;
  s21_decimal result;
  assert.bits[0] = 0b00000000000000000000000000000000;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b10000000000000000000000000000000;

  equal.bits[0] = 0b00000000000000000000000000000000;
  equal.bits[1] = 0b00000000000000000000000000000000;
  equal.bits[2] = 0b00000000000000000000000000000000;
  equal.bits[3] = 0b00000000000000000000000000000000;

  s21_negate(assert, &result);
  ck_assert_int_eq(equal.bits[0], result.bits[0]);
  ck_assert_int_eq(equal.bits[1], result.bits[1]);
  ck_assert_int_eq(equal.bits[2], result.bits[2]);
  ck_assert_int_eq(equal.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_4) {
  s21_decimal assert;
  s21_decimal equal;
  s21_decimal result;
  assert.bits[0] = 1;
  assert.bits[1] = 1;
  assert.bits[2] = 1;
  assert.bits[3] = 0b00000000000000000000000000000000;
  equal.bits[0] = 1;
  equal.bits[1] = 1;
  equal.bits[2] = 1;
  equal.bits[3] = 0b10000000000000000000000000000000;
  s21_negate(assert, &result);
  ck_assert_int_eq(equal.bits[0], result.bits[0]);
  ck_assert_int_eq(equal.bits[1], result.bits[1]);
  ck_assert_int_eq(equal.bits[2], result.bits[2]);
  ck_assert_int_eq(equal.bits[3], result.bits[3]);
}
END_TEST

Suite *test_s21_negate(void) {
  Suite *s = suite_create("s21_negate");
  TCase *tc = tcase_create("Case from s21_negate");
  tcase_add_test(tc, s21_negate_1);
  tcase_add_test(tc, s21_negate_2);
  tcase_add_test(tc, s21_negate_3);
  tcase_add_test(tc, s21_negate_4);
  suite_add_tcase(s, tc);
  return s;
}
