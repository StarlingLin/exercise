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
struct example ex = { // struct example 的初始化器列表开始
                         { // ex.addr 的初始化器列表开始
                            80 // 初始化 struct addr_t 的唯一成员
                         }, // ex.addr 的初始化器列表结束
                         { // ex.in_u 的初始化器列表开始
                            {127,0,0,1} // 初始化 union in_u 的首个成员
                         } // ex.in_u 的初始化器列表结束
                    };
****************************************************************************/

struct example ex = { 80, 127, 0, 0, 1 };
// 80 初始化 ex.addr.port
// 127 初始化 ex.in_u.a8[0]
// 0 初始化 ex.in_u.a8[1]
// 0 初始化 ex.in_u.a8[2]
// 1 初始化 ex.in_u.a8[3]

struct example ex2 = { .in_u.a8[0] = 127, 0, 0, 1, .addr = 80 };

struct example ex3 = {
                        80,
                        .in_u = { // 更改当前对象为联合体 ex.in_u
                                    127,
                                    .a8[2] = 1 // 此指派符指代 union in_u 的成员
                                }
                     };

int main()
{

    struct { int n; } s = { 
                            printf("a\n"),  // 可能打印或跳过它
                            .n = printf("b\n")  // 始终打印
                          }; 

    printf("%hd", ex.in_u.a16[1]);

	return 0;
}