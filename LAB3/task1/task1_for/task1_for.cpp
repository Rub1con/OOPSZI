#include <iostream>

using namespace std;

double sum(int n)
{
    double sum1 = 0;

    for (int i = 0; i < n; ++i) {
        sum1 += pow(-1, i) * 1 / ((i + 1) * (i + 2) * (i + 3));
    }
    return sum1;
}

void main(int n)
{
    double res;
    cout << "n=";
    cin >> n;
    res = sum(n);
    cout << res;

}