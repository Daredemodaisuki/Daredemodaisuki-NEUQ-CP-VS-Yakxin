#include <iostream>
#include <string>
using namespace std;

struct Contact
{
	string name{};
	string tel{};
};

int main()
{
	Contact contact[50]{};
	string max_str = {}, temp_str = {};
	int num,i,j,max_str_pos;
	cin >> num;

	for (i = 0; i < num; i++) cin >> contact[i].name >> contact[i].tel;
	for (i = 0; i < num; i++)
	{
		max_str = contact[0].name;
		max_str_pos = 0;
		for (j = 0; j < num - i; j++)
		{
			if (contact[j].name > max_str)
			{
				max_str = contact[j].name;
				max_str_pos = j;
			}
		}
		temp_str = contact[max_str_pos].name;
		contact[max_str_pos].name = contact[num - 1 - i].name;
		contact[num - 1 - i].name = temp_str;
		temp_str = contact[max_str_pos].tel;
		contact[max_str_pos].tel = contact[num - 1 - i].tel;
		contact[num - 1 - i].tel = temp_str;
	}
	cout << endl;
	for (i = 0; i < num; i++)
	{
		printf("%12.10s", contact[i].name.c_str()); // 需要使用string.c_str()才能输出完整字符串
		printf("%12.10s", contact[i].tel.c_str());
		cout << endl;
	}
	return 0;
}