#include "s21_decimal.h"

// Output bits of decimal
int take_bit(s21_decimal value, int bit) {
  int res;
  int i = bit / 32;
  res = (value.bits[i] >> (bit - i * 32)) & 1;
  return res;
}

// Checks sign
int sign_check(s21_decimal value) { return (value.bits[3] >> 31) & 1; }

// Checks degree
int pow_check(s21_decimal value) {  // Возвращает степень
  return (value.bits[3] >> 16) & 255;
}

// Returns the number for the last bit of the array
int last_bits(int pow, int sign) { return (pow << 16) ^ (sign << 31); }

// Initialize big decimal by zero
void zero_init(s21_decimal *value) {
  for (int i = 0; i < 4; i++) {
    value->bits[i] = 0;
  }
}

// Changes sign to opposite
s21_decimal sign_inv(s21_decimal value) {
  value.bits[3] ^= (1 << 31);
  return value;
}

// Decimal modulus with degree
s21_decimal module(s21_decimal value) {
  s21_decimal res = value;
  res.bits[3] = last_bits(pow_check(value), 0);

  return res;
}

// Multiplying a decimal by 10
int mul_10(s21_decimal *value) {
  int error = 0;
  s21_decimal v1 = *value, v2 = *value, res = {{0, 0, 0, 0}};
  if (((value->bits[2] >> 29) & 7) == 0) {
    shift_bits(&v1, 3);
    shift_bits(&v2, 1);
    error = s21_add(v1, v2, &res);
  } else {
    error = 1;
  }
  if (error == 0) {
    res.bits[3] = last_bits(pow_check(*value) + 1, sign_check(*value));
    *value = res;
  }
  return error;
}

// Rounding to the required precision
s21_decimal bank_p(s21_decimal value, int p) {
  s21_decimal res = value;
  res.bits[3] = last_bits(pow_check(value) - p, sign_check(value));
  s21_banking_round(res, &res);
  res.bits[3] = last_bits(p, sign_check(value));
  return res;
}

// Comma shift
void shift_dec(s21_decimal *value_1, s21_decimal *value_2) {
  int p = abs(pow_check(*value_1) - pow_check(*value_2));
  int error = 0;
  while (p > 0) {
    if (pow_check(*value_1) > pow_check(*value_2)) {
      error = mul_10(value_2);
    } else if (pow_check(*value_1) < pow_check(*value_2)) {
      error = mul_10(value_1);
    }
    if (error == 0) {
      p--;
    } else {
      break;
    }
  }
  if (p > 0) {
    if ((pow_check(*value_1) > pow_check(*value_2))) {
      *value_1 = bank_p(*value_1, pow_check(*value_2));
    } else {
      *value_2 = bank_p(*value_2, pow_check(*value_1));
    }
  }
}

// Checks how many bits are used in decimale
int num_bits_dec(s21_decimal value) {
  int j;
  for (j = 95; j >= 0; j--) {
    int i = j / 32;
    int k = j - i * 32;
    if ((value.bits[i] >> k) & 1) {
      break;
    }
  }
  return j + 1;
}

// Shifts big decimal by j positions
int shift_bits(s21_decimal *value, int j) {
  int res = 1;
  if (j <= 96 - num_bits_dec(*value)) {
    for (int k = 0; k < j; k++) {
      int temp = 0;
      for (int i = 0; i < 3; i++) {
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
