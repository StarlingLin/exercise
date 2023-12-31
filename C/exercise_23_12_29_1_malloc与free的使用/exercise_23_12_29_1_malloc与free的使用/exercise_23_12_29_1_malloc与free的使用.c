#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num = 0;
	scanf("%d", &num);
	int* ptr = NULL;
	ptr = (int*)malloc(num * sizeof(int));
	if (ptr == NULL)	//≈–∂œptr÷∏’Î «∑ÒŒ™ø’
	{
		perror("malloc");
		return 1;
	}
	for (int i = 0; i < num; i++)
		ptr[i] = i;
	for (int i = 0; i < num; i++)
		printf("%d ", ptr[i]);
	free(ptr);
	ptr = NULL;
	return 0;
}