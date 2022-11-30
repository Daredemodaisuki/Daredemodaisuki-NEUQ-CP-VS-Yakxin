#include <iostream>
using namespace std;
int i = 0;

int main()
{
    int step(int total, int n);
    int x;
    cin >> x;
    step(x, 1);
    if (x >= 2) step(x, 2);
    cout << i;
}

int step(int total, int n)
{
    if (total - n >= 2)
    {
        step(total - n, 1);
        step(total - n, 2);
    }
    else if (total - n == 1) step(total - n, 1);
    if (total - n == 0) i++;
    return total - n;
}