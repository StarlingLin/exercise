#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[101] = { 0 }, s1[101] = { 0 }, s2[101] = { 0 };
	int f1 = 0, f2 = 0;
	gets(s);
	for (int i = 1; i < strlen(s); i++)
		(s[i] > s[0]) ? (s1[f1++] = s[i]) : (s2[f2++] = s[i]);
	qsort(s2, strlen(s2), 1, strcmp);
	printf("%s%c%s", s1, s[0], s2);
	return 0;
} 