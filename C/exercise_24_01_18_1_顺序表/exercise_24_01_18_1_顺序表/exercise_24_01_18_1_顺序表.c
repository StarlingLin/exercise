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

	//��������λ�ò���
	SLInsert(&sl, 0, 1);
	SLInsert(&sl, 0, 2);
	SLInsert(&sl, 2, 3);
	SLInsert(&sl, 1, 4);
	SLInsert(&sl, 3, 5);

	//��������λ��ɾ��
	SLRemove(&sl, 4);

	//���Բ���
	int pos = SLFind(&sl, 3);
	printf("pos = %d\n", pos);
	SLDataType x = SLFindByPos(&sl, 2);
	printf("x = %d\n", x);

	//�����޸�
	SLModify(&sl, 2, 6);

	//����ð������
	SLBubbleSort(&sl);

	//���Դ�ӡ
	SLPrint(&sl);

	SLDestory(&sl);
}

int main()
{
	SLTest01();
	return EXIT_SUCCESS;
}
