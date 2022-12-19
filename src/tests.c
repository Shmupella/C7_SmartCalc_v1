#include <check.h>
#include <limits.h>

#include "stack.h"
#include "validation.h"
#include "s21_calc.h"
#include "polish.h"
#include "main_calc.h"

#define ERROR "Input error!"
#define SUCCESS 1

START_TEST(smartcalc_tests) {
    char *input_expression;
    double result, x;
    char *return_value = malloc(255);

    input_expression = ")cos)(17+4)*";
    return_value = main_calc(input_expression, 0);
    ck_assert_str_eq(return_value, ERROR);

    input_expression = "2";
    return_value = main_calc(input_expression, 0);
    ck_assert_str_eq(return_value, ERROR);

    input_expression = "45.56mod2.4";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, fmod(45.56, 2.4), 1e-7);

    return_value = axis_validation(20, 20, -20, 20);
    ck_assert_str_eq(return_value, ERROR);

    input_expression = "asin(0.56)";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, asin(0.56), 1e-7);

    input_expression = "acos(0.56)";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, acos(0.56), 1e-7);

    input_expression = "16*sin(2)";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, 14.5487588292, 1e-7);

    input_expression = "3.5-acos(0.5))";
    return_value = main_calc(input_expression, 0);
    ck_assert_str_eq(return_value, ERROR);

    input_expression = "acos()";
    return_value = main_calc(input_expression, 0);
    ck_assert_str_eq(return_value, ERROR);

    input_expression = "1+2/(1";
    return_value = main_calc(input_expression, 0);
    ck_assert_str_eq(return_value, ERROR);

    input_expression = "1+2/(1mod)";
    return_value = main_calc(input_expression, 0);
    ck_assert_str_eq(return_value, ERROR);

    input_expression = "sqrt(0.25)";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, 0.5, 1e-7);

    input_expression = "0+sqrt(0.25)";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, 0.5, 1e-7);

    input_expression = "(-sqrt(0.25))";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, -0.5, 1e-7);

    input_expression = "(ln(25.9))";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, 3.2542429, 1e-7);

    input_expression = "(-log(982.465))";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, -2.992317, 1e-7);

    input_expression = "(+(-1+(+1)))";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, 0, 1e-7);

    input_expression = "7*(2)*1";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, 14, 1e-7);

    input_expression = "2^sin(3)/1";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, 1.1027608, 1e-7);

    input_expression = "sin(-1000000)";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, 0.3499935, 1e-7);

    input_expression = "cos(123456)";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, -0.6722948, 1e-7);

    input_expression = "atan(1000000)";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, 1.5707953, 1e-7);

    input_expression = "tan(2)+ln(40)";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, 1.5038395, 1e-7);

    input_expression = "log(2)+log(3)";
    return_value = main_calc(input_expression, 0);
    ck_assert_double_eq_tol(result, 0.7781512, 1e-7);

    x = 654123.891357;
    input_expression = "sin(x)+cos(-x)+tan(+x)";
    return_value = main_calc(input_expression, x, &result);
    ck_assert_double_eq_tol(result, 1.5927179, 1e-7);

    x = 1;
    input_expression = "x-x*x/x";
    return_value = main_calc(input_expression, x, &result);
    ck_assert_double_eq_tol(result, 0, 1e-7);

    input_expression = "(-0)";
    return_value = main_calc(input_expression, x, &result);
    ck_assert_double_eq_tol(result, 0, 1e-7);

    input_expression = "(-1*0)";
    return_value = main_calc(input_expression, x, &result);
    ck_assert_double_eq_tol(result, 0, 1e-7);

    input_expression = "(0*(-1))";
    return_value = main_calc(input_expression, x, &result);
    ck_assert_double_eq_tol(result, 0, 1e-7);

    input_expression = "(0*(-1))";
    return_value = main_calc(input_expression, x, &result);
    ck_assert_double_eq_tol(result, 0, 1e-7);

    input_expression =
        "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin("
        "10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+"
        "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin("
        "10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)";
    return_value = main_calc(input_expression, x, &result);
    ck_assert_double_eq_tol(result, -17.4086755, 1e-7);

    // input_expression = "";
    // return_value = main_calc(input_expression, x, &result);
    // ck_assert_str_eq(return_value, ERROR);
}
END_TEST

int main() {
    Suite *s1 = suite_create("Core");
    TCase *s21_test = tcase_create("Test");
    SRunner *sr = srunner_create(s1);
    suite_add_tcase(s1, s21_test);

    tcase_add_test(s21_test, smartcalc_tests);

    srunner_run_all(sr, CK_VERBOSE);
    int errors = srunner_ntests_failed(sr);
    srunner_free(sr);

    return errors == 0 ? 0 : 1;
}
