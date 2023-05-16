#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  enum error { OK = 0, ERROR };
  enum sign { PLUS = 0, MINUS };
  enum error error_status;
  enum sign sign_bit;
  error_status = ERROR;
  sign_bit = PLUS;
  *dst = 0;
  int pow_value;
  long double value_decimal = 0;
  value_decimal = src.bits[2] * pow(2, 64);
  value_decimal += src.bits[1] * pow(2, 32);
  value_decimal += src.bits[0];
  if (src.bits[3] >> 31 == 1) {
    sign_bit = MINUS;
    src.bits[3] = src.bits[3] ^ 0b10000000000000000000000000000000;
  }
  pow_value = src.bits[3] >> 16;
  if (pow_value <= 28) {
    value_decimal /= pow(10, pow_value);
    if (sign_bit == MINUS) {
      value_decimal = -value_decimal;
    }
    *dst = value_decimal;
    error_status = OK;
  } else {
    *dst = 0;
  }
  return error_status;
}
