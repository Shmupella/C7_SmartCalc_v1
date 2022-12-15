#include <stdio.h>
#include <math.h>
#include "parcer.h"
#include "polish_notation.h"
#include "calculate.h"
#include "validation.h"

void print_que(queue *first);

int main() {
    // char str[255] = "cos(2)/*947-sin(1)+atan()^1+tan(17)*acos(0.7878)-asin(123)/sqrt(64)-ln(10)*log(123)-(-4)mod10";
    char str[256] = "3/0";
    queue *output_que = NULL;
    queue *input_que = NULL;
    printf("%s\n", str);
    if (validation_str(str)) {
        printf("Input error!\n");
    } else {
        input_que = make_list(str, input_que, 10);
        print_que(input_que);
        output_que = polish_notation(input_que);
        print_que(output_que);
        printf("res == %.7f\n", calculation(output_que));
    }
    printf("off result == %.7f\n", 3/0);
    
    return 0;
}

void print_que(queue *first) {
    while (first) {
        printf("value: %f ", first->value);
        printf("type: %d\n", first->type);
        // printf("prior: %d\n", first->priority);
        first = first->next;
    }
}



