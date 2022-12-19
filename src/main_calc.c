#include "main_calc.h"

char *main_calc(char *input_string, double x_value) {
    queue *input_que = NULL;
    queue *output_que = NULL;
    char result[256] = "Input error!";
    double res = 0;
    if (!validation_str(input_string)) {
        input_que = make_list(input_string, input_que, x_value);
        output_que = polish_notation(input_que);
        res = calculation(output_que);
        sprintf(result, "%f", res);
    }
    return result;
}
