//��ͷ˫��ѭ������List��

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//������������
typedef int LTDataType;

//��������ڵ�
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
} ListNode;

//��ʼ������
ListNode* ListInit(void);
//��������
void ListDestory(ListNode** pphead);

