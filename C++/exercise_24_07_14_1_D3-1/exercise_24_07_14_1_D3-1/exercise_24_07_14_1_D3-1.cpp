#define _CRT_SECURE_NO_WARNINGS

//���������ʣ�������ǵ�����ĸ��д��ϳɵ���д


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
	vector<string> words;
	string word;
	while (cin >> word) 
	{
		words.push_back(word);
		if (cin.get() == '\n') 
		{
			break;
		}
	}
	for (auto& word : words) {
		cout << (char)toupper(word[0]);
	}
	cout << endl;
	return 0;
}