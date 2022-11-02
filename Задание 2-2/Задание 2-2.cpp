#include <iostream>
using namespace std;

int main()
{
    int n; int proizv;
    proizv=1;
    cout<<"Введите значение n>0"<<endl;
    cin >> n;

    if (n <= 0)
    {
        cout << "Невозможно посчитать произведение натуральных чисел при n <= 0" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            proizv *= i;
        }
        cout << proizv << endl;
    }

}