#define _CRT_SECURE_NO_WARNINGS 1

//题目编号：Exp09 - Enhance03
//
//题目名称：合并单链表
//
//题目描述：请填写缺失代码完成程序，实现如下功能：
//
//首先从键盘输入一行以0结束的若干非零整数，建立一个单链表，输入的整数顺序为数字非递减顺序；
//
//然后以同样的方式，仍在第一行继续输入并建立第二个单链表；
//
//之后将两个链表合并形成一个新链表，使得新链表依然保持数字非递减顺序；
//
//最后验证输出新链表所有值，相邻数字间以一个西文空格间隔，最后一个数字后无任何字符。若是空链表，则输出NULL。

#include <stdio.h>
#include <malloc.h>

struct cell //单链表结点结构体定义
{
    int x;
    struct cell* next;
};

struct cell* build(void)    //新建单链表，并将建好的单链表首结点地址返回
{
    struct cell* head, * tmp, * tail;
    head = tmp = tail = NULL;
    int n, i;
    scanf("%d", &n);
    if (n == 0)
        return NULL;
    head = (struct cell*)malloc(sizeof(struct cell));
    head->x = n;
    head->next = NULL;
    tail = head;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            return head;
        tmp = (struct cell*)malloc(sizeof(struct cell));
        tmp->x = n;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tail->next;
    }
    return head;    //返回单链表头
}

struct cell* combine(struct cell* p, struct cell* q)    //合并两个链表p和q
{
    struct cell* head = NULL, * p0 = NULL, * q0 = NULL, * r = NULL;
    if (p == NULL && q != NULL) return q;
    if (p != NULL && q == NULL) return p;
    if (p == NULL && q == NULL) return NULL;
    struct cell* r0 = NULL;
    if (p != NULL && q != NULL)
    {
        head = p;
        while (p != NULL)   //将两链表连接
        {
            p0 = p;
            p = p->next;
        }
        p0->next = q;
        p = head;
        p0 = NULL;
        while (p != NULL)   //将链表进行插入排序
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
    }
    return head;
}

void print(struct cell* head)   //打印整个单链表,head是单链表首结点指针
{
    struct cell* p;
    int flag = 0;
    p = head;
    while (p != NULL)
    {
        if (flag)
            printf(" ");
        flag = 1;
        printf("%d", p->x);
        p = p->next;

    }
}

void release(struct cell* head) //释放单链表空间,head是单链表首结点指针
{
    struct cell* p = head, * tmp;
    while (p != NULL)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

int main()
{
    struct cell* head1, * head2, * result;
    head1 = build();
    head2 = build();
    result = combine(head1, head2);
    if (result != NULL)
        print(result);
    else
        printf("NULL");
    release(result);
    return 0;
}