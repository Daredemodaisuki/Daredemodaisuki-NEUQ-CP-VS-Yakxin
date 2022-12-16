#include <iostream>
using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};

int get_datepoint(Date date);
bool if_run(int year);

int main()
{
	Date start_day{},end_day{};
	cin >> start_day.year >> start_day.month >> start_day.day >> end_day.year >> end_day.month >> end_day.day;
	int start_daypoint, end_daypoint;
	start_daypoint = get_datepoint(start_day);
	end_daypoint = get_datepoint(end_day);
  	cout << end_daypoint - start_daypoint;
	return 0;
}

bool if_run(int year)
{
	if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) return false; //0
	else return true; //1
}

int get_datepoint(Date date) //以2000年1月1日为0的日期戳
{
	int y_diff = 0, d_diff = 0; //年月日的差值
	if (date.year < 2000)
	{
		y_diff = 1999 - date.year;
		switch (date.month)
		{
		case 1: d_diff = 334 + if_run(date.year) + 32 - date.day; break; //闰年加1天
		case 2: d_diff = 306 + if_run(date.year) + 29 - date.day; break; //闰年加1天
		case 3: d_diff = 275 + 32 - date.day; break;
		case 4: d_diff = 245 + 31 - date.day; break;
		case 5: d_diff = 214 + 32 - date.day; break;
		case 6: d_diff = 184 + 31 - date.day; break;
		case 7: d_diff = 153 + 32 - date.day; break;
		case 8: d_diff = 122 + 32 - date.day; break;
		case 9: d_diff = 92 + 31 - date.day; break;
		case 10: d_diff = 61 + 32 - date.day; break;
		case 11: d_diff = 31 + 31 - date.day; break;
		case 12: d_diff = 0 + 32 - date.day; break;
		};
		return -(y_diff * 365 + (y_diff / 4) + d_diff);
	}
	else
	{
		y_diff = date.year - 2000;
		switch (date.month)
		{
		case 1: d_diff = 0 + date.day; break;
		case 2: d_diff = 31 + date.day; break;
		case 3: d_diff = 59 + if_run(date.year) + date.day; break;
		case 4: d_diff = 90 + if_run(date.year) + date.day; break;
		case 5: d_diff = 120 + if_run(date.year) + date.day; break;
		case 6: d_diff = 151 + if_run(date.year) + date.day; break;
		case 7: d_diff = 181 + if_run(date.year) + date.day; break;
		case 8: d_diff = 212 + if_run(date.year) + date.day; break;
		case 9: d_diff = 243 + if_run(date.year) + date.day; break;
		case 10: d_diff = 273 + if_run(date.year) + date.day; break;
		case 11: d_diff = 304 + if_run(date.year) + date.day; break;
		case 12: d_diff = 334 + if_run(date.year) + date.day; break;
		};
		return y_diff * 365 + ((y_diff - 1) / 4) + d_diff - 1; //20000101的日期戳是0
	}
}