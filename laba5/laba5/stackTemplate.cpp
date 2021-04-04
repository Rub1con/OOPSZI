#include "stackTemplate.h"

template <typename T>
StackTemplate<T>::StackTemplate() : size(0), arr(nullptr) {}

/* template <typename T>
 Stack<T>::Stack(int count)
{
	if (count > 0) {
		size = count;
		arr = new T[count];
	}
	else {
		arr = nullptr;
		size = 0;
	}
} */

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
StackTemplate<T> & StackTemplate<T>::operator=(const StackTemplate& other)

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
StackTemplate<T> & StackTemplate<T>::operator=(StackTemplate&& other)
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
void StackTemplate<T>::insertBefore(const T& value, int index)
{

	int* data = new T[size + 1];

	for (int before = 0; before < index; ++before)
		data[before] = arr[before];

	data[index] = value;

	for (int after = index; after < size; ++after)
		data[after + 1] = arr[after];

	delete[] arr;
	arr = data;
	++size;

}

template <typename T>
void StackTemplate<T>::Push(const T& element)
{
	insertBefore(element, size);
}

template <typename T>
T StackTemplate<T>::Pop()
{
	if (size > 0)
	{
		--size;
		int* data = new int[size];
		for (int i = 0; i < size; ++i)
			data[i] = arr[i];

		delete[] arr;
		arr = data;
		return 0;
	}
}

template <typename T>
T StackTemplate<T>::Peek()
{	
	return arr[size - 1];
}

template <typename T>
bool StackTemplate<T>::CheckNoEmptyStack()
{
	return (size > 0);
}

template <typename T>
void StackTemplate<T>::printArray()
{
	int* data = new int[size];
	for (int i = 0; i < size; ++i) {
		data[i] = arr[i];
		cout << data[i] << " ";
	}
}