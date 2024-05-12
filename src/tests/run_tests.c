#include <stdio.h>

#include "test_s21_decimal.h"

int main(void) {
  int count_tests = 18;
  Suite *list[] = {test_s21_add(),
                   test_s21_div(),
                   test_s21_floor(),
                   test_s21_from_decimal_to_float(),
                   test_s21_from_decimal_to_int(),
                   test_s21_from_float_to_decimal(),
                   test_s21_from_int_to_decimal(),
                   test_s21_is_equal(),
                   test_s21_is_greater(),
                   test_s21_is_greater_or_equal(),
                   test_s21_is_less(),
                   test_s21_is_less_or_equal(),
                   test_s21_is_not_equal(),
                   test_s21_mul(),
                   test_s21_negate(),
                   test_s21_round(),
                   test_s21_sub(),
                   test_s21_truncate()};
  for (int i = 0; i < count_tests; i++) {
    printf(
        "\n===============================================================\n");
    printf("===================== Test Start #%d ===========================\n",
           i + 1);
    SRunner *runner = srunner_create(list[i]);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
    printf("======================= Test End #%d  ==========================\n",
           i + 1);
    printf("===============================================================\n");
  }
  return (0);
}
