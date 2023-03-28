#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    int k = 0, j = 0;
    char f2[255], f3[255], * p;
    ifstream f("F1.txt");
    ofstream f1("F2.txt");

    while (f)
    {
        f.getline(f2, 255);
        k++;
        if (k > 3)
        {
            f1 << f2 << "\n";
        }
        //cout<<f2<<"\n";
    }
    ifstream p1("F1.txt");
    while (p1)
    {
        p1.getline(f3, 255);
        j++;
        if (j == k - 1)
        {
            cout << f3 << "\n";

            p = strtok(f3, " ");
            cout << p;
        }
    }

    f.close();
    f1.close();
    p1.close();


    ifstream f4("F2.txt");
    char ch;
    int amount = 0;
    int last_word = 0;
    while (f4)
    {
        f4.get(ch);
        if (ch == ' ' || ch == '\t' || ch == '\n')
        {
            if (amount > 0)
            {
                last_word = amount;
            }
            amount = 0;
        }
        else
            amount++;
    }

    if (amount > 0)
        last_word = amount;

    f4.close();

    cout << endl;
    cout << "Last word have " << last_word << " symbols" << endl;

    system("pause");


    return 0;
}