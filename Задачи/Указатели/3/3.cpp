#include <iostream>
int main()
{
    setlocale(LC_ALL, "Rus");

    float s, n;
    float* pointer1, * pointer2;

    std::cout << "������� ������ �����: " << std::endl;
    std::cin >> s;
    pointer1 = &s;
    std::cout << "������� ������ �����: " << std::endl;
    std::cin >> n;
    pointer2 = &n;

    std::cout << "����� ���� �����: " << *pointer1 + *pointer2 << std::endl;
}