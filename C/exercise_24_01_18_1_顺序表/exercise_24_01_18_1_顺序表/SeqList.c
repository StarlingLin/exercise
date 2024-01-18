//实现定义的接口/方法

#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

//初始化与销毁
//初始化
void SLInit(SL* psl)
{
	psl->arr = NULL;
	psl->size = psl->capacity = 0;
}
//销毁
void SLDestory(SL* psl)
{

}

//插入与删除
//头部插入
void SLPushBack(SL* psl, SLDataType x)
{

}
//头部删除
void SLPopBack(SL* psl)
{

}
//尾部插入
void SLPushFront(SL* psl, SLDataType x)
{

}
//尾部删除
void SLPopFront(SL* psl)
{

}