#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  enum error { OK = 0, ERROR };
  enum error error_status;
  error_status = ERROR;

  for (int i = 0; i <= 3; i++) {
    dst->bits[i] = 0;
  }
  if (src < 0) {
    src = -src;
    dst->bits[3] = 1;
    dst->bits[3] = dst->bits[3] << 31;
  }
  if (src < 79228162514264337593543950335.0) {
    float helper = src;
    int pow_value = 0;
    if (src) {
      int count = 1;
      while (count != 7 && helper < 1000000) {
        if (count <= 7 && helper > 1) {
          count++;
        }
        helper *= 10;
        pow_value++;
      }
    }
    while (helper > 10000000) {
      helper /= 10;
      pow_value++;
    }
    long long unsigned int new_src = round(helper);
    if (fabs(src) < 1) {
      while (fabs(new_src / pow(10, pow_value) - src) >=
             (0.5 / pow(10, pow_value))) {
        if (new_src / pow(10, pow_value) > src) {
          new_src--;
        } else {
          new_src++;
        }
      }
    }
    while (new_src % 10 == 0 && pow_value != 0 && new_src != 0) {
      new_src /= 10;
      pow_value--;
    }
    if (pow_value <= 28 && (src / pow(10, pow_value)) < 1) {
      pow_value *= pow(2, 16);
      dst->bits[3] = dst->bits[3] ^ pow_value;
      pow_value = 0;
    }
    if (new_src * pow(10, pow_value) > pow(2, 64)) {
      dst->bits[2] = truncl(new_src * pow(10, pow_value) / pow(2, 64));
      new_src = new_src * pow(10, pow_value) - dst->bits[2] * pow(2, 64);
    } else {
      new_src *= pow(10, pow_value);
    }
    if (new_src > pow(2, 32)) {
      dst->bits[1] = truncl(new_src / pow(2, 32));
      new_src -= dst->bits[1] * pow(2, 32);
    }
    dst->bits[0] = new_src;
    error_status = OK;
  }
  return error_status;
}
