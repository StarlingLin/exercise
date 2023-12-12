#define _CRT_SECURE_NO_WARNINGS 1

//��Ŀ��� ��Exp09 - Basic05��GJBook3�� - 13 - 04
//
//��Ŀ���ƣ�������洢��������
//
//��Ŀ����������дȱʧ������ɳ���ʵ�����¹��ܣ�
//
//����һ��������n���õ���������洢n�׷������и���ֵ��n�׷��������ǰ����в���Լ�ֵķ���j / i(0 < i��n; 0��j��i)������������С�
//
//	����һ��������n�����n�׷������и��������ʽ�������ķ��Ӻͷ�ĸ���� / ���ӣ�������������һ�����Ŀո��������һ�����ֺ����κ��ַ������ǿ������n������Ҫ�������NULL��

#include <stdio.h>
#include <malloc.h>

struct farlei_item
{
    int   numerator, denominator;   // ���ӡ���ĸ
    struct  farlei_item* next;  // ���Ӳ���
};
typedef  struct  farlei_item* farleipointer;

int  gcd(int x, int y)  /*  �����Լ�� */
{
    if (y == 0)
        return x;
    int r;
    r = x % y;
    return gcd(y, r);
}

/*���취������,����������ͷָ��*/
farleipointer farlei(int n)
{
    int i, j;
    farleipointer fn, r, r0, p;
    fn = r = r0 = p = NULL;
    if (n < 1)return NULL;  //���n<=0,��û�з�������
    fn = (farleipointer)malloc(sizeof(struct farlei_item));  //����0/1
    fn->numerator = 0;
    fn->denominator = 1;
    p = (farleipointer)malloc(sizeof(struct farlei_item));   //����1/1
    p->numerator = 1;
    p->denominator = 1;
    fn->next = p;
    p->next = NULL;
    for (i = 2; i <= n; i++)
        for (j = 1; j < i; j++)
            if (gcd(i, j) == 1) //�ҵ��·�����λ��
            {
                r = fn;
                while ((1.0 * j) / i > (1.0 * r->numerator) / r->denominator)
                {
                    r0 = r;
                    r = r->next;
                }
                p = (farleipointer)malloc(sizeof(struct farlei_item));  //�����µķ���
                p->numerator = j;
                p->denominator = i;
                r0->next = p;
                p->next = r;
            }
    return fn;
}

void print(farleipointer fn)    //���fn�����ķ�������
{
    struct farlei_item* p;
    p = fn;
    int flag = 0;
    while (p != NULL)
    {
        if (flag)
            printf(" ");
        flag = 1;
        printf("%d/%d", p->numerator, p->denominator);
        p = p->next;
    }
}

void release(farleipointer head)    //�ͷŵ�����ռ�,head�ǵ������׽��ָ��
{
    struct farlei_item* p, * tmp;
    p = head;
    while (p != NULL)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

int main()
{
    int n;
    farleipointer fn;
    scanf("%d", &n);
    fn = farlei(n); //����n����������
    if (fn != NULL)
        print(fn);
    else
        printf("NULL");
    release(fn);
    return 0;
}