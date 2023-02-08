#include <iostream>
#include <stdlib.h>

int main()
{
    int temp;

    int mas[15];

    for (int i = 0; i < 15; i++)
    {
        mas[i] = rand() % 100;
    }

    for (int i = 0; i < 15; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 14 - i; j++)
        {
            if (mas[j] > mas[j + 1])
            {
                temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 15; i++)
    {
        std::cout << mas[i] << " ";
    }
    return 0;
}