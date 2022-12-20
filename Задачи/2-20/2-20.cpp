#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Rus");

    float x, n, dlina, s;
    bool flag = false;

    std::cout << "������� ����� n:" << std::endl;
    std::cin >> n;
    std::cout << "������� ����� ������������������:" << std::endl;
    std::cin >> dlina;
    std::cout << "������� ������� S, ��� �������� ����� ����������� ������� "
        "�������������� �������� �� ������������������:" << std::endl;
    std::cin >> s;

    while (dlina >= 1)
    {
        x = sin(n + dlina / n);
        x = round(x * 1000) / 1000; // ���������, ����� �������� ��������� �����

        if (x == s)
        {
            flag = true;
        }

        dlina--;
    }

    if (flag == true)
    {
        std::cout << "����� S ������������ � ������������������!" << std::endl;
    }
    else
    {
        std::cout << "����� S �� ������������ � ������������������!" << std::endl;
    }
}