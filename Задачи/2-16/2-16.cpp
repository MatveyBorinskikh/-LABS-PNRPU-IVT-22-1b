#include <iostream>
using namespace std;
int main()
{
start:
    int n, s = 0;
    cout << "Vvedite do kakogo chisla >0" << endl;
    cin >> n;
    if (n <= 0)
    {
        goto start;
    }
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            s = s - i;
        }
        else
        {
            s = s + i;
        }
    } cout << s;
    return 0;
}