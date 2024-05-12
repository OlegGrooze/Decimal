#include "../test_s21_decimal.h"

START_TEST(s21_is_not_equal_1) {
  s21_decimal assert_1;
  s21_decimal assert_2;
  int result;
  int equals = FALSE;
  assert_1.bits[0] = 0b00000000000000000000000000000001;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000000000000000000000;

  assert_2.bits[0] = 0b00000000000000000000000000000001;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000000000000000000000;
  result = s21_is_not_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_not_equal_2) {
  s21_decimal assert_1;
  s21_decimal assert_2;
  int result;
  int equals = TRUE;
  assert_1.bits[0] = 0b00000000000000000000000000000000;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000000000000000000000;

  assert_2.bits[0] = 0b00000000000000000000000000000001;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000000000000000000000;
  result = s21_is_not_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_not_equal_3) {
  s21_decimal assert_1;
  s21_decimal assert_2;
  int result;
  int equals = FALSE;
  assert_1.bits[0] = 0b00000000000000000000000000000000;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000000000000000000000;

  assert_2.bits[0] = 0b00000000000000000000000000000000;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000000000000000000000;
  result = s21_is_not_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_not_equal_4) {
  s21_decimal assert_1;
  s21_decimal assert_2;
  int result;
  int equals = FALSE;
  assert_1.bits[0] = 0b00000000000000000000000000000001;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b10000000000000000000000000000000;

  assert_2.bits[0] = 0b00000000000000000000000000000001;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b10000000000000000000000000000000;
  result = s21_is_not_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_not_equal_5) {
  s21_decimal assert_1;
  s21_decimal assert_2;
  int result;
  int equals = TRUE;
  assert_1.bits[0] = 0b00000000000000000000000000000001;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b10000000000000000000000000000000;

  assert_2.bits[0] = 0b00000000000000000000000000000001;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b10000000000001000000000000000000;
  result = s21_is_not_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_not_equal_6) {
  s21_decimal assert_1;
  s21_decimal assert_2;
  int result;
  int equals = TRUE;
  assert_1.bits[0] = 0b11111111111111111111111111111111;
  assert_1.bits[1] = 0b00000000000000000000000000001111;
  assert_1.bits[2] = 0b00000000000000000000000000110000;
  assert_1.bits[3] = 0b10000000000001110000000000000000;

  assert_2.bits[0] = 0b00000000000000000000000000000001;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b10000000000000000000000000000000;
  result = s21_is_not_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_not_equal_7) {
  s21_decimal assert_1;
  s21_decimal assert_2;
  int result;
  int equals = FALSE;
  assert_1.bits[0] = 0b11111111111111111111111111111111;
  assert_1.bits[1] = 0b00000000000000000000000000001111;
  assert_1.bits[2] = 0b00000000000000000000000000110000;
  assert_1.bits[3] = 0b10000000000001110000000000000000;

  assert_2.bits[0] = 0b11111111111111111111111111111111;
  assert_2.bits[1] = 0b00000000000000000000000000001111;
  assert_2.bits[2] = 0b00000000000000000000000000110000;
  assert_2.bits[3] = 0b10000000000001110000000000000000;
  result = s21_is_not_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

Suite *test_s21_is_not_equal(void) {
  Suite *s = suite_create("s21_is_not_equal");
  TCase *tc = tcase_create("Case from s21_is_not_equal");
  tcase_add_test(tc, s21_is_not_equal_1);
  tcase_add_test(tc, s21_is_not_equal_2);
  tcase_add_test(tc, s21_is_not_equal_3);
  tcase_add_test(tc, s21_is_not_equal_4);
  tcase_add_test(tc, s21_is_not_equal_5);
  tcase_add_test(tc, s21_is_not_equal_6);
  tcase_add_test(tc, s21_is_not_equal_7);
  suite_add_tcase(s, tc);
  return s;
}