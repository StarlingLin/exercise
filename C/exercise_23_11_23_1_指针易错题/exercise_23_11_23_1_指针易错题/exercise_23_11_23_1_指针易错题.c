#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//////////////////////////////////////////

//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}
////output?
////2,5

//////////////////////////////////////////

//struct Test
//{
//	int Num;	//4
//	char* pcName;	//8(x64)4(x32)
//	short sDate;	//2
//	char cha[2];	//1
//	short sBa[4];	//2
//}*p = (struct Test*)0x100000;
//
//int main()
//{
//	printf("%p\n", p + 0x1);
//	printf("%zd\n", sizeof (struct Test));
//	printf("%p\n", (unsigned long)p + 0x1);
//	printf("%p\n", (unsigned int*)p + 0x1);
//	return 0;
//}
////output?
////100020(x64)-100014(x86-32)	
////x64об32,x86-32об20
////100001
////100004

//////////////////////////////////////////

//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);
//	return 0;
//}
////output?
////1
 
//////////////////////////////////////////
 
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}
////output?
////FFFFFFFC,-4 (x86-32)
////FFFFFFFFFFFFFFFC,-4 (x64)
////one int in gap

//////////////////////////////////////////

//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}
////output?
////10,5

//////////////////////////////////////////

//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}
////output?
////at

//////////////////////////////////////////

int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}
//output?
//POINT
//ER
//ST
//EW

//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////

