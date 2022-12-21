#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Rus");

    float n, a, max;
    int i = 2;
    int count = 1;

    std::cout << "Введите n: " << std::endl;
    std::cin >> n;

    max = sin(n + 1 / n);

    while (i <= n)
    {
        a = sin(n + 1 / n);
        if (a > max)
        {
            max = a;
            count = 1;
        }
        else if (a == max)
        {
            count++;
        }
        i++;
    }

    std::cout << "Максимальный элемент: " << max << " Его номер: " << count << std::endl;
    std::cout << "Максимальный элемент: " << max << std::endl;
    std::cout << "Число элементов с этим значением: " << count << std:: endl;
}