#include <iostream>

using namespace std;

double sum2(double eps)
{
    double sum1 = 0;

    for (int i = 0;; i++) {
        sum1 += pow(-1, i) * 1 / ((i + 1) * (i + 2) * (i + 3));
        if (abs(sum1) <= eps) break;
    }
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