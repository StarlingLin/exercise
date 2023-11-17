#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

typedef int (*f_calc)(int, int);

void menu()
{
	printf("*******************\n");
	printf("***1.ADD***4.DIV***\n");
	printf("***2.SUB***5.MOD***\n");
	printf("***3.MUL***0.exit**\n");
	printf("*******************\n");
}

int ADD(int a, int b)
{
	return a + b;
}

int SUB(int a, int b)
{
	return a - b;
}

int MUL(int a, int b)
{
	return a * b;
}

int DIV(int a, int b)
{
	return a / b;
}

int MOD(int a, int b)
{
	return a % b;
}


int main()
{
	int m = 0, n = 0, mode = 0;
	f_calc calc[6] = {NULL, ADD, SUB, MUL, DIV, MOD};
	menu();
	printf("Type in calc mode:");
	scanf("%d", &mode);
	printf("Type in the two calc number:");
	scanf("%d%d", &m, &n);
	printf("The answer is: %d\n", calc[mode](m, n));
	return 0;
}