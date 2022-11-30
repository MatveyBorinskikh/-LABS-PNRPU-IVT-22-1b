#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");

start:
    float n;
    char probel = ' ';
    char zvezda = '*';
        int kolprob;
    int kolzv = 1;
    std::cout << "Введите длину основания(N>3)"<< std::endl;
    std::cin >> n;

    if ((n <= 3) or ((int)n != n) or ((int)n % 2 != 1))
    {
        std::cout << "neverno!" << std::endl;
        goto start; // na 13
    }
    kolprob = n / 2;
    std::cout << std::endl;
    for (int i = 1; i <= n; i += 2)
    {
        for (int j = 1; j <= kolprob; j++)
        {
            std::cout << probel;
        }
        for (int j = 1; j <= kolzv; j++)
        {
            std::cout << zvezda;
        }
        if (kolzv != n)
        {
            std::cout << std::endl;
        }
        kolprob--;
        kolzv += 2;
    }
    std::cout << std::endl;
}