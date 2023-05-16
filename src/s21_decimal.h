//#ifndef SRC_SRC_DECIMAL_H_
//#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int bits[4];
  // int bits[4];
} s21_decimal;

typedef struct s21_big_decimal {
  int bits[7];
} s21_big_decimal;

#define code_OK 0
#define code_POS_INF 1
#define code_NEG_INF 2
#define code_DIV_0 3

#define S21_TRUE 1
#define S21_FALSE 0

// ----------------- Преобразования -----------------
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// ----------------- Арифметические операции -----------------
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// -------------------- Сравнение ---------------------
int s21_is_equal(s21_decimal decimal_one, s21_decimal decimal_two);
int s21_is_not_equal(s21_decimal decimal_one, s21_decimal decimal_two);
int s21_is_less(s21_decimal decimal_one, s21_decimal decimal_two);
int s21_is_less_or_equal(s21_decimal decimal_one, s21_decimal decimal_two);
int s21_is_greater(s21_decimal decimal_one, s21_decimal decimal_two);
int s21_is_greater_or_equal(s21_decimal decimal_one, s21_decimal decimal_two);

int s21_compare(s21_decimal number_1, s21_decimal number_2);
int is_zero(s21_decimal decimal_one);

// --------- Округление -----------
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_banking_round(s21_decimal value, s21_decimal *result);
void set_scale_and_sign(s21_decimal *value, int scale, int sign);

// ----------------- Helper для децимала -----------------
// Проверка и создание знака и степени
int sign_check(s21_decimal value);
int pow_check(s21_decimal value);
int last_bits(int pow, int sign);

// Изменения децимала для вычислений
void zero_init(s21_decimal *value);
s21_decimal sign_inv(s21_decimal value);
void sign_copy(s21_decimal value1, s21_decimal *value2);
s21_decimal module(s21_decimal value);

// Сдвиг запятой
void shift_dec(s21_decimal *value_1, s21_decimal *value_2);
int mul_10(s21_decimal *value);
s21_decimal bank_p(s21_decimal value, int p);

// Сколько битов занято и сдвиг всеего децимала
int num_bits_dec(s21_decimal value);
int num_bits_int(int value);
int shift_bits(s21_decimal *value, int j);

// Вывод
int take_bit(s21_decimal value, int bit);
void str_bits(s21_decimal value, char *str);
void print_bits(s21_decimal value);
void print_all(s21_decimal value1, s21_decimal value2, s21_decimal value3);

// ----------------- Часть арифметики -----------------
// Взятие разряда
void change_bits(s21_decimal *value, int j);  // In sub!

// Целочисленное деление
int int_div_10(s21_decimal value_1,
               s21_decimal *result);  // Целочисленное деление на 10

// ============================= BIG DECIMAL =============================
// ----------------- Часть арифметики -----------------
void change_bits_big(s21_big_decimal *value,
                     int j);  // Взятие разряда - In sub!

// Целочисленное деление
void int_div_big(s21_big_decimal *value_1, s21_decimal value_2,
                 s21_big_decimal *mod);
int int_div_big_10(
    s21_big_decimal value_1,
    s21_big_decimal *result);  // Целочисленное деление на 10 расш. децимала

int add_big(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result);
int sub_big(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result);
void mul_big(s21_big_decimal value_1, s21_big_decimal value_2,
             s21_big_decimal *result);
void div_big(s21_big_decimal value_1, s21_decimal value_2,
             s21_big_decimal *result);
void mod_big(s21_big_decimal *value_1, s21_big_decimal value_2,
             s21_big_decimal *mod);

// ----------------- Helper для увеличенного децимала -----------------
// Перевод
s21_big_decimal dec_to_big(s21_decimal value);
int big_to_dec(s21_big_decimal value1, s21_decimal *value2);
int check_big(s21_big_decimal value);
int mul_big_dec_10(s21_big_decimal *value);

// Проверка и создание знака и степени
int sign_check_big(s21_big_decimal value);
int pow_check_big(s21_big_decimal value);

// Изменения децимала для вычислений
void zero_big_init(s21_big_decimal *value);
void sign_copy_big(s21_big_decimal value1, s21_big_decimal *value2);
s21_big_decimal sign_inv_big(s21_big_decimal value);
s21_big_decimal module_big(s21_big_decimal value);

// Сдвиг запятой
void shift_big_dec(s21_big_decimal *value_1, s21_big_decimal *value_2);
int mul_big_10(s21_big_decimal *value);
s21_big_decimal bank_p_big(s21_big_decimal value, int p);

// Сколько битов занято и сдвиг всеего децимала
int num_bits_big_dec(s21_big_decimal value);
int shift_big_bits(s21_big_decimal *value, int j);

// Вывод | done
int take_bit_big(s21_big_decimal value, int bit);
void str_bits_big(s21_big_decimal value, char *str);
void print_bits_big(s21_big_decimal value);
void print_all_big(s21_big_decimal value1, s21_big_decimal value2,
                   s21_big_decimal value3);

//--------- Сравнение ------------
int s21_is_equal_big(s21_big_decimal decimal_one, s21_big_decimal decimal_two);
int s21_is_not_equal_big(s21_big_decimal decimal_one,
                         s21_big_decimal decimal_two);
int s21_is_less_big(s21_big_decimal decimal_one, s21_big_decimal decimal_two);
int s21_is_less_or_equal_big(s21_big_decimal decimal_one,
                             s21_big_decimal decimal_two);
int s21_is_greater_big(s21_big_decimal decimal_one,
                       s21_big_decimal decimal_two);
int s21_is_greater_or_equal_big(s21_big_decimal decimal_one,
                                s21_big_decimal decimal_two);

int s21_compare_big(s21_big_decimal number_1, s21_big_decimal number_2);
int is_zero_big(s21_big_decimal decimal_one);

//--------- Округление -----------
int s21_truncate_big(s21_big_decimal value, s21_big_decimal *result);
int s21_banking_round_big(s21_big_decimal value, s21_big_decimal *result);
void set_scale_and_sign_big(s21_big_decimal *value, int scale, int sign);

//#endif // SRC_s21_DECIMAL_H_
