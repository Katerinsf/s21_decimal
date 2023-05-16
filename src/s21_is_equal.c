#include "s21_decimal.h"

int s21_is_equal(s21_decimal decimal_one, s21_decimal decimal_two) {
  int res = S21_FALSE;
  if (s21_compare(decimal_one, decimal_two) == 0) {
    res = S21_TRUE;
  }
  return res;
}

int s21_is_equal_big(s21_big_decimal decimal_one, s21_big_decimal decimal_two) {
  int res = S21_FALSE;
  if (s21_compare_big(decimal_one, decimal_two) == 0) {
    res = S21_TRUE;
  }
  return res;
}
