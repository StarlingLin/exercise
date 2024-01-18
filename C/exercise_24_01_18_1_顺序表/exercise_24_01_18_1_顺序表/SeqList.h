//定义顺序表结构、要实现的接口/方法

#pragma once
#include <stdio.h>

typedef int SLDataType;

//静态顺序表
//#define N 100
//struct SeqList
//{
//	SLDataType arr[N];
//	int size;
//};

//动态顺序表
typedef struct SeqList
{
	SLDataType* arr;
	int capacity;	//记录顺序表空间大小
	int size;		//记录顺序表当前有效数据个数
} SL;

//初始化与销毁
//初始化
void SLInit(SL* psl);
//销毁
void SLDestory(SL* psl);

//插入与删除
//头部插入
void SLPushBack(SL* psl, SLDataType x);
//头部删除
void SLPopBack(SL* psl);
//尾部插入
void SLPushFront(SL* psl, SLDataType x);
//尾部删除
void SLPopFront(SL* psl);