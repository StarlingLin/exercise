#define _CRT_SECURE_NOWARNINGS

#include <iostream>

using namespace std;

//int main()
//{
//	string s1 = "a";
//	cout << s1.empty() << endl;	//0
//
//	string s2 = "";
//	cout << s2.empty() << endl;	//1
//
//	string s3;
//	cout << s3.empty() << endl;	//1
//
//	return 0;
//}

int main()
{
	string s = "a";
	cout << s.size() << endl;	//1
	cout << s.capacity() << endl;	//15

	s.clear();
	cout << s.size() << endl;	//0
	cout << s.capacity() << endl;	//15
	cout << s << endl;
}