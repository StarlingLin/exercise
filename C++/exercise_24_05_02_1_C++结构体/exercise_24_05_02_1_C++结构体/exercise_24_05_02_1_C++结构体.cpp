#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

typedef int DataType; 

struct Stack
{
	void Init(size_t capacity)
	{
		m_arr = (DataType*)malloc(sizeof(DataType) * capacity);
		if (nullptr == m_arr)
		{
			perror("malloc");
			return;
		}
		m_capacity = capacity;
		m_size = 0;
	}

	void Push(const DataType& data)
	{
		m_arr[m_size] = data;
		++m_size;
	}

	DataType Top()
	{
		return m_arr[m_size - 1];
	}

	void Destory()
	{
		if (nullptr != m_arr)
		{
			free(m_arr);
			m_arr = nullptr;
			m_capacity = 0;
			m_size = 0;
		}
	}

	DataType* m_arr;
	size_t m_capacity;
	size_t m_size;
};

int main()
{
	Stack stack;
	stack.Init(10);
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	
	cout << stack.Top() << endl;

	stack.Destory();

	return 0;
}