#include <iostream>

using namespace std;

int findFirstElement(double eps)
{
    int i = 0;
    int k = 0;
    double sum1 = 0;
    do {
        sum1 = pow(-1, i) * 1 / ((i + 1) * (i + 2) * (i + 3));
        k = i;
        i++;
    } while (abs(sum1) >= eps);

    return k;
}

void main(double eps)
{
    double res;
    cout << "eps=";
    cin >> eps;
    res = findFirstElement(eps);
    cout << res;

}