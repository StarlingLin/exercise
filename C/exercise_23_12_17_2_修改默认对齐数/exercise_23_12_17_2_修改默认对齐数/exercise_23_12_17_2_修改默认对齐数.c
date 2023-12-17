#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//#pragma pack(1)//设置默认对⻬数为1
//
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//#pragma pack()//取消设置的对⻬数，还原为默认
//
//int main()
//{
//	printf("%d\n", sizeof(struct S));
//	return 0;
//}



#pragma pack(4)

int main(int argc, char* argv[])
{
	struct tagTest1
	{
		short a;
		char d;
		long b;
		long c;
	};
	struct tagTest2
	{
		long b;
		short c;
		char d;
		long a;
	};
	struct tagTest3
	{
		short c;
		long b;
		char d;
		long a;
	};
	struct tagTest1 stT1;
	struct tagTest2 stT2;
	struct tagTest3 stT3;

	printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
	return 0;
}

#pragma pack()