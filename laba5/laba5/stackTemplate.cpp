#include "stackTemplate.h"

template <typename T>
StackTemplate<T>::StackTemplate(int size) : size(size), lastnum(0) 
{
	arr = new T[size];
}

template <typename T>
StackTemplate<T>::StackTemplate(const StackTemplate& other)
{
	arr = new T[other.size];
	size = other.size;
	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}

template <typename T>
StackTemplate<T>::StackTemplate(StackTemplate&& other)
{
	arr = other.arr;
	size = other.size;
	other.arr = nullptr;
}

template <typename T>
StackTemplate<T>::~StackTemplate()
{
	delete[] arr;
}

template <typename T>
StackTemplate<T>& StackTemplate<T>::operator=(const StackTemplate& other)

{
	if (this == &other)
	{
		return *this;
	}
	delete[] arr;
	arr = new T[other.size];
	size = other.size;
	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}

template <typename T>
StackTemplate<T>& StackTemplate<T>::operator=(StackTemplate&& other)
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

template <typename T>
int StackTemplate<T>::GetSize() const
{
	return size;
}

template <typename T>
void StackTemplate<T>::Push(const T& element)
{
	arr[lastnum] = element;
	lastnum++;
}

template <typename T>
void StackTemplate<T>::Pop()
{
	lastnum--;
	arr[lastnum] = 0;
}

template <typename T>
T StackTemplate<T>::Peek()
{
	return arr[lastnum - 1];
}

template <typename T>
bool StackTemplate<T>::CheckNoEmptyStack()
{
	return (size > 0);
}

template <typename T>
ostream& operator << (ostream& stream, const StackTemplate<T> &a)
{
	for (int i = 0; i < a.lastnum; ++i)
		cout << a.arr[i] << " ";
	return stream;
}