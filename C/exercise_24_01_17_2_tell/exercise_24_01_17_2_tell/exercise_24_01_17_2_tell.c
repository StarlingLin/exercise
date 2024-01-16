#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* pf = fopen("file.txt", "w");
	if (!pf)
	{
		perror("fopen");
		return EXIT_FAILURE;
	}

	fputs("1145141919810", pf);
	printf("%d\n", ftell(pf));
	fseek(pf, 0, SEEK_SET);
	printf("%d\n", ftell(pf));
	fseek(pf, 7, SEEK_CUR);
	printf("%d\n", ftell(pf));

	return EXIT_SUCCESS;
}