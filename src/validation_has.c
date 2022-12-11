#include "validation.h"
#include "stack.h"
#include <string.h>
#include <stdio.h>

int validation(char *src) {
    int brackets = 0;
    int res = 1;
    int err = 0;
    int float_point = 0;
    delete_spaces(src);
    if (strlen(src) > 255 || strlen(src) < 3) {
        err = 1;
    }
    for (int i = 0; src[i]; i++) {
        if (src[i] == '(') {
            brackets++;
            if (src[i+1] == ')')
                err = 1;
        }
        if (src[i] == ')')
            brackets--;
        if (brackets < 0)
            err = 1;
    }
    if (brackets)
        err = 1;
    for (int i = 0; src[i] && !err; i++) {
        if (src[i] == 'm') {
            int tmp = 0;
            float_point = 0;
            if ((tmp = is_mod(src, i))) {
                i = tmp;
                continue;
            } else {
                err = 1;
            }
        }
        if (src[i] == 'x') {
            if ((src[i-1] != '(' && !is_oper(src, i-1) && i > 0) ||\
             (!is_oper(src, i+1) && src[i+1] != ')' && src[i+1] != 0)) {
                err = 1;
            }
        }
        if (src[i] == '.') {
            if (float_point)
                err = 1;
            float_point = 1;
            if (i == 0 || i == 254) {
                err = 1;
            } else {
                if (!(src[i-1] >= '0' && src[i-1] <= '9') || !(src[i+1] >= '0' && src[i+1] <= '9'))
                    err = 1;
            }
        }
        if (src[i] == '+' || src[i] == '-') {
            float_point = 0;
            if ((src[i-1] != '(' && src[i-1] != 'x' && src[i-1] != ')' && !(src[i-1] >= '0' && src[i-1]\
             <= '9') && i > 0) || i == 0 || (src[i+1] != '(' && !(src[i+1] >= '0' && src[i+1] <= '9') \
             && !(src[i+1] >= 'a' && src[i+1] <= 'z'))) {
                err = 1;
            }
        }
        if (src[i] == '*' || src[i] == '/' || src[i] == '^') {
            float_point = 0;
            if ((src[i-1] != ')' && !(src[i-1] >= '0' && src[i-1] <= '9') && src[i-1] != 'd' &&\
             src[i-1] != 'x' && i > 0) || (src[i+1] != '(' && !(src[i+1] >= '0' && src[i+1] <= '9')\
              && !(src[i+1] >= 'a' && src[i+1] <= 'z')))
                err = 1;
        }
        if (src[i] >= 'a' && src[i] <= 'z' && src[i] != 'x' && src[i] != 'm') {
            int tmp = 0;
            if (i == 0 || (i > 0 && (src[i-1] == '-' || src[i-1] == '*' || src[i-1] == '/' || src[i-1]\
             == 'd' || src[i-1] == '+' || src[i-1] == '^' || src[i-1] == '(')) ) {
                if (src[i+1] == 10) {
                    err = 1;
                } else if ((tmp = valid_funcs(src, i))) {
                    i = tmp;
                    continue;
                } else {
                    err = 1;
                }
            } else {
                err = 1;
            }
        }
    }
    if (err)
        res = 0;
    return res;
}

int valid_funcs(char *src, int i) {
    int res = 0;
    if (src[i] == 's') {
        if (src[i+1] == 'i' && src[i+2] == 'n' && src[i+3] == '(')
            res = i+2;
        if (src[i+1] == 'q' && src[i+2] == 'r' && src[i+3] == 't' && src[i+4] == '(')
            res = i+3;
    }
    if (src[i] == 'c')
        if (src[i+1] == 'o' && src[i+2] == 's' && src[i+3] == '(')
            res = i+2;
    if (src[i] == 't')
        if (src[i+1] == 'a' && src[i+2] == 'n' && src[i+3] == '(')
            res = i+2;
    if (src[i] == 'a') {
        if (src[i+1] == 'c' && src[i+2] == 'o' && src[i+3] == 's' && src[i+4] == '(')
            res = i+3;
        if (src[i+1] == 's' && src[i+2] == 'i' && src[i+3] == 'n' && src[i+4] == '(')
            res = i+3;
        if (src[i+1] == 't' && src[i+2] == 'a' && src[i+3] == 'n' && src[i+4] == '(')
            res = i+3;
    }
    if (src[i] == 'l') {
        if (src[i+1] == 'o' && src[i+2] == 'g' && src[i+3] == '(')
            res = i+2;
        if (src[i+1] == 'n' && src[i+2] == '(')
            res = i+1;
    }
    return res;
}

void delete_spaces(char *src) {
    for (int i = 0; src[i]; i++) {
        if (src[i] == ' ' || src[i] == '\t') {
            for (int n = i; src[n]; n++)
                src[n] = src[n+1];
            i = 0;
        }
    }
}

int is_oper(char *src, int i) {
    return src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/' ||\
     src[i] == 'm' || src[i] == 'd' || src[i] == '^';
}

int is_mod(char *src, int i) {
    int res = 0;
    if (i != 0 && i < 252 && !is_oper(src, i-1) && src[i-1] != '(') {
        if (src[i+1] == 'o' && src[i+2] == 'd') {
            if (src[i+3] != ')' && !is_oper(src, i+3)) {
                res = i+2;
            }
        }
    }
    return res;
}

stack *parcing(char *src) {
    stack *tmp = NULL;
    stack *revtmp = NULL;
    double num = 0;
    int type = 0, prior = 0;
    for (int i = 0; src[i] != 0;) {
        if (src[i] >= '0' && src[i] <= '9') {
            sscanf(src+i, "%lf", &num);
            push(&tmp, num);
            tmp->prior = 0;
            tmp->type = number;
            while ((src[i] >= '0' && src[i] <= '9') || src[i] == '.')
                i++;
            continue;
        }
        if (src[i] == 'x') {
            push(&tmp, 0);
            tmp->type = x;
            tmp->prior = 0;
            i++;
        } else if (src[i] == 'm') {
            push(&tmp, 0);
            tmp->type = modd;
            tmp->prior = 2;
            i += 3;
        } else if (src[i] >= 'a' && src[i] <= 'z') {
            push(&tmp, 0);
            tmp->prior = 4;
            if (src[i] == 's' || src[i] == 'c' || src[i] == 't') {
                if (src[i+1] == 'i') {
                    i += 3;
                    tmp->type = sinn;
                } else if (src[i+1] == 'q') {
                    i += 4;
                    tmp->type = sqrtt;
                } else if (src[i+1] == 'o') {
                    i += 3;
                    tmp->type = coss;
                } else if (src[i+1] == 'a') {
                    i += 3;
                    tmp->type = tann;
                }
            }
            if (src[i] == 'a') {
                if (src[i+1] == 's')
                    tmp->type = asinn;
                if (src[i+1] == 'c')
                    tmp->type = acoss;
                if (src[i+1] == 't')
                    tmp->type = atann;
                i += 4;
            }
            if (src[i] == 'l') {
                if (src[i+1] == 'n') {
                    i += 2;
                    tmp->type = lnn;
                } else {
                    i += 3;
                    tmp->type = logg;
                }
            }
        } else if (is_oper(src, i)) {
            push(&tmp, 0);
            if (src[i] == '+') {
                if (src[i-1] == '(') {
                    tmp->type = number;
                    tmp->prior = 0;
                    push(&tmp, 0);
                }
                tmp->type = plus;
                tmp->prior = 1;
            }
            if (src[i] == '-') {
                if (src[i-1] == '(') {
                    tmp->type = number;
                    tmp->prior = 0;
                    push(&tmp, 0);
                }
                tmp->type = minus;
                tmp->prior = 1;
            }
            if (src[i] == '*') {
                tmp->type = mul;
                tmp->prior = 2;
            }
            if (src[i] == '/') {
                tmp->type = divv;
                tmp->prior = 2;
            }
            if (src[i] == '^') {
                tmp->type = poww;
                tmp->prior = 3;
            }
            i++;
        } else if (src[i] == '(') {
            push(&tmp, 0);
            tmp->type = lbracket;
            tmp->prior = 7;
            i++;
        } else if (src[i] == ')') {
            push(&tmp, 0);
            tmp->type = rbracket;
            tmp->prior = 6;
            i++;
        }
    }
    while (tmp) {
        prior = tmp->prior;
        type = tmp->type;
        num = pop(&tmp);
        push(&revtmp, num);
        revtmp->type = type;
        revtmp->prior = prior;
    }
    return revtmp;
}

int axis_validation(long double xMax, long double xMin, long double yMin, long double yMax) {
    int return_value = 1;
    if (xMin >= xMax || yMin >= yMax || xMin < -10000 || xMax > 10000 || yMin < -10000 || yMax > 10000)
        return_value = 0;
    return return_value;
}
