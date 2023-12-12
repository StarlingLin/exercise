#define _CRT_SECURE_NO_WARNINGS 1

//��Ŀ��ţ�Exp09 - Basic02��GJBook3 - 13 - 06
//
//��Ŀ���ƣ�ɾ���������ظ����
//
//��Ŀ����������дȱʧ������ɳ���ʵ�����¹��ܣ�
//
//���ȸ��ݼ���������룬��0���������ɷ�����������������Ȼ��ɾ����������ֵ�ظ��Ľ�������һ�����Ҳ��ı�ԭ�н��˳�����ɾ���������и����ֵ������������ּ���һ�����Ŀո��������һ�����ֺ����κ��ַ������ǿ����������NULL��

#include <stdio.h>
#include <stdbool.h>
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

struct cell* del2one(struct cell* head) //ɾ���ظ����ֻ����һ����head�ǵ������׽��ָ��
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
    return head;    //����ɾ���ظ����ĵ�����ͷ
}

void print(struct cell* head)   //��ӡ����������,head�ǵ������׽��ָ�� /*��������λ�ò���������ʵ�ֺ���print�Ĺ���
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

void release(struct cell* head) //�ͷŵ�����ռ�,head�ǵ������׽��ָ�� /*��������λ�ò���������ʵ�ֺ���release�Ĺ���
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