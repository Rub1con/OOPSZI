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