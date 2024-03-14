#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

//ջ�ĳ�ʼ��
void InitStack(pStack pst)
{
	assert(pst);
	pst->_data = NULL;
	pst->_top = 0;
	pst->_capacity = 0;
}
//�����������
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
//ѹջ
void StackPush(pStack pst, STDataType x)
{
	assert(pst);
	StackCheck(pst); 
	memcpy(&(pst->_data[pst->_top]), &x, sizeof(STDataType));
	pst->_top++;
}
//��ջ
void StackPop(pStack pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	pst->_top--;
}
//ջ��Ԫ��
STDataType StackTop(pStack pst)
{
	assert(pst);
	return pst->_data[pst->_top - 1];
}
//ջ��С
int StackSize(pStack pst)
{
	assert(pst);
	return pst->_top;
}
//ջ�п�
_Bool StackEmpty(pStack pst)
{
	assert(pst);
	return pst->_top == 0;
}
//ջ����
void StackDestory(pStack pst)
{
	assert(pst);
	free(pst->_data);
	pst->_capacity = 0;
	pst->_top = 0;
	pst->_data = NULL;
}