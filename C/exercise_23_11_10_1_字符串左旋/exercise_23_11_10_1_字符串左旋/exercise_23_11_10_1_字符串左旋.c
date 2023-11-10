#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

void forward(char ch[], int n, int k)
{
	for (int i = 0; i < k; i++)
	{
		int r = ch[0];
		for (int j = 0; j < n - 1; j++)
			ch[j] = ch[j + 1];
		ch[n - 1] = r;
	}
}

int main()
{
	char ch[999] = { 0 };
	gets(ch);
	int n = strlen(ch), k = 0;
	scanf("%d", &k);
	forward(ch, n, k);
	printf("%s", ch);
	return 0;
}