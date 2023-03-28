#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <fstream>
using namespace std;

struct student
{
    char fio[256];
    char address[256];
    int group;
    float rating;
};

void tabl()
{
    for (int z = 0; z < 40; z++)
    {
        cout << ' ';
    }
}

void print(student* s, int n)
{
    cout << '|' << ' ' << setw(30) << "ÔÈÎ";
    cout << '|' << ' ' << setw(40) << "Äîìàøíèé àäðåñ";
    cout << '|' << ' ' << setw(40) << "Ãðóïïà";
    cout << '|' << ' ' << setw(48) << "Ðåéòèíã" << '|';
    tabl();
    for (int i = 0; i < n; i++)
    {
        cout << '|' << ' ' << setw(30) << s[i].fio << '|';
        cout << ' ' << setw(40) << s[i].address << '|';
        cout << ' ' << setw(40) << s[i].group << '|';
        cout << ' ' << setw(48) << s[i].rating << '|';
        tabl();
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    student* s;
    int n, o;
    cout << "Ââåäèòå êîëè÷åñòâî ñòóäåíòîâ: ";
    cin >> n;
    s = new student[n];
    cout << "1.Ââîä ñ êëàâèàòóðû â êîíñîëüíîì ðåæèìå" << endl;
    cout << "2.Âûâîä íà ýêðàí â êîíñîëüíîì ðåæèìå" << endl;
    cout << "3.Ñîçäàòü ôàéë è çàïèñàòü â íåãî ñòðóêòóðèðîâàííûå äàííûå" << endl;
    cout << "4.Âûâåñòè ñîçäàííûé ôàéë íà ýêðàí" << endl;
    cout << "5.Óäàëèòü âñå ýëåìåíòû, ó êîòîðûõ ðåéòèíã ìåíüøå çàäàííîãî" << endl;
    cout << "6.Äîáàâèòü ýëåìåíò â êîíöå ôàéëà" << endl;
    cout << "7.Âûõîä" << endl;
    cout << "Âûáåðèòå íóæíûé âàì ïóíêò: ";
    while (true)
    {
        cout << endl;
        cin >> o;
        if (o == 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "Ââåäèòå ÔÈÎ ñòóäåíòà: ";
                cin.get();
                cin.getline(s[i].fio, 79);
                cout << "Ââåäèòå äîìàøíèé àäðåñ ñòóäåíòà: ";
                cin.getline(s[i].address, 79);
                cout << "Ââåäèòå ãðóïïó ñòóäåíòà: ";
                cin >> s[i].group;
                cout << "Ââåäèòå ðåéòèíã ñòóäåíòà: ";
                cin >> s[i].rating;
            }
        }
        if (o == 2)
        {
            print(s, n);
        }
        if (o == 3)
        {
            ofstream fp("test.txt");
            if (!fp.is_open())
            {
                cout << "Îøèáêà!" << endl;
                break;
            }
            for (int i = 0; i < n; i++)
            {
                fp << s[i].fio << ' ';
                fp << s[i].address << ' ';
                fp << s[i].group << ' ';
                fp << s[i].rating << ' ' << "\n";
            }
            fp.close();
        }
        if (o == 4)
        {
            ifstream fp("test.txt");

            if (!fp.is_open())
            {
                cout << "Îøèáêà!" << endl;
                break;
            }

            while (fp.peek() != EOF)
            {
                string str;
                getline(fp, str);
                cout << str << "\n";
            }
            fp.close();
        }
        if (o == 5)
        {
            ofstream fp("test.txt");
            ofstream fp2("temp.txt");
            float x;

            if (!fp.is_open())
            {
                cout << "Îøèáêà!" << endl;
                break;
            }

            cout << "Óäàëèòü èç ôàéëà ýëåìåíòû ðåéòèíã êîòîðûõ ìåíüøå: ";
            cin >> x;

            for (int i = 0; i < n; i++)
            {
                if (x < s[i].rating)
                {
                    fp2 << s[i].fio << ' ';
                    fp2 << s[i].address << ' ';
                    fp2 << s[i].group << ' ';
                    fp2 << s[i].rating << ' ' << "\n";
                }
            }
            fp.close();
            fp2.close();

            remove("test.txt");
            rename("temp.txt", "test.txt");
        }
        if (o == 6)
        {
            ofstream fp;
            fp.open("test.txt", ios::app);

            if (!fp.is_open())
            {
                cout << "Îøèáêà!" << endl;
                break;
            }

            student r;

            cout << "Ââåäèòå ÔÈÎ ñòóäåíòà: ";
            cin.get();
            cin.getline(r.fio, 79);
            cout << "Ââåäèòå äîìàøíèé àäðåñ ñòóäåíòà: ";
            cin.getline(r.address, 79);
            cout << "Ââåäèòå ãðóïïó ñòóäåíòà: ";
            cin >> r.group;
            cout << "Ââåäèòå ðåéòèíã ñòóäåíòà: ";
            cin >> r.rating;

            fp << r.fio << ' ';
            fp << r.address << ' ';
            fp << r.group << ' ';
            fp << r.rating << ' ' << '\n';

            fp.close();
        }
        if (o == 7)
        {
            break;
        }
    }
    delete[] s;
    return 0;
}