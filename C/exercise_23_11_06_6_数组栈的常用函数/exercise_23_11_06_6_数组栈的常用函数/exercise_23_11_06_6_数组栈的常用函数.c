#define _CRT_SECURE_NO_WARNINGS 1

#include <stdbool.h>

#define SIZE 200	/*ջ�ĳߴ�*/
typeofelement stack[SIZE] = { 0 };	/*ջ*/
int top = 0;	/*ջ��ָ��*/

//ѹջ
_Bool push(typeofelement x)
{
	if (top > SIZE - 1)
		return false;
	else
	{
		stack[top] = x;
		top += 1;
		return true;
	}
}

//��ջǰԤ���壬�洢����Ԫ��
typeofelement x;
//��ջ
_Bool pop(void)
{
	if (top <= 0)
		return false;
	else
	{
		top -= 1;
		x = stack[top];
		return true;
	}
}