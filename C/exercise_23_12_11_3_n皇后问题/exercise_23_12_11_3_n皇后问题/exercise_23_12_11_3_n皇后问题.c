#define _CRT_SECURE_NO_WARNINGS 1

//��Ŀ��ţ�Exp08 - Basic02��GJBook3�� - 12 - 02
//
//��Ŀ���ƣ�N�ʺ�����
//
//��Ŀ������
//
//�˻ʺ������ɸ�˹(C.F.Gauss)������1850��������о�������δ��ȫ�����N�ʺ�����ָ��һ��N��N�������Ϸ���N���ʺ�ʹ���������ʺ󶼲��ܻ��๥����������������������ʺ�����ͬһ���ϣ�����ͬһ����, ����ͬһ��б����, �����ǿ��Ի��๥������ͼ������˻ʺ�������һ����֡�
//
//��д����������������������Ŀ��
//
//https://p.ananas.chaoxing.com/star3/origin/7526b606547480a9447d2c9b30011191.jpg
//
//���룺һ��������N��0 < N��13������������Ŀ

#include <stdio.h>
#include <stdbool.h>

#define N 20

int board[N] = { 0 };
_Bool col[N] = { false }, maindiag[2 * N] = { false }, subdiag[2 * N] = {false};
int n = 0, tot = 0;

void dfs(int i)//�������
{
	if (i >= n)//�÷�֧��������
	{
		tot++;
		return;
	}
	for (int j = 0; j < n; j++)
	{
		if (col[j] || maindiag[i - j + n] || subdiag[i + j])//��֦
			continue;
		board[i] = j;//�б�i����λ���б�j
		col[j] = maindiag[i - j + n] = subdiag[i + j] = true;//ռ���Ӧ���������Խ���
		dfs(i + 1);
		col[j] = maindiag[i - j + n] = subdiag[i + j] = false;//�������ν��ռ���Ӧ���������Խ���
	}
}

int main()
{
	scanf("%d", &n);
	dfs(0);
	printf("%d", tot);
	return 0;
}