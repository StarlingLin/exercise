#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//    char ch = 'a';
//    char* pch = &ch;
//    printf("%c", *pch);
//    return 0;
//}

#include <stdio.h>

//int main()
//{
//    const char* pch = "abc";
//    printf("%s", pch);
//    return 0;
//}

#include <stdio.h>

int main()
{
    char str1[] = "abcdef";
    char str2[] = "abcdef";
    const char* str3 = "abcdef";    //const可省略
    const char* str4 = "abcdef";    //const可省略

    if (str1 == str2)
        printf("str1 and str2 are same\n");
    else
        printf("str1 and str2 are not same\n");
    if (str3 == str4)
        printf("str3 and str4 are same\n");
    else
        printf("str3 and str4 are not same\n");

    return 0;
}