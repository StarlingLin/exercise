#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

int main()
{
	int n = 0;
	int arr[100] = { 0 };
	_Bool flag = false;

	scanf("%d", &n);

	for (int i = 0; i < n * n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n * n; i++)
		for (int j = i + 1; j < n * n; j++)
			if (arr[i] == arr[j])
			{
				flag = true;
				goto end;
			}
			
end:
	if (flag)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}