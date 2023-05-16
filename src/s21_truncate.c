#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  zero_init(result);
  int res = 0;
  int scale = pow_check(value);
  int sign = sign_check(value);
  if (!result) res = 1;
  if (result != NULL) {
    *result = value;
    result->bits[3] = last_bits(0, sign);
  }
  if (scale) {
    for (int i = scale; i > 0; i--) {
      int_div_10(*result, result);
    }
  }
  return res;
}

int s21_truncate_big(s21_big_decimal value, s21_big_decimal *result) {
  zero_big_init(result);
  int res = 0;
  int scale = pow_check_big(value);
  int sign = sign_check_big(value);
  if (!result) res = 1;
  if (result != NULL) {
    *result = value;
    result->bits[6] = last_bits(0, sign);
  }
  if (scale) {
    for (int i = scale; i > 0; i--) {
      int_div_big_10(*result, result);
    }
  }
  return res;
}
