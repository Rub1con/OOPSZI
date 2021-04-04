#pragma once
#include "iostream"

using namespace std;

class Stack
{
	int *arr;
	int size;

public:
	void insertBefore(const int& value, int index);
	Stack();
	Stack(int count);
	Stack(const Stack& other);
	Stack(Stack&& other);
	~Stack();
	int GetSize() const;
	void Push(const int &element);
	void Pop();
	int Peek(const int& number);
	bool CheckNoEmptyStack();
	Stack& operator=(const Stack& other);
	Stack& operator=(Stack&& other);
	friend ostream& operator << (ostream& stream, const Stack& a);
};

