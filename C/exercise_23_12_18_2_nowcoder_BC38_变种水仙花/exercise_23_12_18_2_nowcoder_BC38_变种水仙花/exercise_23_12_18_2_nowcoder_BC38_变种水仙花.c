#define _CRT_SECURE_NO_WARNINGS 1

// 变种水仙花数 - Lily Number：把任意的数字，从中间拆分成两个数字，
// 比如1461 可以拆分成（1和461）, （14和61）, （146和1), 如果所有
// 拆分后的乘积之和等于自身，则是一个Lily Number。
//
// 例如：
//
// 655 = 6 * 55 + 65 * 5
//
// 1461 = 1 * 461 + 14 * 61 + 146 * 1

#include <stdio.h>
#include <math.h>

int lily(int n, int len)
{
	if (len > 0 && n > 9)
		return (n / (int)pow(10, len - 1)) * (n % (int)pow(10, len - 1)) + lily(n, len - 1);
	else if (len > 0 && n < 10)
		return n;
	else
		return 0;
}

int main()
{
	for (int i = 1; i < 100000; i++)
		if (i == lily(i, (int)log(i) + 1))
			printf("%d ", i);
	return 0;
}