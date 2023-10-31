#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	int bai = n / 100;
	int shi = n % 100 / 10;
	int ge = n % 10;
	_Bool flag = false;

	if (0 < n && 1000 > n)
	{
		switch (bai)
		{
		case 0: break;
		case 1: printf("one hundred"); break;
		case 2: printf("two hundred"); break;
		case 3: printf("three hundred"); break;
		case 4: printf("four hundred"); break;
		case 5: printf("five hundred"); break;
		case 6: printf("six hundred"); break;
		case 7: printf("seven hundred"); break;
		case 8: printf("eight hundred"); break;
		case 9: printf("nine hundred"); break;
		}
		
		if (bai != 0 && (shi != 0 || ge != 0))
			printf(" and ");

		switch (shi)
		{
		case 0: break;
		case 1: flag = true; break;
		case 2: printf("twenty"); break;
		case 3: printf("thirty"); break;
		case 4: printf("forty"); break;
		case 5: printf("fifty"); break;
		case 6: printf("sixty"); break;
		case 7: printf("seventy"); break;
		case 8: printf("eighty"); break;
		case 9: printf("ninety"); break;
		}

		if (flag)
			switch (ge)
			{
			case 0: printf("ten"); break;
			case 1: printf("eleven"); break;
			case 2: printf("twelve"); break;
			case 3: printf("thirteen"); break;
			case 4: printf("fourteen"); break;
			case 5: printf("fifteen"); break;
			case 6: printf("sixteen"); break;
			case 7: printf("seventeen"); break;
			case 8: printf("eighteen"); break;
			case 9: printf("nineteen"); break;
			}
		else
		{
			if (shi != 0 && ge != 0)
				printf("-");
			
			switch (ge)
			{
			case 1: printf("one\n"); break;
			case 2: printf("two\n"); break;
			case 3: printf("three\n"); break;
			case 4: printf("four\n"); break;
			case 5: printf("five\n"); break;
			case 6: printf("six\n"); break;
			case 7: printf("seven\n"); break;
			case 8: printf("eight\n"); break;
			case 9: printf("nine\n"); break;
			}
		}
	}
	else if (0 == n)
		printf("zero\n"); 
	else if (1000 == n)
		printf("one thousand\n");
	else
		printf("ERR\n");
	
	return 0;
}