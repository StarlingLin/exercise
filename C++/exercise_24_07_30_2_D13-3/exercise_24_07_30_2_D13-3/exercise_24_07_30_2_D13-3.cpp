#define _CRT_SECURE_NO_WARNINGS

//�����ַ�����ʹ����������������ͬ��������ĸ
//��һ����������n�������ַ�������
//�ڶ�������һ��ȫСд��ĸ��ɵ��ַ���

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        string result = "";
        int nums[26] = { 0 };
        int len = S.size();

        // ͳ�Ʋ�ͬ��ĸ����
        for (char c : S) {
            nums[c - 'a']++;
        }
        int maxIndex = 0;
        for (int i = 0; i < 26; ++i) {
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }

        // ���һ����ĸ���������� (len + 1) / 2����������Ҫ��
        if (nums[maxIndex] > (len + 1) / 2) return "";

        while (result.size() != len) {
            // �ȼ�һ������������ĸ
            for (int i = 0; i < 26; ++i) {
                if (nums[i] > nums[maxIndex]) maxIndex = i;
            }
            result += char('a' + maxIndex);
            nums[maxIndex]--;

            // ��������ˣ�ֱ�ӷ��ؽ��
            if (result.size() == len) return result;

            // �ټ�һ�������ڶ������ĸ
            int secondMaxIndex = maxIndex == 0 ? 1 : 0;
            for (int i = 0; i < 26; ++i) {
                if (i == maxIndex) continue;
                if (nums[i] > nums[secondMaxIndex]) secondMaxIndex = i;
            }
            result += char('a' + secondMaxIndex);
            nums[secondMaxIndex]--;
        }
        return result;
    }
};

int main() {
	Solution solution;
	string S;
	int n;
	cin >> n;
	cin >> S;
	cout << solution.reorganizeString(S) << endl;
	return 0;
}