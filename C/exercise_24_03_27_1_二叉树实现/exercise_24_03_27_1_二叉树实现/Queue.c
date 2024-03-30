#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"

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