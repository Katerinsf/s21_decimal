#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  zero_init(result);
  int return_value = 0;
  if (!result) return_value = 1;
  int sign = sign_check(value);
  int scale = pow_check(value);
  set_scale_and_sign(&value, scale, 0);
  s21_decimal tmp;
  zero_init(&tmp);
  s21_truncate(value, &tmp);
  s21_decimal tmp_1 = tmp;
  s21_sub(value, tmp, &tmp);
  s21_decimal half = {{5, 0, 0, last_bits(1, 0)}};
  s21_decimal one = {{1, 0, 0, 0}};
  if (!s21_is_greater_or_equal(tmp, half)) {
    *result = tmp_1;
  } else {
    return_value = s21_add(tmp_1, one, result);
  }
  if (sign) set_scale_and_sign(result, 0, 1);
  set_scale_and_sign(&value, scale, sign);
  return return_value;
}

void set_scale_and_sign(s21_decimal *value, int scale, int sign) {
  value->bits[3] = last_bits(scale, sign);
}

void set_scale_and_sign_big(s21_big_decimal *value, int scale, int sign) {
  value->bits[6] = last_bits(scale, sign);
}
