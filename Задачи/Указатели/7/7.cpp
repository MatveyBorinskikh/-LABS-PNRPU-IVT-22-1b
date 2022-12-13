#include <iostream>
int main()
{
    setlocale(LC_ALL, "Rus");

    int s = 0;
    int* x = &s;

    std::cout << "Введите переменную: " << std::endl;
    std::cin >> s;

    std::cout << "Введите новое значение: " << std::endl;
    std::cin >> s;
    std::cout << "Новое значение: " << *x << std::endl;
}