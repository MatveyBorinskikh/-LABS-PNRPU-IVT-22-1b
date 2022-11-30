#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");

    start:
    float n;
    char zv = '*';
    char prob = ' ';
    int kprob;
    int kzv = 1;

    std::cout << "Введите длину N (N>2):" << std::endl;
    std::cin >> n;

    if ((n <= 2) or ((int)n != n))
    {
        std::cout << "Неверно!" << std::endl;
        goto start; 
    }
    kprob = 0;
    kzv = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= kzv; j++)
        {
            std::cout << zv;
        }
        if (kprob >= 1)
        {
            for (int j = 1; j <= kprob; j++)
            {
                std::cout << prob;
            }
        }
        kzv--;
        kprob++;
        if (kzv < n)
        {
            std::cout << std::endl;
        }
        if (kzv == n)
        {
            break;
        }
    }
}