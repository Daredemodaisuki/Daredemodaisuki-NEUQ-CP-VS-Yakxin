#include <iostream>
using namespace std;

int main()
{
    int i;
    int in_put[5];
    for (i = 0; i < 5; i++) cin >> in_put[i];
    for (i = 0; i < 5; i++)
    {
        cout << in_put[4 - i];
        if (i < 4) cout << " ";
    }
    return 0;
}