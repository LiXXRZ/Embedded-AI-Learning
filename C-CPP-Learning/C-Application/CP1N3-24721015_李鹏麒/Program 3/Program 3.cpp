#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int a = 1, c = 0;
	int b;
	for (b = 1; b <= 9; b++) {
		a *= b;
		if (b % 2 == 0) {
			c += a;
		}
	}
	printf("The sum is %d", c);
	return 0;
}