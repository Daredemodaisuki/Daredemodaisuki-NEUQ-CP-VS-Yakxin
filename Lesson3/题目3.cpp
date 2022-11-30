#include <iostream>
using namespace std;

int main()
{
    bool ifexsist = false;
    int i, j, rmax = 0, rmax_p = 0, cmin = 0, cmin_p = 0;
    int table[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            cin >> table[i][j];
    }
    for (i = 0; i < 3; i++)
    {
        rmax = 0;//不归零会出错，例如1 2 4 8 3 1 9 6 6
        rmax_p = 0;
        for (j = 0; j < 3; j++)
        {
            if (table[i][j] >= rmax)
            {
                rmax = table[i][j];
                rmax_p = j;
            }
        }
        cmin = table[0][rmax_p];
        cmin_p = 0;
        for (j = 0; j < 3; j++)
        {
            if (table[j][rmax_p] <= cmin)
            {
                cmin = table[j][rmax_p];
                cmin_p = j;
            }
        }
        if (cmin_p == i)
        {
            cout << "Saddle point:a[" << i << "][" << rmax_p << "]=" << table[i][rmax_p];
            ifexsist = true;
        }
    }
    if (ifexsist == false) cout << "There is no saddle point";
    return 0;
}