#pragma once

#include <iostream>
#include <string>

using namespace std;

typedef int StackDataType;

class Stack
{
public:
	Stack(int size);
	~Stack();
	void Push(StackDataType data);
	StackDataType Pop();
	StackDataType Top();
	bool IsEmpty();
	bool IsFull();
	int GetSize();
	int GetTop();

private:
	StackDataType* m_data;
	int m_size;
	int m_capacity;
};