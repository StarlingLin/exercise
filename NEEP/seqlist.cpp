#include <cstdlib>

class SeqList
{
  private:
    int* data;
    int size;
    int capacity;

  private:
    void CheckCapacity();

  public:
    SeqList();
    ~SeqList();
    bool ListInsert(int index, int value);
    bool ListDelete(int index);
    int LocateElem(int value);
    int GetElem(int index);
    int Length();
    void Empty();
};

SeqList::SeqList()
{
    size = capacity = 0;
    data = nullptr;
}

SeqList::~SeqList()
{
    delete[] data;
    size = capacity = 0;
}

bool SeqList::ListInsert(int index, int value)
{
    if (index < 0 || index > size) return false;
    CheckCapacity();
    for (int i = size; i > index; --i) data[i] = data[i - 1];
    data[index] = value;
    ++size;
    return true;
}

bool SeqList::ListDelete(int index)
{
    if (index < 0 || index >= size) return false;
    for (int i = index; i < size - 1; ++i) data[i] = data[i + 1];
    --size;
    return true;
}

int SeqList::LocateElem(int value)
{
    for (int i = 0; i < size; i++)
        if (data[i] == value) return i;
    return -1;
}

int SeqList::GetElem(int index)
{
    if (index < 0 || index >= size) exit(EXIT_FAILURE);
    return data[index];
}

void SeqList::CheckCapacity()
{
    if (capacity == size)
    {
        int newCapa = (capacity == 0) ? 4 : capacity * 2;
        int* p = data;
        data = new int[newCapa];
        for (int i = 0; i < size; i++) data[i] = p[i];
        capacity = newCapa;
        delete[] p;
    }
}

int SeqList::Length()
{
    return size;
}

void SeqList::Empty()
{
    size = 0;
}