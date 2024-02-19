#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int missingNumber(int* nums, int numsSize)
{
	int sum = 0;
	for (int i = 0; i < numsSize; i++) {
		sum += nums[i];
	}
	return (numsSize + 1) * numsSize / 2 - sum;
}