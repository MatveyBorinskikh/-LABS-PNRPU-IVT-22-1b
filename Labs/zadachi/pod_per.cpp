#include <iostream>
#include <stdlib.h>

int main()
{
    int temp, p, q;

    int mas[5];

    std::cout << "¬ведите массив" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cin >> mas[i];
    }

    std::cout << "¬ведите индексы" << std::endl;

    std::cin >> p >> q;

    for (p; p <= q; p++)
    {
        temp = mas[p];
        mas[p] = mas[q];
        mas[q] = temp;
        q = q - 1;
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << mas[i] << " ";
    }
    return 0;
}