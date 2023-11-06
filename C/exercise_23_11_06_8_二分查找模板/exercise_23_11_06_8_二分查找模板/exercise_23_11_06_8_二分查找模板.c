#define _CRT_SECURE_NO_WARNINGS 1

//二分查找，要求被检索数组递增不重复
int half_search(int n, int a[], int key)/*n为数组长度，key为关键字，a[]为查找数组*/
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