#define _CRT_SECURE_NO_WARNINGS 1

//���ֲ��ң�Ҫ�󱻼�������������ظ�
int half_search(int n, int a[], int key)/*nΪ���鳤�ȣ�keyΪ�ؼ��֣�a[]Ϊ��������*/
{
	int lower, upper, j;
	lower = 0;
	upper = n - 1;
	
	while (upper - lower >= 0)
	{
		j = (lower + upper) / 2;
		if (key == a[j])
			return j;
		else if (key > a[j])
			lower = j + 1;
		else
			upper = j - 1;
	}
	
	return -1;
}