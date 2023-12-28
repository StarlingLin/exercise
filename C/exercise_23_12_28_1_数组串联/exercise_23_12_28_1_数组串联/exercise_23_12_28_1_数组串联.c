#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//给你一个长度为 n 的整数数组 nums 。请你构建一个长度为 2n 的答案数组 ans ，数组下标 从 0 开始计数 ，对于所有 0 <= i < n 的 i ，满足下述所有要求：
//
//    ans[i] == nums[i]
//    ans[i + n] == nums[i]
//    具体而言，ans 由两个 nums 数组 串联 形成。
//
//    返回数组 ans 。

int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    nums = (int*)realloc(nums, 2 * numsSize * sizeof(int));
    *returnSize = numsSize * 2;
    for (int i = 0; i < numsSize; i++)
    {
        nums[numsSize + i] = nums[i];
    }
    return nums;
}

int main()
{
    int ret = 0, arr[5] = { 1,2,3,4,5 };
    int* num = getConcatenation(arr, 5, &ret);
    printf("num[%d] = {", ret);
    for (int i = 0; i < ret; i++)
        printf(" %d,", num[i]);
    printf("\b }\n");
    
    return 0;
}