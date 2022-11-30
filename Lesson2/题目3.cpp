#include <iostream>
using namespace std;

int main()
{
    int fac(int n);
    int n;
    cin >> n;
    cout << fac(n);
    return 0;
}

int fac(int x)
{
    if (x > 1) return x * fac(x - 1);
    else return 1;
}