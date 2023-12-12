#define _CRT_SECURE_NO_WARNINGS 1

//题目编号：Exp09 - Enhance04，GJBook3例 - 13 - 02
//
//题目名称：排序单链表
//
//题目描述：请填写缺失代码完成程序，实现如下功能：
//
//首先根据键盘随机输入一行以0结束的若干非零整数建立单链表；
//
//然后递增排序链表；
//
//最后验证输出排序后链表中所有值，相邻数字间以一个西文空格间隔，最后一个数字后无任何字符。
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
    return head;    //返回单链表头
}

struct cell* sort(struct cell* head)    //递增排序链表，head是单链表首结点指针
{
    struct cell* p, * p0, * r, * r0, * q;
    p = p0 = r = r0 = q = NULL;
    p = head;
    while (p != NULL)
    {
        r = head;
        while ((r->x < p->x) && (r != p))
        {
            r0 = r;
            r = r->next;
        }
        if (r != p)
        {
            q = p;
            p0->next = p->next;
            p = p0;
            if (r == head)
            {
                q->next = head;
                head = q;
            }
            else
            {
                q->next = r;
                r0->next = q;
            }
        }
        p0 = p;
        p = p->next;
    }
    return head;
}   /*  sort */

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

int main()
{
    struct cell* head;
    head = build();
    if (head != NULL) {
        head = sort(head);
        print(head);
    }
    else
        printf("NULL");
    release(head);
    return 0;
}