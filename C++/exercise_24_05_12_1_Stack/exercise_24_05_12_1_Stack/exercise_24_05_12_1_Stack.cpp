#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack stack(5);

	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(6);

	cout << stack.GetSize() << endl;
	cout << stack.Top() << endl;

	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;

	return 0;
}