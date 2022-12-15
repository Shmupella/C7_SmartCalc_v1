#include "calculate.h"

double calculation(queue *input_que) {
    double num1 = 0;
    double num2 = 0;
    double value = 0;
    int priority = 0;
    enum lexeme_type type = 0;
    enum lexeme_type trash_type = 0;
    double res = 0;
    stack *first_stack = NULL;
    while (input_que) {
        input_que = pop_q(input_que, &value, &priority, &type);
        if (type == t_number || type == t_x) {
            first_stack = push_s(first_stack, value, priority, type);
        } else if (is_operator(type)) {
            first_stack = pop_s(first_stack, &num1, &priority, &trash_type);
            first_stack = pop_s(first_stack, &num2, &priority, &trash_type);
            switch((int)type) {
                case t_plus:
                    res = num2 + num1;
                    break;
                case t_minus:
                    res = num2 - num1;
                    break;
                case t_mul:
                    res = num2 * num1;
                    break;
                case t_div:
                    res = num2 / num1;
                    break;
                case t_mod:
                    res = fmod(num2, num1);
                    break;
                case t_pow:
                    res = pow(num2, num1);
                    break;
            }
            first_stack = push_s(first_stack, res, 0, t_number);
        } else if (is_function(type)) {
            first_stack = pop_s(first_stack, &num1, &priority, &trash_type);
            switch((int)type) {
                case t_cos:
                    res = cos(num1);
                    break;
                case t_sin:
                    res = sin(num1);
                    break;
                case t_sqrt:
                    res = sqrt(num1);
                    break;
                case t_tan:
                    res = tan(num1);
                    break;
                case t_acos:
                    res = acos(num1);
                    break;
                case t_asin:
                    res = asin(num1);
                    break;
                case t_atan:
                    res = atan(num1);
                    break;
                case t_ln:
                    res = log(num1);
                    break;
                case t_log:
                    res = log10(num1);
                    break;
            }
            first_stack = push_s(first_stack, res, 0, t_number);
        }
    }
    first_stack = pop_s(first_stack, &res, &priority, &type);
    return res;
}
