#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "¬ведите число N(натуральное)" << endl;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = 1;
        for (int j = 0; j <= i; j++)
        {
            k *= i + j;
        }
        sum += k;
    }

    cout << sum << endl;

    return 0;
}