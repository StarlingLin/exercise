#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void reverse(int* nums, int start, int end)
{
	int temp;
	while (start < end)
	{
		temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++;
		end--;
	}
	return;
}

void rotate(int* nums, int numsSize, int k)
{
	k = k % numsSize;
	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - 1);
	return;
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

//void rotate(int* nums, int numsSize, int k)
//{
//	int* temp = (int*)malloc(sizeof(int) * numsSize);
//	for (int i = 0; i < numsSize; i++) {
//		temp[(i + k) % numsSize] = nums[i];
//	}
//	for (int i = 0; i < numsSize; i++) {
//		nums[i] = temp[i];
//	}
//	free(temp);
//}