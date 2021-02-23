#include <iostream>

using namespace std;

double sum2(double eps)
{
    int i = 0;
    double sum1 = 0;
    do {
        sum1 += pow(-1, i) * 1 / ((i + 1) * (i + 2) * (i + 3));
        i++;
    } while (abs(sum1) >= eps);

    return sum1;
}

void main(double eps)
{
    double res;
    cout << "eps=";
    cin >> eps;
    res = sum2(eps);
    cout << res;

}