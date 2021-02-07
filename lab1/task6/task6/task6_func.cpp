#include <iostream>
#include "task6.h"

using namespace std;
double x;
double result;

void f(void) {

	result = (x * x + 2 * x - 3 + (x + 1) * sqrt(x * x - 9)) / (x * x - 2 * x - 3 + (x - 1) * sqrt(x * x - 9));

}