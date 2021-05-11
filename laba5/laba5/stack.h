#pragma once
#include "iostream"

using namespace std;

class Stack
{
	int *arr;
	int size;
	int lastnum;

public:
	Stack(int size);
	Stack(const Stack& other);
	Stack(Stack&& other);
	~Stack();
	int GetSize() const;
	void Push(const int& element);
	void Pop();
	int Peek() const;
	bool CheckNoEmptyStack() const;
	Stack& operator=(const Stack& other);
	Stack& operator=(Stack&& other);
	friend ostream& operator << (ostream& stream, const Stack& a);
};