#include <stdio.h>

int main()
{
    //����
    #define A 1
    #if A
        printf("A is true.\n"); //...
    #endif

    //���֧
    #define B 2
    #if B==0
        printf("B is 0.\n");    //...
    #elif B==1
        printf("B is 1.\n");    //...
    #elif B==2
        printf("B is 2.\n");    //...
    #else
        printf("B is not 0/1/2.\n");    //...
    #endif

    //�ж��Ƿ���
    #define C 1
    #ifdef C
        printf("C is defined.\n");  //...
    #endif
    #if defined C
        printf("C is defined.\n");  //...
    #endif
    #if defined(C)
        printf("C is defined.\n");  //...
    #endif
    #undef C
    #ifndef C
        printf("C is not defined.\n");  //...
    #endif
    #if !defined C
        printf("C is not defined.\n");  //...
    #endif
    #if !defined(C)
        printf("C is not defined.\n");  //...
    #endif

    //Ƕ��
    #ifdef A
        #ifdef B
            printf("A and B is defined.\n");    //...
        #endif
    #endif

    return 0;
}