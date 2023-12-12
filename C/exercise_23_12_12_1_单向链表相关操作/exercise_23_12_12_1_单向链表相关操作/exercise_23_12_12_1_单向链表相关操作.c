#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

typedef int items;	//���Բ���int
typedef struct cell
{
	items data;
	struct cell* next;
} celltype;
typedef celltype* pcelltype;
pcelltype top, rear;	//topָ����ͷ��rearָ����β��rear���Բ�Ҫ

//���������ͷֻҪ�����������溯��
void push(items x)
{
	pcelltype p;
	p = (pcelltype)malloc(sizeof(celltype));
	p->data = x;
	p->next = top;
	top = p;
}

//���������β,��Ҫrear
void InRear(items x)
{
	pcelltype p;
	p = (pcelltype)malloc(sizeof(celltype));
	p->data = x;
	p->next = NULL;
	if (rear == NULL)	//����һ��ʼ�ͼӣ�����ͷ����
		rear = top = p;
	else
	{
		rear->next = p;
		rear = p;
	}
}

//�������������������ͷ��β�������ݼӹ�
p = top;
while (p != NULL)
{
	//�ӹ�p->data
	p = p->next;
}

//���������������Ǳ���ǰ����
p0 = NULL;
p = top;
while (p != NULL)
{
	//�ӹ�p->data
	p0 = p;
	p = p->next;
}

//�ڵ��������м������ҵ����ؽڵ�ָ�룬����NULL���ؼ���key0������Ϊkey
p0 = NULL;
p = top;
while (p != NULL && p->key != key0)
{
	p0 = p;
	p = p->next;
}

//����һ���r���뵽p0��p��ָ�������֮��
r->next = p;
p0->next = r;
p0 = r;	//p0��Ϊp��ǰ����

//ɾ��һ���p����ָ��ɾ��
p = p->next;
free(p0->next);
p0->next = p;

//��������(p0��p��ǰ����q0��q��ǰ��)
/*����p->next��q->next*/
g = p->next;
p->next = q->next;
q->next = g;
/*����p0->next��q0->next*/
p0->next = q;
q0->next = p;
/*����p��q*/
p = p0->next;
q = q0->next;

