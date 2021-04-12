#pragma once
#include "iostream"

using namespace std;

template <typename T>
class StackTemplate
{
	T* arr;
	int size;
	int lastnum;

public:
	StackTemplate(int size);
	StackTemplate(const StackTemplate& other);
	StackTemplate(StackTemplate&& other);
	~StackTemplate();
	int GetSize() const;
	void Push(const T& element);
	void Pop();
	T Peek();
	bool CheckNoEmptyStack();
	StackTemplate& operator=(const StackTemplate& other);
	StackTemplate& operator=(StackTemplate&& other);
	template <typename T> friend ostream& operator << (ostream& stream, const StackTemplate<T>& a);
};