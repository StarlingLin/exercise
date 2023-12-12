#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

//��Ŀ��ţ�Exp09-Basic01
//
//��Ŀ���ƣ�����������
//
//��Ŀ����������дȱʧ������ɳ���ʵ�����¹��ܣ�
//
//���ݴӼ������������0���������ɷ�������������һ��������֮�󽫴������б��������˳��������������ּ���һ�����Ŀո��������һ�����ֺ����κ��ַ������ǿ����������NULL��

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
    return head;//���ص�����ͷ
}

void print(struct cell* head)   //��ӡ����������,head��ָ�������׽���ָ��
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

void release(struct cell* head) //�ͷŵ�����ռ�,head��ָ�������׽���ָ��
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
    if (head != NULL)
        print(head);
    else
        printf("NULL");
    release(head);
}