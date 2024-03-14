#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Stack.h"

int main()
{
	Stack st;
	InitStack(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	StackPop(&st);
	printf("%d\n", StackTop(&st));

	return EXIT_SUCCESS;
}