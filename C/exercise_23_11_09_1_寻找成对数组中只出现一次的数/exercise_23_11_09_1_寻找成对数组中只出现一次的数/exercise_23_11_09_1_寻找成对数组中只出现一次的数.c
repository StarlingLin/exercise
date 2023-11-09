#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>

int main()
{
	int n = 0, tem = 0, xor = 0, arr[666] = { 0 };
	while ((tem = getchar()) != '\n')
	{
		if (isdigit(tem))
		{
			ungetc(tem, stdin);
			scanf("%d", &arr[n++]);
		}
	}
	xor = arr[0];
	for (int i = 1; i < n; i++)
		xor ^= arr[i];
	printf("%d\n", xor);
	return 0;
}