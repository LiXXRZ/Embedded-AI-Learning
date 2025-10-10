#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	while (1) {
		char ch;
		printf("Please enter a character:");
		ch = getchar();
		if (ch >= 'a' && ch <= 'z') {
			printf("You enter a lowercase letter.\n");
		}
		else if (ch >= 'A' && ch <= 'Z') {
			printf("You enter a uppercase letter.\n");
		}
		else if (ch >= '0' && ch <= '9') {
			printf("You enter a digit.\n");
		}
		else {
			printf("You enter a special chcracter.\n");
		}
		getchar();
	}
	return 0;
}