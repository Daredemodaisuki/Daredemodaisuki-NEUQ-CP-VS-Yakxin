#include <iostream>
using namespace std;

int main()
{
    void str_bin(char str1[], char str2[], char s[]);
    char str1[100]{}, str2[100]{}, s[200]{};
    cin >> str1;
    cin >> str2;
    str_bin(str1, str2, s);
    return  0;
}

void str_bin(char str1[], char str2[], char s[])
{
    int i,j;
    char stemp = 0;
    char s1[200]{};
    for (i = 0; i < 100; i++) s1[i] = str1[i];
    for (i = 0; i < 100; i++) s1[i + 100] = str2[i];
    for (i = 0; i < 200; i++)
    {
        for (j = 0; j < 200 - i; j++)
        {
            if (s1[i + j] < s1[i])
            {
                stemp = s1[i + j];
                s1[i + j] = s1[i];
                s1[i] = stemp;
            }
        }
    }
    for (i = 0; i < 200; i++)
        if (s1[i] != 0 && (i != 0 && s1[i] != s1[i - 1]))
            cout << s1[i];
}