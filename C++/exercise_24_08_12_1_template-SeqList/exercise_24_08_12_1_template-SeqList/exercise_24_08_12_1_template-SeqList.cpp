#define _CRT_SECURE_NO_WARNINGS

using namespace std;

template <class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10) 
		: m_data(new T[capacity])
		, m_capacity(capacity)
		, m_size(0)
	{}

	~SeqList()
	{
		if (m_data)
			delete[] m_data;
		m_size = m_capacity = 0;
	}

	void push_back(const T& value)
	{
		if (m_size == m_capacity)
		{
			size_t new_capacity = m_capacity * 2;
			T* new_data = new T[new_capacity];
			for (size_t i = 0; i < m_size; ++i)
				new_data[i] = m_data[i];
			delete[] m_data;
			m_data = new_data;
			m_capacity = new_capacity;
		}
		m_data[m_size++] = value;
	}

	void pop_back()
	{
		if (m_size > 0)
			--m_size;
	}

	size_t size() const
	{
		return m_size;
	}

	T& operator[](size_t index)
	{
		if (index >= m_size)
			throw out_of_range("Index out of range");
		return m_data[index];
	}


private:
	T* m_data;
	size_t m_capacity;
	size_t m_size;
};