#define _CRT_SECURE_NO_WARNINGS

//n个苹果m个桃子，2个苹果和1个桃子组成价值a元的拼盘，1个苹果和2个桃子组成价值b元的拼盘，求n个苹果m个桃子的最大价值

#include <iostream>

using namespace std;

int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int max = 0;
	for (int i = 0; i <= n / 2; i++) {
		for (int j = 0; j <= m / 2; j++) {
			if (i * 2 + j <= n && i + j * 2 <= m) {
				if (i * a + j * b > max) {
					max = i * a + j * b;
				}
			}
		}
	}
	cout << max << endl;
	return 0;
}