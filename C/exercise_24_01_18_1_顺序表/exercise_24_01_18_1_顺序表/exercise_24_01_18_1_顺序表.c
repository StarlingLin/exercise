//≤‚ ‘

#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

void SLTest01()
{
	SL sl;
	SLInit(&sl);

	//≤‚ ‘Œ≤≤ø≤Â»Î
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);

	//≤‚ ‘Õ∑≤ø≤Â»Î
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 6);
	SLPushFront(&sl, 7);
	SLPushFront(&sl, 8);

	//≤‚ ‘Œ≤≤ø…æ≥˝
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);

	//≤‚ ‘Õ∑≤ø…æ≥˝
	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);

	//≤‚ ‘»Œ“‚Œª÷√≤Â»Î
	SLInsert(&sl, 0, 1);
	SLInsert(&sl, 0, 2);
	SLInsert(&sl, 2, 3);
	SLInsert(&sl, 1, 4);
	SLInsert(&sl, 3, 5);

	//≤‚ ‘»Œ“‚Œª÷√…æ≥˝
	SLRemove(&sl, 4);

	//≤‚ ‘≤È’“
	int pos = SLFind(&sl, 3);
	printf("pos = %d\n", pos);
	SLDataType x = SLFindByPos(&sl, 2);
	printf("x = %d\n", x);

	//≤‚ ‘–ﬁ∏ƒ
	SLModify(&sl, 2, 6);

	//≤‚ ‘√∞≈›≈≈–Ú
	SLBubbleSort(&sl);

	//≤‚ ‘¥Ú”°
	SLPrint(&sl);

	SLDestory(&sl);
}

int main()
{
	SLTest01();
	return EXIT_SUCCESS;
}
