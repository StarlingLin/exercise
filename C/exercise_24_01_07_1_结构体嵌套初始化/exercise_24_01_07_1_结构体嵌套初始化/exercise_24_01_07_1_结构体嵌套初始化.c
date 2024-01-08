#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//
//struct example
//{
//    struct addr_t
//    {
//        int port;
//    } addr;
//    union
//    {
//        char a8[4];
//        short a16[2];
//    } in_u;
//};
//
///**************************************************************************** 
//struct example ex = { // struct example 的初始化器列表开始
//                         { // ex.addr 的初始化器列表开始
//                            80 // 初始化 struct addr_t 的唯一成员
//                         }, // ex.addr 的初始化器列表结束
//                         { // ex.in_u 的初始化器列表开始
//                            {127,0,0,1} // 初始化 union in_u 的首个成员
//                         } // ex.in_u 的初始化器列表结束
//                    };
//****************************************************************************/
//
//struct example ex = { 80, 127, 0, 0, 1 };
//// 80 初始化 ex.addr.port
//// 127 初始化 ex.in_u.a8[0]
//// 0 初始化 ex.in_u.a8[1]
//// 0 初始化 ex.in_u.a8[2]
//// 1 初始化 ex.in_u.a8[3]
//
//struct example ex2 = { .in_u.a8[0] = 127, 0, 0, 1, .addr = 80 };
//
//struct example ex3 = {
//                        80,
//                        .in_u = { // 更改当前对象为联合体 ex.in_u
//                                    127,
//                                    .a8[2] = 1 // 此指派符指代 union in_u 的成员
//                                }
//                     };
//
//int main()
//{
//
//    struct { int n; } s = { 
//                            printf("a\n"),  // 可能打印或跳过它
//                            .n = printf("b\n")  // 始终打印
//                          }; 
//
//    printf("%hd", ex.in_u.a16[1]);
//
//	return 0;
//}

#include <stdio.h>

typedef struct { int k; int l; int a[2]; } T;
typedef struct { int i;  T t; } S;
T x = { .l = 43, .k = 42, .a[1] = 19, .a[0] = 18 };
// 初始化 x 为 {42, 43, {18, 19} }

int main(void)
{
    S l = { 1,          // 初始化 l.i 为 1
           .t = x,      // 初始化 l.t 为 {42, 43, {18, 19} }
           .t.l = 41,   // 更改 l.t 为 {42, 41, {18, 19} }
           .t.a[1] = 17 // 更改 l.t 为 {42, 41, {18, 17} }
          };
    printf("l.t.k is %d\n", l.t.k); // .t = x 显式设置 l.t.k 为 42
    // .t.l = 41 会隐式清零 l.t.k
}