#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct Stu
{
	char name[10];
	struct Stu* next;
};
typedef struct Stu strc_stu;

int main()
{
	strc_stu stu1 = { "aaa", NULL };
	strc_stu stu2 = { "bbb", NULL };
	strc_stu stu3 = { "ccc", NULL };
	strc_stu stu4 = { "ddd", NULL };
	strc_stu stu5 = { "eee", NULL };
	strc_stu stu6 = { "fff", NULL };

	stu1.next = &stu2;
	stu2.next = &stu3;
	stu3.next = &stu4;
	stu4.next = &stu5;
	stu5.next = &stu6;

	strc_stu* p = NULL;

	p = &stu1;

	while (p)
	{
		printf("%s\n", p->name);
		p = p->next;
	}

	return 0;
}