#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");

    int s, n, kostyl;

    int* pointer1, * pointer2;

    std::cout << "������� ������ ����������: " << std::endl;
    std::cin >> s;
    pointer1 = &s;
    std::cout << "������� ������ ����������: " << std::endl;
    std::cin >> kostyl;
    pointer2 = &kostyl;

    n = *pointer1;
    s = *pointer2;

    std::cout << "������ ���������� ���������� ��: " << s << std::endl;
    std::cout << "������ ���������� ���������� ��: " << n << std::endl;
}