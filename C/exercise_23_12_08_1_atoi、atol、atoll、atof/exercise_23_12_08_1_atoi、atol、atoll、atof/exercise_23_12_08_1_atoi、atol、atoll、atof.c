#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	char s[] = "  -1145141919810fiufw";
//	char t[] = "  -114514.191981e5hhiul";
//
//	double f = atof(t);
//	int n = atoi(s);
//	long m = atol(s);
//	long long p = atoll(s);
//	printf("%lf\n", f);
//	printf("%d\n", n);
//	printf("%ld\n", m);
//	printf("%lld\n", p);
//	return 0;
//}

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    printf("%g\n", atof("  -0.0000000123junk"));
    printf("%g\n", atof("0.012"));
    printf("%g\n", atof("15e16"));
    printf("%g\n", atof("-0x1afp-2"));
    printf("%g\n", atof("inF"));
    printf("%g\n", atof("Nan"));
    printf("%g\n", atof("1.0e+309"));   // 超出 double 范围
    printf("%g\n", atof("0.0"));
    printf("%g\n", atof("junk"));       // 无可进行的转换
}