#define _CRT_SECURE_NO_WARNINGS 1
//双指针法二维查找
#include <stdio.h>
#include <stdbool.h>

_Bool Find(int key, int arr[6][9], int m, int n)
{
	int px = n - 1, py = 0;
	while (px >= 0 && py < m)
	{
		if (key > arr[py][px])
			py++;
		else if (key < arr[py][px])
			px--;
		else
			return true;
	}
	return false;
}

int main()
{
	int key = 0, m = 6, n = 9;
	scanf("%d", &key);
	int arr[6][9] = {
	{1  ,2  ,3  ,4  ,5  ,6  ,7  ,9  ,11 },
	{2  ,4  ,5  ,6  ,7  ,8  ,9  ,10 ,12 },
	{4  ,6  ,9  ,11 ,12 ,13 ,14 ,15 ,19 },
	{7  ,8  ,9  ,12 ,15 ,16 ,17 ,19 ,22 },
	{9  ,10 ,11 ,18 ,22 ,24 ,44 ,99 ,144},
	{17 ,22 ,55 ,77 ,69 ,101,111,114,999},
	};
	if (Find(key, arr, m, n))
		printf("Find it!");
	else
		printf("Oops~");
	return 0;
}