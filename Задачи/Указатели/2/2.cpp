#include <iostream>
int main()
{
    setlocale(LC_ALL, "Rus");

    int s, n;
    int* pointer1, * pointer2;

    std::cout << "¬ведите первое число: " << std::endl;
    std::cin >> s;
    pointer1 = &s;
    std::cout << "¬ведите второе число: " << std::endl;
    std::cin >> n;
    pointer2 = &n;

    std::cout << "—умма чисел: " << *pointer1 + *pointer2 << std::endl;
}