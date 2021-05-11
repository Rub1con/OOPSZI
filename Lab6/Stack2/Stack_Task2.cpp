#include <iostream>
#include "Stack2.cpp"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    StackTemp<int>* a = new StackTemp<int>;
    StackTemp<int>* aclass;
    a->Push(1);
    a->Push(2);
    a->Push(3);
    a->Push(4);
    cout << "Stack: " << *a << endl;
    cout << "Back = " << a->Peek() << endl;
    cout << "Size = " << a->GetSize() << endl;
    a->Pop();
    cout << "PopBackStack: " << *a << endl;
    aclass = a;
    cout << "New Aclass = " << *aclass << endl;
    system("pause");
}
