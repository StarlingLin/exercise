#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

enum ��ɫ
{
	RED = 4,
	GREEN = 2,
	BLUE = 1
};

enum Sex
{
	MALE,	//0
	FEMALE,	//1
	OTHER	//2
};

int main()
{
	int a = GREEN;
	printf("%d = %d\n", a, GREEN);

	enum ��ɫ clr = GREEN;
	clr = 2;	//C:ok;C++:err	C++���ͼ��Ƚ��ϸ�

	enum ENUM_A
	{
		X1,
		Y1,
		Z1 = 255,
		A1,
		B1,
	} enumB = B1, * penmB = &enumB;
	enum ENUM_A enumA = Y1;
	printf("%d %d %x\n", enumA, enumB, penmB);

	return 0;
}