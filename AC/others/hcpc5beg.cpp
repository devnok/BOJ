#include <iostream>
#include <string>

using namespace std;

bool special;
int months[12] = {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3};
int num = 0;


int init(int year, int day)
{   special = false;
    if (year % 4 == 0)
    {
        special = true;
    }
    if (year % 100 == 0)
    {
        special = false;
    }
    if (year % 400 == 0)
    {
        special = true;
    }
    for (int i = 0; i < 2; i++)
    {
        if ((day + months[i]) % 7 == 5 ) {
            num++;
        }
    }
    if (special)
    {
        day += 1;
    }
    for (int i = 2; i < 12; i++)
    {
        if ((day + months[i]) % 7 == 5 ) {
            num++;
        }
    }
    return (day + 1) % 7;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int k;
    cin >> k;
    int j = 2;
    for (int i = 2019; i < k + 1; i++)
    {
        j = init(i, j);
        cout<<j<<endl;
    }
    cout << num << endl;
}