#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

void forward(int queue[], int i, int cnt)
{
	for (;i < cnt - 1;i++)
		queue[i] = queue[i + 1];
}

int main()
{
	_Bool flag = false;
	int queue[1000] = { 0 };
	int n = 0, s = 0, m = 0;
	scanf("%d%d%d", &n, &s, &m);
	int cnt = n;
	
	for (int i = 0; i < n; i++)
		queue[i] = i + 1;
	for (int i = m + s - 2;; i = (i + m - 1) % cnt)
	{
		if (flag)
			printf(" ");
		printf("%d", queue[i]);
		forward(queue, i, cnt);
		cnt--;
		if (cnt == 0)
			break;
		flag = true;
	}
	
	return 0;
}