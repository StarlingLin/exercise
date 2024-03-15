#pragma once

#include <stdbool.h>

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
} Queue;

//���еĳ�ʼ��
void QueueInit(Queue* pq);
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
void QueueDestory(Queue* pq);