#include "../test_s21_decimal.h"

START_TEST(s21_is_greater_or_equal_1) {
  s21_decimal assert_1;
  assert_1.bits[0] = 0b00000000000000000000000000000010;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal assert_2;
  assert_2.bits[0] = 0b00000000000000000000000000000001;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000000000000000000000;
  int equals = TRUE;
  int result = s21_is_greater_or_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_greater_or_equal_2) {
  s21_decimal assert_1;
  assert_1.bits[0] = 0b00000000000000000000000000000001;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal assert_2;
  assert_2.bits[0] = 0b00000000000000000000000000000001;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000000000000000000000;
  int equals = TRUE;
  int result = s21_is_greater_or_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_greater_or_equal_3) {
  s21_decimal assert_1;
  assert_1.bits[0] = 0b00000000000000000000000000000001;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal assert_2;
  assert_2.bits[0] = 0b00000000000000000000000000000001;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000000000000000000000;
  s21_set_sign_minus(&assert_2);
  int equals = TRUE;
  int result = s21_is_greater_or_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST
// 0 > -1
START_TEST(s21_is_greater_or_equal_4) {
  s21_decimal assert_1;
  assert_1.bits[0] = 0b00000000000000000000000000000000;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal assert_2;
  assert_2.bits[0] = 0b00000000000000000000000000000001;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000000000000000000000;
  s21_set_sign_minus(&assert_2);
  int equals = TRUE;
  int result = s21_is_greater_or_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

// 0 < 1
START_TEST(s21_is_greater_or_equal_5) {
  s21_decimal assert_1;
  assert_1.bits[0] = 0b00000000000000000000000000000000;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal assert_2;
  assert_2.bits[0] = 0b00000000000000000000000000000001;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000000000000000000000;
  int equals = FALSE;
  int result = s21_is_greater_or_equal(assert_1, assert_2);

  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_greater_or_equal_6) {
  s21_decimal assert_1;
  assert_1.bits[0] = 0b00000000000000000000000000000011;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal assert_2;
  assert_2.bits[0] = 0b00000000000000000000000000000001;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000000000000000000000;
  int equals = FALSE;
  int result = s21_is_greater_or_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_greater_or_equal_7) {
  s21_decimal assert_1;
  assert_1.bits[0] = 0b00000000000000000000000000000011;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal assert_2;
  assert_2.bits[0] = 0b00000000000000000000000000000000;
  assert_2.bits[1] = 0b00000000000000000000000000000001;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000000000000000000000;
  int equals = FALSE;
  int result = s21_is_greater_or_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_greater_or_equal_8) {
  s21_decimal assert_1;
  assert_1.bits[0] = 0b00000000000000000000000000000011;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal assert_2;
  assert_2.bits[0] = 0b00000000000000000000000001000000;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000110000000000000000;
  int equals = TRUE;
  int result = s21_is_greater_or_equal(assert_1, assert_2);

  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_greater_or_equal_9) {
  s21_decimal assert_1;
  assert_1.bits[0] = 0b00000000000000000000000000011111;
  assert_1.bits[1] = 0b00000000000000000000000000000001;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal assert_2;
  assert_2.bits[0] = 0b00000000000000000011111111000000;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000110000000000000000;
  int equals = TRUE;
  int result = s21_is_greater_or_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_greater_or_equal_10) {
  s21_decimal assert_1;
  assert_1.bits[0] = 0b00000000000000000000000000011111;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal assert_2;
  assert_2.bits[0] = 0b00000000000000000011111111000000;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000110000000000000000;
  int equals = FALSE;
  int result = s21_is_greater_or_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_greater_or_equal_11) {
  s21_decimal assert_1;
  assert_1.bits[0] = 0b00000000000000000000000000000001;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal assert_2;
  assert_2.bits[0] = 0b00000000000000000000000000000011;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000000000000000000000;
  int equals = TRUE;
  s21_set_sign_minus(&assert_1);
  s21_set_sign_minus(&assert_2);
  int result = s21_is_greater_or_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_greater_or_equal_12) {
  s21_decimal assert_1;
  assert_1.bits[0] = 0b00000000000000000000000000000001;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal assert_2;
  assert_2.bits[0] = 0b00000000000000000000000000000011;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000000000000000000000;
  int equals = FALSE;
  s21_set_sign_minus(&assert_1);
  int result = s21_is_greater_or_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

START_TEST(s21_is_greater_or_equal_13) {
  s21_decimal assert_1;
  assert_1.bits[0] = 0b00000000000000000000000000000011;
  assert_1.bits[1] = 0b00000000000000000000000000000000;
  assert_1.bits[2] = 0b00000000000000000000000000000000;
  assert_1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal assert_2;
  assert_2.bits[0] = 0b00000000000000000000000000000001;
  assert_2.bits[1] = 0b00000000000000000000000000000000;
  assert_2.bits[2] = 0b00000000000000000000000000000000;
  assert_2.bits[3] = 0b00000000000000000000000000000000;
  int equals = FALSE;
  s21_set_sign_minus(&assert_1);
  int result = s21_is_greater_or_equal(assert_1, assert_2);
  ck_assert_int_eq(equals, result);
}
END_TEST

Suite *test_s21_is_greater_or_equal(void) {
  Suite *s = suite_create("s21_is_greater_or_equal");
  TCase *tc = tcase_create("Case from s21_is_greater_or_equal");
  tcase_add_test(tc, s21_is_greater_or_equal_1);
  tcase_add_test(tc, s21_is_greater_or_equal_2);
  tcase_add_test(tc, s21_is_greater_or_equal_3);
  tcase_add_test(tc, s21_is_greater_or_equal_4);
  tcase_add_test(tc, s21_is_greater_or_equal_5);
  tcase_add_test(tc, s21_is_greater_or_equal_6);
  tcase_add_test(tc, s21_is_greater_or_equal_7);
  tcase_add_test(tc, s21_is_greater_or_equal_8);
  tcase_add_test(tc, s21_is_greater_or_equal_9);
  tcase_add_test(tc, s21_is_greater_or_equal_10);
  tcase_add_test(tc, s21_is_greater_or_equal_11);
  tcase_add_test(tc, s21_is_greater_or_equal_12);
  tcase_add_test(tc, s21_is_greater_or_equal_13);
  suite_add_tcase(s, tc);
  return s;
}