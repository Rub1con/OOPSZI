#include <iostream>
#include <locale.h>

using namespace std;

bool result;

bool isInArea(double x, double y) {

	if (x > 0 && y < 0) return false;

	else if (x < 0 && y > 0)  return true;

	else if (x <= y) return true;

	else return false;
	
}

void main(double x, double y)
{	
	setlocale(LC_ALL, "Rus");

	cout << "x:";
	cin >> x;

	cout << "y:";
	cin >> y;

	if (abs(x) <=1 && abs(y) <= 1) {

		result = isInArea(x, y);

		if (result == true) cout << "Точка попадает в заштрихованную область\n";

		else cout << "Точка НЕ попадает в заштрихованную область\n";

		cin >> x;

	}

	else cout << "Модуль числа должен быть меньше  или равен 1\n";
	
}

