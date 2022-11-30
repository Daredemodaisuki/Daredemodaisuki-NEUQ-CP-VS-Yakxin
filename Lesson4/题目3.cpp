#include <iostream>
using namespace std;

char* insert(char* string, char c);
char* (*p) (char*, char);

int main()
{
    p = insert;
    char text[51]{}; //不初始化（{}）会输出烫烫烫...
    char putin;
    cin >> text >> putin;
    cout << p(text, putin);
    return 0;
}

char* insert(char* string, char c)
{
    int i=0, length=0, place=0; //place=插入位置，【如果在中间】则其后搬迁完毕后替换其【后面一个】成员
    while (string[length] != '\0') length++;

    if (string[0] > c)
    {
        place = 0; //在最前面
        for (i = 0; i < length; i++)
            string[length - i] = string[length - 1 - i];
        string[0] = c;
    }
    else if (string[length - 1] < c) //在最后面
    {
        place = length - 1;
        string[length] = c;
    }
    else  //在中间
    {
        for (i = 0; i < 49; i++) if (string[i] <= c && string[i + 1] >= c) place = i;
        for (i = 0; i < length - place - 1; i++)
            string[length - i] = string[length - 1 - i];
        string[place + 1] = c; //替换place【后面一个】元素（17行）
    }
    return string;
}