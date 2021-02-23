#include <iostream>

using namespace std;

double sum(int n)
{
    double sum1 = 0;
    int i = 0;
    while (i < n) {
        sum1 += pow(-1, i) * 1 / ((i + 1) * (i + 2) * (i + 3));
        i++;
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