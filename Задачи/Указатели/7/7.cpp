#include <iostream>
int main()
{
    setlocale(LC_ALL, "Rus");

    int s = 0;
    int* x = &s;

    std::cout << "������� ����������: " << std::endl;
    std::cin >> s;

    std::cout << "������� ����� ��������: " << std::endl;
    std::cin >> s;
    std::cout << "����� ��������: " << *x << std::endl;
}