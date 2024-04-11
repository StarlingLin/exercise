#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

//Õ»µÄ³õÊ¼»¯
void InitStack(pStack pst)
{
	assert(pst);
	pst->_data = NULL;
	pst->_top = 0;
	pst->_capacity = 0;
}
//ÈÝÁ¿¼ì²éÀ©ÈÝ
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
//Ñ¹Õ»
void StackPush(pStack pst, STDataType x)
{
	assert(pst);
	StackCheck(pst); 
	memcpy(&(pst->_data[pst->_top]), &x, sizeof(STDataType));
	pst->_top++;
}
//µ¯Õ»
void StackPop(pStack pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	pst->_top--;
}
//Õ»¶¥ÔªËØ
STDataType StackTop(pStack pst)
{
	assert(pst);
	return pst->_data[pst->_top - 1];
}
//Õ»´óÐ¡
int StackSize(pStack pst)
{
	assert(pst);
	return pst->_top;
}
//Õ»ÅÐ¿Õ
_Bool StackEmpty(pStack pst)
{
	assert(pst);
	return pst->_top == 0;
}
//Õ»Ïú»Ù
void StackDestory(pStack pst)
{
	assert(pst);
	free(pst->_data);
	pst->_capacity = 0;
	pst->_top = 0;
	pst->_data = NULL;
}