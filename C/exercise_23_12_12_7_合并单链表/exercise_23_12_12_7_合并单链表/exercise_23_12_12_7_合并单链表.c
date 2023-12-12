#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
struct cell {//��������ṹ�嶨��
    int x;
    struct cell* next;
};
struct cell* build(void) {//�½��������������õĵ������׽���ַ����
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
    return head;//���ص�����ͷ
}
struct cell* combine(struct cell* p, struct cell* q) {//�ϲ���������p��q
    struct cell* head = NULL, * p0 = NULL, * q0 = NULL, * r = NULL;
    if (p == NULL && q != NULL) return q;
    if (p != NULL && q == NULL) return p;
    if (p == NULL && q == NULL) return NULL;
    struct cell* r0;
    if (p != NULL && q != NULL)
    {
        head = p;
        while (p != NULL)//������������
        {
            p0 = p;
            p = p->next;
        }
        p0->next = q;
        p = head;
        p0 = NULL;
        while (p != NULL)//��������в�������
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
void print(struct cell* head) {//��ӡ����������,head�ǵ������׽��ָ��
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
void release(struct cell* head) {//�ͷŵ�����ռ�,head�ǵ������׽��ָ��
    struct cell* p = head, * tmp;
    while (p != NULL)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}
int main(void) {
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