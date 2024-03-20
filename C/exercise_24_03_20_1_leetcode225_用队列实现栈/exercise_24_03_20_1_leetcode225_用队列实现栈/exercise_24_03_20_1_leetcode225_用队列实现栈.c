#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//������������
#define QueueData int

//����
typedef struct QueueNode
{
	QueueData _data;
	struct QueueNode* _next;
} QueueNode;
//�������ͷβ��Ϣ��ָ��
typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
	int _size;
} Queue;

//���еĳ�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
	pq->_size = 0;
}
//���
void QueuePush(Queue* pq, QueueData x)
{
	assert(pq);
	QueueNode* new = (QueueNode*)malloc(sizeof(QueueNode));
	if (new == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	new->_data = x;
	new->_next = NULL;

	if (pq->_rear)
	{
		pq->_rear->_next = new;
		pq->_rear = new;
	}
	else
	{
		pq->_front = pq->_rear = new;
	}

	pq->_size++;
}
//����
void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->_front == NULL)
	{
		return;
	}
	if (pq->_front->_next == NULL)
	{
		free(pq->_front);
		pq->_front = pq->_rear = NULL;
	}
	else
	{
		QueueNode* head = pq->_front->_next;
		free(pq->_front);
		pq->_front = head;
	}
	pq->_size--;
}
//����ͷ
QueueData QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_front);
	return pq->_front->_data;
}
//����β
QueueData QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_rear);
	return pq->_rear->_data;
}
//���г�
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->_size;
}
//�����п�
_Bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_size == 0;
}
//��������
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur != NULL)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
	pq->_size = 0;
}

typedef struct
{
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* tmp = (MyStack*)malloc(sizeof(MyStack));
	if (tmp == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	QueueInit(&tmp->q1);
	QueueInit(&tmp->q2);
	return tmp;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) 
{
	Queue* pEmpty = &obj->q1;
	Queue* pNotEmpty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		pEmpty = &obj->q2;
		pNotEmpty = &obj->q1;
	}
	while (QueueSize(pNotEmpty) > 1)
	{
		int front = QueueFront(pNotEmpty);
		QueuePush(pEmpty, front);
		QueuePop(pNotEmpty);
	}
	int front = QueueFront(pNotEmpty);
	QueuePop(pNotEmpty);
	return front;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj)
{
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) 
{
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	free(obj);
}

//["MyStack","push","pop","push","top"]
int main()
{
	MyStack* obj = myStackCreate();
	myStackPush(obj, 1);
	myStackPop(obj);
	myStackPush(obj, 2);
	int param_3 = myStackTop(obj);
	printf("%d\n", param_3);

	return EXIT_SUCCESS;
}