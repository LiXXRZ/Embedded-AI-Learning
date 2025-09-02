#include<stdio.h>

int main()
{
	printf("the first programming experience by class 1\n");

	float  num1, num2, num3, num4;

	printf("Enter Experiment scorce(<=50):");
	scanf_s("%f", &num1);

	printf("Enter Experiment socument scorce(<=10):");
	scanf_s("%f", &num2);

	printf("Enter Test scorce(<=40):");
	scanf_s("%f", &num3);

	printf("Enter Bonus scorce(<=5):");
	scanf_s("%f", &num4);

	int sum = num1 + num2 + num3 + num4;

	if (sum <= 100) {
		printf("Score=%d\nExperiment scorce=%f\nExperiment socument scorce=%f\nTest scorce=%f\nBonus scorce=%f", sum, num1, num2, num3, num4);
	}
	else {
		printf("Score=100\nExperiment scorce=%f\nExperiment socument scorce=%f\nTest scorce=%f\nBonus scorce=%f", num1, num2, num3, num4);
	}
	system("pause");//单走一个exe闪一下就关了只好这样了（悲
	return 0;
}