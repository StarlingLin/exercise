#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

int main()
{
	ListNode* plist = ListInit();
	//Î²²å
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	return 0;
}