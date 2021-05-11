#include <iostream>
using namespace std;
template<typename T>
class Base
{
public:
	virtual void Push(const T& element) = 0;
	virtual T Pop() = 0;
	virtual int GetSize() const = 0;
	virtual T Peek() const = 0;
	virtual ~Base() {}
};

template<typename T>
class StackTemp : Base<T>
{
	T* arr;
	int count;
	int end = 0, size = 0;

public:
	//инициализация
	StackTemp(int count)
		: count(count)
	{
		this->count = count;
		arr = new T[count];
	}
	//копирование
	StackTemp(const StackTemp& other)
	{
		arr = new T[other.count];
		count = other.count;
		end = other.end;
		size = other.size;
		for (int i = 0; i < count; ++i)
		{
			arr[i] = other.arr[i];
		}
	}

	//перемещение
	StackTemp(StackTemp&& other)
	{
		arr = other.arr;
		count = other.count;
		other.arr = nullptr;
	}
	//деструктор
	~StackTemp()
	{
		delete[] arr;
	}
	//присваивание
	StackTemp& operator=(const StackTemp& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] arr;
		arr = new T[other.count];
		count = other.count;
		for (int i = 0; i < count; ++i)
		{
			arr[i] = other.arr[i];
		}
	}
	//присваивание с перемещением
	StackTemp& operator=(StackTemp&& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] arr;
		arr = other.arr;
		count = other.count;
		other.arr = nullptr;
	}

	int GetSize() const
	{
		return this->size;
	}
	//Вставка элемента

	void Push(const T &element)
	{
		if (size <= count)
		{	
			arr[end] = element;
			end += 1;
			size++;
		}
	}
	//Удаление элемента

	T Pop()
	{
		if (size <= count)
		{
			arr[end] = 0;
			end--;
			size--;
			return 0;
		}
	}
	//Просмотр элемента

	T Peek() const
	{	
		return arr[end];
	}

	//Вывод

	friend ostream& operator<<(ostream& stream, StackTemp& a)
	{
		for (int i = 0; i < a.size; i++)
			stream << a.arr[i] << " ";
		return stream;
	}
};

