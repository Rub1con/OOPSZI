#include <iostream>

using namespace std;

void print(int n, int k)
{   
    int i = 0;
    double sum1 = 0;

    while (i < n) {
        sum1 = pow(-1, i) * 1 / ((i + 1) * (i + 2) * (i + 3));
        i++;
        if (i % k == 0) continue;
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

    system("pause");

}