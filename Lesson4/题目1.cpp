#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x;
    string week[7] = { "Monday", "Tuesday" ,"Wednesday" ,"Thursday" ,"Friday" ,"Saturday" ,"Sunday" };
    cin >> x;
    cout << week[x - 1];
    return 0;
}
