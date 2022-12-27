#include <iostream>
#include <string.h>
using namespace std;

class Person //人类
{
protected:
    string name;
    int age;
    string sex;
    string addr;
    string tel;
public:
    Person(string p_name, int p_age, string p_sex, string p_addr, string p_tel)
        :name(p_name), age(p_age), sex(p_sex), addr(p_addr), tel(p_tel) {};
};

class Teacher :virtual public Person //教师类
{
protected:
    string title;
public:
    Teacher(string t_name, int t_age, string t_sex, string t_addr, string t_tel, string t_title)
        :Person(t_name, t_age, t_sex, t_addr, t_tel), title(t_title) {};
};

class Cadre :virtual public Person //干部类
{
protected:
    string post;
public:
    Cadre(string c_name, int c_age, string c_sex, string c_addr, string c_tel, string c_post)
        :Person(c_name, c_age, c_sex, c_addr, c_tel), post(c_post) {};
};

class Teacher_Cadre :public Teacher, public Cadre //教师兼干部类
{
private:
    int wages;
public:
    Teacher_Cadre(string tc_name = "Unnamed", int tc_age = 0, string tc_sex = "Other", string tc_addr = "Shimokitazawa", string tc_tel = "114514", string tc_title = "Untitled", string tc_post = "Undifined", int tc_wages = 0)
        :Person(tc_name, tc_age, tc_sex, tc_addr, tc_tel), Teacher(tc_name, tc_age, tc_sex, tc_addr, tc_tel, tc_title), Cadre(tc_name, tc_age, tc_sex, tc_addr, tc_tel, tc_post), wages(tc_wages) {};
    void putin();
    void display();
};

void Teacher_Cadre::display()
{
    cout << name << " " << age << " " << sex << " " << title << " " << addr << " " << tel << " " << post << " " << wages;
}

void Teacher_Cadre::putin()
{
    cin >> name >> age >> sex >> title >> addr >> tel >> post >> wages;
}

int main()
{
    Teacher_Cadre person;
    person.putin();
    person.display();
    return 0;
}