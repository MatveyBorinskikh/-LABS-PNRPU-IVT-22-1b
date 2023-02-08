#include <iostream>
#include <stdlib.h>

int main()
{
    int temp, n = 15;

    int mas[15];

    for (int i = 0; i < n; i++)
    {
        mas[i] = rand() % 100;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; (j >= 0) && (mas[j - 1] > mas[j]); j--)
        {
            temp = mas[j - 1];
            mas[j - 1] = mas[j];
            mas[j] = temp;
        }

    }

    for (int i = 0; i < 15; i++)
    {
        std::cout << mas[i] << " ";
    }
    return 0;
}