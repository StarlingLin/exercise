#define _CRT_SECURE_NOWARNINGS

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string str = "Hello";

    //iterator �������
    for (string::iterator it = str.begin(); it != str.end(); ++it) 
    {
        cout << *it << ' ';  // ���: H e l l o
    }
    cout << endl;

    // ʹ�� const_iterator ֻ������
    for (string::const_iterator cit = str.cbegin(); cit != str.cend(); ++cit) 
    {
        cout << *cit << ' ';  // ���: H e l l o
    }
    cout << endl;

    // ʹ�� reverse_iterator �������
    for (string::reverse_iterator rit = str.rbegin(); rit != str.rend(); ++rit) 
    {
        cout << *rit << ' ';  // ���: o l l e H
    }
    cout << endl;

	string::iterator it = str.begin();
	cout << typeid(it).name() << endl;

    return 0;
}
