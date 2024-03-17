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
void QueuePush(Queue* pq, QueueData x);
//出队
void QueuePop(Queue* pq);
//队列头
QueueData QueueFront(Queue* pq);
//队列尾
QueueData QueueBack(Queue* pq);
//队列长
int QueueSize(Queue* pq);
//队列判空
_Bool QueueEmpty(Queue* pq);
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