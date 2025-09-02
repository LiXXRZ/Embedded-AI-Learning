#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int a, b;
    int Correct = 0;
    printf("Enter the secret:");
    scanf("%d", &a);
    printf("I'm thinking of a number between 1 and 499.\n");

    while (Correct == 0) {
        printf("Enter your guess: ");
        scanf("%d", &b);

        if (b > a) {
            printf("It is high.\n");
        }
        else if (b < a) {
            printf("It is low.\n");
        }
        else {
            printf("You are right.\n");
            Correct = 1;
        }
    }
    getchars();
    return 0;
}