#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

int main()
{
	ListNode* plist = ListInit();
	//β��
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	//ͷ��
	ListPushFront(plist, 5);
	ListPushFront(plist, 6);
	ListPushFront(plist, 7);
	ListPushFront(plist, 8); 
	ListPrint(plist);
	//βɾ
	ListPopBack(plist);
	ListPrint(plist);
	//ͷɾ
	ListPopFront(plist);
	ListPrint(plist);

	ListNode* pos = ListFind(plist, 3);
	printf("%d\n", pos->data);

	ListInsert(pos, 10);
	ListPrint(plist);

	ListErase(pos);
	ListPrint(plist);

	ListDestory(&plist);
	return 0;
}