#include <iostream>
using namespace std;
int main()
{
    int n, s, max = 0;
    cout << "Введите количество чисел" << endl;
    cin >> n;
    cout << "Введите последовательность чисел" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s > max)
        {
            max = s;
        }
    } cout << "Наибольшее число равно " << max << endl;
    return 0;
}