#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

char* str_delete(char* s, int v, int w)
{
	for (int i = 0; i < w; i++)
		for (int j = v; j < 256; j++)
			s[j - 1] = s[j];
	return s;
}

int main()
{
	int v = 0, w = 0;
	scanf("%d%d", &v, &w);
	getchar();
	char s[256] = { 0 };
	scanf("%[^\n]", s);
	str_delete(s, v, w);
	printf("%s", s);
	return 0;
}