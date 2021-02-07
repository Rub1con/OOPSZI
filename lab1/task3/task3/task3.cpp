#include <iostream>

using namespace std;

double f(double x);

void main(double x) {

	double result;

	x = 12;
	result = f(x);
	cout << result << endl;

	cin >> x;
	result = f(x);
	cout << result;

	cin >> x;
}


double f(double x) {

	double func;
	func = (x * x + 2 * x - 3 + (x + 1) * sqrt(x * x - 9)) / (x * x - 2 * x - 3 + (x - 1) * sqrt(x * x - 9));
	return func;
}



