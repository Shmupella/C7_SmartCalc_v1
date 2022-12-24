all: gcov_report

test:
	checkmk clean_mode=1 calc.check > calc_tests.c
	gcc -Wall -Werror -Wextra calc_tests.c calculate.c main_calc.c parcer.c polish_notation.c stack.c validation.c -lcheck -o test.out
	./test.out

gcov_report:
	checkmk clean_mode=1 calc.check > calc_tests.c
	gcc --coverage -Wall -Werror -Wextra calc_tests.c calculate.c main_calc.c parcer.c polish_notation.c stack.c validation.c -lcheck -o calc_report
	./calc_report
	lcov -t "calc_rep" -o calc_rep.info -c -d .
	genhtml -o report calc_rep.info
	open report/index.html

clean:
	rm -rf *.o *.a test.out *.gcda *.gcno *.info report calc_report calc_tests.c