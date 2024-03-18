#pragma once

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
void QueueInit(Queue* pq);
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
void QueueDestory(Queue* pq);