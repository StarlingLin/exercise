#define _CRT_SECURE_NO_WARNINGS 1

//题目编号：Exp09 - Enhance01
//
//题目名称：单链表倒数第K个结点
//
//题目描述：请填写缺失代码完成程序，实现如下功能：
//
//首先根据键盘随机输入，以0结束的若干非零整数建立单链表；
//
//然后根据输入的整数K，输出链表倒数第K个结点的值，相邻数字间以一个西文空格间隔，最后一个数字后无任何字符；
//
//若不存在则输出NULL。

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
    return head;    //返回单链表头
}

struct cell* back(struct cell* head, int k) //求链表倒数第k个结点，head是单链表首结点指针
{
    struct cell* p;
    int size = 0;
    if (head == NULL)
        return NULL;
    else
    {
        p = head;
        while (p != NULL)
        {
            size++;
            p = p->next;
        }
    }
    if (k > size)
        return NULL;
    size = size - k;
    p = head;
    for (; size > 0 && p != NULL; size--)
        p = p->next;
    return p;
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

int main()
{
    struct cell* head, * result;
    int k;
    head = build();
    scanf("%d", &k);
    result = back(head, k);
    if (result != NULL)
        printf("%d", result->x);
    else
        printf("NULL");
    release(head);
}