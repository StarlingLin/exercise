//带头双向不循环链表（List）

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//定义数据类型
typedef int LTDataType;

//定义链表节点
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
} ListNode;

//申请节点
ListNode* BuyListNode(LTDataType x);

//初始化链表
ListNode* ListInit(void);
//销毁链表
void ListDestory(ListNode** pphead);

//打印
void ListPrint(ListNode* phead);

//尾插
void ListPushBack(ListNode* phead, LTDataType x);
//头插
void ListPushFront(ListNode* phead, LTDataType x);