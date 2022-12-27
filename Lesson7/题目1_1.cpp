#include <iostream>
#include <string.h>
using namespace std;

class Teacher //教师类
{
protected:
    string name;
    int age;
    string sex;
    string addr;
    string tel;
    string title;
public:
    Teacher(string t_name, int t_age, string t_sex, string t_addr, string t_tel, string t_title)
        :name(t_name), age(t_age), sex(t_sex), addr(t_addr), tel(t_tel), title(t_title) {};
};

class Cadre //干部类
{
protected:
    string name;
    int age;
    string sex;
    string addr;
    string tel;
    string post;
public:
    Cadre(string c_name, int c_age, string c_sex, string c_addr, string c_tel, string c_post)
        :name(c_name), age(c_age), sex(c_sex), addr(c_addr), tel(c_tel), post(c_post) {};
};

class Teacher_Cadre :public Teacher, public Cadre //教师兼干部类
{
private:
    int wages;
public:
    Teacher_Cadre(string tc_name = "Unnamed", int tc_age = 0, string tc_sex = "Other", string tc_addr = "Shimokitazawa", string tc_tel = "114514", string tc_title = "Untitled", string tc_post = "Undifined", int tc_wages = 0)
        :Teacher(tc_name, tc_age, tc_sex, tc_addr, tc_tel, tc_title), Cadre(tc_name, tc_age, tc_sex, tc_addr, tc_tel, tc_post), wages(tc_wages) {};
    void putin();
    void display();
};

void Teacher_Cadre::display()
{
    cout << Teacher::name << " " << Teacher::age << " " << Teacher::sex << " " << Teacher::title << " " << Teacher::addr << " " << Teacher::tel << " " << Cadre::post << " " << wages;
}

void Teacher_Cadre::putin()
{
    cin >> Teacher::name >> Teacher::age >> Teacher::sex >> Teacher::title >> Teacher::addr >> Teacher::tel >> Cadre::post >> wages;
    Cadre::age = Teacher::age;
    Cadre::sex = Teacher::sex;
    Cadre::addr = Teacher::addr;
    Cadre::tel = Teacher::tel;
}

int main()
{
    Teacher_Cadre person;
    person.putin();
    person.display();
    return 0;
}