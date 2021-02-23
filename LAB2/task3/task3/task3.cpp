#include <iostream>
using namespace std;

int key;
int task;

bool isInArea(double x, double y) {
    if (x > 0 && y < 0) return false;
    else if (x < 0 && y > 0)  return true;
    else if (x <= y) return true;
    else return false;
}

double f(double x) {
    x <= 3? x = x * x + 3 * x + 9 : x = 1 / (pow(x, 3) + 6);
    return x;
}   

int main()
{
    char key;
    setlocale(LC_ALL, "RUS");
    cout << "Выберете нужное задание:\n1. Задание 1\n2. Задание 2" << endl;
    cin >> key;

    switch (key) {

    case'1': {

        bool result;
        double x, y;

        cout << "Задание 1:\n";
        cout << "x=";
        cin >> x;
        cout << "y=";
        cin >> y;

        if (abs(x) <= 1 && abs(y) <= 1) {
            result = isInArea(x, y);
            if (result == true) cout << "Точка попадает в заштрихованную область\n";
            else cout << "Точка НЕ попадает в заштрихованную область\n";
        }
        else cout << "Модуль числа должен быть меньше  или равен 1\n";

        break;
    }

    case'2': {

        double x, res;

        cout << "Задание 2:\n";
        cout << "x=";
        cin >> x;
        res = f(x);
        cout << "f(x)=" << res << endl;
    }
        break;

    default:

        cout << "Введено неверное число\n";

        break;

    }

    system("pause");

}
