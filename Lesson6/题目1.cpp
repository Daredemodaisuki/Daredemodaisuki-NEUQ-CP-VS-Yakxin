/*实验六 类和对象

实验目的：
掌握类的概念与声明；
掌握对象的定义、初始化方法；
掌握构造函数、析构函数的作用与定义方法；
掌握通过对象名调用成员函数；
掌握对象数组;
培养运用新方法解决问题的能力，进而培养工匠精神，能够适应持续的环境变化与技术变革。*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
private:
    int num;
    string name;
    int grade[3];

    int sum;
    double averange;

public:
    Student(int stu_num = 0, string stu_name = "未定义", int stu_grade0 = 0, int stu_grade1 = 0, int stu_grade2 = 0);
    bool operator>(Student studentB);
    bool operator==(Student studentB);

    double get_averange();
    void display();
};

bool Student::operator>(Student studentB)
{
    if (averange > studentB.averange) return true;
    else return false;
}

bool Student::operator==(Student studentB)
{
    if (averange == studentB.averange) return true;
    else return false;
}

Student::Student(int stu_num, string stu_name, int stu_grade0, int stu_grade1, int stu_grade2)
{
    int i = 0;
    num = stu_num;
    name = stu_name;
    int* stu_grade = &stu_grade0;
    for (i = 0, sum = 0; i < 3; i++)
    {
        grade[i] = *stu_grade;
        sum += grade[i];
        stu_grade += 2;
    }
    /*grade[0] = stu_grade0;
    grade[1] = stu_grade1;
    grade[2] = stu_grade2;*/
    for (i = 0, sum = 0; i < 3; i++) sum += grade[i];
    averange = (double)(sum) / 3;
}

double Student::get_averange()
{
    return averange;
}

void Student::display()
{
    cout << num << " " << name << " " << sum << " " << setiosflags(ios::fixed) << setprecision(2) << averange << endl;
}

int main()
{
    int n, i;
    int num;
    string name;
    int grade[3];
    Student max_ave = Student();
    cin >> n;
    Student* students = new Student[n];
    for (i = 0; i < n; i++)
    {
        cin >> num >> name >> grade[0] >> grade[1] >> grade[2];
        students[i] = Student(num, name, grade[0], grade[1], grade[2]);
        if (students[i] > max_ave) max_ave = students[i];
    }
    for (i = 0; i < n; i++)
    {
        if (students[i] == max_ave) students[i].display();
    }
    delete[] students;
    return 0;
}