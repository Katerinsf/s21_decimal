#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  zero_init(result);
  int res = 0;
  if (!result) res = 1;
  int sign = sign_check(value);
  if (result != NULL) {
    *result = value;
    s21_truncate(*result, result);
    if (sign == 1) {
      s21_decimal one = {{1, 0, 0, 0}};
      s21_sub(*result, one, result);
    }
  }
  return res;
}
