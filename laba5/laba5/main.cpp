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
		int arr, element, num;
		cout << "Stack length: ";
		cin >> arr;
		Stack s;
		do
		{
			cout << "Add Element: ";
			cin >> element;
			s.Push(element);

		} while ((s.GetSize()) < arr);
		cout << endl << "Stack: " << s << endl;
		cin >> num;
		cout << s.Peek(num) << endl;
	}
	else if (n == 2)
	{
		int arr, element, num;
		cout << "Stack length: ";
		cin >> arr;
		StackTemplate<int> s;
		do
		{
			cout << "Add Element: ";
			cin >> element;
			s.Push(element);

		} while ((s.GetSize()) < arr);
		cout << endl << "Stack: "; 
		s.printArray();
	}

	system("pause");
}