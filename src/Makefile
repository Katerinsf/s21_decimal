FLAGS = -Wall -Werror -Wextra -std=c11
FUNC_C = big_helper.c helper.c s21_add.c s21_banking_round.c s21_div.c s21_floor.c s21_from_decimal_to_float.c \
s21_from_decimal_to_int.c s21_from_float_to_decimal.c s21_from_int_to_decimal.c s21_is_equal.c s21_is_greater.c \
s21_is_greater_or_equal.c s21_is_less.c s21_is_less_or_equal.c s21_is_not_equal.c s21_mod.c s21_mul.c s21_negate.c \
s21_round.c s21_sub.c s21_truncate.c
FUNC_O = big_helper.o helper.o s21_add.o s21_banking_round.o s21_div.o s21_floor.o s21_from_decimal_to_float.o \
s21_from_decimal_to_int.o s21_from_float_to_decimal.o s21_from_int_to_decimal.o s21_is_equal.o s21_is_greater.o \
s21_is_greater_or_equal.o s21_is_less.o s21_is_less_or_equal.o s21_is_not_equal.o s21_mod.o s21_mul.o s21_negate.o \
s21_round.o s21_sub.o s21_truncate.o

all: s21_decimal.a

rebuild: clean all

clean:
	rm -rf *.o out *.info *.gcda *.gcno *.gcov *.gch *.out *.a test

s21_decimal.a: s21_decimal.o
	ar rc s21_decimal.a $(FUNC_O)
	ranlib s21_decimal.a

s21_decimal.o:
	gcc $(FLAGS) -c $(FUNC_C)

test: clean
	gcc $(FLAGS) -fprofile-arcs -ftest-coverage $(FUNC_C) -o test  s21_test.c -lcheck -lm -lpthread
	./test

gcov_report: test
	gcov s21_test.c
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out

style:
	clang-format -n *.c

leaks:
	leaks -atExit -- ./test | grep LEAK

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem ./

valgrind:
	valgrind --leak-check=full \
             --show-leak-kinds=all \
             --track-origins=yes \
             --verbose \
             --log-file=valgrind-out.txt \
             ./test exampleParam1

