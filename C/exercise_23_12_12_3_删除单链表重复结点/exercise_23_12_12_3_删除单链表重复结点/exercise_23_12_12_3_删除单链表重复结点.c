#define _CRT_SECURE_NO_WARNINGS 1

//题目编号：Exp09 - Basic02，GJBook3 - 13 - 06
//
//题目名称：删除单链表重复结点
//
//题目描述：请填写缺失代码完成程序，实现如下功能：
//
//首先根据键盘随机输入，以0结束的若干非零整数建立单链表；然后删除此链表中值重复的结点仅保留一个，且不改变原有结点顺序；最后将删除后链表中各结点值输出，相邻数字间以一个西文空格间隔，最后一个数字后无任何字符；若是空链表，则输出NULL。

#include <stdio.h>
#include <stdbool.h>
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
    return head;    //返回单链表头
}

struct cell* del2one(struct cell* head) //删除重复结点只保留一个，head是单链表首结点指针
{
    struct cell* p, * p1, * p0;
    _Bool x;
    if (head == NULL) return head;
    p = head; p1 = p->next;
    while (p->next != NULL && p != NULL)
    {
        x = false;
        p1 = p->next; p0 = p;
        while (p1 != NULL)
        {
            if (p->x == p1->x)
            {
                p0->next = p1->next;
                free(p1);
                x = true;
            }
            else p0 = p0->next;
            p1 = p0->next;
        }
        if (!x)
            p = p->next;
    }
    return head;    //返回删除重复结点的单链表头
}

void print(struct cell* head)   //打印整个单链表,head是单链表首结点指针 /*请在以下位置补充完整，实现函数print的功能
{
    struct cell* p; p = head;
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

void release(struct cell* head) //释放单链表空间,head是单链表首结点指针 /*请在以下位置补充完整，实现函数release的功能
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
    struct cell* head;
    head = build();
    head = del2one(head);
    if (head != NULL)
        print(head);
    else
        printf("NULL");
    release(head);
}