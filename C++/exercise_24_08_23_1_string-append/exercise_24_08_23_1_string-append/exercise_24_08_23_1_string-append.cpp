#define _CRT_SECURE_NOWARNINGS

#include <iostream>
#include <string>

using namespace std;

//int main()
//{
//	string s = "append:";
//	string t = "uvwxyz";
//	s.append(t);		// 将字符串t的内容追加到字符串s的末尾
//	cout << s << endl;	// append:uvwxyz
//	s.append(t, 2, 3);	// 将字符串t的子串（从t[2]开始数3位）追加到字符串s的末尾
//	cout << s << endl;	// append:uvwxyzwxy
//	s.append("123");	// 将字符串"123"追加到字符串s的末尾
//	cout << s << endl;	// append:uvwxyzwxy123
//	s.append("456", 2);	// 将字符串"456"的前2个字符追加到字符串s的末尾
//	cout << s << endl;	// append:uvwxyzwxy12345
//	s.append(3, 'x');	// 将字符'x'追加到字符串s的末尾3次
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