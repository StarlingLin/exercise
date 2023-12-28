#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//����һ������Ϊ n ���������� nums �����㹹��һ������Ϊ 2n �Ĵ����� ans �������±� �� 0 ��ʼ���� ���������� 0 <= i < n �� i ��������������Ҫ��
//
//    ans[i] == nums[i]
//    ans[i + n] == nums[i]
//    ������ԣ�ans ������ nums ���� ���� �γɡ�
//
//    �������� ans ��

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