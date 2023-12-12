#define _CRT_SECURE_NO_WARNINGS 1

//��Ŀ��ţ�Exp09 - Enhance01
//
//��Ŀ���ƣ�����������K�����
//
//��Ŀ����������дȱʧ������ɳ���ʵ�����¹��ܣ�
//
//���ȸ��ݼ���������룬��0���������ɷ�����������������
//
//Ȼ��������������K�������������K������ֵ���������ּ���һ�����Ŀո��������һ�����ֺ����κ��ַ���
//
//�������������NULL��

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

struct cell* back(struct cell* head, int k) //����������k����㣬head�ǵ������׽��ָ��
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