#define _CRT_SECURE_NOWARNINGS

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string str = "Hello";

    //iterator 正向遍历
    for (string::iterator it = str.begin(); it != str.end(); ++it) 
    {
        cout << *it << ' ';  // 输出: H e l l o
    }
    cout << endl;

    // 使用 const_iterator 只读遍历
    for (string::const_iterator cit = str.cbegin(); cit != str.cend(); ++cit) 
    {
        cout << *cit << ' ';  // 输出: H e l l o
    }
    cout << endl;

    // 使用 reverse_iterator 反向遍历
    for (string::reverse_iterator rit = str.rbegin(); rit != str.rend(); ++rit) 
    {
        cout << *rit << ' ';  // 输出: o l l e H
    }
    cout << endl;

	string::iterator it = str.begin();
	cout << typeid(it).name() << endl;

    return 0;
}
