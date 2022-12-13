#include <iostream>
int main()
{
    setlocale(LC_ALL, "Rus");

    int s, sfact = 1, i = 1;
    int* n, * pi = &i;

    std::cout << "Введите число: " << std::endl;
    std::cin >> s;
    n = &s;

    while (*pi <= *n)
    {
        sfact *= *pi;
        i++;
    }
    std::cout << "Факториал равен: " << sfact << std::endl;
}