#include "../test_s21_decimal.h"

START_TEST(s21_from_int_to_decimal_1) {
  int assert = 0;
  s21_decimal result;
  s21_decimal equals;
  equals.bits[0] = 0b00000000000000000000000000000000;
  equals.bits[1] = 0b00000000000000000000000000000000;
  equals.bits[2] = 0b00000000000000000000000000000000;
  equals.bits[3] = 0b00000000000000000000000000000000;
  s21_from_int_to_decimal(assert, &result);
  ck_assert_int_eq(equals.bits[0], result.bits[0]);
  ck_assert_int_eq(equals.bits[1], result.bits[1]);
  ck_assert_int_eq(equals.bits[2], result.bits[2]);
  ck_assert_int_eq(equals.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_2) {
  int assert = 1;
  s21_decimal result;
  s21_decimal equals;
  equals.bits[0] = 0b00000000000000000000000000000001;
  equals.bits[1] = 0b00000000000000000000000000000000;
  equals.bits[2] = 0b00000000000000000000000000000000;
  equals.bits[3] = 0b00000000000000000000000000000000;
  s21_from_int_to_decimal(assert, &result);
  ck_assert_int_eq(equals.bits[0], result.bits[0]);
  ck_assert_int_eq(equals.bits[1], result.bits[1]);
  ck_assert_int_eq(equals.bits[2], result.bits[2]);
  ck_assert_int_eq(equals.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_3) {
  int assert = -1;
  s21_decimal result;
  s21_decimal equals;
  equals.bits[0] = 0b00000000000000000000000000000001;
  equals.bits[1] = 0b00000000000000000000000000000000;
  equals.bits[2] = 0b00000000000000000000000000000000;
  equals.bits[3] = 0b10000000000000000000000000000000;
  s21_from_int_to_decimal(assert, &result);
  ck_assert_int_eq(equals.bits[0], result.bits[0]);
  ck_assert_int_eq(equals.bits[1], result.bits[1]);
  ck_assert_int_eq(equals.bits[2], result.bits[2]);
  ck_assert_int_eq(equals.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_4) {
  int assert = -2;
  s21_decimal result;
  s21_decimal equals;
  equals.bits[0] = 0b00000000000000000000000000000010;
  equals.bits[1] = 0b00000000000000000000000000000000;
  equals.bits[2] = 0b00000000000000000000000000000000;
  equals.bits[3] = 0b10000000000000000000000000000000;
  s21_from_int_to_decimal(assert, &result);
  ck_assert_int_eq(equals.bits[0], result.bits[0]);
  ck_assert_int_eq(equals.bits[1], result.bits[1]);
  ck_assert_int_eq(equals.bits[2], result.bits[2]);
  ck_assert_int_eq(equals.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_5) {
  int assert = 2;
  s21_decimal result;
  s21_decimal equals;
  equals.bits[0] = 0b00000000000000000000000000000010;
  equals.bits[1] = 0b00000000000000000000000000000000;
  equals.bits[2] = 0b00000000000000000000000000000000;
  equals.bits[3] = 0b00000000000000000000000000000000;
  s21_from_int_to_decimal(assert, &result);
  ck_assert_int_eq(equals.bits[0], result.bits[0]);
  ck_assert_int_eq(equals.bits[1], result.bits[1]);
  ck_assert_int_eq(equals.bits[2], result.bits[2]);
  ck_assert_int_eq(equals.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_6) {
  int assert = MAX_INT;
  s21_decimal result;
  s21_decimal equals;
  equals.bits[0] = 0b01111111111111111111111111111111;
  equals.bits[1] = 0b00000000000000000000000000000000;
  equals.bits[2] = 0b00000000000000000000000000000000;
  equals.bits[3] = 0b00000000000000000000000000000000;
  s21_from_int_to_decimal(assert, &result);
  ck_assert_int_eq(equals.bits[0], result.bits[0]);
  ck_assert_int_eq(equals.bits[1], result.bits[1]);
  ck_assert_int_eq(equals.bits[2], result.bits[2]);
  ck_assert_int_eq(equals.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_7) {
  int assert = -MAX_INT;
  s21_decimal result;
  s21_decimal equals;
  equals.bits[0] = 0b01111111111111111111111111111111;
  equals.bits[1] = 0b00000000000000000000000000000000;
  equals.bits[2] = 0b00000000000000000000000000000000;
  equals.bits[3] = 0b10000000000000000000000000000000;
  s21_from_int_to_decimal(assert, &result);
  ck_assert_int_eq(equals.bits[0], result.bits[0]);
  ck_assert_int_eq(equals.bits[1], result.bits[1]);
  ck_assert_int_eq(equals.bits[2], result.bits[2]);
  ck_assert_int_eq(equals.bits[3], result.bits[3]);
}
END_TEST

Suite *test_s21_from_int_to_decimal(void) {
  Suite *s = suite_create("s21_from_int_to_decimal");
  TCase *tc = tcase_create("Case from s21_from_int_to_decimal");
  tcase_add_test(tc, s21_from_int_to_decimal_1);
  tcase_add_test(tc, s21_from_int_to_decimal_2);
  tcase_add_test(tc, s21_from_int_to_decimal_3);
  tcase_add_test(tc, s21_from_int_to_decimal_4);
  tcase_add_test(tc, s21_from_int_to_decimal_5);
  tcase_add_test(tc, s21_from_int_to_decimal_6);
  tcase_add_test(tc, s21_from_int_to_decimal_7);
  suite_add_tcase(s, tc);
  return s;
}