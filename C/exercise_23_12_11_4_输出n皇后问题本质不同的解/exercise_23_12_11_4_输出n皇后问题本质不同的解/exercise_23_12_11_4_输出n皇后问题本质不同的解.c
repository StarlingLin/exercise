#define _CRT_SECURE_NO_WARNINGS 1

//��Ŀ��ţ�Exp08 - Basic03
//
//��Ŀ���ƣ��˻ʺ��ʲ�ͬ�Ľ�
//
//��Ŀ������
//
//��������������N = 8ʱ��һ����92�ֿ��ܡ����ȥ���������¶Գơ����ҶԳ���֡�����
//�Խ��߶Գ���ֺ���ת���ظ���֣�����12����ȫ��ͬ����֡���д���������12����֡�
//
//���룺
//
//��
//
//�����
//
//��12�У�ÿ�����1����֣�
//
//���磬��һ����� No1 : 1 5 8 6 3 7 2 4��ð��Ϊ����ð����ǰ���޶����ַ���ð�ź�
//��ÿ�����ֺ����һ�����Ŀո񣩣�����No1 ��ʾ���ǵ�1����֣������������б�ʾ�˻ʺ�
//����λ�ã���ֵ�����ʾĳ���ʺ��������ϵ������꣬����ֵ����λ�ñ�ʾ�ûʺ�������꣨
// > 0)�����磬����5λ�����еĵ�2λ����ʾ�����ϵ�5�е�2����һ���ʺ�����4λ������
// �ĵ�8λ����ʾ�����ϵ�4�е�8����һ���ʺ��ɴˣ���8������������һ����֡�12�����
//�����˳���ֵ���

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 100

int board[N] = { 0 }, solution[114514][N] = { 0 }, n = 0, tot = 0;
_Bool col[N] = { false }, maindiag[2 * N] = { false }, subdiag[2 * N] = { false }, flag = true;

void answer();//����dfs����������
void dfs(int i);//�������
void printans(int i);//������
_Bool check(int* arr1, int* arr2);//�������ܽⲻһ���򷵻�false
_Bool up_down(int* arr1, int* arr2);//���¶Գ�
_Bool left_right(int* arr1, int* arr2);//���ҶԳ�
_Bool turn_maindiag(int* arr1, int* arr2);//���Խ��߶Գ�
_Bool turn_subdiag(int* arr1, int* arr2);//���Խ��߶Գ�
_Bool turn_cw(int* arr1, int* arr2);//˳ʱ����ת�Գ�
_Bool turn_ccw(int* arr1, int* arr2);//��ʱ����ת�Գ�
_Bool turn_central(int* arr1, int* arr2);//���ĶԳ�

int main()
{
	scanf("%d", &n);
	dfs(0);
	printf("%d\n", tot);
	answer();
	return 0;
}

void answer()
{
	for (int i = 0; i < tot; i++)
	{
		flag = true;
		for (int j = 0; j < i; j++)
			if (check(solution[i], solution[j]))
				flag = false;
		if (flag)
			printans(i);
	}
}

void printans(int i)//������
{
	static int ans = 0;
	printf("No%d:", ++ans);
	for (int j = 0; j < n; j++)
		printf("%d ", solution[i][j] + 1);
	printf("\n");
}

_Bool check(int* arr1, int* arr2)//�������ܽⲻһ���򷵻�false
{
	if (up_down(arr1, arr2) || left_right(arr1, arr2) || turn_maindiag(arr1, arr2) || turn_subdiag(arr1, arr2) || turn_cw(arr1, arr2) || turn_ccw(arr1, arr2) || turn_central(arr1, arr2))
		return true;
	return false;
}

_Bool up_down(int* arr1, int* arr2)//���¶Գ�
{
	for (int i = 0; i < n; i++)
		if (arr1[i] != arr2[n - i - 1])
			return false;
	return true;
}

_Bool left_right(int* arr1, int* arr2)//���ҶԳ�
{
	for (int i = 0; i < n; i++)
		if (arr1[i] != n - arr2[i] - 1)
			return false;
	return true;
}

_Bool turn_maindiag(int* arr1, int* arr2)//���Խ��߶Գ�
{
	for (int i = 0; i < n; i++)
		if (arr2[arr1[i]] != i)
			return false;
	return true;
}

_Bool turn_subdiag(int* arr1, int* arr2)//���Խ��߶Գ�
{
	for (int i = 0; i < n; i++)
		if (arr2[n - arr1[i] - 1] != n - i - 1)
			return false;
	return true;
}

_Bool turn_cw(int* arr1, int* arr2)//˳ʱ����ת�Գ�
{
	for (int i = 0; i < n; i++)
		if (arr2[arr1[i]] != n - 1 - i)
			return false;
	return true;
}

_Bool turn_ccw(int* arr1, int* arr2)//��ʱ����ת�Գ�
{
	for (int i = 0; i < n; i++)
		if (arr2[n - 1 - arr1[i]] != i)
			return false;
	return true;
}

_Bool turn_central(int* arr1, int* arr2)//���ĶԳ�
{
	for (int i = 0; i < n; i++)
		if (arr2[n - 1 - i] != n - 1 - arr1[i])
			return false;
	return true;
}

void dfs(int i)//�������
{
	if (i >= n)//�÷�֧��������
	{
		memcpy(solution[tot], board, n * sizeof(int));
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