#define _CRT_SECURE_NO_WARNINGS 1

#include <stdbool.h>

#define SIZE 200	/*队列大小*/
typeofelement queue[SIZE];	/*队列*/
int inpointer, outpointer, count;	/*送入指针、取出指针、现存有效数据计数器*/

/*进队*/
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

/*出队预定义*/
typeofelement x;
/*出队*/
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