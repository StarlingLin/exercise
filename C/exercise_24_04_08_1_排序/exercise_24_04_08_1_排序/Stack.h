#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//数据类型
typedef int STDataType;

typedef struct Stack
{
	STDataType* _data;
	int _top;
	int _capacity;
} Stack, * pStack;

//栈的初始化
void InitStack(pStack pst);
//压栈
void StackPush(pStack pst, STDataType x);
//弹栈
void StackPop(pStack pst);
//栈顶元素
STDataType StackTop(pStack pst);
//栈大小
int StackSize(pStack pst);
//栈判空
_Bool StackEmpty(pStack pst);
//栈销毁
void StackDestory(pStack pst);