#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//��������
typedef int STDataType;

typedef struct Stack
{
	STDataType* _data;
	int _top;
	int _capacity;
} Stack, * pStack;

//ջ�ĳ�ʼ��
void InitStack(pStack pst);
//ѹջ
void StackPush(pStack pst, STDataType x);
//��ջ
void StackPop(pStack pst);
//ջ��Ԫ��
STDataType StackTop(pStack pst);
//ջ��С
int StackSize(pStack pst);
//ջ�п�
_Bool StackEmpty(pStack pst);
//ջ����
void StackDestory(pStack pst);