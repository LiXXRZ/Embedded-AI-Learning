#include<stdio.h>

int binarysearch(int nums[], int low, int high, int target) {
	while (low <= high) {
		int middle = (low + high) / 2;
		if (target == nums[middle])
			return middle;
		else if (target > nums[middle])
			low = middle + 1;
		else if (target < nums[middle])
			high = middle - 1;
	}
	return -1;
}

void sort(int nums[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}

int main() {
	int nums[] = { -5,0,6,-2,2,-1,9 };
	int n = sizeof(nums) / sizeof(nums[0]);
	sort(nums, n);
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	int target;
	printf("Enter the number you want to find:");
	scanf("%d", &target);

	int low = 0;
	int high = sizeof(nums) / sizeof(nums[0]);
	int right = binarysearch(nums, low, high, target);

	if (right == -1) {
		printf("Element not found.");
	}
	else {
		printf("Find the element.");
	}
	return 0;
}