#include <iostream>
#include <string>

int main() {
    int countC, countV;
    countC = countV = 0;
    std::string st;
    std::cout << "������� ������" << std::endl;
    std::cin >> st;
    const char* pt = st.c_str();
    for (int i = 0; i < st.length(); i++)
    {
        if (*pt == '�' || *pt == '�' || *pt == '�' || *pt == '�' || *pt == '�' || *pt == '�' || *pt == '�' || *pt == '�' || *pt == '�' || *pt == '�' || *pt == '�' || *pt == '�' || *pt == '�' || *pt == '�' || *pt == '�' || *pt == '�')
        {
            countV++;
        }
        else { countC++; }
        pt++;
    }

    std::cout << "���������� �������:  " << countV << std::endl;
    std::cout << "���������� ���������:  " << countC << std::endl;
    return 0;
}