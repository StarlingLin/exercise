#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int gender = 0;
	int age = 0;

	scanf("%d%d", &gender, &age);

	switch (gender)
	{
	case 1:
		if (age <= 65)
			printf("NULL");
		else if (age > 70)
			printf("70");
		else
			printf("50");
		break;
	case 2:
		if (age <= 60)
			printf("NULL");
		else if (age > 65)
			printf("70");
		else
			printf("45");
	}

	return 0;
}