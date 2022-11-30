#include <iostream>
using namespace std;

int main()
{
    int i, j;
    int x[100];
    for (i = 0; i < 100; i++) x[i] = i + 1;
    for (i = 0; i < 100; i++)
    {
        x[0] = 0;
        for (j = 0; j < i - 1; j++)
        {
            if (x[j] != 0 && x[i] % x[j] == 0)
                x[i] = 0;
        }
    }
    for (i = 0; i < 100; i++)
    {
        if (x[i] != 0)
        {
            if (x[i] != 2) cout << " ";
            cout << x[i];
        }
    }
    return 0;
}