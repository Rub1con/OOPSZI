#include <iostream>

using namespace std;

int findFirstElement(double eps)
{   
    int k;
    double sum1 = 0;

    for (int i = 0;; i++) {
        k = i;
        sum1 = pow(-1, i) * 1 / ((i + 1) * (i + 2) * (i + 3));
        if (abs(sum1) <= eps) break;
    }
    return k;
}

void main(double eps)
{
    double res;
    cout << "eps=";
    cin >> eps;
    res = findFirstElement(eps);
    cout << res;
    system("pause");

}