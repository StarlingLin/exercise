#define _CRT_SECURE_NO_WARNINGS 1

#include <stdbool.h>

#define SIZE 200	/*Õ»µÄ³ß´ç*/
typeofelement stack[SIZE] = { 0 };	/*Õ»*/
int top = 0;	/*Õ»¶¥Ö¸Õë*/

//Ñ¹Õ»
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

//µ¯Õ»Ç°Ô¤¶¨Òå£¬´æ´¢µ¯³öÔªËØ
typeofelement x;
//µ¯Õ»
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