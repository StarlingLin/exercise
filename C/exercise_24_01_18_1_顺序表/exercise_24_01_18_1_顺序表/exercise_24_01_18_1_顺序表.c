//����

#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

void SLTest01()
{
	SL sl;
	SLInit(&sl);

	//����β������
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);

	//����ͷ������
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 6);
	SLPushFront(&sl, 7);
	SLPushFront(&sl, 8);

	//����β��ɾ��
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);

	//����ͷ��ɾ��
	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);

	SLPrint(&sl);

	SLDestory(&sl);
}

int main()
{
	SLTest01();
	return EXIT_SUCCESS;
}
