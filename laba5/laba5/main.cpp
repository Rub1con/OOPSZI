#include <iostream>
#include "stack.h"
#include "stackTemplate.h"
#include "stackTemplate.cpp"
#include <string>

using namespace std;

int main()
{	
	int n;
	cout << "1-Stack, 2 - StackTemp: ";
	cin >> n;
	if (n == 1)
	{
		int element, num, size, counter = 0;
		cout << "Enter the array size: ";
		cin >> size;
		Stack s(size);
		do
		{	
			cout << "Enter the element: ";
			cin >> element;
			s.Push(element);
			counter++;
		}
		while (counter < s.GetSize());
		cout << "Array: " << s << endl;
		cout << "Peek: " << s.Peek() << endl;
		s.Pop(); cout << "Pop: " << s << endl;
		s.Push(2021); cout << "Push: " << s;
	}
	else if (n == 2)
	{	
		int element, num, size, counter = 0;
		cout << "Enter the array size: ";
		cin >> size;
		StackTemplate<int> s(size);
		do
		{
			cout << "Enter array element: ";
			cin >> element;
			s.Push(element);
			counter++;
		} 	
		while (counter < s.GetSize());
		cout << "Array: " << s << endl;
		cout << "Peek: " << s.Peek() << endl;
		s.Pop(); cout << "Pop: " << s << endl;
		s.Push(2021); cout << "Push: " << s;
	}

	system("pause");
}