#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Sort.h"

#define N 100000000

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

void MergeFile(char* file1, char* file2, char* mergeFileName)
{
	FILE* fp1 = fopen(file1, "r");
	FILE* fp2 = fopen(file2, "r");
	if (fp1 == NULL)
	{
		perror("fail to open");
		exit(EXIT_FAILURE);
	}
	if (fp2 == NULL)
	{
		perror("fail to open");
		exit(EXIT_FAILURE);
	}
	FILE* fin = fopen("tmp.txt", "w");
	if (fin == NULL)
	{
		perror("fail to open");
		exit(EXIT_FAILURE);
	}
	int n1, n2;
	int ret1 = fscanf(fp1, "%d", &n1);
	int ret2 = fscanf(fp2, "%d", &n2);
	while (ret1 != EOF && ret2 != EOF)
	{
		if (n1 < n2)
		{
			fprintf(fin, "%d\n", n1);
			ret1 = fscanf(fp1, "%d", &n1);
		}
		else
		{
			fprintf(fin, "%d\n", n2);
			ret2 = fscanf(fp2, "%d", &n2);
		}
	}
	while (fscanf(fp1, "%d", &n1) != EOF)
	{
		fprintf(fin, "%d\n", n1);
	}
	while (fscanf(fp2, "%d", &n2) != EOF)
	{
		fprintf(fin, "%d\n", n2);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fin);
	remove(file1);
	remove(file2);
	rename("tmp.txt", mergeFileName);
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
			printf("�ѷָ��%d���ļ����ܹ���ָ�%d���ļ���\n", iFile, splitCount);
			iNum = 0;
		}
	}

	//�鲢�ļ�
	char* mergeFileName = "sort_merge.txt";
	char file1[50] = "SubSort\\sort_split0.txt", file2[50] = {0};
	for (int i = 1; i < splitCount; i++)
	{
		sprintf(file2, "SubSort\\sort_split%d.txt", i);
		MergeFile(file1, file2, mergeFileName);
		strcpy(file1, mergeFileName);
		printf("�ѹ鲢%d���ļ����ܹ���鲢%d���ļ���\n", i + 1, splitCount);
	}

	//�ر��ļ�
	fclose(fp);
}

//�ⲿ����
int main()
{
	//GenerateRand("data.txt");
	FileSort("data.txt", 100);
	return EXIT_SUCCESS;
}