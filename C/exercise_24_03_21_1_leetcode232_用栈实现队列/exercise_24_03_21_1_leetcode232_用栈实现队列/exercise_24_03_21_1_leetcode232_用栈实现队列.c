#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

//数据类型
typedef int STDataType;

typedef struct Stack
{
	STDataType* _data;
	int _top;
	int _capacity;
} Stack, * pStack;

//栈的初始化
void InitStack(pStack pst)
{
	assert(pst);
	pst->_data = NULL;
	pst->_top = 0;
	pst->_capacity = 0;
}
//容量检查扩容
void StackCheck(pStack pst)
{
	if (pst->_top == pst->_capacity)
	{
		int newCapacity = ((pst->_capacity == 0) ? 4 : (2 * pst->_capacity));
		STDataType* temp = (STDataType*)realloc(pst->_data, newCapacity * sizeof(STDataType));
		if (temp == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		pst->_data = temp;
		pst->_capacity = newCapacity;
	}
}
//压栈
void StackPush(pStack pst, STDataType x)
{
	assert(pst);
	StackCheck(pst);
	memcpy(&(pst->_data[pst->_top]), &x, sizeof(STDataType));
	pst->_top++;
}
//弹栈
_Bool StackEmpty(pStack pst);
void StackPop(pStack pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	pst->_top--;
}
//栈顶元素
STDataType StackTop(pStack pst)
{
	assert(pst);
	return pst->_data[pst->_top - 1];
}
//栈大小
int StackSize(pStack pst)
{
	assert(pst);
	return pst->_top;
}
//栈判空
_Bool StackEmpty(pStack pst)
{
	assert(pst);
	return pst->_top == 0;
}
//栈销毁
void StackDestory(pStack pst)
{
	assert(pst);
	free(pst->_data);
	pst->_capacity = 0;
	pst->_top = 0;
	pst->_data = NULL;
}

typedef struct {
	Stack pushStack;
	Stack popStack;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	InitStack(&obj->pushStack);
	InitStack(&obj->popStack);
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushStack, x);
}

int myQueuePeek(MyQueue* obj);
int myQueuePop(MyQueue* obj) {
	int front = myQueuePeek(obj);
	StackPop(&obj->popStack);
	return front;
}

int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popStack))
	{
		while (!StackEmpty(&obj->pushStack))
		{
			StackPush(&obj->popStack, StackTop(&obj->pushStack));
			StackPop(&obj->pushStack);
		}
	}
	return StackTop(&obj->popStack);
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushStack) && StackEmpty(&obj->popStack);
}	

void myQueueFree(MyQueue* obj) {
	StackDestory(&obj->pushStack);
	StackDestory(&obj->popStack);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

int main()
{
	MyQueue* obj = myQueueCreate();
	myQueuePush(obj, 1);
	myQueuePush(obj, 2);
	myQueuePush(obj, 3);
	myQueuePush(obj, 4);
	myQueuePush(obj, 5);

	int param_2 = myQueuePop(obj);
	printf("param_2 = %d\n", param_2);

	int param_3 = myQueuePeek(obj);
	printf("param_3 = %d\n", param_3);

	bool param_4 = myQueueEmpty(obj);
	printf("param_4 = %d\n", param_4);

	myQueueFree(obj);

	return EXIT_SUCCESS;
}