#define _CRT_SECURE_NO_WARNINGS 1

//题目编号 ：Exp09 - Basic03
//
//题目名称：求单链表中间结点
//
//题目描述：请填写缺失代码完成程序，实现如下功能：
//
//首先根据键盘随机输入，以0结束的若干非零整数建立单链表；
//
//然后寻找处于链表中间位置的结点，若中间结点有两个，则设定前一个为中间位置结点；
//
//最后将从中间结点开始到链表尾各结点值输出，相邻数字间以一个西文空格间隔，最后一个数字后无任何字符。
//
//若是空链表，则输出NULL。

#include <stdio.h>
#include <malloc.h>

struct cell //单链表结点结构体定义
{
    int x;
    struct cell* next;
};

struct cell* build(void)    //新建单链表，并将建好的单链表首结点地址返回
{
    struct cell* head, * tmp, * p;
    head = tmp = p = NULL;
    int n;
    scanf("%d", &n);
    if (n == 0)
        return head;
    p = (struct cell*)malloc(sizeof(struct cell));
    p->x = n;
    head = p;
    head->next = NULL;
    scanf("%d", &n);
    while (n != 0)
    {
        tmp = (struct cell*)malloc(sizeof(struct cell));
        tmp->x = n;
        tmp->next = NULL;
        p->next = tmp;
        p = p->next;
        scanf("%d", &n);
    }
    return head;//返回单链表头
}

struct cell* mid(struct cell* head) //寻找链表中间位置结点地址并返回，head是单链表首结点指针
{
    struct cell* p;
    int m = 0;
    p = head;
    while (p != NULL)
    {
        p = p->next;
        m++;
    }
    if (m == 1 || m == 0)
        return head;
    if (m % 2 == 0)
        m = m / 2 - 1;
    else
        m = m / 2;
    p = head;
    for (; m != 0; m--)
        p = p->next;
    return p;
}

void print(struct cell* head)   //打印整个单链表,head是单链表首结点指针
{
    struct cell* p;
    p = head;
    if (p == NULL)
    {
        printf("NULL"); 
        return;
    }
    else
    {
        while (p->next != NULL)
        {
            printf("%d ", p->x);
            p = p->next;
        }
        printf("%d", p->x);
    }
}

void release(struct cell* head) //释放单链表空间,head是单链表首结点指针
{
    struct cell* p0, * p1;
    p1 = head;
    while (p1 != NULL)
    {
        p0 = p1;
        p1 = p1->next;
        free(p0);
    }
}

int main(void)
{
    struct cell* head, * half;
    head = build();
    half = mid(head);
    if (half != NULL)
        print(half);
    else
        printf("NULL");
    release(head);
}