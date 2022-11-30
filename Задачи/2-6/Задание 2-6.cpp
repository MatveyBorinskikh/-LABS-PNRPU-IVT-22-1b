#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");

    start:
    float n;
    char zv = '*';
    char prob = ' ';
    int kprob=0;
    int kzv = 1;

    std::cout << "Введите длину катетов N (N>2):" << std::endl;
    std::cin >> n;

    if ((n <= 2) or ((int)n != n))
    {
        std::cout << "Неверно!" << std::endl;
        goto start; // на строку 14
    }
    kzv = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= kprob; j++)
        {
            std::cout << prob;
        }
        for (int j = 1; j <= kzv; j++)
        {
            std::cout << zv;
        }
        kprob++;
        kzv--;
        if (kzv< n)
        {
            std::cout << std::endl;
        }
        if (kzv == n)
        {
            break;
        }
    }
}