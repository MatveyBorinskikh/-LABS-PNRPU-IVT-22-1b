#include <iostream>
int main()
{
    setlocale(LC_ALL, "Rus");
    int n, max, min, dl;

    int* pointer;

    std::cout << "������� ����� ������������������: " << std::endl;
    std::cin >> dl;

    std::cout << "������� �����" << std::endl;
    std::cin >> n;
    pointer = &n;

    max = *pointer;
    min = *pointer;

    for (int i = 1; i <= dl - 1; i++)
    {
        std::cin >> n;
        pointer = &n;

        if (*pointer > max)
        {
            max = *pointer;
        }

        if (*pointer < min)
        {
            min = *pointer;
        }
    }
    std::cout << "������������ ����� � ������������������: " << max << std::endl;
    std::cout << "����������� ����� � ������������������: " << min << std::endl;
}