#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char ch;
	int correct = 0;
	while (correct == 0) {
		printf("Enter a lowercase English letter:");
		scanf_s("%c", &ch);
		getchar();
		if (ch >= 'a' && ch <= 'z') {
			correct = 1;
		}
		else {
			printf("Please enter the correct letter.\n");
		}
	}
	printf("The number is %d", ch - 'a' + 1);
	return 0;
}