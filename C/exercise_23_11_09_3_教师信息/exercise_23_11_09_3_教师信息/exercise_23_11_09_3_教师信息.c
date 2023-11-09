#define _CRT_SECURE_NO_WARNINGS 1


//成员为数组

//#include <stdio.h>
//
//struct Teacher
//{
//	char name[10][20];
//	int gender[10];
//	int age[10];
//};
//
//int main()
//{
//	int n = 0;
//	struct Teacher t;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s", t.name[i]);
//		scanf("%d", &t.gender[i]);
//		scanf("%d", &t.age[i]);
//	}
//	printf("%s %s %d ", t.name[n / 2], 0 == t.gender[n / 2] ? "Female" : "Male", t.age[n / 2]);
//	return 0;
//}


//结构体数组

#include <stdio.h>

struct Teacher
{
	char name[20];
	int gender;
	int age;
};

int main()
{
	int n = 0;
	struct Teacher t[10];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", t[i].name);
		scanf("%d", &t[i].gender);
		scanf("%d", &t[i].age);
	}
	printf("%s %s %d ", t[n / 2].name, 0 == t[n / 2].gender ? "Female" : "Male", t[n / 2].age);
	return 0;
}