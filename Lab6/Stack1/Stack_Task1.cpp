#include <iostream>
#include "Stack.cpp"
using namespace std;
int main()
{
	int arr, pos, element;
	cout << "Stack Length = ";
	cin >> arr;
	StackTemp<int> a(arr);
	while (a.GetSize() < arr)
	{
		cout << "Element " << a.GetSize() + 1 << " / " << arr << ": ";
		cin >> element;
		a.PushBack(element);
	}
	cout << endl << "Stack: " << a << endl;
	system("pause");
	while (true)
	{
		cout << "Action list:" << endl << "1. Peek" << endl <<  "2. Pop" << endl << "3. Exit" << endl;
		cin >> pos;
		switch (pos)
		{
		case 1:
		{
			cout << a.PeekBack() << endl;
			break;
		}
		case 2:
		{
			a.PopBack();
			cout << endl << "Stack: " << a << endl;
			break;
		}
		case 3:
		{
			return 0;
		}
		default:
		{
			cout << "Error. Selected Item not exist.";
		}
		}
	}
}

