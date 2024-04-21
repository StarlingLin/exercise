#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sort.h"

#define N 1000000000

//生成随机数文件
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
		num = rand() % 100 * 100 * 100 * 100 + rand() % 100 * 100 * 100 + rand() % 100 * 100 + rand() % 100;	//生成0-99999999的随机数
		fprintf(fp, "%d\n", num);
	}
	fclose(fp);
}

void FileSort(const char* filename, int splitCount)
{
	//分割文件
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		perror("fail to open");
		exit(EXIT_FAILURE);
	}
	int* num = (int*)malloc(sizeof(int) * N / splitCount);	//存放每个分割文件的数据
	int iNum = 0;	//num数组的下标
	int iFile = 0;	//分割文件的下标
	int n = 0;	//读取的数据
	char splitFileName[50] = { 0 };	//分割文件名
	while (fscanf(fp, "%d", &n) != EOF)
	{
		if (iNum < N / splitCount - 1)
		{
			num[iNum++] = n;
		}
		else
		{
			num[iNum] = n;
			//排序
			HeapSort(num, N / splitCount);
			//写入文件
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
	//归并文件

	//关闭文件
	fclose(fp);
}

//外部排序
int main()
{
	GenerateRand("data.txt");
	//FileSort("data.txt", 10);
	return EXIT_SUCCESS;
}