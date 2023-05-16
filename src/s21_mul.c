#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // 0 - OK
  // 1 - the number is too large or equal to infinity
  // 2 - the number is too small or equal to negative infinity
  int error = 0;
  int sign = sign_check(value_1) ^ sign_check(value_2);

  s21_big_decimal v1 = dec_to_big(value_1);
  s21_big_decimal v2 = dec_to_big(value_2);
  s21_big_decimal res = {{0, 0, 0, 0, 0, 0, 0}};

  mul_big(v1, v2, &res);

  error = big_to_dec(res, result);
  if (error != 0) {
    error = sign ? code_NEG_INF : code_POS_INF;
  }

  return error;
}

// Multiplication of big decimal
void mul_big(s21_big_decimal value_1, s21_big_decimal value_2,
             s21_big_decimal *result) {
  zero_big_init(result);
  s21_big_decimal temp_res;
  zero_big_init(&temp_res);

  int exp = pow_check_big(value_1) + pow_check_big(value_2);
  int sign = sign_check_big(value_1) ^ sign_check_big(value_2);
  value_1.bits[6] = 0;
  value_2.bits[6] = 0;

  for (int j = 0; j < num_bits_big_dec(value_2); j++) {
    if (take_bit_big(value_2, j)) {
      temp_res = value_1;
      shift_big_bits(&temp_res, j);
      add_big(
          *result, temp_res,
          result);  // There will never be an error, so the result is not needed
    }
  }
  result->bits[6] = last_bits(exp, sign);
}
