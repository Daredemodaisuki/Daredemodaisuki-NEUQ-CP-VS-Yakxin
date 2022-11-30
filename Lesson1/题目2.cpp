// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//【问题描述】
// 编写一个程序，当用户输入一个小数（正值浮点数）后，将小数转化为最近的整数输出（四舍五入）。
// 【输入形式】
// 用户在第一行输入一个小数
// 【输出形式】
// 用户在下一行显示输出结果

#include <iostream>
using namespace std;

int main()
{
    float x;
    cin >> x;
    if (x - (int)x < 0.5) cout << (int)x;
    else cout << (int)x+1;
    return 0;
}