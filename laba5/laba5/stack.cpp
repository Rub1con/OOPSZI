#include "stack.h"

Stack::Stack(int size) : size(size), arr(nullptr), lastnum(0) 
{
	arr = new int[size];
}

Stack::Stack(const Stack& other)
{
	arr = new int[other.size];
	size = other.size;
	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}

Stack::Stack(Stack&& other)
{
	arr = other.arr;
	size = other.size;
	other.arr = nullptr;
}

Stack::~Stack()
{
	delete[] arr;
}

Stack& Stack::operator=(const Stack& other)

{
	if (this == &other)
	{
		return *this;
	}
	delete[] arr;
	arr = new int[other.size];
	size = other.size;
	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}

Stack& Stack::operator=(Stack&& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] arr;
	arr = other.arr;
	size = other.size;
	other.arr = nullptr;
}

int Stack::GetSize() const
{
	return size;
}

void Stack::Push(const int& element)
{
	arr[lastnum] = element;
	lastnum++;
}

void Stack::Pop()
{	
	lastnum--;
	arr[lastnum] = 0;
}

int Stack::Peek()
{
	return arr[lastnum-1];
}


bool Stack::CheckNoEmptyStack()
{
	return (size > 0);
}

ostream& operator << (ostream& stream, const Stack& a)
{
	for (int i = 0; i < a.lastnum; ++i)
		cout << a.arr[i] << " ";
	return stream;
}