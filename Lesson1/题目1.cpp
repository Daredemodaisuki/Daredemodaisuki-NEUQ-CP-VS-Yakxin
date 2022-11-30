// 
// 【问题描述】
// 从键盘输入三个整数，分别存入x, y, z三个整型变量中，计算并输出三个数的和以及平均值。
// 【输入形式】
// 从键盘输入三个整数，整数之间以空格隔开。
// 【输出形式】
// 在屏幕上分两行显示结果：
// 第一行为三个数的和，整数形式输出；
// 第二行为三个数的平均值，浮点数形式输出，小数点后保留两位小数。
// CE2203汤迪森202219224©2022

#include <iostream>
#include <iomanip>

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z ; //输入xyz的值
    std::cout << x+y+z << std::endl << std::setiosflags(std::ios::fixed) << std::setprecision(2) << (double)(x+y+z)/3; //输出和和平均值
}