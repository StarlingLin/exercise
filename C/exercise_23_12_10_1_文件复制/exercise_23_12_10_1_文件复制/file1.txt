#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	FILE* pf1 = fopen("file1.txt", "r");
	if (pf1 == NULL)
	{
		perror("fopen->file1");
		return 1;
	}
	FILE* pf2 = fopen("file2.txt", "w");
	if (pf2 == NULL)
	{ 
		perror("fopen->file2");
		return 1;
	}
	int ch = 0;
	while ((ch = fgetc(pf1)) != EOF)
		fputc(ch, pf2);
	fclose(pf1);
	fclose(pf2);
	pf1 = pf2 = NULL;
	return 0;
}