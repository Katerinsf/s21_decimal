#include "s21_decimal.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // 0 - OK
  // 1 - the number is too large or equal to infinity
  // 2 - the number is too small or equal to negative infinity
  int error = 0;
  int sign = sign_check(value_1) ^ sign_check(value_2);
  int exp = pow_check(value_1) > pow_check(value_2) ? pow_check(value_1)
                                                    : pow_check(value_2);
  s21_decimal zero = {{0, 0, 0, 0}};

  if (s21_is_equal(value_2, zero)) {
    error = code_DIV_0;
  } else if (s21_is_equal(value_1, zero)) {
    *result = value_1;
  } else {
    zero_init(result);
    s21_big_decimal mod = {{0, 0, 0, 0, 0, 0, 0}};

    s21_big_decimal v1 = dec_to_big(value_1);
    s21_big_decimal v2 = dec_to_big(value_2);

    shift_big_dec(&v1, &v2);
    mod_big(&v1, v2, &mod);

    mod.bits[6] = last_bits(abs(exp), sign_check(value_1));
    error = big_to_dec(mod, result);
    if (error != 0) {
      error = sign ? code_NEG_INF : code_POS_INF;
    }
  }
  return error;
}

// Mod for big decimal
void mod_big(s21_big_decimal *value_1, s21_big_decimal value_2,
             s21_big_decimal *mod) {
  s21_big_decimal result;
  zero_big_init(&result);

  s21_big_decimal v1;  // Divisible at each iteration
  zero_big_init(&v1);
  s21_big_decimal v2 = value_2;
  v2.bits[6] = 0;  // Divisor modulo and unsigned

  int exp = pow_check_big(*value_1) - pow_check_big(value_2);
  int sign = sign_check_big(*value_1) ^ sign_check_big(value_2);
  if (exp < 0) {
    for (int i = 0; i < abs(exp); i++) {
      mul_big_dec_10(value_1);
    }
    exp = 0;
  }

  int j =
      0;  // Iteration or bit number on the left from 0 to (amount of bits - 1)
  int num = num_bits_big_dec(*value_1);  // // Amount of bits in dividend

  while (j < num) {
    shift_big_bits(&v1, 1);
    int k = num - 1 -
            j;  // Bit number from 0 to 95(191) on the right in the dividend
    v1.bits[0] ^= take_bit_big(*value_1, k);
    shift_big_bits(&result, 1);

    if (s21_is_greater_or_equal_big(v1, v2)) {
      sub_big(v1, v2, &v1);
      result.bits[0] ^= 1;
    }
    j++;
  }

  result.bits[6] = last_bits(exp, sign);
  *value_1 = result;
  *mod = v1;
  mod->bits[6] = last_bits(exp, sign);
}
