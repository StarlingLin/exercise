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

//初始化链表
void ListInit(ListNode** pphead);
//销毁链表
void ListDestory(ListNode** pphead);