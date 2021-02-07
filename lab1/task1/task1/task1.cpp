#include <iostream>
using namespace std;

void main(double f, double x) {
	x = 5;
	f = (x * x + 2 * x - 3 + (x + 1) * sqrt(x * x - 9)) / (x * x - 2 * x - 3 + (x - 1) * sqrt(x * x - 9));
	cout << f << endl;
	cin >> x;
	f = (x * x + 2 * x - 3 + (x + 1) * sqrt(x * x - 9)) / (x * x - 2 * x - 3 + (x - 1) * sqrt(x * x - 9));
	cout << f << endl;
	cin >> x;
}