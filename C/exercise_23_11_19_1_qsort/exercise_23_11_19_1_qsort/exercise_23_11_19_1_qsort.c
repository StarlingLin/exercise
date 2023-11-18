#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Stu
{
	char Name[20];
	short ID;
};

int Comp_int(void* a, void* b)
{
	return *(int*)a - *(int*)b;
}

int Comp_flt(void* a, void* b)
{
	int c = 0;
	if ((c = *(float*)a - *(float*)b) == 0)
		return 0;
	return c > 0 ? 1 : -1;
}

int Comp_struct_by_ID(void* a, void* b)
{
	return ((struct Stu*)a)->ID - ((struct Stu*)b)->ID;
}

int main()
{
	int arr_int[] = { 2,5,78,3,31,6,7865,34,1,7,8,132,4,7,5 };
	size_t len_int = sizeof arr_int / sizeof arr_int[0];
	qsort(arr_int, len_int, sizeof arr_int[0], Comp_int);

	for (int i = 0; i < len_int; i++)
		printf("%d ", arr_int[i]);
	printf("\n");

	float arr_flt[] = { 12.5,3.5,6.2,9,1.1,98.2,0.4,-9.3,14.7 };
	size_t len_flt = sizeof arr_flt / sizeof arr_flt[0];
	qsort(arr_flt, len_flt, sizeof arr_flt[0], Comp_flt);
	for (int i = 0; i < len_flt; i++)
		printf("%.2f ", arr_flt[i]);
	printf("\n");

	struct Stu arr_struct[] = { {"zhangsan",2},{"lisi",1},{"wangwu",3} };
	size_t len_struct = sizeof arr_struct / sizeof arr_struct[0];
	qsort(arr_struct, len_struct, sizeof arr_struct[0], Comp_struct_by_ID);
	for (int i = 0; i < len_struct; i++)
		printf("%s %hd ", arr_struct[i].Name, arr_struct[i].ID);
	printf("\n");
	qsort(arr_struct, len_struct, sizeof arr_struct[0], strcmp);
	for (int i = 0; i < len_struct; i++)
		printf("%s %hd ", arr_struct[i].Name, arr_struct[i].ID);
	printf("\n");


	return 0;
}