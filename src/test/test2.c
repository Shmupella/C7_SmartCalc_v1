#include <stdio.h>

void aaa (int *x) {
    *x = 10;
}


int main() {
    int i = 5;
    aaa(&(i+5));
}
