#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Rus");

    float x, n, dlina, s;
    bool flag = false;

    std::cout << "Введите число n:" << std::endl;
    std::cin >> n;
    std::cout << "Введите длину последовательности:" << std::endl;
    std::cin >> dlina;
    std::cout << "Введите элемент S, для которого будет проверяться наличие "
        "тождественного элемента из последовательности:" << std::endl;
    std::cin >> s;

    while (dlina >= 1)
    {
        x = sin(n + dlina / n);
        x = round(x * 1000) / 1000; // Округляем, чтобы проверка проходила ровно

        if (x == s)
        {
            flag = true;
        }

        dlina--;
    }

    if (flag == true)
    {
        std::cout << "Число S присутствует в последовательности!" << std::endl;
    }
    else
    {
        std::cout << "Число S не присутствует в последовательности!" << std::endl;
    }
}