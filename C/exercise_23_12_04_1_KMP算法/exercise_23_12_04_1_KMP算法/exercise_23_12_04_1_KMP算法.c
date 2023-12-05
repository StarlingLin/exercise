#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void GetNext(const char*, int*);

char* BF(const char* str1, const char* str2)
{
	assert(str1 && str2);
	char* sign1 = (char*)str1;
	char* sign2 = (char*)str1;
	char* sign = (char*)str2;
	while (*sign1)
	{
		if (!*sign)
			return sign1;
		sign1++;
		sign2 = sign1;
		sign = (char*)str2;
		while (*sign2 && *sign && !(*sign2 - *sign))
			sign2++, sign++;
	}
	return NULL;
}

char* KMP(const char* s, const char* p)
{
	assert(s && p);
	int i = 0, j = 0;
	int sLen = (int)strlen(s);
	int pLen = (int)strlen(p);
	int* next = (int*)malloc(sizeof p);
	GetNext(p, next);
	while (i < sLen && j < pLen)
	{
		if (j == -1 || s[i] == p[j])
			++i, ++j;
		else
			j = next[j];
	}
	return (j == pLen) ? (char*)&s[i - j] : NULL;
}

int main()
{
	char str1[] = "ababcabcdabcde";
	char str2[] = "abcd";
	//char* s = BF(str1, str2);
	char* s = KMP(str1, str2);
	strncpy(s, "@@@@", 4);
	printf("%s", str1);
	return 0;
}

void GetNext(const char* p, int next[])
{
	int pLen = (int)strlen(p);
	next[0] = -1;
	int k = -1, j = 0;
	while (j < pLen - 1)
	{
		if (k == -1 || p[j] == p[k])
		{
			++j, ++k;
			next[j] = (p[j] != p[k]) ? k : next[k];
		}
		else
			k = next[k];
	}
}
