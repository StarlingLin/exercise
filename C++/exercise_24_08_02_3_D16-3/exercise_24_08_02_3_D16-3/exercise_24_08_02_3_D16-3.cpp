#define _CRT_SECURE_NO_WARNINGS

//����string���ͻ������к�int����n��Ѱ�ҳ���Ϊn���Ӵ���GC������ߵ��Ӵ�

#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string s;
	int n;
	cin >> s >> n;
	double max_gc = 0;
	string max_gc_str;
	for (int i = 0; i < s.size() - n + 1; i++) 
	{
		string sub = s.substr(i, n);
		int gc = 0;
		for (int j = 0; j < n; j++) 
		{
			if (sub[j] == 'G' || sub[j] == 'C') 
			{
				gc++;
			}
		}
		double gc_rate = (double)gc / n;
		if (gc_rate > max_gc) {
			max_gc = gc_rate;
			max_gc_str = sub;
		}
	}
	cout << max_gc_str << endl;
	return 0;
}