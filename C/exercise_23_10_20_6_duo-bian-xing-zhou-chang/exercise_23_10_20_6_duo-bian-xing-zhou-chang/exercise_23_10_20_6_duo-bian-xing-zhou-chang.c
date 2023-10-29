#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

float dis(float a, float b, float x, float y)
{
	float disa = 0;

	disa = sqrt(pow(a - x, 2) + pow(b - y, 2));
	
	return disa;
}

int main()
{
	short n = 0;
	float arr[10][2] = { 0 };
	float ans = 0;

	scanf("%hd", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%f%f", &arr[i][1], &arr[i][2]);
		
		if (i != 1 && n != 1 && n != 2)
		{
			ans += dis(arr[i - 1][1], arr[i - 1][2], arr[i][1], arr[i][2]);
		}
	}

	if (1 == n)
		printf("0.00");
	else if (2 == n)
		printf("%.2f", dis(arr[1][1], arr[1][2], arr[2][1], arr[2][2]));
	else
	{
		ans += dis(arr[n][1], arr[n][2], arr[1][1], arr[1][2]);
		printf("%.2f", ans);
	}

	return 0;
}