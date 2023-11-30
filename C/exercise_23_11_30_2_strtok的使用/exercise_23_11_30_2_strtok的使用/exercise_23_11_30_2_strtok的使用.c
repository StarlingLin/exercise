#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	char arr[] = "192.168.0.1:23333";
	char* sep = ".:";
	char* str = NULL;
	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
		printf("%s\n", str);
	return 0;
}