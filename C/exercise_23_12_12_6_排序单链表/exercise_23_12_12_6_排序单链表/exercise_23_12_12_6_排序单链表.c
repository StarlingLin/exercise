#define _CRT_SECURE_NO_WARNINGS 1

//��Ŀ��ţ�Exp09 - Enhance04��GJBook3�� - 13 - 02
//
//��Ŀ���ƣ���������
//
//��Ŀ����������дȱʧ������ɳ���ʵ�����¹��ܣ�
//
//���ȸ��ݼ����������һ����0���������ɷ�����������������
//
//Ȼ�������������
//
//�����֤������������������ֵ���������ּ���һ�����Ŀո��������һ�����ֺ����κ��ַ���
//
//���ǿ����������NULL��

#include <stdio.h>
#include <malloc.h>

struct cell //��������ṹ�嶨��
{
    int x;
    struct cell* next;
};

struct cell* build(void)    //�½��������������õĵ������׽���ַ����
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
    return head;    //���ص�����ͷ
}

struct cell* sort(struct cell* head)    //������������head�ǵ������׽��ָ��
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

void print(struct cell* head)   //��ӡ����������,head�ǵ������׽��ָ��
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

void release(struct cell* head) //�ͷŵ�����ռ�,head�ǵ������׽��ָ��
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