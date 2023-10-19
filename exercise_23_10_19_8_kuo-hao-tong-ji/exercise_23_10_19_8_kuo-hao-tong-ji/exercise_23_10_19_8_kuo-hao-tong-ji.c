#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	char x = 0;
	int lx = 0;
	int rx = 0;
	int lz = 0;
	int rz = 0;
	int ld = 0;
	int rd = 0;

	while (x != '@')
	{
		scanf("%c", &x);
		
		switch (x)
		{
			case '(':
				lx++;
				break;
			case ')':
				rx++;
				break;
			case '[':
				lz++;
				break;
			case ']':
				rz++;
				break;
			case '{':
				ld++;
				break;
			case '}':
				rd++;
				break;
		}
	}

	if (ld != rd)
		printf("{}");
	if (lz != rz)
		printf("[]");
	if (lx != rx)
		printf("()");

	return 0;
}

