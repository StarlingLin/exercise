#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	FILE* pf = fopen("abc.txt", "w");
	if (pf == NULL)
	{
		perror(fopen);
		return 1;
	}
	for (int i = 0; i < 26; i++)
		fputc('a' + i, pf);
	fclose(pf);
	pf = NULL;
	return 0;
}