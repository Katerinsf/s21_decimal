#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int res = S21_TRUE;
  zero_init(result);
  *result = value;
  result->bits[3] ^= 0b10000000000000000000000000000000;
  if (s21_is_not_equal(*result, value)) res = S21_FALSE;
  return res;
}
