#include <iostream>
using namespace std;

int main()
{
    int sum(int x); //声明
    int mun; //mun=输入数字
    cin >> mun;
    cout << sum(mun);
}

int sum(int x)
{
    int k, i, pwr_10 = 1, sum = 0; //mun=输入数字，k=计次变量，i=位数，pwr_10=10的幂，sum=各数和

    if (x < 10) i = 1; //判断mun的位数
    else for (i = 0; x % pwr_10 != x; i++) pwr_10 *= 10;

    for (k = 1, pwr_10=1; k <= i; k++) //取各位求和
    {
        sum += (x % (pwr_10 * 10) - x % pwr_10) / pwr_10;
        pwr_10 *= 10;
    }
    return sum;
}