#include "s21_decimal.h"

int s21_is_not_equal(s21_decimal decimal_one, s21_decimal decimal_two) {
  int res = S21_FALSE;
  if (s21_compare(decimal_one, decimal_two) != 0) {
    res = S21_TRUE;
  }
  return res;
}
