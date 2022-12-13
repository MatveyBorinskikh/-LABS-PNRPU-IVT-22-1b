#include <iostream>
#include <string>

int main() {
    int countC, countV;
    countC = countV = 0;
    std::string st;
    std::cout << "Введите строку" << std::endl;
    std::cin >> st;
    const char* pt = st.c_str();
    for (int i = 0; i < st.length(); i++)
    {
        if (*pt == 'А' || *pt == 'Е' || *pt == 'И' || *pt == 'О' || *pt == 'У' || *pt == 'Э' || *pt == 'Ю' || *pt == 'Я' || *pt == 'а' || *pt == 'е' || *pt == 'и' || *pt == 'о' || *pt == 'у' || *pt == 'э' || *pt == 'ю' || *pt == 'я')
        {
            countV++;
        }
        else { countC++; }
        pt++;
    }

    std::cout << "Количество гласных:  " << countV << std::endl;
    std::cout << "Количество согласных:  " << countC << std::endl;
    return 0;
}