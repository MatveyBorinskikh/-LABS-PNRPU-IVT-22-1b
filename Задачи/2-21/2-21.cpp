#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");

    float chislo = 1, proshloe;
    bool flag = true, flagjokDlyaProshlogoChisla = true;

    std::cout << "������� �����, ���� ���������� �������� ������������������, ������� '0': " << std::endl;

    while (chislo != 0)
    {
        std::cin >> chislo;

        if (flagjokDlyaProshlogoChisla)
        {
            flagjokDlyaProshlogoChisla = false;
            proshloe = chislo;
        }

        if ((chislo < proshloe) && (chislo != 0))
        {
            flag = false;
        }

        proshloe = chislo;
    }

    if (flag)
    {
        std::cout << "����� ����������� �� �����������" << std::endl;
    }
    else
    {
        std::cout << "����� �� ����������� �� �����������" << std::endl;
    }
}