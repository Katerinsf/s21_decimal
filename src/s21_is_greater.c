#include "s21_decimal.h"

int s21_is_greater(s21_decimal decimal_one, s21_decimal decimal_two) {
  int res = S21_FALSE;
  if (s21_is_less_or_equal(decimal_one, decimal_two) == S21_FALSE) {
    res = S21_TRUE;
  }
  return res;
}

int s21_is_greater_big(s21_big_decimal decimal_one,
                       s21_big_decimal decimal_two) {
  int res = S21_FALSE;
  if (s21_is_less_or_equal_big(decimal_one, decimal_two) == S21_FALSE) {
    res = S21_TRUE;
  }
  return res;
}
