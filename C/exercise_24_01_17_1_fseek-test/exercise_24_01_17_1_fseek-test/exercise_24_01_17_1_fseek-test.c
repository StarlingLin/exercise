#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* pf = fopen("file.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return EXIT_FAILURE;
	}

	fputs("This is an apple.", pf);
	fseek(pf, 9, SEEK_SET);
	fputs(" sam", pf);

	fclose(pf);
	pf = NULL;
	return EXIT_SUCCESS;
}