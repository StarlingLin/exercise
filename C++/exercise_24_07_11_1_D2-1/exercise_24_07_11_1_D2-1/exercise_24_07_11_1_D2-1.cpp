#define _CRT_SECURE_NO_WARNINGS

//快递，1kg以内按起步价20元计算，超出部分每千克1元，如果加急则额外加5元。（重量向上取整）
//输入第一行为一个单精度浮点数a和一个字符b，a表示快递重量，b表示是否加急，b为y表示加急，b为n表示不加急。

#include <iostream>

using namespace std;

int main() 
{
	float weight;
	char urgent;
	cin >> weight >> urgent;
	weight = (int)(weight + 0.999999);
	if (urgent == 'y')
		cout << 20 + 5 + (weight - 1) << endl;
	else
		cout << 20 + weight - 1 << endl;
	return 0;
}