#include <iostream>
//#include <string>
using namespace std;

int main()
{

    int i = 0, j = 0, total_num = 0, length = 0;
    bool if_new_num = true;
    int* num = new int[0] {}; //申请2个数组空间
    int* temp = new int[0] {};

    /*
    char text[80]{};
    char now_type;
    now_type = getchar();
    while (now_type != '\n')
    {
        text[length] = now_type;
        length++;
        now_type = getchar();
    }
    */ //getchar方法直至换行才停止输入。

    char text[80]{};
    cin.getline(text, 80);
    while (text[length] != '\0') length++; //统计输入长度，不用单开计数变量，因为每次都读下一个，也就是当前最大值那个
    //getline法输入

    /*
    //string text; //如果没有空格，可以直接string
    //cin >> text; //如果没有空格，可以直接上cin
    //while (text[length] != '\0') length++; //统计输入长度，不用单开计数变量，因为每次都读下一个，也就是当前最大值那个
    */ //cin直接至string，前提是没有空格

    for (i = 0; i < length + 1; i++)
    {
        if (text[i] >= '0' && text[i] <= '9')
        {
            if (if_new_num == true) //如果是新的数字的开头，num删了并扩展1个元素重建
            {
                total_num++;
                int* temp = new int[total_num] {};
                for (j = 0; j < total_num - 1; j++) temp[j] = num[j];
                temp[total_num - 1] = 0;
                delete[] num;
                num = temp;
                //delete[] temp;
                //temp = NULL;//怪，temp不能删，但是可以NULL，删了就错
            }

            //cout << num[total_num - 1] << "=" << (text[i] - 48) << "+" << num[total_num - 1] << "*" << if_new_num << endl;
            num[total_num - 1] = (text[i] - 48) + num[total_num - 1] * 10;
            if_new_num = false;
        }
        else if_new_num = true;
    }

    if (total_num > 0)
    {
        cout << total_num << endl;
        cout << num[0];
        for (j = 1; j < total_num; j++)cout << " " << num[j];
    }
    else cout << "0";
    delete[] temp;
    delete[] num;

    return 0;
}