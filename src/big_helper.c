#include "s21_decimal.h"

// Converts decimal to big decimal
s21_big_decimal dec_to_big(s21_decimal value) {
  s21_big_decimal res;
  zero_big_init(&res);
  for (int i = 0; i < 3; i++) {
    res.bits[i] = value.bits[i];
  }
  res.bits[6] = value.bits[3];
  return res;
}

// Converts big decimal to decimal with rounding
// Error code: 0 - OK, 1 - the number is too large or equal to infinity
int big_to_dec(s21_big_decimal value1, s21_decimal *value2) {
  int error = 1;
  s21_big_decimal v1;
  zero_big_init(&v1);
  int exp = pow_check_big(value1);
  for (int p = exp; p >= 0; p--) {
    v1 = bank_p_big(value1, p);
    if (check_big(v1) == 0 && pow_check_big(v1) < 29) {
      for (int i = 0; i < 3; i++) {
        value2->bits[i] = v1.bits[i];
      }
      value2->bits[3] = v1.bits[6];
      error = 0;
      break;
    }
  }
  return error;
}

// Checks if there are bits in the extended part of the decimal
// Error code: 0 - nothing, 1 - yes
int check_big(s21_big_decimal value) {
  return (value.bits[3] == 0 && value.bits[4] == 0 && value.bits[5] == 0) ? 0
                                                                          : 1;
}

// Output bits of big decimal
int take_bit_big(s21_big_decimal value, int bit) {
  int res;
  int i = bit / 32;
  res = (value.bits[i] >> (bit - i * 32)) & 1;
  return res;
}

// Checks sign
int sign_check_big(s21_big_decimal value) { return (value.bits[6] >> 31) & 1; }

// Returns degree
int pow_check_big(s21_big_decimal value) { return (value.bits[6] >> 16) & 255; }

// Initialize big decimal by zero
void zero_big_init(s21_big_decimal *value) {
  for (int i = 0; i < 7; i++) {
    value->bits[i] = 0;
  }
}

// Multiplying a big decimal by 10
int mul_big_10(s21_big_decimal *value) {
  int error = 0;
  s21_big_decimal v1 = *value, v2 = *value, res = {{0, 0, 0, 0, 0, 0, 0}};
  if (((value->bits[5] >> 29) & 7) == 0) {
    shift_big_bits(&v1, 3);
    shift_big_bits(&v2, 1);
    error = add_big(v1, v2, &res);
  } else {
    error = 1;
  }
  if (error == 0) {
    res.bits[6] = last_bits(pow_check_big(*value) + 1, sign_check_big(*value));
    *value = res;
  }
  return error;
}

// Rounding to the required precision
s21_big_decimal bank_p_big(s21_big_decimal value, int p) {
  s21_big_decimal res = value;
  res.bits[6] = last_bits(pow_check_big(value) - p, sign_check_big(value));
  s21_banking_round_big(res, &res);
  res.bits[6] = last_bits(p, sign_check_big(value));
  return res;
}

// Comma shift
void shift_big_dec(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  int p = abs(pow_check_big(*value_1) - pow_check_big(*value_2));
  int error = 0;
  while (p > 0) {
    if (pow_check_big(*value_1) > pow_check_big(*value_2)) {
      error = mul_big_10(value_2);
    } else if (pow_check_big(*value_1) < pow_check_big(*value_2)) {
      error = mul_big_10(value_1);
    }
    if (error == 0) {
      p--;
    } else {
      break;
    }
  }
}

// Checks how many bits are used in big decimale
int num_bits_big_dec(s21_big_decimal value) {
  int j;
  for (j = 191; j >= 0; j--) {
    int i = j / 32;
    int k = j - i * 32;
    if ((value.bits[i] >> k) & 1) {
      break;
    }
  }
  return j + 1;
}

// Shifts big decimal by j positions
int shift_big_bits(s21_big_decimal *value, int j) {
  int res = 1;
  if (j <= 192 - num_bits_big_dec(*value)) {
    for (int k = 0; k < j; k++) {
      int temp = 0;
      for (int i = 0; i < 6; i++) {
        if (temp) {
          temp = value->bits[i] >> 31;
          value->bits[i] = ((value->bits[i] & ~(1 << 31)) << 1) ^ 1;
        } else {
          temp = value->bits[i] >> 31;
          value->bits[i] = (value->bits[i] & ~(1 << 31)) << 1;
        }
      }
    }
  } else {
    res = 0;
  }
  return res;
}

// Multiplying a big decima by 10, degree and sign do not change | (To divide)
int mul_big_dec_10(s21_big_decimal *value) {
  int error = 0;
  s21_big_decimal v1 = *value, v2 = *value, res = {{0, 0, 0, 0, 0, 0, 0}};
  if (((value->bits[5] >> 29) & 7) == 0) {
    shift_big_bits(&v1, 3);
    shift_big_bits(&v2, 1);
    error = add_big(v1, v2, &res);
  } else {
    error = 1;
  }
  if (error == 0) {
    res.bits[6] = last_bits(pow_check_big(*value), sign_check_big(*value));
    *value = res;
  }
  return error;
}
