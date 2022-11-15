#include <iostream>
using namespace std;

int main()
{
start:
    int n, s, a;
    cout << "¬ведите число, а после цифру от 0 до 9, которую желаете встретить" << endl;
    cin >> n >> s;
    if (n <= 0 or s > 0 or s < 9)
    {
        goto start; // на ввод данных
    }
    else
    {
        while (n)
        {
            a = n % 10;
            if (s == a)
            {
                cout << "÷ифра входит в запись числа"; break;
            }
            else
            {
                n = n / 10;
            }
        }
        if (s = !n)
        {
            cout << "÷ифра не входит в запись числа";
        }
    }
    return 0;
}