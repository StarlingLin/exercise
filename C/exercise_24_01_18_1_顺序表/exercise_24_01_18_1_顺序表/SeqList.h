//����˳���ṹ��Ҫʵ�ֵĽӿ�/����

#pragma once
#include <stdio.h>

typedef int SLDataType;

//��̬˳���
//#define N 100
//struct SeqList
//{
//	SLDataType arr[N];
//	int size;
//};

//��̬˳���
typedef struct SeqList
{
	SLDataType* arr;
	int capacity;	//��¼˳���ռ��С
	int size;		//��¼˳���ǰ��Ч���ݸ���
} SL;

//��ʼ��������
//��ʼ��
void SLInit(SL* psl);
//����
void SLDestory(SL* psl);

//������ɾ��
//ͷ������
void SLPushBack(SL* psl, SLDataType x);
//ͷ��ɾ��
void SLPopBack(SL* psl);
//β������
void SLPushFront(SL* psl, SLDataType x);
//β��ɾ��
void SLPopFront(SL* psl);