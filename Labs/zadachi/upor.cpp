#include <iostream>
#include <stdlib.h>

int main()
{
    int temp;

    bool flag = true;

    int mas[15];

    std::cout << "������� ������" << std::endl;

    for (int i = 0; i < 15; i++)
    {
        std::cin >> mas[i];
    }

    for (int i = 0; i < 14; i++)
    {
        if (mas[i] > mas[i + 1])
        {
            flag = false;
        }
    }

    if (flag == true)
    {
        std::cout << "������ ���������� �� ��������" << std::endl;
    }
    else
    {
        std::cout << "������ �� ����������" << std::endl;
    }
    return 0;
}