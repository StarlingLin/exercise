#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

_Bool pd(char kh2, char khsz[100], int n)
{
	int j = 0;
	for (j = n; 0 == khsz[j]; j--);
	if (khsz[j] == '(' && kh2 == ')' || khsz[j] == '[' && kh2 == ']' || khsz[j] == '{' && kh2 == '}')
		return true;
	else
		return false;
}

int main()
{
	char arr[100] = { 0 };
	char kuohao[100] = { 0 };
	int kh = 0;
	int i = 0;
	int k = 0;

	do
	{
		scanf("%c", &arr[i]);
		switch (arr[i])
		{
		case '{':
		case '[':
		case '(': kuohao[kh] = arr[i]; kh++; break;
		case '}':
		case ']':
		case ')': 
			if (pd(arr[i], kuohao, kh))
			{
				for (k = i; 0 == kuohao[k]; k--);
				kuohao[k] = 0;
			}
			else
				goto no;
		default:
			break;
		}
		i++;
	}while (arr[i - 1] != '@');

	if (0 == kuohao[0])
		printf("YES\n");
	else
	{
	no:
		printf("NO\n");
	}
	return 0;
}