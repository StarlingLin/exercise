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
void QueuePush(Queue* pq, QueueData x);
//����
void QueuePop(Queue* pq);
//����ͷ
QueueData QueueFront(Queue* pq);
//����β
QueueData QueueBack(Queue* pq);
//���г�
int QueueSize(Queue* pq);
//�����п�
_Bool QueueEmpty(Queue* pq);
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