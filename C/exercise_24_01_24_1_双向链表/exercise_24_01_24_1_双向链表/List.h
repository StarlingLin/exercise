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

//����ڵ�
ListNode* BuyListNode(LTDataType x);

//��ʼ������
ListNode* ListInit(void);
//��������
void ListDestory(ListNode** pphead);

//��ӡ
void ListPrint(ListNode* phead);

//β��
void ListPushBack(ListNode* phead, LTDataType x);
//ͷ��
void ListPushFront(ListNode* phead, LTDataType x);

//βɾ
void ListPopBack(ListNode* phead);
//ͷɾ
void ListPopFront(ListNode* phead);

//����
ListNode* ListFind(ListNode* phead, LTDataType x);

//��posλ��֮�����x
void ListInsert(ListNode* pos, LTDataType x);
//ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
