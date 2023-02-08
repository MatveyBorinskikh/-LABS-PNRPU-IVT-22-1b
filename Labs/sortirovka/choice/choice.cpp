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

    for (int i = 0; i < (n - 1); i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (mas[j] < mas[min])
            {
                min = j;
            }
        }
        temp = mas[min];
        mas[min] = mas[i];
        mas[i] = temp;
    }

    for (int i = 0; i < 15; i++)
    {
        std::cout << mas[i] << " ";
    }
    return 0;
}