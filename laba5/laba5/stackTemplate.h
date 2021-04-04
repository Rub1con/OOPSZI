#pragma once
#include "iostream"

using namespace std;

template <typename T>
class StackTemplate
{
	T *arr;
	int size;

public:
	StackTemplate();
	StackTemplate(int count);
	StackTemplate(const StackTemplate& other);
	StackTemplate(StackTemplate&& other);
	~StackTemplate();
	int GetSize() const;
	void Push(const T& element);
	T Pop();
	T Peek();
	bool CheckNoEmptyStack();
	StackTemplate& operator=(const StackTemplate& other);
	StackTemplate& operator=(StackTemplate&& other);
	friend ostream& operator << (ostream& stream, const StackTemplate<T> &a);
	void insertBefore(const T& value, int index);
	void printArray();
};