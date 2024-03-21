#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* tmp = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    tmp->capacity = k + 1;
    tmp->front = tmp->rear = 0;
    tmp->data = (int*)malloc(tmp->capacity * sizeof(int));
    return tmp;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if ((obj->rear + 1) % obj->capacity == obj->front)
    {
        return false;
    }
    obj->data[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->rear == obj->front)
    {
        return false;
    }
    obj->front = (obj->front + 1) % obj->capacity;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->front == obj->rear)
    {
        return -1;
    }
    return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->front == obj->rear)
    {
        return -1;
    }
    return obj->data[(obj->rear + obj->capacity - 1) % obj->capacity];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->rear == obj->front;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % obj->capacity == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}

int main()
{
	MyCircularQueue* obj = myCircularQueueCreate(3);
	myCircularQueueEnQueue(obj, 1);
	myCircularQueueEnQueue(obj, 2);
	myCircularQueueEnQueue(obj, 3);
	myCircularQueueEnQueue(obj, 4);
	printf("%d\n", myCircularQueueRear(obj));
	myCircularQueueDeQueue(obj);
	myCircularQueueEnQueue(obj, 4);
	printf("%d\n", myCircularQueueRear(obj));
	myCircularQueueFree(obj);
	return 0;
}