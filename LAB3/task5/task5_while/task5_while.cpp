#include <iostream>

using namespace std;

int findFirstNegativeElement(double eps)
{
    int i = 0;
    int k = 0;
    double sum1 = pow(-1, i) * 1 / ((i + 1) * (i + 2) * (i + 3));

    while (true) {
        i++;
        sum1 = pow(-1, i) * 1 / ((i + 1) * (i + 2) * (i + 3));
        if (sum1 > 0) continue;
        k = i;
        if (abs(sum1) <= eps) {
            return k;
        }
    }
}

void main(double eps)
{
    double res;
    cout << "eps=";
    cin >> eps;
    res = findFirstNegativeElement(eps);
    cout << res;
    system("pause");

}