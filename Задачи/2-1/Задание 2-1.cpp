#include <iostream>
using namespace std;

int main()
{
    int n; int sum;
    sum=0;
    cout<<"Введите значение n>0"<<endl;
    cin >> n;

    if (n <= 0)
    {
        cout << "Невозможно посчитать сумму натуральных чисел при n <= 0" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }
        cout << sum << endl;
    }

}