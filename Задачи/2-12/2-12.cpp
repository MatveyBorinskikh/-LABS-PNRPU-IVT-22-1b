#include <iostream>
using namespace std;
int main()
{
    int n, num, min = 32767, max = -32768;
    cout << "¬ведите количество чисел в последовательности" << endl;
    cin >> n;
    cout << "¬ведите последовательность чисел" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num < min and num != 0)
        {
            min = num;
        }
        if (num > max and num > min)
        {
            max = num;
        }
    } cout << min + max;
    return 0;
}