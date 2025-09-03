#include<stdio.h>
int main() {
	int m, n;
	printf("Enter the number of course and student:");
	scanf("%d %d", &m, &n);
	int score[m][n];

    int i, j;
    printf("The grade of each student.");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &score[i][j]);
		}
	}

	for (i = 0; i < m; i++) {
		int max = score[i][0];
		int min = score[i][0];
        int sum = 0;
		for (j = 0; j < n; j++) {
			sum += score[i][j];
			if (score[i][j] > max) {
				max = score[i][j];
			}
			if (score[i][j] < min) {
				min = score[i][j];
			}
		}
        int average = sum / n;
        printf("Course%d: Average:%d Max:%d Min:%d\n", i+1, average, max, min);
	}

	for (i = 0; i < m; i++) {
        int num1 = 0, num2 = 0;
		for (j = 0; j < n; j++) {
			if (score[i][j] > 80) {
				num1 ++;
			}
			if (score[i][j] < 60) {
				num2 ++;
			}
		}
        printf("Course%d: Over:%d Below:%d\n", i+1, num1, num2);
	}

	return 0;
}