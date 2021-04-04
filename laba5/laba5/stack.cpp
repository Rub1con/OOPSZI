#include "stack.h"

Stack::Stack() : size(0), arr(nullptr) {}

/*Stack::Stack(int count)
{
	if (count > 0) {
		size = count;
		arr = new int[count];
	} else {
		arr = nullptr;
		size = 0;
	}
} */

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

void Stack::insertBefore(const int &value, int index)
{

	int* data = new int[size + 1];

	for (int before = 0; before < index; ++before)
		data[before] = arr[before];

	data[index] = value;

	for (int after = index; after < size; ++after)
		data[after + 1] = arr[after];

	delete[] arr;
	arr = data;
	++size;

}

void Stack::Push(const int& element)
{
	insertBefore(element, size);
}

void Stack::Pop()
{
	if (size > 0)
	{
		--size;
		int *data = new int[size];
		for (int i = 0; i < size; ++i)
			data[i] = arr[i];

		delete[] arr;
		arr = data;

	}
}

int Stack::Peek(const int &number) 
{	
	if (number <= size) {
		return arr[number - 1];
	} else {
		cout << "Element not found" << endl;
	}
}


bool Stack::CheckNoEmptyStack()
{
	return (size > 0);
}

ostream& operator << (ostream& stream, const Stack& a)
{
	for (int i = 0; i < a.size; ++i)
		cout << a.arr[i] << " ";
	return stream;
}