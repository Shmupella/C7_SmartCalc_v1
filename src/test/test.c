#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int* array, int arrayLength);
int max(int* array, int arrayLength);

int main() {
    int array[7] = {5, 10, -7, 0, 6, 16000, 16000};
    int array_size = 7;
    int min_num = min(array, array_size);
    int max_num = max(array,array_size);
    printf("min_num: %d\nmax_num: %d\n", min_num, max_num);
    return 0;
}


// struct stack *make_stack(char *arr, int len) {
//     struct stack *first = NULL;
//     for (int i = 0; i < len; i++) {
//         first = push(first, arr[i]);
//     }
//     return first;
// }

// struct queue *make_list(char *arr, int len) {
//     struct queue *first = malloc(sizeof(struct queue));
//     struct queue *tmp = first; 
//     for (int i = 0; i < len; i++) {
//         tmp->value = arr[i];
//         if (i == len - 1) {
//             tmp->next = NULL;
//         } else {
//             tmp->next = malloc(sizeof(struct queue));
//             tmp = tmp->next;
//         }
//     }
//     return first;
// }

// void print_que(struct queue *first) {
//     while (first) {
//         printf("%c ", first->value);
//         first = first->next;
//     }
//     putchar('\n');
// }

// void print_stack(struct stack *first) {
//     while (first) {
//         printf("%c ", first->data);
//         first = first->next;
//     }
//     putchar('\n');
// }

// void destroy_queue(struct queue *first) {
//     struct queue *tmp = NULL;
//     while (first) {
//         tmp = first->next;
//         free(first);
//         first = tmp;
//     }
// }



// int min(int* array, int arrayLength) {
//     int min = array[0];
//     for (int i = 1; i < arrayLength; i ++) {
//         if (array[i] < min) {
//             min = array[i];
//         }
//     }
//     return min;
// }

// int max(int* array, int arrayLength) {
//     int i = 1;
//     int max = array[0];
//     for (; i < arrayLength; i ++) {
//         if (array[i] > max) {
//             max = array[i];
//         }
//     }
//     return max;
// }

// void get_arr_symb(char *arr) {
//     int c = 0;
//     int i = 0;
//     while (c != '=' && i < 256) {
//         c = getchar();
//         if (c == '\n' || c == ' ' || c == '\t')  {
//             continue;
//         }
//         if (c != '=') {
//             arr[i] = c;
//             i++;
//         } else {
//             break;
//         }
//     }
//     arr[i] = '\0';
// }
// void print_arr(char *input) {
//     // for(int k = 0; k < i; k++) {
//     //     printf("%c", input[k]);
//     // }
//      printf("%s\n", input);
// }

// unsigned long square_digits (unsigned n) {
//     unsigned long arr[100];
//     int count_of_elem = 0;
//     if (n == 0)
//         return 0;
//     while (n > 0) {
//         arr[count_of_elem] = n % 10;
//         n /= 10;
//         count_of_elem++;
//     }
//     unsigned long ready_arr[count_of_elem];
//     inverse_square_arr(arr, count_of_elem, ready_arr);
//     int i = 0;
//     char str[100] = {'\0'};
//     while (i < count_of_elem) {
//         sprintf(str+strlen(str), "%ld", ready_arr[i]);
//         printf("%s\n", str);
//         i++;
//     }
//     unsigned long result = 0;
//     sscanf(str, "%lu", &result);
// 	return result;
// }

// void inverse_square_arr(unsigned long *arr, int count_of_elem, unsigned long *ready_arr) {
//     int max_index_arr = count_of_elem - 1;
//     for (int i = 0, j = 0; max_index_arr >= i; max_index_arr--, j++) {
//         ready_arr[j] = arr[max_index_arr] * arr[max_index_arr];
//     }
// }

// char* itoa(int val, int base){

// 	static char buf[32] = {0};

// 	int i = 30;

// 	for(; val && i ; --i, val /= base)
	
// 		buf[i] = "0123456789abcdef"[val % base];

// 	return &buf[i+1];
	
// }

// void high_and_low (const char *str_num, char *result) {
//     long result_arr[1000] = {0};
//     long max_num = 0;
//     long min_num = 0;
//     char answer[1000];
//     int count_of_elem = inverse_str((char*)str_num, result_arr);
//     printf("%d\n", count_of_elem);
//     find_max_min_num(&max_num, &min_num, result_arr, count_of_elem);
//     printf("%ld %ld\n", max_num, min_num);
//     sprintf(answer, "%ld %ld", max_num, min_num);
// }

// int inverse_str(char *str_num, long *result_arr) {
//     long res = 0;
//     int count_of_elem = 0;
//     while ((res = strtol(str_num, &str_num, 0))) {
//         result_arr[count_of_elem] = res;
//         count_of_elem++;
//     }
//     return count_of_elem;
// }

// void find_max_min_num(long *max_num, long *min_num, long *result_arr, int count_of_elem) {
//     int k = 0;
//     while (k < count_of_elem ) {
//         if (result_arr[k] < *min_num) {
//             *min_num = result_arr[k];
//         }
//         if (result_arr[k] > *max_num) {
//             *max_num = result_arr[k];
//         }
//         k++;
//     }
// }

// bool solution(const char *string, const char *ending) {
//     int count_s = 0;
//     int count_e = 0;
//     int start = 0;
//     bool flag = false;

//     while (string[count_s] != '\0') {
//         count_s++;
//     }

//     while (ending[count_e] != '\0') {
//         count_e++;
//     }

//     start = count_s - count_e;
    
//     if (count_e == 0) {
//         flag = true;
//     } else if (start < 0) {
//         flag = false;
//     } else {
//         flag = true;
//         for (int i = 0; start < count_s; start++, i++) {
//             if (string[start] != ending[i]) {
//                 flag = false;
//                 break;
//             }
//         }
//     }
//     return flag;
// }





