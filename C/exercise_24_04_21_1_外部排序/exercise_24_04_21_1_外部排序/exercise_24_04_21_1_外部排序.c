#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sort.h"

#define N 1000000000

//����������ļ�
void GenerateRand(const char* filename)
{
	srand((unsigned)time(NULL));
	FILE *fp;
	int i;
	int num;
	if ((fp = fopen(filename, "w")) == NULL)
	{
		perror("fail to open");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < N; i++)
	{
		num = rand() % 100 * 100 * 100 * 100 + rand() % 100 * 100 * 100 + rand() % 100 * 100 + rand() % 100;	//����0-99999999�������
		fprintf(fp, "%d\n", num);
	}
	fclose(fp);
}

void FileSort(const char* filename, int splitCount)
{
	//�ָ��ļ�
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		perror("fail to open");
		exit(EXIT_FAILURE);
	}
	int* num = (int*)malloc(sizeof(int) * N / splitCount);	//���ÿ���ָ��ļ�������
	int iNum = 0;	//num������±�
	int iFile = 0;	//�ָ��ļ����±�
	int n = 0;	//��ȡ������
	char splitFileName[50] = { 0 };	//�ָ��ļ���
	while (fscanf(fp, "%d", &n) != EOF)
	{
		if (iNum < N / splitCount - 1)
		{
			num[iNum++] = n;
		}
		else
		{
			num[iNum] = n;
			//����
			HeapSort(num, N / splitCount);
			//д���ļ�
			sprintf(splitFileName, "SubSort\\sort_split%d.txt", iFile++);
			FILE* splitFile = fopen(splitFileName, "w");
			if (splitFile == NULL)
			{
				perror("fail to open");
				exit(EXIT_FAILURE);
			}
			for (int i = 0; i < N / splitCount; i++)
			{
				fprintf(splitFile, "%d\n", num[i]);
			}
			fclose(splitFile);
			iNum = 0;
		}
	}
	//�鲢�ļ�

	//�ر��ļ�
	fclose(fp);
}

//�ⲿ����
int main()
{
	GenerateRand("data.txt");
	//FileSort("data.txt", 10);
	return EXIT_SUCCESS;
}