#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//队列数据类型
#define QueueData int

//队列
typedef struct QueueNode
{
	QueueData _data;
	struct QueueNode* _next;
} QueueNode;
//储存队列头尾信息的指针
typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
	int _size;
} Queue;

//队列的初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
	pq->_size = 0;
}
//入队
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
//出队
void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->_front == NULL)
	{
		return;
	}
	QueueNode* head = pq->_front->_next;
	free(pq->_front);
	pq->_front = head;

	pq->_size--;
}
//队列头
QueueData QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_front);
	return pq->_front->_data;
}
//队列尾
QueueData QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_rear);
	return pq->_rear->_data;
}
//队列长
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->_size;
}
//队列判空
_Bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_size == 0;
}
//队列销毁
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
	if (QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q2);
	}
	else
	{
		return QueueBack(&obj->q1);
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

int main()
{
	MyStack* obj = myStackCreate();
	myStackPush(obj, 1);
	myStackPush(obj, 2);
	myStackPush(obj, 3);
	myStackPush(obj, 4);
	myStackPush(obj, 5);

	int param_2 = myStackPop(obj);
	printf("%d\n", param_2);

	int param_3 = myStackTop(obj);
	printf("%d\n", param_3);

	bool param_4 = myStackEmpty(obj);
	printf("%d\n", param_4);

	myStackFree(obj);

	return EXIT_SUCCESS;
}