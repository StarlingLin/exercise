#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"

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