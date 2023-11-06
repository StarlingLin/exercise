#define _CRT_SECURE_NO_WARNINGS 1

#include <stdbool.h>

#define SIZE 200	/*���д�С*/
typeofelement queue[SIZE];	/*����*/
int inpointer, outpointer, count;	/*����ָ�롢ȡ��ָ�롢�ִ���Ч���ݸ���������*/

//���
_Bool putx(typeofelement x)
{
	if (count >= SIZE)
		return false;
	else
	{
		queue[inpointer] = x;
		inpointer = (inpointer + 1) % SIZE;
		count++;
		return true;
	}
}

//����ǰԤ���壬�洢����Ԫ��
typeofelement x;
//����
_Bool getx(void)
{
	if (count < 1)
		return false;
	else
	{
		x = queue[outpointer];
		outpointer = (outpointer + 1) % SIZE;
		count--;
		return true;
	}
}