#define _CRT_SECURE_NOWARNINGS

#include <iostream>
#include <string>

using namespace std;

//int main()
//{
//	string s = "append:";
//	string t = "uvwxyz";
//	s.append(t);		// ���ַ���t������׷�ӵ��ַ���s��ĩβ
//	cout << s << endl;	// append:uvwxyz
//	s.append(t, 2, 3);	// ���ַ���t���Ӵ�����t[2]��ʼ��3λ��׷�ӵ��ַ���s��ĩβ
//	cout << s << endl;	// append:uvwxyzwxy
//	s.append("123");	// ���ַ���"123"׷�ӵ��ַ���s��ĩβ
//	cout << s << endl;	// append:uvwxyzwxy123
//	s.append("456", 2);	// ���ַ���"456"��ǰ2���ַ�׷�ӵ��ַ���s��ĩβ
//	cout << s << endl;	// append:uvwxyzwxy12345
//	s.append(3, 'x');	// ���ַ�'x'׷�ӵ��ַ���s��ĩβ3��
//	cout << s << endl;	// append:uvwxyzwxy12345xxx
//
//	return 0; 
//}

int main()
{
	string s = "append:";
	cout << (s += "abc") << endl;	// append:abc
	cout << (s += s) << endl;		// append:abcappend:abc
	cout << (s += '.') << endl;		// append:abcappend:abc.

	return 0;
}