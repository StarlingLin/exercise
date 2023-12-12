#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

typedef int items;	//可以不是int
typedef struct cell
{
	items data;
	struct cell* next;
} celltype;
typedef celltype* pcelltype;
pcelltype top, rear;	//top指向链头，rear指向链尾，rear可以不要

//新项加入链头只要反复调用下面函数
void push(items x)
{
	pcelltype p;
	p = (pcelltype)malloc(sizeof(celltype));
	p->data = x;
	p->next = top;
	top = p;
}

//新项加入链尾,需要rear
void InRear(items x)
{
	pcelltype p;
	p = (pcelltype)malloc(sizeof(celltype));
	p->data = x;
	p->next = NULL;
	if (rear == NULL)	//放置一开始就加，做链头处理
		rear = top = p;
	else
	{
		rear->next = p;
		rear = p;
	}
}

//遍历单项链表，对链表从头到尾所有数据加工
p = top;
while (p != NULL)
{
	//加工p->data
	p = p->next;
}

//遍历单项链表，但是保留前驱项
p0 = NULL;
p = top;
while (p != NULL)
{
	//加工p->data
	p0 = p;
	p = p->next;
}

//在单向链表中检索，找到返回节点指针，否则NULL。关键字key0，域名为key
p0 = NULL;
p = top;
while (p != NULL && p->key != key0)
{
	p0 = p;
	p = p->next;
}

//插入一项，把r插入到p0与p所指向的两项之间
r->next = p;
p0->next = r;
p0 = r;	//p0仍为p的前驱项

//删除一项，把p的所指项删掉
p = p->next;
free(p0->next);
p0->next = p;

//交换两项(p0是p的前驱、q0是q的前驱)
/*交换p->next、q->next*/
g = p->next;
p->next = q->next;
q->next = g;
/*交换p0->next、q0->next*/
p0->next = q;
q0->next = p;
/*交换p、q*/
p = p0->next;
q = q0->next;

