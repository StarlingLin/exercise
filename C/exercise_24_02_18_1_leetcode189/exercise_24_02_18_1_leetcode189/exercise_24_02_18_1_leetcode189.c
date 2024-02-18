#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void rotate(int* nums, int numsSize, int k)
{
	int* temp = (int*)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		temp[(i + k) % numsSize] = nums[i];
	}
	for (int i = 0; i < numsSize; i++) {
		nums[i] = temp[i];
	}
	free(temp);
}

int main()
{
	int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;
	int numsSize = sizeof(nums) / sizeof(int);
	rotate(nums, numsSize, k);
	for (int i = 0; i < numsSize; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}