#include "s21_decimal.h"

int s21_is_even(s21_decimal value);
void s21_tmp_upgrade(s21_decimal *value);

int s21_banking_round(s21_decimal value, s21_decimal *result) {
  int return_value = 0;
  zero_init(result);
  if (!result) return_value = 1;
  int sign = sign_check(value);
  int scale = pow_check(value);
  set_scale_and_sign(&value, scale, 0);
  s21_decimal tmp = {0};
  s21_truncate(value, &tmp);
  s21_decimal tmp_1 = tmp;
  s21_sub(value, tmp, &tmp);

  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal half = {{5, 0, 0, last_bits(1, 0)}};
  if (scale) {
    s21_tmp_upgrade(&tmp);
    if (s21_is_less(tmp, half)) {
      *result = tmp_1;
    } else if (s21_is_greater(tmp, half)) {
      return_value = s21_add(tmp_1, one, result);
    } else if (s21_is_equal(tmp, half)) {
      if (s21_is_even(tmp_1)) {
        *result = tmp_1;
      } else {
        return_value = s21_add(tmp_1, one, result);
      }
    }
  } else {
    *result = value;
  }
  if (sign) set_scale_and_sign(result, 0, 1);
  set_scale_and_sign(&value, scale, sign);
  return return_value;
}

int s21_is_even(s21_decimal value) {
  s21_decimal two = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  int return_value = 0;
  s21_div(value, two, &res);
  int l = pow_check(res);
  if (l == 0) return_value = 1;
  return return_value;
}

void s21_tmp_upgrade(s21_decimal *value) {
  value->bits[3] = last_bits((pow_check(*value) - 1), 0);
  s21_truncate(*value, value);
  value->bits[3] = last_bits(1, 0);
}

int s21_is_even_big(s21_big_decimal value);
void s21_tmp_upgrade_big(s21_big_decimal *value);

int s21_banking_round_big(s21_big_decimal value, s21_big_decimal *result) {
  int return_value = 0;
  zero_big_init(result);
  if (!result) return_value = 1;
  int sign = sign_check_big(value);
  int scale = pow_check_big(value);
  set_scale_and_sign_big(&value, scale, 0);
  s21_big_decimal tmp = {0};
  s21_truncate_big(value, &tmp);
  s21_big_decimal tmp_1 = tmp;
  sub_big(value, tmp, &tmp);

  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal half = {{5, 0, 0, 0, 0, 0, last_bits(1, 0)}};
  if (scale) {
    s21_tmp_upgrade_big(&tmp);
    if (s21_is_less_big(tmp, half)) {
      *result = tmp_1;
    } else if (s21_is_greater_big(tmp, half)) {
      return_value = add_big(tmp_1, one, result);
    } else if (s21_is_equal_big(tmp, half)) {
      if (s21_is_even_big(tmp_1)) {
        *result = tmp_1;
      } else {
        return_value = add_big(tmp_1, one, result);
      }
    }
  } else {
    *result = value;
  }
  if (sign) set_scale_and_sign_big(result, 0, 1);
  set_scale_and_sign_big(&value, scale, sign);
  return return_value;
}

int s21_is_even_big(s21_big_decimal value) {
  s21_decimal two = {{2, 0, 0, 0}};
  s21_big_decimal res = {0};
  int return_value = 0;
  div_big(value, two, &res);
  int l = pow_check_big(res);
  if (l == 0) return_value = 1;
  return return_value;
}

void s21_tmp_upgrade_big(s21_big_decimal *value) {
  value->bits[6] = last_bits((pow_check_big(*value) - 1), 0);
  s21_truncate_big(*value, value);
  value->bits[6] = last_bits(1, 0);
}
