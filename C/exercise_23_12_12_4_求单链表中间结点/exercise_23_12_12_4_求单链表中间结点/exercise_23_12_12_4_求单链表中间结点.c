#define _CRT_SECURE_NO_WARNINGS 1

//��Ŀ��� ��Exp09 - Basic03
//
//��Ŀ���ƣ��������м���
//
//��Ŀ����������дȱʧ������ɳ���ʵ�����¹��ܣ�
//
//���ȸ��ݼ���������룬��0���������ɷ�����������������
//
//Ȼ��Ѱ�Ҵ��������м�λ�õĽ�㣬���м��������������趨ǰһ��Ϊ�м�λ�ý�㣻
//
//��󽫴��м��㿪ʼ������β�����ֵ������������ּ���һ�����Ŀո��������һ�����ֺ����κ��ַ���
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
    return head;//���ص�����ͷ
}

struct cell* mid(struct cell* head) //Ѱ�������м�λ�ý���ַ�����أ�head�ǵ������׽��ָ��
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