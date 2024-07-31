#define _CRT_SECURE_NO_WARNINGS

//重排字符串，使不包含任意两个相同的相邻字母
//第一行输入整数n，代表字符串长度
//第二行输入一个全小写字母组成的字符串

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

        // 统计不同字母个数
        for (char c : S) {
            nums[c - 'a']++;
        }
        int maxIndex = 0;
        for (int i = 0; i < 26; ++i) {
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }

        // 如果一个字母的数量超过 (len + 1) / 2，不能满足要求
        if (nums[maxIndex] > (len + 1) / 2) return "";

        while (result.size() != len) {
            // 先加一个数量最多的字母
            for (int i = 0; i < 26; ++i) {
                if (nums[i] > nums[maxIndex]) maxIndex = i;
            }
            result += char('a' + maxIndex);
            nums[maxIndex]--;

            // 如果加满了，直接返回结果
            if (result.size() == len) return result;

            // 再加一个数量第二多的字母
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