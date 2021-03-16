#include <iostream>

using namespace std;

double sum2(double eps)
{   
    int i = 0;
    double sum1 = pow(-1, i) * 1 / ((i + 1) * (i + 2) * (i + 3));;

    while (abs(sum1) >= eps)  {
        i++;
        sum1 = pow(-1, i) * 1 / ((i + 1) * (i + 2) * (i + 3));
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
    system("pause");

}