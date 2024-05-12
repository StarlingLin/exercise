#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

Stack::Stack(int size = 4)
{
	m_data = new StackDataType[size];
	m_size = 0;
	m_capacity = size;
}

Stack::~Stack()
{
	delete[] m_data;
}

void Stack::Push(StackDataType data)
{
	if (IsFull())
	{
		cout << "Stack is full!" << endl;
		return;
	}

	m_data[m_size++] = data;
}

StackDataType Stack::Pop()
{
	if (IsEmpty())
	{
		cout << "Stack is empty!" << endl;
		return -1;
	}

	return m_data[--m_size];
}

StackDataType Stack::Top()
{
	if (IsEmpty())
	{
		cout << "Stack is empty!" << endl;
		return -1;
	}

	return m_data[m_size - 1];
}

bool Stack::IsEmpty()
{
	return m_size == 0;
}

bool Stack::IsFull()
{
	return m_size == m_capacity;
}

int Stack::GetSize()
{
	return m_size;
}

int Stack::GetTop()
{
	return m_size - 1;
}