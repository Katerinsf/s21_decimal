#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // 0 - OK
  // 1 - the number is too large or equal to infinity
  // 2 - the number is too small or equal to negative infinity
  int error = 0;
  if (sign_check(value_1) == sign_check(value_2)) {
    zero_init(result);
    if (s21_is_greater_or_equal(module(value_1), module(value_2))) {
      // The result has the same sign as value_1, and change - to + for value_1
      // and value_2
      int sign = sign_check(value_1);
      value_1 = sign_check(value_1) ? sign_inv(value_1) : value_1;
      value_2 = sign_check(value_2) ? sign_inv(value_2) : value_2;

      s21_big_decimal v1 = dec_to_big(value_1);
      s21_big_decimal v2 = dec_to_big(value_2);
      s21_big_decimal res;
      sub_big(v1, v2, &res);
      res.bits[6] = last_bits(pow_check_big(res), sign);

      error = big_to_dec(res, result);
      if (error != 0) {
        error = sign_check_big(res) ? code_NEG_INF : code_POS_INF;
      }
    } else {
      zero_init(result);
      error = s21_sub(value_2, value_1, result);
      *result = sign_inv(*result);
    }
  } else {
    value_2 = sign_inv(value_2);
    error = s21_add(value_1, value_2, result);
  }
  return error;
}

// Subtraction of big decimals (without comparison of signs and modules)
int sub_big(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result) {
  int error = 0;  // Not really necessary
  zero_big_init(result);

  // Subtract positive numbers and |a| > |b|
  shift_big_dec(&value_1, &value_2);
  result->bits[6] = last_bits(pow_check_big(value_1), sign_check_big(value_1));
  for (int j = 0; j < 192; j++) {
    int i = j / 32;
    int temp_res =
        ((value_1.bits[i] >> (j - i * 32)) ^
         (value_2.bits[i] >> (j - i * 32))) &
        1;  // The result of adding specific bits without a bit transition
    if (temp_res && !(value_1.bits[i] >> (j - i * 32) & 1)) {
      change_bits_big(&value_1, j);
    }
    result->bits[i] = result->bits[i] ^ (temp_res << (j - i * 32));
  }
  return error;
}

// Takes a digit for a big decimal
void change_bits_big(s21_big_decimal *value, int j) {
  j++;
  int i = j / 32;
  while (j < 192 && !((value->bits[i] >> (j - i * 32)) & 1)) {
    value->bits[i] ^= 1 << (j - i * 32);
    j++;
    i = j / 32;
  }
  value->bits[i] &= ~(1 << (j - i * 32));
}
