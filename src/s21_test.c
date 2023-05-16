#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_decimal.h"

// меньше

START_TEST(is_less_1) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(x, y));
}
END_TEST

START_TEST(is_less_2) {
  s21_decimal x = {{123451967, 202, 7, last_bits(6, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(x, y));
}
END_TEST

START_TEST(is_less_3) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 2, last_bits(5, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(x, y));
}
END_TEST

START_TEST(is_less_4) {
  s21_decimal x = {{123451967, 0, 7, last_bits(5, 1)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 1)}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(x, y));
}
END_TEST

START_TEST(is_less_5) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 1)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(x, y));
}
END_TEST

START_TEST(is_less_6) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(x, y));
}
END_TEST

START_TEST(is_less_7) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(7, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(7, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_less(x, y));
}
END_TEST

START_TEST(is_less_8) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(10, 1)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(10, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(x, y));
}
END_TEST

START_TEST(is_less_9) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(10, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_less(x, y));
}
END_TEST

// меньше или равно

START_TEST(is_less_or_equal_1) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(x, y));
}
END_TEST

START_TEST(is_less_or_equal_2) {
  s21_decimal x = {{123451967, 202, 7, last_bits(6, 1)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(x, y));
}
END_TEST

START_TEST(is_less_or_equal_3) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 1)}};
  s21_decimal y = {{123451967, 202, 2, last_bits(5, 1)}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(x, y));
}
END_TEST

START_TEST(is_less_or_equal_4) {
  s21_decimal x = {{123451967, 0, 7, last_bits(5, 1)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 1)}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(x, y));
}
END_TEST

START_TEST(is_less_or_equal_5) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(x, y));
}
END_TEST

START_TEST(is_less_or_equal_6) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_less_or_equal(x, y));
}
END_TEST

START_TEST(is_less_or_equal_7) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(7, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(7, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(x, y));
}
END_TEST

START_TEST(is_less_or_equal_8) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(10, 1)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(10, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(x, y));
}
END_TEST

START_TEST(is_less_or_equal_9) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(10, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_less_or_equal(x, y));
}
END_TEST

// равно

START_TEST(is_equal_1) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_equal(x, y));
}
END_TEST

START_TEST(is_equal_2) {
  s21_decimal x = {{123451967, 202, 7, last_bits(6, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 1)}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(x, y));
}
END_TEST

START_TEST(is_equal_3) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 1)}};
  s21_decimal y = {{123451967, 202, 2, last_bits(5, 1)}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(x, y));
}
END_TEST

START_TEST(is_equal_4) {
  s21_decimal x = {{123451967, 0, 7, last_bits(5, 1)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 1)}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(x, y));
}
END_TEST

START_TEST(is_equal_5) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_equal(x, y));
}
END_TEST

START_TEST(is_equal_6) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(x, y));
}
END_TEST

START_TEST(is_equal_7) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(7, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(7, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_equal(x, y));
}
END_TEST

START_TEST(is_equal_8) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(10, 1)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(10, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(x, y));
}
END_TEST

START_TEST(is_equal_9) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(10, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_equal(x, y));
}
END_TEST

// больше или равно

START_TEST(is_greater_or_equal_1) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater_or_equal(x, y));
}
END_TEST

START_TEST(is_greater_or_equal_2) {
  s21_decimal x = {{123451967, 202, 7, last_bits(6, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 1)}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater_or_equal(x, y));
}
END_TEST

START_TEST(is_greater_or_equal_3) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 1)}};
  s21_decimal y = {{123451967, 202, 2, last_bits(5, 1)}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater_or_equal(x, y));
}
END_TEST

START_TEST(is_greater_or_equal_4) {
  s21_decimal x = {{123451967, 0, 7, last_bits(5, 1)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 1)}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater_or_equal(x, y));
}
END_TEST

START_TEST(is_greater_or_equal_5) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater_or_equal(x, y));
}
END_TEST

START_TEST(is_greater_or_equal_6) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater_or_equal(x, y));
}
END_TEST

START_TEST(is_greater_or_equal_7) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(7, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(7, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater_or_equal(x, y));
}
END_TEST

START_TEST(is_greater_or_equal_8) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(10, 1)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(10, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater_or_equal(x, y));
}
END_TEST

START_TEST(is_greater_or_equal_9) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(5, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater_or_equal(x, y));
}
END_TEST

// больше

START_TEST(is_greater_1) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(x, y));
}
END_TEST

START_TEST(is_greater_2) {
  s21_decimal x = {{123451967, 202, 7, last_bits(6, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 1)}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(x, y));
}
END_TEST

START_TEST(is_greater_3) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 1)}};
  s21_decimal y = {{123451967, 202, 2, last_bits(5, 1)}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(x, y));
}
END_TEST

START_TEST(is_greater_4) {
  s21_decimal x = {{123451967, 0, 7, last_bits(5, 1)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 1)}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(x, y));
}
END_TEST

START_TEST(is_greater_5) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(x, y));
}
END_TEST

START_TEST(is_greater_6) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_greater(x, y));
}
END_TEST

START_TEST(is_greater_7) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(7, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(7, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(x, y));
}
END_TEST

START_TEST(is_greater_8) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(10, 1)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(10, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(x, y));
}
END_TEST

START_TEST(is_greater_9) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(5, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_greater(x, y));
}
END_TEST

//  не равно

START_TEST(is_not_equal_1) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_not_equal(x, y));
}
END_TEST

START_TEST(is_not_equal_2) {
  s21_decimal x = {{123451967, 202, 7, last_bits(6, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 1)}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(x, y));
}
END_TEST

START_TEST(is_not_equal_3) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 1)}};
  s21_decimal y = {{123451967, 202, 2, last_bits(5, 1)}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(x, y));
}
END_TEST

START_TEST(is_not_equal_4) {
  s21_decimal x = {{123451967, 0, 7, last_bits(5, 1)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 1)}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(x, y));
}
END_TEST

START_TEST(is_not_equal_5) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_not_equal(x, y));
}
END_TEST

START_TEST(is_not_equal_6) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(5, 0)}};
  s21_decimal y = {{123451967, 202, 7, last_bits(5, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(x, y));
}
END_TEST

START_TEST(is_not_equal_7) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(7, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(7, 0)}};
  ck_assert_int_eq(S21_FALSE, s21_is_not_equal(x, y));
}
END_TEST

START_TEST(is_not_equal_8) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(10, 1)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(10, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(x, y));
}
END_TEST

START_TEST(is_not_equal_9) {
  s21_decimal x = {{123451967, 202, 7, last_bits(5, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(10, 0)}};
  ck_assert_int_eq(S21_TRUE, s21_is_not_equal(x, y));
}
END_TEST

//  Преобразования
START_TEST(from_decimal_to_float) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, 2149318656}};
  float y;
  s21_from_decimal_to_float(x, &y);
  ck_assert_float_eq(-7.9228162514264337593543950335, y);
}
END_TEST

START_TEST(from_decimal_to_float2) {
  s21_decimal x = {{0, 0, 0, 0}};
  float y;
  s21_from_decimal_to_float(x, &y);
  ck_assert_float_eq(0, y);
}
END_TEST

START_TEST(from_decimal_to_int) {
  s21_decimal x = {{0, 0, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(0, y);
}
END_TEST

START_TEST(from_decimal_to_int2) {
  s21_decimal x = {{INT_MAX, 0, 0, 2147483648}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(-INT_MAX, y);
}
END_TEST

START_TEST(from_float_to_decimal) {
  s21_decimal x;
  float y = 0.0;
  s21_from_float_to_decimal(y, &x);
  ck_assert_int_eq(0, x.bits[0]);
  ck_assert_int_eq(0, x.bits[1]);
  ck_assert_int_eq(0, x.bits[2]);
  ck_assert_int_eq(0, x.bits[3]);
}
END_TEST

START_TEST(from_float_to_decimal2) {
  s21_decimal x;
  float y = -0.000000026262;
  s21_from_float_to_decimal(y, &x);
  ck_assert_int_eq(26262, x.bits[0]);
  ck_assert_int_eq(0, x.bits[1]);
  ck_assert_int_eq(0, x.bits[2]);
  ck_assert_int_eq(2148270080, x.bits[3]);
}
END_TEST

START_TEST(from_float_to_decimal3) {
  s21_decimal x;
  float y = 19393939393993993.95757575;
  s21_from_float_to_decimal(y, &x);
  ck_assert_int_eq(2290010112, x.bits[0]);
  ck_assert_int_eq(4515503, x.bits[1]);
  ck_assert_int_eq(0, x.bits[2]);
  ck_assert_int_eq(0, x.bits[3]);
}
END_TEST

START_TEST(from_int_to_decimal) {
  int x = 555655555;
  s21_decimal y;
  s21_from_int_to_decimal(x, &y);
  ck_assert_int_eq(abs(x), y.bits[0]);
  ck_assert_int_eq(0, y.bits[3]);
}
END_TEST

START_TEST(from_int_to_decimal2) {
  int x = -555655555;
  s21_decimal y;
  s21_from_int_to_decimal(x, &y);
  ck_assert_int_eq(abs(x), y.bits[0]);
  ck_assert_int_eq(2147483648, y.bits[3]);
}
END_TEST

START_TEST(from_int_to_decimal3) {
  unsigned int x = 193939393;
  s21_decimal y;
  ck_assert_int_eq(0, s21_from_int_to_decimal(x, &y));
}
END_TEST

// s21_negate

START_TEST(negate1) {
  s21_decimal x = {{1, 0, 0, last_bits(0, 0)}};
  s21_decimal y = {{1, 0, 0, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_negate(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(negate2) {
  s21_decimal x = {{100, 0, 0, last_bits(0, 0)}};
  s21_decimal y = {{100, 0, 0, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_negate(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(negate3) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(0, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_negate(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(negate4) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(28, 0)}};
  s21_decimal y = {{4294967295, 4294967295, 4294967295, last_bits(28, 1)}};
  s21_decimal res;
  int i = s21_negate(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(negate5) {
  s21_decimal x = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal y = {{0, 0, 0, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_negate(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(truncate1) {
  s21_decimal x = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal y = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal res;
  int i = s21_truncate(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(truncate2) {
  s21_decimal x = {{1, 0, 0, last_bits(1, 0)}};
  s21_decimal y = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal res;
  int i = s21_truncate(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(truncate3) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(28, 0)}};
  s21_decimal y = {{7, 0, 0, last_bits(0, 0)}};
  s21_decimal res;
  int i = s21_truncate(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(truncate4) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(27, 0)}};
  s21_decimal y = {{79, 0, 0, last_bits(0, 0)}};
  s21_decimal res;
  int i = s21_truncate(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(truncate5) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(28, 1)}};
  s21_decimal y = {{7, 0, 0, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_truncate(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(truncate6) {
  s21_decimal x = {{75483, 0, 0, last_bits(5, 1)}};
  s21_decimal y = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal res;
  int i = s21_truncate(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(truncate7) {
  s21_decimal x = {{100000, 0, 0, last_bits(5, 1)}};
  s21_decimal y = {{1, 0, 0, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_truncate(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(truncate8) {
  s21_decimal dec1;
  dec1.bits[0] =
      0b11111111111111111111111111111111;  // 7922816251426433759354395033.5
  dec1.bits[1] = 0b11111111111111111111111111111111;
  dec1.bits[2] = 0b11111111111111111111111111111111;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result;
  result.bits[0] = 0b10011001100110011001100110011001;
  result.bits[1] = 0b10011001100110011001100110011001;
  result.bits[2] = 0b00011001100110011001100110011001;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncate9) {
  s21_decimal value_1 = {{35, 0, 0, last_bits(1, 0)}};
  s21_decimal check = {{3, 0, 0, 0}};
  s21_truncate(value_1, &value_1);
  ck_assert_int_eq(s21_is_equal(value_1, check), 1);
}
END_TEST

START_TEST(truncate10) {
  s21_decimal value_1 = {{123456, 0, 0, last_bits(3, 1)}};
  s21_decimal check = {{123, 0, 0, last_bits(0, 1)}};
  s21_truncate(value_1, &value_1);
  ck_assert_int_eq(s21_is_equal(value_1, check), 1);
}
END_TEST

START_TEST(truncate11) {
  s21_decimal src1;
  src1.bits[3] = 0x000A0000;
  src1.bits[2] = 0x0;
  src1.bits[1] = 0xFFFFFFFF;
  src1.bits[0] = 0xFFFFFFFF;
  s21_decimal result;
  result.bits[3] = 0x0;
  result.bits[2] = 0x0;
  result.bits[1] = 0x0;
  result.bits[0] = 0x6DF37F67;
  s21_decimal res_od;
  s21_truncate(src1, &res_od);
  ck_assert_float_eq(res_od.bits[0], result.bits[0]);
  ck_assert_float_eq(res_od.bits[1], result.bits[1]);
  ck_assert_float_eq(res_od.bits[2], result.bits[2]);
  ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

START_TEST(truncate12) {
  s21_decimal src1;
  src1.bits[0] = 0b00000000000000000000000001101101;
  src1.bits[1] = 0b00000000000011000110010101011011;
  src1.bits[2] = 0b00000000000000000011000000111001;
  src1.bits[3] = 0b00000000000011100000000000000000;
  s21_decimal result;
  result.bits[0] = 0b10000111101111000001011000011110;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res_od;
  s21_truncate(src1, &res_od);
  ck_assert_float_eq(res_od.bits[0], result.bits[0]);
  ck_assert_float_eq(res_od.bits[1], result.bits[1]);
  ck_assert_float_eq(res_od.bits[2], result.bits[2]);
  ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

START_TEST(floor1) {
  s21_decimal x = {{75483, 0, 0, last_bits(5, 1)}};
  s21_decimal y = {{1, 0, 0, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_floor(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(floor2) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(28, 1)}};
  s21_decimal y = {{8, 0, 0, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_floor(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(floor3) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(28, 0)}};
  s21_decimal y = {{7, 0, 0, last_bits(0, 0)}};
  s21_decimal res;
  int i = s21_floor(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(floor4) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(1, 0)}};
  s21_decimal y = {{2576980377, 2576980377, 429496729, last_bits(0, 0)}};
  s21_decimal res;
  int i = s21_floor(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(floor5) {
  s21_decimal x = {{14, 0, 0, last_bits(1, 1)}};
  s21_decimal y = {{2, 0, 0, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_floor(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(floor6) {
  s21_decimal x = {{75, 0, 0, last_bits(2, 1)}};
  s21_decimal y = {{1, 0, 0, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_floor(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(floor7) {
  s21_decimal src1;
  src1.bits[0] = 0b00001111111111111111111111111111;
  src1.bits[1] = 0b00111110001001010000001001100001;
  src1.bits[2] = 0b00100000010011111100111001011110;
  src1.bits[3] = 0b10000000000010100000000000000000;
  s21_decimal res_od;
  s21_floor(src1, &res_od);
  s21_decimal result;
  result.bits[0] = 0b10100111011001000000000000000000;
  result.bits[1] = 0b00001101111000001011011010110011;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_float_eq(res_od.bits[0], result.bits[0]);
  ck_assert_float_eq(res_od.bits[1], result.bits[1]);
  ck_assert_float_eq(res_od.bits[2], result.bits[2]);
  ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

START_TEST(floor8) {
  s21_decimal x = {{666, 0, 0, last_bits(2, 1)}};
  s21_decimal res = {0};
  s21_decimal result = {{7, 0, 0, last_bits(0, 1)}};
  s21_floor(x, &res);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(round1) {
  s21_decimal x = {{75, 0, 0, last_bits(1, 1)}};
  s21_decimal y = {{8, 0, 0, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_round(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(round2) {
  s21_decimal x = {{0, 0, 0, last_bits(1, 1)}};
  s21_decimal y = {{0, 0, 0, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_round(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(round3) {
  s21_decimal x = {{4294967295, 4294967295, 4294967295, last_bits(28, 1)}};
  s21_decimal y = {{8, 0, 0, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_round(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(round4) {
  s21_decimal x = {{165, 0, 0, last_bits(1, 0)}};
  s21_decimal y = {{17, 0, 0, 0}};
  s21_decimal res;
  int i = s21_round(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(round5) {
  s21_decimal x = {{124392478, 0, 0, last_bits(1, 0)}};
  s21_decimal y = {{12439248, 0, 0, 0}};
  s21_decimal res;
  int i = s21_round(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(round6) {
  s21_decimal x = {{124392344, 0, 0, last_bits(1, 1)}};
  s21_decimal y = {{12439234, 0, 0, last_bits(0, 1)}};
  s21_decimal res;
  int i = s21_round(x, &res);
  ck_assert_int_eq(i, 0);
  for (int j = 0; j < 4; j++) {
    ck_assert_int_eq(res.bits[j], y.bits[j]);
  }
}
END_TEST

START_TEST(round7) {
  s21_decimal value_1 = {{7464923, 0, 0, last_bits(5, 0)}};
  s21_decimal check = {{75, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, code_OK);
}
END_TEST

START_TEST(round8) {
  s21_decimal value_1 = {{7444923, 0, 0, last_bits(5, 0)}};
  s21_decimal check = {{74, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, code_OK);
}
END_TEST

START_TEST(round9) {
  s21_decimal src1;
  src1.bits[0] = 0b01010101001110101110101110110001;
  src1.bits[1] = 0b00001101101101001101101001011111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000001;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res_od;
  s21_round(src1, &res_od);
  ck_assert_float_eq(res_od.bits[0], result.bits[0]);
  ck_assert_float_eq(res_od.bits[1], result.bits[1]);
  ck_assert_float_eq(res_od.bits[2], result.bits[2]);
  ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

START_TEST(round10) {
  s21_decimal src1;
  src1.bits[0] = 0b10010111011100111001111111111111;
  src1.bits[1] = 0b00111100000010000011000110001101;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b10000000000001110000000000000000;
  s21_decimal res_od;
  s21_round(src1, &res_od);
  s21_decimal result;
  result.bits[3] = 0b10000000000000000000000000000000;
  result.bits[2] = 0;
  result.bits[1] = 0b00000000000000000000001000010010;
  result.bits[0] = 0b00110110101101101000110001000000;
  ck_assert_float_eq(res_od.bits[0], result.bits[0]);
  ck_assert_float_eq(res_od.bits[1], result.bits[1]);
  ck_assert_float_eq(res_od.bits[2], result.bits[2]);
  ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

// ------------------- add ------------------
START_TEST(add_int_1) {
  // int a = -1000000000, b = -1234567;
  // int res = a + b;
  int error, res_int;
  s21_decimal x, y, res_dec;
  zero_init(&x);
  zero_init(&y);
  zero_init(&res_dec);
  // s21_from_int_to_decimal(a, &x);
  // s21_from_int_to_decimal(b, &y);
  // error = s21_add(x, y, &res_dec);
  // s21_from_decimal_to_int(res_dec, &res_int);
  // ck_assert_int_eq(res_int, a + b);
  // ck_assert_int_eq(error, 0);
  for (int a = -1000000000; a < 1000000000; a += 560000000) {
    for (int b = -1234567; b < 1000000000; b += 123456) {
      s21_from_int_to_decimal(a, &x);
      s21_from_int_to_decimal(b, &y);
      error = s21_add(x, y, &res_dec);
      s21_from_decimal_to_int(res_dec, &res_int);
      ck_assert_int_eq(res_int, a + b);
      ck_assert_int_eq(error, 0);
    }
  }
}
END_TEST

START_TEST(add_int_2) {
  int error, res_int;
  s21_decimal x, y, res_dec;
  zero_init(&x);
  zero_init(&y);
  zero_init(&res_dec);
  for (int a = 1; abs(a) < 1000000000; a *= -133) {
    for (int b = -1; abs(b) < 1000000000; b *= -77) {
      s21_from_int_to_decimal(a, &x);
      s21_from_int_to_decimal(b, &y);
      error = s21_add(x, y, &res_dec);
      s21_from_decimal_to_int(res_dec, &res_int);
      ck_assert_int_eq(res_int, a + b);
      ck_assert_int_eq(error, 0);
    }
  }
}
END_TEST

START_TEST(add_plus_max_1) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(1, 0)}};  // 7922816251426433759354395033.5
  s21_decimal y = {{4294967295, 4294967295, 4294967295,
                    last_bits(1, 0)}};  // 7922816251426433759354395033.5
  s21_decimal z = {{858993459, 858993459, 858993459,
                    last_bits(0, 0)}};  // 15845632502852867518708790067
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_plus_max_2) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(14, 0)}};  // 792281625142643.37593543950335
  s21_decimal y = {{4294967295, 4294967295, 4294967295,
                    last_bits(14, 0)}};  // 792281625142643.37593543950335
  s21_decimal z = {{858993459, 858993459, 858993459,
                    last_bits(13, 0)}};  // 1584563250285286.7518708790067
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_plus_max_3) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(28, 0)}};  // 7.9228162514264337593543950335
  s21_decimal y = {{4294967295, 4294967295, 4294967295,
                    last_bits(28, 0)}};  // 7.9228162514264337593543950335
  s21_decimal z = {{858993459, 858993459, 858993459,
                    last_bits(27, 0)}};  // 15.84563250285286751870879007
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_plus_max_4) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(0, 0)}};  // 79228162514264337593543950335
  s21_decimal y = {{4, 0, 0, last_bits(1, 0)}};  // 0.4
  s21_decimal z = {{4294967295, 4294967295, 4294967295,
                    last_bits(0, 0)}};  // 79228162514264337593543950335
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_minus_max_1) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(1, 1)}};  // -7922816251426433759354395033.5
  s21_decimal y = {{4294967295, 4294967295, 4294967295,
                    last_bits(1, 1)}};  // -7922816251426433759354395033.5
  s21_decimal z = {{858993459, 858993459, 858993459,
                    last_bits(0, 1)}};  // -15845632502852867518708790067
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_minus_max_2) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(0, 1)}};  // -79228162514264337593543950335
  s21_decimal y = {{4, 0, 0, last_bits(1, 1)}};  // -0.4
  s21_decimal z = {{4294967295, 4294967295, 4294967295,
                    last_bits(0, 1)}};  // -79228162514264337593543950335
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_plus_0) {
  int error;
  s21_decimal x = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal y = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal z = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_plus_1) {
  int error;
  s21_decimal x = {
      {268435456, 1042612833, 542101086, last_bits(0, 0)}};  // 1*10^28
  s21_decimal y = {
      {536870912, 2085225666, 1084202172, last_bits(0, 0)}};  // 2*10^28
  s21_decimal z = {
      {805306368, 3127838499, 1626303258, last_bits(0, 0)}};  // 3*10^28
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_plus_2) {
  int error;
  s21_decimal x = {
      {3071635911, 258700, 0, last_bits(0, 0)}};  // 1111111111111111
  s21_decimal y = {
      {3071635911, 258700, 0, last_bits(15, 0)}};  // 1.111111111111111
  s21_decimal z = {{3046052295, 1158461031, 602334540,
                    last_bits(13, 0)}};  // 1111111111111112.1111111111111(13)
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_plus_3) {
  int error;
  s21_decimal x = {{12345, 0, 0, last_bits(2, 0)}};      // 123.45
  s21_decimal y = {{6789, 0, 0, last_bits(6, 0)}};       // 0.006789
  s21_decimal z = {{123456789, 0, 0, last_bits(6, 0)}};  // 123.456789
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_plus_4) {
  int error;
  s21_decimal x = {{1068173785, 3648486728, 2837640,
                    last_bits(28, 0)}};  // 0.0052345234523452349765847513
  s21_decimal y = {{1410065407, 2, 0, last_bits(5, 0)}};  // 99999.99999
  s21_decimal z = {{2105877690, 2426444364, 542101114,
                    last_bits(23, 0)}};  // 100000.00522452345234523497658
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// Сокращение числа
START_TEST(add_plus_5) {
  int error;
  s21_decimal x = {{1068173785, 3648486728, 2837640,
                    last_bits(0, 0)}};  // 52345234523452349765847513
  s21_decimal y = {{1410065407, 2, 0, last_bits(5, 0)}};  // 99999.99999
  s21_decimal z = {{3121895592, 2059493944, 2837640849,
                    last_bits(3, 0)}};  // 52345234523452349765947513.000
  // s21_decimal z = {{1068273785, 3648486728, 2837640, last_bits(0, 0)}};    //
  // 52345234523452349765947513
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_plus_6) {
  int error;
  s21_decimal x = {{1068173785, 3648486728, 2837640,
                    last_bits(0, 0)}};  // 52345234523452349765847513
  s21_decimal y = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal z = {{1068173785, 3648486728, 2837640,
                    last_bits(0, 0)}};  // 52345234523452349765847513
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_plus_7) {
  int error;
  s21_decimal x = {{59652323, 1497326221, 3011672701,
                    last_bits(28, 0)}};  // 5.5555555555555555555555555555
  s21_decimal y = {{3, 0, 0, last_bits(0, 0)}};  // 3
  s21_decimal z = {{1804482788, 33019742, 463797596,
                    last_bits(27, 0)}};  // 8.555555555555555555555555556
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_minus_1) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(1, 1)}};  // -7922816251426433759354395033.5
  s21_decimal y = {{5, 0, 0, last_bits(1, 1)}};  // -0.5
  s21_decimal z = {{2576980378, 2576980377, 429496729,
                    last_bits(0, 1)}};  // -7922816251426433759354395034
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_minus_2) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 0,
                    last_bits(0, 1)}};  // -18446744073709551615 = -(2^64-1)
  s21_decimal y = {{1, 0, 0, last_bits(0, 1)}};  // -1
  s21_decimal z = {
      {0, 0, 1, last_bits(0, 1)}};  // -18446744073709551616 = -2^64
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_minus_3) {
  int error;
  s21_decimal x = {
      {2354985187, 50133870, 3, last_bits(0, 1)}};  // -55555555555555555555
  s21_decimal y = {{2354985187, 50133870, 3,
                    last_bits(20, 1)}};  // -0.55555555555555555555(20)
  s21_decimal z = {{59652324, 1497326221, 3011672701,
                    last_bits(9, 1)}};  // -55555555555555555555.555555556(9)
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_sub_1) {
  int error;
  s21_decimal x = {
      {3071635911, 258700, 0, last_bits(0, 0)}};  // 1111111111111111(16)
  s21_decimal y = {
      {3071635911, 258700, 0, last_bits(15, 1)}};  // -1.111111111111111
  s21_decimal z = {{2984619577, 1158455857, 602334540,
                    last_bits(13, 0)}};  // 1111111111111109.8888888888889(13)
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_sub_2) {
  int error;
  s21_decimal x = {{0, 0, 1, last_bits(1, 1)}};  // -1844674407370955161.6
  s21_decimal y = {{1, 0, 0, last_bits(1, 0)}};  // 0.1
  s21_decimal z = {
      {4294967295, 4294967295, 0, last_bits(1, 1)}};  // -1844674407370955161.5
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// Сокращение числа
START_TEST(add_sub_3) {
  int error;
  s21_decimal x = {{1068173785, 3648486728, 2837640,
                    last_bits(0, 0)}};  // 52345234523452349765847513
  s21_decimal y = {{1410065407, 2, 0, last_bits(5, 1)}};  // -99999.99999
  s21_decimal z = {{2921895592, 2059493944, 2837640849,
                    last_bits(3, 0)}};  // 52345234523452349765747513.000
  // s21_decimal z = {{1068073785, 3648486728, 2837640, last_bits(0, 0)}};  //
  // 52345234523452349765747513
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_sub_4) {
  int error;
  s21_decimal x = {{1068173785, 3648486728, 2837640,
                    last_bits(28, 1)}};  // -0.0052345234523452349765847513
  s21_decimal y = {{1215752191, 23, 0, last_bits(5, 0)}};  // 99999.99999
  s21_decimal z = {{1670505146, 1716657010, 542101083,
                    last_bits(22, 0)}};  // 999999.9947554765476547650234
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(add_err1_1) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(0, 0)}};  // 79228162514264337593543950335
  s21_decimal y = {{5, 0, 0, last_bits(1, 0)}};  // 0.5
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(add_err1_2) {
  int error;
  s21_decimal x = {
      {0, 0, 2147483648,
       last_bits(0, 0)}};  // 39614081257132168796771975168 = (2^96-1)/2
  s21_decimal y = {
      {0, 0, 2147483648,
       last_bits(0, 0)}};  // 39614081257132168796771975168 = (2^96-1)/2
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(add_err2_1) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(0, 1)}};  // -79228162514264337593543950335
  s21_decimal y = {{5, 0, 0, last_bits(1, 1)}};  // -0.5
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 2);
}
END_TEST

START_TEST(add_err2_2) {
  int error;
  s21_decimal x = {{1073741824, 4170451332, 2168404344,
                    last_bits(0, 1)}};  // -40000000000000000000000000000(28)
  s21_decimal y = {{1073741824, 4170451332, 2168404344,
                    last_bits(0, 1)}};  // -40000000000000000000000000000(28)
  s21_decimal res;
  error = s21_add(x, y, &res);
  ck_assert_int_eq(error, 2);
}
END_TEST

// ------------------- sub ------------------
START_TEST(sub_int_1) {
  int error, res_int;
  s21_decimal x, y, res_dec;
  zero_init(&x);
  zero_init(&y);
  zero_init(&res_dec);
  for (int a = -1000000000; a < 1000000000; a += 560000000) {
    for (int b = -1234567; b < 1000000000; b += 123456) {
      s21_from_int_to_decimal(a, &x);
      s21_from_int_to_decimal(b, &y);
      error = s21_sub(x, y, &res_dec);
      s21_from_decimal_to_int(res_dec, &res_int);
      ck_assert_int_eq(res_int, a - b);
      ck_assert_int_eq(error, 0);
    }
  }
}
END_TEST

START_TEST(sub_int_2) {
  int error, res_int;
  s21_decimal x, y, res_dec;
  zero_init(&x);
  zero_init(&y);
  zero_init(&res_dec);
  for (int a = 1; abs(a) < 1000000000; a *= -133) {
    for (int b = -1; abs(b) < 1000000000; b *= -77) {
      s21_from_int_to_decimal(a, &x);
      s21_from_int_to_decimal(b, &y);
      error = s21_sub(x, y, &res_dec);
      s21_from_decimal_to_int(res_dec, &res_int);
      ck_assert_int_eq(res_int, a - b);
      ck_assert_int_eq(error, 0);
    }
  }
}
END_TEST

START_TEST(sub_add_max_1) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(1, 1)}};  // -7922816251426433759354395033.5
  s21_decimal y = {{4294967295, 4294967295, 4294967295,
                    last_bits(1, 0)}};  // 7922816251426433759354395033.5
  s21_decimal z = {{858993459, 858993459, 858993459,
                    last_bits(0, 1)}};  // -15845632502852867518708790067
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_add_max_2) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(14, 0)}};  // 792281625142643.37593543950335
  s21_decimal y = {{4294967295, 4294967295, 4294967295,
                    last_bits(14, 1)}};  // 792281625142643.37593543950335
  s21_decimal z = {{858993459, 858993459, 858993459,
                    last_bits(13, 0)}};  // 1584563250285286.7518708790067
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_add_max_3) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(28, 1)}};  // -7.9228162514264337593543950335
  s21_decimal y = {{4294967295, 4294967295, 4294967295,
                    last_bits(28, 0)}};  // 7.9228162514264337593543950335
  s21_decimal z = {{858993459, 858993459, 858993459,
                    last_bits(27, 1)}};  // -15.84563250285286751870879007
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_0) {
  int error;
  s21_decimal x = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal y = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal z = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_1) {
  int error;
  s21_decimal x = {
      {805306368, 3127838499, 1626303258, last_bits(0, 0)}};  // 3*10^28
  s21_decimal y = {
      {536870912, 2085225666, 1084202172, last_bits(0, 0)}};  // 2*10^28
  s21_decimal z = {
      {268435456, 1042612833, 542101086, last_bits(0, 0)}};  // 1*10^28
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// Сокращение числа
START_TEST(sub_2) {
  int error;
  s21_decimal x = {{3046052295, 1158461031, 602334540,
                    last_bits(13, 0)}};  // 1111111111111112.1111111111111(13)
  s21_decimal y = {
      {3071635911, 258700, 0, last_bits(15, 0)}};  // 1.111111111111111
  // s21_decimal z = {{3071635911, 258700, 0, last_bits(0, 0)}}; //
  // 1111111111111111
  s21_decimal z = {{3015335936, 1158458444, 602334540,
                    last_bits(13, 0)}};  // 1111111111111111
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_3) {
  int error;
  s21_decimal x = {{123456789, 0, 0, last_bits(6, 0)}};  // 123.456789
  s21_decimal y = {{12345, 0, 0, last_bits(2, 0)}};      // 123.45
  s21_decimal z = {{6789, 0, 0, last_bits(6, 0)}};       // 0.006789
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_4) {
  int error;
  s21_decimal x = {{858993459, 858993459, 858993459,
                    last_bits(0, 0)}};  // 15845632502852867518708790067
  s21_decimal y = {{4294967295, 4294967295, 4294967295,
                    last_bits(1, 0)}};  // 7922816251426433759354395033.5
  s21_decimal z = {{4294967295, 4294967295, 4294967295,
                    last_bits(1, 0)}};  // 7922816251426433759354395033.5
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_5) {
  int error;
  s21_decimal x = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal y = {
      {3071635911, 258700, 0, last_bits(15, 0)}};  // 1.111111111111111
  s21_decimal z = {
      {3071635911, 258700, 0, last_bits(15, 1)}};  // -1.111111111111111
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_6) {
  int error;
  s21_decimal x = {
      {536870912, 2085225666, 1084202172, last_bits(0, 0)}};  // 2*10^28
  s21_decimal y = {
      {805306368, 3127838499, 1626303258, last_bits(0, 0)}};  // 3*10^28
  s21_decimal z = {
      {268435456, 1042612833, 542101086, last_bits(0, 1)}};  // -1*10^28
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_7) {
  int error;
  s21_decimal x = {{12345, 0, 0, last_bits(2, 0)}};      // 123.45
  s21_decimal y = {{123456789, 0, 0, last_bits(6, 0)}};  // 123.456789
  s21_decimal z = {{6789, 0, 0, last_bits(6, 1)}};       // -0.006789
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_8) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(1, 0)}};  // 7922816251426433759354395033.5
  s21_decimal y = {{858993459, 858993459, 858993459,
                    last_bits(0, 0)}};  // 15845632502852867518708790067
  s21_decimal z = {{4294967295, 4294967295, 4294967295,
                    last_bits(1, 1)}};  // -7922816251426433759354395033.5
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// Сокращение числа
START_TEST(sub_9) {
  int error;
  s21_decimal x = {{1068273785, 3648486728, 2837640,
                    last_bits(0, 0)}};  // 52345234523452349765947513
  s21_decimal y = {{1410065407, 2, 0, last_bits(5, 0)}};  // 99999.99999
  s21_decimal z = {{3021895592, 2059493944, 2837640849,
                    last_bits(3, 0)}};  // 52345234523452349765847513.000
  // s21_decimal z = {{1068173785, 3648486728, 2837640, last_bits(0, 0)}}; //
  // 52345234523452349765947513.000
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// Сокращение числа
START_TEST(sub_10) {
  int error;
  s21_decimal x = {{1410065407, 2, 0, last_bits(5, 0)}};  // 99999.99999
  s21_decimal y = {{1068273785, 3648486728, 2837640,
                    last_bits(0, 0)}};  // 52345234523452349765947513
  s21_decimal z = {{3021895592, 2059493944, 2837640849,
                    last_bits(3, 1)}};  // -52345234523452349765847513.000
  // s21_decimal z = {{1068173785, 3648486728, 2837640, last_bits(0, 1)}}; //
  // 52345234523452349765947513.000
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_11) {
  int error;
  s21_decimal x = {{1068173785, 3648486728, 2837640,
                    last_bits(0, 0)}};  // 52345234523452349765847513
  s21_decimal y = {{1068173785, 3648486728, 2837640,
                    last_bits(0, 0)}};  // 52345234523452349765847513
  s21_decimal z = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_12) {
  int error;
  s21_decimal x = {{5, 0, 0, last_bits(1, 1)}};  // -0.5
  s21_decimal y = {{2576980378, 2576980377, 429496729,
                    last_bits(0, 1)}};  // -7922816251426433759354395034
  s21_decimal z = {{4294967295, 4294967295, 4294967295,
                    last_bits(1, 0)}};  // 7922816251426433759354395033.5
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
    if (res.bits[i] != z.bits[i]) {
      printf("res.bits[%d]\n", i);
    }
  }
}
END_TEST

START_TEST(sub_13) {
  int error;
  s21_decimal x = {
      {536870912, 2085225666, 1084202172, last_bits(0, 1)}};  // -2*10^28
  s21_decimal y = {
      {805306368, 3127838499, 1626303258, last_bits(0, 1)}};  // -3*10^28
  s21_decimal z = {
      {268435456, 1042612833, 542101086, last_bits(0, 0)}};  // 1*10^28
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_14) {
  int error;
  s21_decimal x = {{12345, 0, 0, last_bits(2, 1)}};      // -123.45
  s21_decimal y = {{123456789, 0, 0, last_bits(6, 1)}};  // -123.456789
  s21_decimal z = {{6789, 0, 0, last_bits(6, 0)}};       // 0.006789
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_15) {
  int error;
  s21_decimal x = {{0, 0, 1, last_bits(0, 0)}};  // 18446744073709551616 = 2^64
  s21_decimal y = {{1, 0, 0, last_bits(0, 0)}};  // 1
  s21_decimal z = {{4294967295, 4294967295, 0,
                    last_bits(0, 0)}};  // 18446744073709551615 = 2^64-1
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_16) {
  int error;
  s21_decimal x = {{2283167487, 1, 0, last_bits(0, 0)}};  // 6578134783
  s21_decimal y = {{4272371539, 1505593010, 1269234,
                    last_bits(0, 0)}};  // 23413241234123412344354643
  s21_decimal z = {{1989204052, 1505593009, 1269234,
                    last_bits(0, 1)}};  // -23413241234123405766219860
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_17) {
  int error;
  s21_decimal x = {{2283167487, 1, 0, last_bits(0, 0)}};  // 6578134783
  s21_decimal y = {{4272371539, 1505593010, 1269234,
                    last_bits(28, 0)}};  // 0.0023413241234123412344354643
  s21_decimal z = {{2269844844, 1349744608, 3566014011,
                    last_bits(19, 0)}};  // 6578134782.9976586758765876588
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_18) {
  int error;
  s21_decimal x = {{1959365038, 1724015916, 2235306310,
                    last_bits(0, 0)}};  // 41234123434322657813478345134
  s21_decimal y = {{4272371539, 1505593010, 1269234,
                    last_bits(0, 0)}};  // 23413241234123412344354643
  s21_decimal z = {{1981960795, 218422905, 2234037076,
                    last_bits(0, 0)}};  // 41210710193088534401133990491
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_19) {
  int error;
  s21_decimal x = {{4272371539, 1505593010, 1269234,
                    last_bits(0, 0)}};  // 23413241234123412344354643
  s21_decimal y = {{1959365038, 1724015916, 2235306310,
                    last_bits(0, 0)}};  // 41234123434322657813478345134
  s21_decimal z = {{1981960795, 218422905, 2234037076,
                    last_bits(0, 1)}};  // -41210710193088534401133990491
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_add_1) {
  int error;
  s21_decimal x = {{4272371539, 1505593010, 1269234,
                    last_bits(0, 1)}};  // -23413241234123412344354643
  s21_decimal y = {{1959365038, 1724015916, 2235306310,
                    last_bits(0, 1)}};  // -41234123434322657813478345134
  s21_decimal z = {{1981960795, 218422905, 2234037076,
                    last_bits(0, 0)}};  //  41210710193088534401133990491
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_add_2) {
  int error;
  s21_decimal x = {{4272371539, 1505593010, 1269234,
                    last_bits(0, 1)}};  // -23413241234123412344354643
  s21_decimal y = {{1959365038, 1724015916, 2235306310,
                    last_bits(0, 0)}};  // 41234123434322657813478345134
  s21_decimal z = {{1936769281, 3229608927, 2236575544,
                    last_bits(0, 1)}};  //  -41257536675556781225822699777
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_plus_max_1) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(0, 0)}};  // 79228162514264337593543950335
  s21_decimal y = {{4, 0, 0, last_bits(1, 0)}};  // 0.4
  s21_decimal z = {{4294967295, 4294967295, 4294967295,
                    last_bits(0, 0)}};  // 79228162514264337593543950335
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_minus_max_2) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(0, 1)}};  // -79228162514264337593543950335
  s21_decimal y = {{4, 0, 0, last_bits(1, 1)}};  // -0.4
  s21_decimal z = {{4294967295, 4294967295, 4294967295,
                    last_bits(0, 1)}};  // -79228162514264337593543950335
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(sub_err1_1) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(0, 0)}};  // 79228162514264337593543950335
  s21_decimal y = {{5, 0, 0, last_bits(1, 1)}};  // -0.5
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(sub_err1_2) {
  int error;
  s21_decimal x = {
      {0, 0, 2147483648,
       last_bits(0, 0)}};  // 39614081257132168796771975168 = (2^96-1)/2
  s21_decimal y = {
      {0, 0, 2147483648,
       last_bits(0, 1)}};  // -39614081257132168796771975168 = (2^96-1)/2
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(sub_err2_1) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(0, 1)}};  // -79228162514264337593543950335
  s21_decimal y = {{5, 0, 0, last_bits(1, 0)}};  // 0.5
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 2);
}
END_TEST

START_TEST(sub_err2_2) {
  int error;
  s21_decimal x = {{1073741824, 4170451332, 2168404344,
                    last_bits(0, 1)}};  // -40000000000000000000000000000(28)
  s21_decimal y = {{1073741824, 4170451332, 2168404344,
                    last_bits(0, 0)}};  // 40000000000000000000000000000(28)
  s21_decimal res;
  error = s21_sub(x, y, &res);
  ck_assert_int_eq(error, 2);
}
END_TEST

// ------------------- mul ------------------
START_TEST(mul_int_1) {
  int error, res_int;
  s21_decimal x, y, res_dec;
  zero_init(&x);
  zero_init(&y);
  zero_init(&res_dec);
  for (int a = -10000; a < 10000; a += 560) {
    for (int b = -1234; b < 1000; b += 123) {
      s21_from_int_to_decimal(a, &x);
      s21_from_int_to_decimal(b, &y);
      error = s21_mul(x, y, &res_dec);
      s21_from_decimal_to_int(res_dec, &res_int);
      ck_assert_int_eq(res_int, a * b);
      ck_assert_int_eq(error, 0);
    }
  }
}
END_TEST

START_TEST(mul_int_2) {
  int error, res_int;
  s21_decimal x, y, res_dec;
  zero_init(&x);
  zero_init(&y);
  zero_init(&res_dec);
  for (int a = 1; abs(a) < 10000; a *= -13) {
    for (int b = -1; abs(b) < 100000; b *= -77) {
      s21_from_int_to_decimal(a, &x);
      s21_from_int_to_decimal(b, &y);
      error = s21_mul(x, y, &res_dec);
      s21_from_decimal_to_int(res_dec, &res_int);
      ck_assert_int_eq(res_int, a * b);
      ck_assert_int_eq(error, 0);
    }
  }
}
END_TEST

START_TEST(mul_0) {
  int error;
  s21_decimal x = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal y = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal z = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_1) {
  int error;
  s21_decimal x = {{829341696, 69849, 0, last_bits(0, 0)}};  // 3*10^14
  s21_decimal y = {{552894464, 46566, 0, last_bits(0, 0)}};  // 2*10^14
  s21_decimal z = {
      {1610612736, 1960709702, 3252606517, last_bits(0, 0)}};  // 6*10^28
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_2) {
  int error;
  s21_decimal x = {{829341696, 69849, 0, last_bits(0, 1)}};  // -3*10^14
  s21_decimal y = {{552894464, 46566, 0, last_bits(0, 0)}};  // 2*10^14
  s21_decimal z = {
      {1610612736, 1960709702, 3252606517, last_bits(0, 1)}};  // -6*10^28
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_3) {
  int error;
  s21_decimal x = {{829341696, 69849, 0, last_bits(0, 0)}};  // 3*10^14
  s21_decimal y = {{552894464, 46566, 0, last_bits(0, 1)}};  // -2*10^14
  s21_decimal z = {
      {1610612736, 1960709702, 3252606517, last_bits(0, 1)}};  // -6*10^28
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_4) {
  int error;
  s21_decimal x = {{829341696, 69849, 0, last_bits(0, 1)}};  // -3*10^14
  s21_decimal y = {{552894464, 46566, 0, last_bits(0, 1)}};  // -2*10^14
  s21_decimal z = {
      {1610612736, 1960709702, 3252606517, last_bits(0, 0)}};  // 6*10^28
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_5) {
  int error;
  s21_decimal x = {{2147483648, 0, 0, last_bits(0, 1)}};  // -2147483648 = -2^16
  s21_decimal y = {{2, 0, 0, last_bits(0, 0)}};           // 2
  s21_decimal z = {{0, 1, 0, last_bits(0, 1)}};           // -4294967296 = -2^32
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_6) {
  int error;
  s21_decimal x = {{0, 2147483648, 0, last_bits(0, 0)}};  // 2^63
  s21_decimal y = {{2, 0, 0, last_bits(0, 1)}};           // -2
  s21_decimal z = {{0, 0, 1, last_bits(0, 1)}};           // -2^64
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_7) {
  int error;
  s21_decimal x = {{0, 0, 4294967295, last_bits(0, 0)}};
  s21_decimal y = {{5, 0, 0, last_bits(1, 1)}};
  s21_decimal z = {{0, 2147483648, 2147483647, last_bits(0, 1)}};
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// Сокращение числа
START_TEST(mul_8) {
  int error;
  s21_decimal x = {
      {4294967295, 4294967295, 4294967295,
       last_bits(0, 0)}};  // 2^96 - 1 = 79228162514264337593543950335
  s21_decimal y = {{5, 0, 0, last_bits(1, 1)}};
  s21_decimal z = {
      {0, 0, 2147483648, last_bits(0, 1)}};  // 39614081257132168796771975168.0
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_9) {
  int error;
  s21_decimal x = {
      {307163591, 25870, 0, last_bits(14, 1)}};  // -1.11111111111111(14)
  s21_decimal y = {
      {307163591, 25870, 0, last_bits(14, 1)}};  // -1.11111111111111(14)
  s21_decimal z = {{899434673, 1287170588, 669260600,
                    last_bits(28, 0)}};  // 1.2345679012345654320987654321
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// Сокращение числа(округление работает верно)
START_TEST(mul_11) {
  int error;
  s21_decimal x = {{2283167487, 1, 0, last_bits(0, 0)}};  // 6578134783
  s21_decimal y = {{4272371539, 1505593010, 1269234,
                    last_bits(28, 1)}};  // -2.3413241234123412344354643
  s21_decimal z = {{3465978008, 3916779380, 834919462,
                    last_bits(21, 1)}};  // -15401545.654495706525705085080
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_12) {
  int error;
  s21_decimal x = {{555991807, 4274016055, 2881,
                    last_bits(15, 0)}};  // 53163426.435536578134783
  s21_decimal y = {{4272371539, 1505593010, 1269234,
                    last_bits(10, 0)}};  // 2341324123412341.2344354643
  s21_decimal z = {{596000907, 1066214266, 674768470,
                    last_bits(5, 0)}};  // 124472812796779167719089.93163
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_13) {
  int error;
  s21_decimal x = {{4272371539, 1505593010, 1269234,
                    last_bits(15, 1)}};  // -2341324123412341.2344354643
  s21_decimal y = {{555991807, 4274016055, 2881,
                    last_bits(10, 1)}};  // -53163426.435536578134783
  s21_decimal z = {{596000907, 1066214266, 674768470,
                    last_bits(5, 0)}};  // 124472812796779167719089.93163
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_14) {
  int error;
  s21_decimal x = {{4272371539, 1505593010, 1269234,
                    last_bits(15, 1)}};  // -2341324123412341.2344354643
  s21_decimal y = {{555991807, 4274016055, 2881,
                    last_bits(10, 0)}};  // 53163426.435536578134783
  s21_decimal z = {{596000907, 1066214266, 674768470,
                    last_bits(5, 1)}};  // -124472812796779167719089.93163
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_15) {
  int error;
  s21_decimal x = {{268435455, 1042612833, 542101086,
                    last_bits(28, 0)}};  // 0.9999999999999999999999999999
  s21_decimal y = {{10, 0, 0, last_bits(0, 0)}};  // 10
  s21_decimal z = {{268435455, 1042612833, 542101086,
                    last_bits(27, 0)}};  // 9.999999999999999999999999999
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_16) {
  int error;
  s21_decimal x = {{268435455, 1042612833, 542101086,
                    last_bits(28, 1)}};  // -0.9999999999999999999999999999
  s21_decimal y = {{1000, 0, 0, last_bits(0, 0)}};  // 1000
  s21_decimal z = {{268435455, 1042612833, 542101086,
                    last_bits(25, 1)}};  // -999.9999999999999999999999999
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_max_1) {
  int error;
  s21_decimal x = {{0, 2147483648, 0,
                    last_bits(4, 0)}};  // 2^63*10^(-4) = 922337203685477.5808
  s21_decimal y = {{0, 2, 0, last_bits(2, 0)}};  // 2^33*10^(-2) = 85899345.92
  s21_decimal z = {
      {2576980378, 2576980377, 429496729,
       last_bits(5, 0)}};  // 2^96*10^(-6) ~ 79228162514264337593543.95034
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_max_2) {
  int error;
  s21_decimal x = {{0, 65536, 0, last_bits(1, 0)}};  // 2^48*10^(-1)
  s21_decimal y = {{0, 65536, 0, last_bits(0, 1)}};  // -2^48
  s21_decimal z = {
      {2576980378, 2576980377, 429496729,
       last_bits(0, 1)}};  // -2^96*10^(-1) ~ -7922816251426433759354395034
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// Сокращение числа
START_TEST(mul_max_3) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(28, 1)}};  // 7.9228162514264337593543950335
  s21_decimal y = {{4294967295, 4294967295, 4294967295,
                    last_bits(28, 1)}};  // 7.9228162514264337593543950335
  s21_decimal z = {{158262358, 899300158, 3402823669,
                    last_bits(27, 0)}};  // 62.771017353866807638357894230
  // s21_decimal z = {{874819695, 3955400582, 340282366, last_bits(26, 0)}};
  // // 62.77101735386680763835789423
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_pow_1) {
  int error;
  s21_decimal x = {
      {3071635911, 258700, 0, last_bits(15, 0)}};  // 1.111111111111111
  s21_decimal y = {
      {3071635911, 258700, 0, last_bits(15, 0)}};  // 1.111111111111111
  s21_decimal z = {{960867391, 1287175762, 669260600,
                    last_bits(28, 0)}};  // 1.2345679012345676543209876543
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_pow_2) {
  int error;
  s21_decimal x = {
      {3071635911, 258700, 0, last_bits(15, 1)}};  // -1.111111111111111
  s21_decimal y = {
      {3071635911, 258700, 0, last_bits(15, 0)}};  // 1.111111111111111
  s21_decimal z = {{960867391, 1287175762, 669260600,
                    last_bits(28, 1)}};  // -1.2345679012345676543209876543
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// Сокращение числа
START_TEST(mul_pow_3) {
  int error;
  s21_decimal x = {{11, 0, 0, last_bits(20, 0)}};
  s21_decimal y = {{33, 0, 0, last_bits(15, 0)}};
  s21_decimal z = {{0, 0, 0, last_bits(28, 0)}};
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_pow_4) {
  int error;
  s21_decimal x = {{12335, 0, 0, last_bits(28, 0)}};
  s21_decimal y = {{11, 0, 0, last_bits(1, 0)}};
  s21_decimal z = {
      {13568, 0, 0, last_bits(28, 0)}};  // 135685*10^(-29) ~ 13568*10^(-28)
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mul_err1_1) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(5, 0)}};  // 792281625142643375935439.50335
  s21_decimal y = {{4294967295, 4294967295, 4294967295,
                    last_bits(5, 0)}};  // 792281625142643375935439.50335
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(mul_err1_2) {
  int error;
  s21_decimal x = {{4272371539, 1505593010, 1269234,
                    last_bits(0, 1)}};  // 2341324123412341.2344354643
  s21_decimal y = {{555991807, 4274016055, 2881,
                    last_bits(0, 1)}};  // 53163426.435536578134783
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(mul_err2_1) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(5, 0)}};  // 792281625142643375935439.50335
  s21_decimal y = {{4294967295, 4294967295, 4294967295,
                    last_bits(5, 1)}};  // 792281625142643375935439.50335 // 0.5
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 2);
}
END_TEST

START_TEST(mul_err2_2) {
  int error;
  s21_decimal x = {{4272371539, 1505593010, 1269234,
                    last_bits(0, 0)}};  // 2341324123412341.2344354643
  s21_decimal y = {{555991807, 4274016055, 2881,
                    last_bits(0, 1)}};  // 53163426.435536578134783
  s21_decimal res;
  error = s21_mul(x, y, &res);
  ck_assert_int_eq(error, 2);
}
END_TEST

// ------------------- div ------------------
START_TEST(div_int_1) {
  int error, res_int;
  s21_decimal x, y, res_dec;
  zero_init(&x);
  zero_init(&y);
  zero_init(&res_dec);
  for (int a = -200000; a < 200000; a += 5694) {
    for (int b = -1234; b < 10000; b += 1973) {
      int c = a * b;
      s21_from_int_to_decimal(c, &x);
      s21_from_int_to_decimal(a, &y);
      error = s21_div(x, y, &res_dec);
      s21_from_decimal_to_int(res_dec, &res_int);
      ck_assert_int_eq(res_int, b);
      ck_assert_int_eq(error, 0);
    }
  }
}
END_TEST

START_TEST(div_int_2) {
  int error, res_int;
  s21_decimal x, y, res_dec;
  zero_init(&x);
  zero_init(&y);
  zero_init(&res_dec);
  for (int a = 1; abs(a) < 20000; a *= -13) {
    for (int b = -1; abs(b) < 200000; b *= -77) {
      int c = a * b;
      s21_from_int_to_decimal(c, &x);
      s21_from_int_to_decimal(a, &y);
      error = s21_div(x, y, &res_dec);
      s21_from_decimal_to_int(res_dec, &res_int);
      ck_assert_int_eq(res_int, b);
      ck_assert_int_eq(error, 0);
    }
  }
}
END_TEST

START_TEST(div_1) {
  int error;
  s21_decimal x = {
      {1610612736, 1960709702, 3252606517, last_bits(0, 0)}};  // 6*10^28
  s21_decimal y = {{552894464, 46566, 0, last_bits(0, 0)}};    // 2*10^14
  s21_decimal z = {{829341696, 69849, 0, last_bits(0, 0)}};    // 3*10^14
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_2) {
  int error;
  s21_decimal x = {
      {1610612736, 1960709702, 3252606517, last_bits(0, 1)}};  // -6*10^28
  s21_decimal y = {{829341696, 69849, 0, last_bits(0, 1)}};    // -3*10^14
  s21_decimal z = {{552894464, 46566, 0, last_bits(0, 0)}};    // 2*10^14
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_3) {
  int error;
  s21_decimal x = {
      {1610612736, 1960709702, 3252606517, last_bits(0, 1)}};  // -6*10^28
  s21_decimal y = {{829341696, 69849, 0, last_bits(0, 0)}};    // 3*10^14
  s21_decimal z = {{552894464, 46566, 0, last_bits(0, 1)}};    // -2*10^14
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_4) {
  int error;
  s21_decimal x = {
      {1610612736, 1960709702, 3252606517, last_bits(0, 0)}};  // 6*10^28
  s21_decimal y = {{829341696, 69849, 0, last_bits(0, 1)}};    // -3*10^14
  s21_decimal z = {{552894464, 46566, 0, last_bits(0, 1)}};    // -2*10^14
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_5) {
  int error;
  s21_decimal x = {{0, 1, 0, last_bits(0, 1)}};           // -4294967296 = -2^32
  s21_decimal y = {{2147483648, 0, 0, last_bits(0, 1)}};  // -2147483648 = -2^16
  s21_decimal z = {{2, 0, 0, last_bits(0, 0)}};           // 2
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_6) {
  int error;
  s21_decimal x = {{0, 0, 1, last_bits(0, 1)}};           // -2^64
  s21_decimal y = {{0, 2147483648, 0, last_bits(0, 0)}};  // 2^63
  s21_decimal z = {{2, 0, 0, last_bits(0, 1)}};           // -2
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_7) {
  int error;
  s21_decimal x = {{0, 2147483648, 2147483647, last_bits(0, 1)}};
  s21_decimal y = {{0, 0, 4294967295, last_bits(0, 0)}};
  s21_decimal z = {{5, 0, 0, last_bits(1, 1)}};
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// Сокращение числа
START_TEST(div_8) {
  int error;
  s21_decimal x = {
      {0, 0, 2147483648, last_bits(0, 1)}};  // 39614081257132168796771975168.0
  s21_decimal y = {
      {4294967295, 4294967295, 4294967295,
       last_bits(0, 0)}};  // 2^96 - 1 = 79228162514264337593543950335
  s21_decimal z = {{2281701376, 521306416, 271050543, last_bits(28, 1)}};
  // s21_decimal z = {{5, 0, 0, last_bits(1, 1)}};
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_9) {
  int error;
  s21_decimal x = {{899434673, 1287170588, 669260600,
                    last_bits(28, 0)}};  // 1.2345679012345654320987654321
  s21_decimal y = {
      {307163591, 25870, 0, last_bits(14, 1)}};  // -1.11111111111111(14)
  s21_decimal z = {
      {307163591, 25870, 0, last_bits(14, 1)}};  // -1.11111111111111(14)
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_11) {
  int error;
  s21_decimal x = {{3465978009, 3916779380, 834919462,
                    last_bits(21, 1)}};  // -15401545.654495706525705085081
  s21_decimal y = {{2283167487, 1, 0, last_bits(0, 0)}};  // 6578134783
  s21_decimal z = {{4272371539, 1505593010, 1269234,
                    last_bits(28, 1)}};  // -2.3413241234123412344354643
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// Сокращение числа
START_TEST(div_12) {
  int error;
  s21_decimal x = {{596000907, 1066214266, 674768470,
                    last_bits(5, 0)}};  // 124472812796779167719089.93163
  s21_decimal y = {{555991807, 4274016055, 2881,
                    last_bits(15, 0)}};  // 53163426.435536578134783
  s21_decimal z = {{3174046776, 2354457394, 1269234350,
                    last_bits(13, 0)}};  // 2341324123412341.2344354643000
  // s21_decimal z = {{4272371539, 1505593010, 1269234, last_bits(10, 0)}};  //
  // 2341324123412341.2344354643
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_13) {
  int error;
  s21_decimal x = {{1, 0, 0, last_bits(0, 0)}};
  s21_decimal y = {{3, 0, 0, last_bits(0, 0)}};
  s21_decimal z = {{89478485, 347537611, 180700362, last_bits(28, 0)}};
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_14) {
  int error;
  s21_decimal x = {{11987654, 0, 0, last_bits(5, 1)}};  // -119.87654
  s21_decimal y = {{121234, 0, 0, last_bits(4, 1)}};    // 12.1234
  s21_decimal z = {{3599404075, 1733969346, 536031167,
                    last_bits(27, 0)}};  // 9.888029760628206608707128363
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_15) {
  int error;
  s21_decimal x = {{268435455, 1042612833, 542101086,
                    last_bits(27, 1)}};  // 9.999999999999999999999999999
  s21_decimal y = {{268435455, 1042612833, 542101086,
                    last_bits(28, 0)}};  // 0.9999999999999999999999999999
  s21_decimal z = {{10, 0, 0, last_bits(0, 1)}};  // 10
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_16) {
  int error;
  s21_decimal x = {{268435455, 1042612833, 542101086,
                    last_bits(25, 1)}};  // -999.9999999999999999999999999
  s21_decimal y = {{1000, 0, 0, last_bits(0, 0)}};  // 1000
  s21_decimal z = {{268435455, 1042612833, 542101086,
                    last_bits(28, 1)}};  // -0.9999999999999999999999999999
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_17) {
  int error;
  s21_decimal x = {{2283167487, 1, 0, last_bits(0, 0)}};  // 6578134783
  s21_decimal y = {{4272371539, 1505593010, 1269234,
                    last_bits(28, 0)}};  // 0.0023413241234123412344354643
  s21_decimal z = {{79915116, 3683955822, 1523075756,
                    last_bits(16, 0)}};  // 2809578869162.616482743893412
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// pow 28
START_TEST(div_18) {
  int error;
  s21_decimal x = {{2764758783, 3642796910, 53540,
                    last_bits(0, 1)}};  // -987654323400006578134783
  s21_decimal y = {{4272371539, 1505593010, 1269234,
                    last_bits(0, 1)}};  // -23413241234123412344354643
  s21_decimal z = {{936638503, 1197965095, 22867764,
                    last_bits(28, 0)}};  // 0.0421835795191209536611678248
  // s21_decimal z = {{936638504, 1197965095, 22867764, last_bits(28, 0)}};  //
  // 0.0421835795191209536611678248
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(div_err3_0) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(5, 0)}};  // 792281625142643375935439.50335
  s21_decimal y = {{0, 0, 0, last_bits(0, 0)}};
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 3);
}
END_TEST

START_TEST(div_err1_1) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(5, 0)}};  // 792281625142643375935439.50335
  s21_decimal y = {{1, 0, 0, last_bits(6, 0)}};  // 0.000001
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(div_err1_2) {
  int error;
  s21_decimal x = {{2764758783, 3642796910, 53540,
                    last_bits(0, 1)}};  // -987654323400006578134783
  s21_decimal y = {
      {3222026067, 960056, 0, last_bits(28, 1)}};  // -4123412344354643*10^(-28)
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(div_err2_1) {
  int error;
  s21_decimal x = {{4294967295, 4294967295, 4294967295,
                    last_bits(5, 0)}};  // 792281625142643375935439.50335
  s21_decimal y = {{1, 0, 0, last_bits(6, 1)}};  // -0.000001
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 2);
}
END_TEST

START_TEST(div_err2_2) {
  int error;
  s21_decimal x = {{2764758783, 3642796910, 53540,
                    last_bits(0, 1)}};  // -987654323400006578134783
  s21_decimal y = {
      {3222026067, 960056, 0, last_bits(28, 0)}};  // 4123412344354643*10^(-28)
  s21_decimal res;
  error = s21_div(x, y, &res);
  ck_assert_int_eq(error, 2);
}
END_TEST

// ------------------- mod ------------------

START_TEST(mod_1) {
  int error;
  s21_decimal x = {
      {1610612736, 1960709702, 3252606517, last_bits(0, 0)}};  // 6*10^28
  s21_decimal y = {{552894464, 46566, 0, last_bits(0, 0)}};    // 2*10^14
  s21_decimal z = {{0, 0, 0, last_bits(0, 0)}};                // 0
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mod_2) {
  int error;
  s21_decimal x = {{0, 2147483648, 2147483647, last_bits(0, 1)}};
  s21_decimal y = {{0, 0, 4294967295, last_bits(0, 0)}};
  s21_decimal z = {{0, 2147483648, 2147483647, last_bits(0, 1)}};
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mod_3) {
  int error;
  s21_decimal x = {
      {0, 0, 2147483648, last_bits(0, 1)}};  // 39614081257132168796771975168.0
  s21_decimal y = {
      {4294967295, 4294967295, 4294967295,
       last_bits(0, 0)}};  // 2^96 - 1 = 79228162514264337593543950335
  s21_decimal z = {
      {0, 0, 2147483648, last_bits(0, 1)}};  // 39614081257132168796771975168.0
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mod_4) {
  int error;
  s21_decimal x = {
      {1879048192, 3003322535, 3794707603, last_bits(0, 1)}};  // -7*10^28
  s21_decimal y = {{123456789, 0, 0, last_bits(0, 0)}};        // 123456789
  s21_decimal z = {{33386083, 0, 0, last_bits(0, 1)}};         // 33386083
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mod_5) {
  int error;
  s21_decimal x = {
      {1879048192, 3003322535, 3794707603, last_bits(0, 0)}};  // -7*10^28
  s21_decimal y = {{123456789, 0, 0, last_bits(4, 1)}};        // 12345.6789
  s21_decimal z = {{33672544, 0, 0, last_bits(4, 0)}};         // 3367.2544
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mod_6) {
  int error;
  s21_decimal x = {
      {1879048192, 3003322535, 3794707603, last_bits(0, 0)}};  // -7*10^28
  s21_decimal y = {{123456789, 0, 0, last_bits(9, 1)}};        // 0.123456789
  s21_decimal z = {{93936814, 0, 0, last_bits(9, 0)}};         // 3367.2544
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mod_7) {
  int error;
  s21_decimal x = {{268435455, 1042612833, 542101086,
                    last_bits(15, 1)}};  // -9999999999999.999999999999999
  s21_decimal y = {{123456789, 0, 0, last_bits(9, 1)}};  // -0.123456789
  s21_decimal z = {
      {3466279167, 192, 0, last_bits(15, 1)}};  // 0.087359265999999
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mod_8) {
  int error;
  s21_decimal x = {{268435455, 1042612833, 542101086,
                    last_bits(27, 1)}};  // -9.999999999999999999999999999
  s21_decimal y = {{123456789, 0, 0, last_bits(8, 0)}};  // 0.123456789
  s21_decimal z = {{1337982975, 3759015984, 6692610,
                    last_bits(27, 1)}};  // -0.123456879999999999999999999
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// Сокращение числа
START_TEST(mod_9) {
  int error;
  s21_decimal x = {
      {1879048192, 3003322535, 3794707603, last_bits(0, 0)}};  // 7*10^28
  s21_decimal y = {{1, 0, 0, last_bits(3, 0)}};                // 0.001
  s21_decimal z = {{0, 0, 0, last_bits(3, 0)}};                // 0
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mod_11) {
  int error;
  s21_decimal x = {
      {1879048192, 3003322535, 3794707603, last_bits(0, 0)}};  // 7*10^28
  s21_decimal y = {{1, 0, 0, last_bits(0, 1)}};                // -1
  s21_decimal z = {{0, 0, 0, last_bits(0, 0)}};                // 0
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mod_12) {
  int error;
  s21_decimal x = {{228485049, 1, 0, last_bits(0, 0)}};  // 4523452345
  s21_decimal y = {{4272371539, 1505593010, 1269234,
                    last_bits(0, 1)}};  // 23413241234123412344354643
  s21_decimal z = {{228485049, 1, 0, last_bits(0, 0)}};  // 4523452345
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

// Сокращение числа
START_TEST(mod_13) {
  int error;
  s21_decimal x = {{4272371539, 1505593010, 1269234,
                    last_bits(0, 1)}};  // 23413241234123412344354643
  s21_decimal y = {{228485049, 1, 0, last_bits(1, 0)}};  // 452345234.5
  s21_decimal z = {{12375944, 1, 0, last_bits(1, 1)}};   // 430734324.0
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mod_14) {
  int error;
  s21_decimal x = {{4272371539, 1505593010, 1269234,
                    last_bits(28, 0)}};  // 0.0023413241234123412344354643
  s21_decimal y = {{228485049, 1, 0, last_bits(0, 0)}};  // 4523452345
  s21_decimal z = {{4272371539, 1505593010, 1269234, last_bits(28, 0)}};  // 0
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

START_TEST(mod_16) {
  int error;
  s21_decimal x = {{0, 0, 0, last_bits(0, 0)}};  // 0
  s21_decimal y = {{4272371539, 1505593010, 1269234,
                    last_bits(28, 0)}};  // 0.0023413241234123412344354643
  s21_decimal z = {{0, 0, 0, last_bits(0, 0)}};  // 0
  s21_decimal res;
  error = s21_mod(x, y, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], z.bits[i]);
  }
}
END_TEST

Suite *s21_decimal_test(void) {
  Suite *s;
  TCase *tc_core;
  TCase *tc_arith;

  s = suite_create("s21_decimal");
  tc_core = tcase_create("Core");
  tc_arith = tcase_create("arith_case");

  // diannper
  tcase_add_test(tc_core, is_less_1);
  tcase_add_test(tc_core, is_less_2);
  tcase_add_test(tc_core, is_less_3);
  tcase_add_test(tc_core, is_less_4);
  tcase_add_test(tc_core, is_less_5);
  tcase_add_test(tc_core, is_less_6);
  tcase_add_test(tc_core, is_less_7);
  tcase_add_test(tc_core, is_less_8);
  tcase_add_test(tc_core, is_less_9);

  tcase_add_test(tc_core, is_less_or_equal_2);
  tcase_add_test(tc_core, is_less_or_equal_3);
  tcase_add_test(tc_core, is_less_or_equal_1);
  tcase_add_test(tc_core, is_less_or_equal_4);
  tcase_add_test(tc_core, is_less_or_equal_5);
  tcase_add_test(tc_core, is_less_or_equal_6);
  tcase_add_test(tc_core, is_less_or_equal_7);
  tcase_add_test(tc_core, is_less_or_equal_8);
  tcase_add_test(tc_core, is_less_or_equal_9);

  tcase_add_test(tc_core, is_equal_2);
  tcase_add_test(tc_core, is_equal_3);
  tcase_add_test(tc_core, is_equal_1);
  tcase_add_test(tc_core, is_equal_4);
  tcase_add_test(tc_core, is_equal_5);
  tcase_add_test(tc_core, is_equal_6);
  tcase_add_test(tc_core, is_equal_7);
  tcase_add_test(tc_core, is_equal_8);
  tcase_add_test(tc_core, is_equal_9);

  tcase_add_test(tc_core, is_greater_or_equal_2);
  tcase_add_test(tc_core, is_greater_or_equal_3);
  tcase_add_test(tc_core, is_greater_or_equal_1);
  tcase_add_test(tc_core, is_greater_or_equal_4);
  tcase_add_test(tc_core, is_greater_or_equal_5);
  tcase_add_test(tc_core, is_greater_or_equal_6);
  tcase_add_test(tc_core, is_greater_or_equal_7);
  tcase_add_test(tc_core, is_greater_or_equal_8);
  tcase_add_test(tc_core, is_greater_or_equal_9);

  tcase_add_test(tc_core, is_greater_2);
  tcase_add_test(tc_core, is_greater_3);
  tcase_add_test(tc_core, is_greater_1);
  tcase_add_test(tc_core, is_greater_4);
  tcase_add_test(tc_core, is_greater_5);
  tcase_add_test(tc_core, is_greater_6);
  tcase_add_test(tc_core, is_greater_7);
  tcase_add_test(tc_core, is_greater_8);
  tcase_add_test(tc_core, is_greater_9);

  tcase_add_test(tc_core, is_not_equal_2);
  tcase_add_test(tc_core, is_not_equal_3);
  tcase_add_test(tc_core, is_not_equal_1);
  tcase_add_test(tc_core, is_not_equal_4);
  tcase_add_test(tc_core, is_not_equal_5);
  tcase_add_test(tc_core, is_not_equal_6);
  tcase_add_test(tc_core, is_not_equal_7);
  tcase_add_test(tc_core, is_not_equal_8);
  tcase_add_test(tc_core, is_not_equal_9);

  // michaleh
  tcase_add_test(tc_core, from_decimal_to_float);
  tcase_add_test(tc_core, from_decimal_to_float2);
  tcase_add_test(tc_core, from_decimal_to_int);
  tcase_add_test(tc_core, from_decimal_to_int2);
  tcase_add_test(tc_core, from_float_to_decimal);
  tcase_add_test(tc_core, from_float_to_decimal2);
  tcase_add_test(tc_core, from_float_to_decimal3);
  tcase_add_test(tc_core, from_int_to_decimal);
  tcase_add_test(tc_core, from_int_to_decimal2);
  tcase_add_test(tc_core, from_int_to_decimal3);

  // staceymo
  tcase_add_test(tc_core, negate1);
  tcase_add_test(tc_core, negate2);
  tcase_add_test(tc_core, negate3);
  tcase_add_test(tc_core, negate4);
  tcase_add_test(tc_core, negate5);
  tcase_add_test(tc_core, truncate1);
  tcase_add_test(tc_core, truncate2);
  tcase_add_test(tc_core, truncate3);
  tcase_add_test(tc_core, truncate4);
  tcase_add_test(tc_core, truncate5);
  tcase_add_test(tc_core, truncate6);
  tcase_add_test(tc_core, truncate7);
  tcase_add_test(tc_core, truncate8);
  tcase_add_test(tc_core, truncate9);
  tcase_add_test(tc_core, truncate10);
  tcase_add_test(tc_core, truncate11);
  tcase_add_test(tc_core, truncate12);
  tcase_add_test(tc_core, floor1);
  tcase_add_test(tc_core, floor2);
  tcase_add_test(tc_core, floor3);
  tcase_add_test(tc_core, floor4);
  tcase_add_test(tc_core, floor5);
  tcase_add_test(tc_core, floor6);
  tcase_add_test(tc_core, floor7);
  tcase_add_test(tc_core, floor8);
  tcase_add_test(tc_core, round1);
  tcase_add_test(tc_core, round2);
  tcase_add_test(tc_core, round3);
  tcase_add_test(tc_core, round4);
  tcase_add_test(tc_core, round5);
  tcase_add_test(tc_core, round6);
  tcase_add_test(tc_core, round7);
  tcase_add_test(tc_core, round8);
  tcase_add_test(tc_core, round9);
  tcase_add_test(tc_core, round10);

  // swindell
  // ------------------- add ------------------
  tcase_add_test(tc_arith, add_int_1);
  tcase_add_test(tc_arith, add_int_2);

  tcase_add_test(tc_arith, add_plus_max_1);
  tcase_add_test(tc_arith, add_plus_max_2);
  tcase_add_test(tc_arith, add_plus_max_3);
  tcase_add_test(tc_arith, add_plus_max_4);
  tcase_add_test(tc_arith, add_minus_max_1);
  tcase_add_test(tc_arith, add_minus_max_2);

  tcase_add_test(tc_arith, add_plus_0);
  tcase_add_test(tc_arith, add_plus_1);
  tcase_add_test(tc_arith, add_plus_2);
  tcase_add_test(tc_arith, add_plus_3);
  tcase_add_test(tc_arith, add_plus_4);
  tcase_add_test(tc_arith, add_plus_5);
  tcase_add_test(tc_arith, add_plus_6);
  tcase_add_test(tc_arith, add_plus_7);

  tcase_add_test(tc_arith, add_minus_1);
  tcase_add_test(tc_arith, add_minus_2);
  tcase_add_test(tc_arith, add_minus_3);

  tcase_add_test(tc_arith, add_sub_1);
  tcase_add_test(tc_arith, add_sub_2);
  tcase_add_test(tc_arith, add_sub_3);
  tcase_add_test(tc_arith, add_sub_4);

  tcase_add_test(tc_arith, add_err1_1);
  tcase_add_test(tc_arith, add_err1_2);
  tcase_add_test(tc_arith, add_err2_1);
  tcase_add_test(tc_arith, add_err2_2);

  // ------------------- sub ------------------
  tcase_add_test(tc_arith, sub_int_1);
  tcase_add_test(tc_arith, sub_int_2);

  tcase_add_test(tc_arith, sub_add_max_1);
  tcase_add_test(tc_arith, sub_add_max_2);
  tcase_add_test(tc_arith, sub_add_max_3);

  tcase_add_test(tc_arith, sub_plus_max_1);
  tcase_add_test(tc_arith, sub_minus_max_2);

  tcase_add_test(tc_arith, sub_0);
  tcase_add_test(tc_arith, sub_1);
  tcase_add_test(tc_arith, sub_2);
  tcase_add_test(tc_arith, sub_3);
  tcase_add_test(tc_arith, sub_4);
  tcase_add_test(tc_arith, sub_5);
  tcase_add_test(tc_arith, sub_6);
  tcase_add_test(tc_arith, sub_7);
  tcase_add_test(tc_arith, sub_8);
  tcase_add_test(tc_arith, sub_9);
  tcase_add_test(tc_arith, sub_10);
  tcase_add_test(tc_arith, sub_11);
  tcase_add_test(tc_arith, sub_12);
  tcase_add_test(tc_arith, sub_13);
  tcase_add_test(tc_arith, sub_14);
  tcase_add_test(tc_arith, sub_15);
  tcase_add_test(tc_arith, sub_16);
  tcase_add_test(tc_arith, sub_17);
  tcase_add_test(tc_arith, sub_18);
  tcase_add_test(tc_arith, sub_19);

  tcase_add_test(tc_arith, sub_add_1);
  tcase_add_test(tc_arith, sub_add_2);

  tcase_add_test(tc_arith, sub_err1_1);
  tcase_add_test(tc_arith, sub_err1_2);
  tcase_add_test(tc_arith, sub_err2_1);
  tcase_add_test(tc_arith, sub_err2_2);

  // ------------------- mul ------------------
  tcase_add_test(tc_arith, mul_int_1);
  tcase_add_test(tc_arith, mul_int_2);

  tcase_add_test(tc_arith, mul_0);
  tcase_add_test(tc_arith, mul_1);
  tcase_add_test(tc_arith, mul_2);
  tcase_add_test(tc_arith, mul_3);
  tcase_add_test(tc_arith, mul_4);
  tcase_add_test(tc_arith, mul_5);
  tcase_add_test(tc_arith, mul_6);
  tcase_add_test(tc_arith, mul_7);
  tcase_add_test(tc_arith, mul_8);
  tcase_add_test(tc_arith, mul_9);
  tcase_add_test(tc_arith, mul_11);
  tcase_add_test(tc_arith, mul_12);
  tcase_add_test(tc_arith, mul_13);
  tcase_add_test(tc_arith, mul_14);
  tcase_add_test(tc_arith, mul_15);
  tcase_add_test(tc_arith, mul_16);

  tcase_add_test(tc_arith, mul_pow_1);
  tcase_add_test(tc_arith, mul_pow_2);
  tcase_add_test(tc_arith, mul_pow_3);
  tcase_add_test(tc_arith, mul_pow_4);

  tcase_add_test(tc_arith, mul_max_1);
  tcase_add_test(tc_arith, mul_max_2);
  tcase_add_test(tc_arith, mul_max_3);

  tcase_add_test(tc_arith, mul_err1_1);
  tcase_add_test(tc_arith, mul_err1_2);
  tcase_add_test(tc_arith, mul_err2_1);
  tcase_add_test(tc_arith, mul_err2_2);

  // ------------------- div ------------------
  tcase_add_test(tc_arith, div_int_1);
  tcase_add_test(tc_arith, div_int_2);

  tcase_add_test(tc_arith, div_1);
  tcase_add_test(tc_arith, div_2);
  tcase_add_test(tc_arith, div_3);
  tcase_add_test(tc_arith, div_4);
  tcase_add_test(tc_arith, div_5);
  tcase_add_test(tc_arith, div_6);
  tcase_add_test(tc_arith, div_7);
  tcase_add_test(tc_arith, div_8);
  tcase_add_test(tc_arith, div_9);
  tcase_add_test(tc_arith, div_11);
  tcase_add_test(tc_arith, div_12);
  tcase_add_test(tc_arith, div_13);
  tcase_add_test(tc_arith, div_14);
  tcase_add_test(tc_arith, div_15);
  tcase_add_test(tc_arith, div_16);
  tcase_add_test(tc_arith, div_17);
  tcase_add_test(tc_arith, div_18);

  tcase_add_test(tc_arith, div_err3_0);
  tcase_add_test(tc_arith, div_err1_1);
  tcase_add_test(tc_arith, div_err1_2);
  tcase_add_test(tc_arith, div_err2_1);
  tcase_add_test(tc_arith, div_err2_2);

  // ------------------- mod ------------------
  tcase_add_test(tc_arith, mod_1);
  tcase_add_test(tc_arith, mod_2);
  tcase_add_test(tc_arith, mod_3);
  tcase_add_test(tc_arith, mod_4);
  tcase_add_test(tc_arith, mod_5);
  tcase_add_test(tc_arith, mod_6);
  tcase_add_test(tc_arith, mod_7);
  tcase_add_test(tc_arith, mod_8);
  tcase_add_test(tc_arith, mod_9);
  tcase_add_test(tc_arith, mod_11);
  tcase_add_test(tc_arith, mod_12);
  tcase_add_test(tc_arith, mod_13);
  tcase_add_test(tc_arith, mod_14);
  tcase_add_test(tc_arith, mod_16);

  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc_arith);
  return s;
}

int main(void) {
  int no_failed;
  Suite *s;
  SRunner *sr;

  s = s21_decimal_test();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
