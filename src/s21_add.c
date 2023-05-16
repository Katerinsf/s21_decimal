#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // 0 - OK
  // 1 - the number is too large or equal to infinity
  // 2 - the number is too small or equal to negative infinity
  int error = 0;
  if (sign_check(value_1) == sign_check(value_2)) {
    s21_big_decimal v1 = dec_to_big(value_1);
    s21_big_decimal v2 = dec_to_big(value_2);
    s21_big_decimal res;

    add_big(v1, v2, &res);

    error = big_to_dec(res, result);
    if (error != 0) {
      error = sign_check(value_1) ? code_NEG_INF : code_POS_INF;
    }
  } else {
    error = sign_check(value_2) ? s21_sub(value_1, sign_inv(value_2), result)
                                : s21_sub(value_2, sign_inv(value_1), result);
  }
  return error;
}

// Adds of big decimal
int add_big(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result) {
  int flag_bit = 0;  // Bit transition flag

  zero_big_init(result);
  shift_big_dec(&value_1, &value_2);

  result->bits[6] = last_bits(pow_check_big(value_1), sign_check_big(value_1));
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 32; j++) {
      int temp_res =
          ((value_1.bits[i] >> j) ^ (value_2.bits[i] >> j)) &
          1;  // The result of adding specific bits without a bit transition
      temp_res ^= flag_bit;  // Bit transition
      if (!flag_bit) {       // No bit transition
        if (((temp_res & 1) == 0) && (((value_1.bits[i] >> j) & 1) ==
                                      1)) {  // There will be a bit transition
          flag_bit = 1;
        }
      } else if ((((value_1.bits[i] >> j) & 1) == 1) ||
                 (((value_2.bits[i] >> j) & 1) ==
                  1)) {  // There will be a bit transition
        flag_bit = 1;
      } else {
        flag_bit = 0;
      }
      result->bits[i] = result->bits[i] ^ (temp_res << j);
    }
  }
  return flag_bit;
}
