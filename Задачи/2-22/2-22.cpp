#include <iostream>
#include <cmath>
int main()
{
    setlocale(LC_ALL, "Rus");
    float s, n, dl, max, number, count = 1;
    std::cout << "������� �����: " << std::endl;
    std::cin >> n;
    std::cout << "������� ����� ������������������: " << std::endl;
    std::cin >> dl;
    s = sin(n + 1 / n);
    s = round(s * 1000) / 1000;
    max = s;
    number = 1;
    for (int i = 2; i <= dl; i++)
    {
        s = sin(n + i / n);
        s = round(s * 1000) / 1000;
        if (s > max)
        {
            number = count;
            max = s;
        }
        count++;
    }
    std::cout << "������������ ������� � ��� ����� �����: " << max << " " << number << std::endl;
}
}