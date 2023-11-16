#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n = 6;
	int* pn = &n;
	char* pn_ch = (char*)&n;

	printf("&n        = %p\n", &n);
	printf("pn        = %p\n", pn);
	printf("pn + 1    = %p\n", pn + 1);
	printf("pn_ch     = %p\n", pn_ch);
	printf("pn_ch + 1 = %p\n", pn_ch + 1);

	return 0;
}

//#include <stdio.h>
//int main()
//{
//    int a = 114514;
//    char* pa_ch = (char*)&a;
//    *pa_ch = 1;
//    printf("%d", a);
//}