#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    double Fahrenheit, Celsius;
    printf("Enter the Fahrenheit temperature: ");
    scanf("%lf", &Fahrenheit);
    Celsius = 5.0 / 9.0 * (Fahrenheit - 32);
    printf("The corresponding Celsius temperature is: %.2f\n", Celsius);
    return 0;
}