#include <iostream>
#include <math.h>

using namespace std;

int main()
{

begin:

    int n;

    char star = '*';

    cout << "??????? ??????????? ????? N, ?????????? ????????? ??????-???? ????? (? ????????? ?????? ????? ?????????? ? ??????? ??????? ?? ?????????? ????????)" << endl;
    cin >> n;

    int n1 = n; int a;

    if (n1 < 3)
    {
        cout << "??????? ???????? ????? N";
        goto begin;
    }
    else
    {
        cout << "??????? ?:" << endl;
        a = sqrt(n1);
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= a; j++)
            {
                cout << star;
                if (j == a)
                {
                    cout << endl;
                }
            }

        }
    }

    cout << endl << "??????? ?:" << endl;

    int n2 = n;

    for (int i = 1; i <= n2; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            cout << star;
            if (j == n2)
            {
                cout << endl;
            }
        }
    }

    cout << endl << "??????? ?:" << endl;

    int n3 = n;

    char space = ' ';

    for (int i = 1; i <= n3; i++)
    {
        if ((i == 1) or (i == n3))
        {
            for (int j = 1; j <= n3; j++)
            {
                cout << star;

                if (j == n3)
                {
                    cout << endl;
                }
            }
        }
        else
        {
            cout << star;
            for (int j = 1; j <= n3 - 2; j++)
            {
                cout << space;
            }
            cout << star << endl;
        }

    }
}