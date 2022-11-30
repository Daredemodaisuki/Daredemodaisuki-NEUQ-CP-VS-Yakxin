// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//【问题描述】
// 假设税前工资和税率如下（s代表税前工资，t代表税率）：
// s < 1000    t = 0 %
//     1000 <= s < 2000     t = 10 %
//     2000 <= s < 3000     t = 15 %
//     3000 <= s < 4000     t = 20 %
//     4000 <= s            t = 25 %
//     编写一程序，要求用户输入税前工资额，然后用switch语句计算税后工资额。
// 【输入形式】
// 从键盘输入税前工资s，可以是浮点数。
// 【输出形式】
// 输出税后工资额，保留小数后两位。

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float s,f=0;
    cin >> s;
    if (s < 1000) f = 0;
    else if (s >= 1000 && s < 2000) f = s * 0.1;
    else if (s >= 2000 && s < 3000) f = s * 0.15;
    else if (s >= 3000 && s < 4000) f = s * 0.2;
    else f = s * 0.25;
    cout << setiosflags(ios::fixed) << setprecision(2) << s - f;
}