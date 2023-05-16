#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // 0 - OK
  // 1 - the number is too large or equal to infinity
  // 2 - the number is too small or equal to negative infinity
  // 3 - division by 0
  int error = 0;
  int sign = sign_check(value_1) ^ sign_check(value_2);
  s21_decimal zero = {{0, 0, 0, 0}};
  s21_decimal one = {{1, 0, 0, 0}};

  if (s21_is_equal(value_2, zero)) {
    error = code_DIV_0;
  } else if (s21_is_equal(value_1, zero) || s21_is_equal(value_2, one)) {
    *result = value_1;
  } else {
    s21_big_decimal v1 = dec_to_big(value_1);
    s21_big_decimal res = {{0, 0, 0, 0, 0, 0, 0}};

    div_big(v1, value_2, &res);

    error = big_to_dec(res, result);
    if (error != 0) {
      error = sign ? code_NEG_INF : code_POS_INF;
    }
  }
  return error;
}

// Вivision of big decimal
void div_big(s21_big_decimal value_1, s21_decimal value_2,
             s21_big_decimal *result) {
  zero_big_init(result);
  s21_big_decimal mod;  // Remainder of the division
  zero_big_init(&mod);

  s21_big_decimal v1 = value_1;  // Dividend on every iteration
  s21_decimal v2 = value_2;

  int exp = pow_check_big(value_1) - pow_check(value_2);
  int sign = sign_check_big(value_1) ^ sign_check(value_2);
  if (exp < 0) {
    for (int i = 0; i < abs(exp); i++) {
      mul_big_dec_10(&v1);
    }
    exp = 0;
  }

  v1.bits[6] = last_bits(0, 0);
  v2.bits[3] = last_bits(0, 0);

  do {
    int_div_big(&v1, v2, &mod);
    mul_big_dec_10(result);
    add_big(*result, v1, result);
    mul_big_dec_10(&mod);
    v1 = mod;
    exp++;
  } while (!(v1.bits[0] == 0 && v1.bits[1] == 0 && v1.bits[2] == 0 &&
             v1.bits[3] == 0 && v1.bits[4] == 0 && v1.bits[5] == 0) &&
           exp <= 28);
  exp--;
  result->bits[6] = last_bits(exp, sign);
}

// Integer division big decimal and simple
// The degree of the quotient and the remainder are preserved and the same
void int_div_big(s21_big_decimal *value_1, s21_decimal value_2,
                 s21_big_decimal *mod) {
  s21_big_decimal result;
  zero_big_init(&result);

  s21_big_decimal v1;  // Divisible at each iteration
  zero_big_init(&v1);
  s21_big_decimal v2 = dec_to_big(value_2);
  v2.bits[6] = 0;  // Divisor modulo and unsigned

  int exp = pow_check_big(*value_1) - pow_check(value_2);
  int sign = sign_check_big(*value_1) ^ sign_check(value_2);
  if (exp < 0) {
    for (int i = 0; i < abs(exp); i++) {
      mul_big_dec_10(value_1);
    }
    exp = 0;
  }

  int j =
      0;  // Iteration or bit number on the left from 0 to (amount of bits - 1)
  int num = num_bits_big_dec(*value_1);  // Amount of bits in dividend

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

// Integer division by 10
int int_div_10(s21_decimal value_1, s21_decimal *result) {
  int error = 0;
  s21_decimal ten = {{10, 0, 0, 0}};
  zero_init(result);

  if (s21_is_greater_or_equal(module(value_1), ten)) {
    s21_decimal v1;  // Divisible at each iteration
    zero_init(&v1);

    int j = 0;  // Iteration or bit number on the left from 0 to (amount of bits
                // - 1)
    while (j < num_bits_dec(value_1)) {
      shift_bits(&v1, 1);
      int k = num_bits_dec(value_1) - 1 -
              j;  // Bit number from 0 to 95 on the right in the dividend
      v1.bits[0] ^= take_bit(value_1, k);
      shift_bits(result, 1);

      if (s21_is_greater_or_equal(v1, ten)) {
        s21_sub(v1, ten, &v1);
        result->bits[0] ^= 1;
      }
      j++;
    }
    result->bits[3] = last_bits(pow_check(value_1), sign_check(value_1));
  }
  return error;
}

// Integer division by 10 for big decimal
int int_div_big_10(s21_big_decimal value_1, s21_big_decimal *result) {
  int error = 0;
  s21_decimal ten = {{10, 0, 0, 0}};
  zero_big_init(result);

  s21_decimal v1;  // Divisible at each iteration
  zero_init(&v1);

  int j =
      0;  // Iteration or bit number on the left from 0 to (amount of bits - 1)
  while (j < num_bits_big_dec(value_1)) {
    shift_bits(&v1, 1);
    int k = num_bits_big_dec(value_1) - 1 -
            j;  // Bit number from 0 to 95 on the right in the dividend
    v1.bits[0] ^= take_bit_big(value_1, k);
    shift_big_bits(result, 1);

    if (s21_is_greater_or_equal(v1, ten)) {
      s21_sub(v1, ten, &v1);
      result->bits[0] ^= 1;
    }
    j++;
  }
  result->bits[6] = last_bits(pow_check_big(value_1), pow_check_big(value_1));
  return error;
}
