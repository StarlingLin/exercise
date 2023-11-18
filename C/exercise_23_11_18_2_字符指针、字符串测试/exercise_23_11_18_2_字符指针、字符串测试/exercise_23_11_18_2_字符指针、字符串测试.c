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

int main()
{
    const char* pch = "abc";
    printf("%s", pch);
    return 0;
}