#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct example
{
    struct addr_t
    {
        int port;
    } addr;
    union
    {
        char a8[4];
        short a16[2];
    } in_u;
};

/**************************************************************************** 
struct example ex = { // struct example �ĳ�ʼ�����б�ʼ
                         { // ex.addr �ĳ�ʼ�����б�ʼ
                            80 // ��ʼ�� struct addr_t ��Ψһ��Ա
                         }, // ex.addr �ĳ�ʼ�����б����
                         { // ex.in_u �ĳ�ʼ�����б�ʼ
                            {127,0,0,1} // ��ʼ�� union in_u ���׸���Ա
                         } // ex.in_u �ĳ�ʼ�����б����
                    };
****************************************************************************/

struct example ex = { 80, 127, 0, 0, 1 };
// 80 ��ʼ�� ex.addr.port
// 127 ��ʼ�� ex.in_u.a8[0]
// 0 ��ʼ�� ex.in_u.a8[1]
// 0 ��ʼ�� ex.in_u.a8[2]
// 1 ��ʼ�� ex.in_u.a8[3]

struct example ex2 = { .in_u.a8[0] = 127, 0, 0, 1, .addr = 80 };

struct example ex3 = {
                        80,
                        .in_u = { // ���ĵ�ǰ����Ϊ������ ex.in_u
                                    127,
                                    .a8[2] = 1 // ��ָ�ɷ�ָ�� union in_u �ĳ�Ա
                                }
                     };

int main()
{

    struct { int n; } s = { 
                            printf("a\n"),  // ���ܴ�ӡ��������
                            .n = printf("b\n")  // ʼ�մ�ӡ
                          }; 

    printf("%hd", ex.in_u.a16[1]);

	return 0;
}