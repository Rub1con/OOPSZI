#include <iostream>

using namespace std;

double x;
double result;
void f(void);

void main() {

	x = 13;

	f();

	cout << result << endl;

	cin >> x;

	f();

	cout << result;

	cin >> x;

}

void f(void) {

	result = (x * x + 2 * x - 3 + (x + 1) * sqrt(x * x - 9)) / (x * x - 2 * x - 3 + (x - 1) * sqrt(x * x - 9));

}






