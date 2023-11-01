#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void count(char* str, int* upper, int* lower, int* space, int* num, int* other)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] >= 'A' && str[i] <= 'Z')
			*upper += 1;
		else if (str[i] >= 'a' && str[i] <= 'z')
			*lower += 1;
		else if (str[i] == ' ')
			*space += 1;
		else if (str[i] >= '0' && str[i] <= '9')
			*num += 1;
		else
			*other += 1;
}

int main()
{
	char str[1000] = { 0 };
	int upper = 0, lower = 0, space = 0, num = 0, other = 0;
	scanf("%[^\n]", str);
	count(str, &upper, &lower, &space, &num, &other);
	printf("%d %d %d %d %d", upper, lower, space, num, other);
	return 0;
}