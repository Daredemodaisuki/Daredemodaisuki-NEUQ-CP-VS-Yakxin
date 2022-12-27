#include <iostream>
#include <fstream>
using namespace std;

void fun1()
{
    int i, num[20]{};
    fstream intxt("D:\\学习用\\2 - C++\\实验课8\\题目1\\x64\\Debug\\in.txt", ios::in);
    fstream txt[2] = {
        fstream("D:\\学习用\\2 - C++\\实验课8\\题目1\\x64\\Debug\\1.txt", ios::out),
        fstream("D:\\学习用\\2 - C++\\实验课8\\题目1\\x64\\Debug\\2.txt", ios::out)
    };
    for (i = 0; i < 20; i++)
    {
        intxt >> num[i];
        txt[i / 10] << num[i] << " ";
    }
    intxt.close();
    for (i = 0; i < 2; i++) txt[i].close();
    cout << "操作1完成" << endl;
}

void fun2()
{
    int i, num1[2][10]{};
    fstream txt1[2] = {
        fstream("D:\\学习用\\2 - C++\\实验课8\\题目1\\x64\\Debug\\1.txt", ios::in),
        fstream("D:\\学习用\\2 - C++\\实验课8\\题目1\\x64\\Debug\\2.txt", ios::in)
    };
    for (i = 0; i < 10; i++)
    {
        txt1[0] >> num1[1][i];
        txt1[1] >> num1[0][i];
    }
    for (i = 0; i < 2; i++) txt1[i].close();
 
    fstream outtxt("D:\\学习用\\2 - C++\\实验课8\\题目1\\x64\\Debug\\2.txt", ios::out);
    for (i = 0; i < 20; i++)
    {
        outtxt << num1[i / 10][i % 10] << " ";
    }
    outtxt.close();
    cout << "操作2完成" << endl;
}

void fun3()
{
    fstream txt2("D:\\学习用\\2 - C++\\实验课8\\题目1\\x64\\Debug\\2.txt", ios::in);
    int i, j, temp, num2[20]{};
    for (i = 0; i < 20; i++) txt2 >> num2[i];
    txt2.close();
    
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20 - i; j++)
        {
            if (num2[j] > num2[19 - i])
            {
                temp = num2[j];
                num2[j] = num2[19 - i];
                num2[19 - i] = temp;
            }
        }
    }
    fstream txt3("D:\\学习用\\2 - C++\\实验课8\\题目1\\x64\\Debug\\2.txt", ios::out);
    for (i = 0; i < 20; i++) txt3 << num2[i] << " ";
    txt3.close();
    cout << "操作3完成" << endl;
}

int main()
{
    fun1();
    fun2();
    fun3();
    return 0;
}