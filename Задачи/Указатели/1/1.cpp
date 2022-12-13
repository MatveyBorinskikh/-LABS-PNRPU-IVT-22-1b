#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");

    int s, n, kostyl;

    int* pointer1, * pointer2;

    std::cout << "Введите первую переменную: " << std::endl;
    std::cin >> s;
    pointer1 = &s;
    std::cout << "Введите вторую переменную: " << std::endl;
    std::cin >> kostyl;
    pointer2 = &kostyl;

    n = *pointer1;
    s = *pointer2;

    std::cout << "Первая переменная поменялась на: " << s << std::endl;
    std::cout << "Вторая переменная поменялась на: " << n << std::endl;
}