#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"

//���еĳ�ʼ��
void QueueInit(Queue* pq)
{

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
void QueueDestory(Queue* pq);