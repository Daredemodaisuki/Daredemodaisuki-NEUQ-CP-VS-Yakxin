#include <iostream>
using namespace std;

int j = 0; //j=素数表元素数
int primetable[100];//prime_table[]=预设素数表
bool bignum = 0; //是否是大数
bool ifprime_table(int x);
bool isprime(int n);

bool isprime(int n)
{
    int i; 
    for (i = 1; i <= n; i++)
    {
        if (ifprime_table(i) == 1)
        {
            if (j < 100)
            {
                primetable[j] = i;
                j++;
            }
            else
            {
                bignum = 1;
                //cout << primetable[99] << " " << bignum << endl;
                break;
            }
        }
    }
    if (ifprime_table(n) == 1) return 1;
    else return 0;
}

bool ifprime_table(int x)
{
    int i,k;
    bool result=1;
    for (i = 0; i < j; i++)
    {
        if (x % primetable[i] == 0 && primetable[i] != 1 && x != primetable[i])
        {
            result = 0;
            break;
        }
    }
    //cout << result << " " << x << endl;
    if (bignum == 1 && result == 1)
    {
        for (k = 0; k < x - primetable[99] ; k++)
        {
            if (x % (primetable[99] + k) == 0)
            {
                result = 0;
                break;
            }
        }
    }
    return result;
}

int main()
{
    int num;
    cin >> num;
    cout << isprime(num);
    return 0;
}