#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int max = 0;

    while (1) {
        max += 1;
        if (max < 0) {
            printf("The maximum value of int is:%d\n", max - 1);
            break;
        }
    }
    
    printf("Exceed the maximum value: %d\n", max);
    
    int min = 0;

    while (1) {
        min -= 1;
        if (min > 0) {
            printf("The minimum value of int is:%d\n", min + 1);
            break;
        }
    }
    
    printf("Below the minimum value: %d\n", min);

    return 0;
}