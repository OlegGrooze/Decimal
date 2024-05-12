#include "../test_s21_decimal.h"

START_TEST(s21_truncate_1) {
  s21_decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000000000001;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000001;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal assert;
  assert.bits[0] = 0b00000000000000000000000001001111;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal equals;
  equals.bits[0] = 0b00000000000000000000000001001111;
  equals.bits[1] = 0b00000000000000000000000000000000;
  equals.bits[2] = 0b00000000000000000000000000000000;
  equals.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  s21_truncate(assert, &result);
  ck_assert_int_eq(equals.bits[0], result.bits[0]);
  ck_assert_int_eq(equals.bits[1], result.bits[1]);
  ck_assert_int_eq(equals.bits[2], result.bits[2]);
  ck_assert_int_eq(equals.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_3) {
  s21_decimal assert;
  assert.bits[0] = 0b00000000000000000000000001001111;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal equals;
  equals.bits[0] = 0b00000000000000000000000000000111;
  equals.bits[1] = 0b00000000000000000000000000000000;
  equals.bits[2] = 0b00000000000000000000000000000000;
  equals.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  s21_truncate(assert, &result);
  ck_assert_int_eq(equals.bits[0], result.bits[0]);
  ck_assert_int_eq(equals.bits[1], result.bits[1]);
  ck_assert_int_eq(equals.bits[2], result.bits[2]);
  ck_assert_int_eq(equals.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_4) {
  s21_decimal assert;
  assert.bits[0] = 799;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b10000000000000100000000000000000;
  s21_decimal equals;
  equals.bits[0] = 7;
  equals.bits[1] = 0b00000000000000000000000000000000;
  equals.bits[2] = 0b00000000000000000000000000000000;
  equals.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  s21_truncate(assert, &result);
  ck_assert_int_eq(equals.bits[0], result.bits[0]);
  ck_assert_int_eq(equals.bits[1], result.bits[1]);
  ck_assert_int_eq(equals.bits[2], result.bits[2]);
  ck_assert_int_eq(equals.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_5) {
  s21_decimal assert;
  assert.bits[0] = 7999;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b00000000000000110000000000000000;
  s21_decimal equals;
  equals.bits[0] = 7;
  equals.bits[1] = 0b00000000000000000000000000000000;
  equals.bits[2] = 0b00000000000000000000000000000000;
  equals.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  s21_truncate(assert, &result);
  ck_assert_int_eq(equals.bits[0], result.bits[0]);
  ck_assert_int_eq(equals.bits[1], result.bits[1]);
  ck_assert_int_eq(equals.bits[2], result.bits[2]);
  ck_assert_int_eq(equals.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_6) {
  s21_decimal assert;
  assert.bits[0] = 79999;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b10000000000001000000000000000000;
  s21_decimal equals;
  equals.bits[0] = 7;
  equals.bits[1] = 0b00000000000000000000000000000000;
  equals.bits[2] = 0b00000000000000000000000000000000;
  equals.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  s21_truncate(assert, &result);
  ck_assert_int_eq(equals.bits[0], result.bits[0]);
  ck_assert_int_eq(equals.bits[1], result.bits[1]);
  ck_assert_int_eq(equals.bits[2], result.bits[2]);
  ck_assert_int_eq(equals.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_7) {
  s21_decimal assert;
  assert.bits[0] = 0b00000000000000000000000001001111;
  assert.bits[1] = 0b00000000000000000000000000000000;
  assert.bits[2] = 0b00000000000000000000000000000000;
  assert.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal equals;
  equals.bits[0] = 0b00000000000000000000000001001111;
  equals.bits[1] = 0b00000000000000000000000000000000;
  equals.bits[2] = 0b00000000000000000000000000000000;
  equals.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result;
  s21_truncate(assert, &result);
  ck_assert_int_eq(equals.bits[0], result.bits[0]);
  ck_assert_int_eq(equals.bits[1], result.bits[1]);
  ck_assert_int_eq(equals.bits[2], result.bits[2]);
  ck_assert_int_eq(equals.bits[3], result.bits[3]);
}
END_TEST

Suite *test_s21_truncate(void) {
  Suite *s = suite_create("s21_truncate");
  TCase *tc = tcase_create("Case from s21_truncate");
  tcase_add_test(tc, s21_truncate_1);
  tcase_add_test(tc, s21_truncate_2);
  tcase_add_test(tc, s21_truncate_3);
  tcase_add_test(tc, s21_truncate_4);
  tcase_add_test(tc, s21_truncate_5);
  tcase_add_test(tc, s21_truncate_6);
  tcase_add_test(tc, s21_truncate_7);
  suite_add_tcase(s, tc);
  return s;
}
