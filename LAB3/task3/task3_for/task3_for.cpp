#include <iostream>

using namespace std;

void print(int n, int k)
{
    double sum1 = 0;

    for (int i = 0; i < n; ++i) {
        
        if (i % k == k-1) continue;
        sum1 = pow(-1, i) * 1 / ((i + 1) * (i + 2) * (i + 3));
        cout << sum1 << endl;
    }
}

void main(int n, int k)
{
    double res;
    cout << "n=";
    cin >> n;
    cin >> k;
    print(n, k);

}