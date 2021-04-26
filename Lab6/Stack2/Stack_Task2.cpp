#include <iostream>
#include "Stack2.cpp"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    StackTemp<int>* a = new StackTemp<int>;
    StackTemp<int>* aclass;
    a->PushBack(1);
    a->PushBack(2);
    a->PushBack(3);
    a->PushBack(4);
    cout << "Stack: " << *a << endl;
    cout << "Back = " << a->PeekBack() << endl;
    cout << "Size = " << a->GetSize() << endl;
    a->PopBack();
    cout << "PopBackStack: " << *a << endl;
    aclass = a;
    cout << "New Aclass = " << *aclass << endl;
    system("pause");
}
