#include "stdafx.h"
#include <iostream>

using namespace std;

void Print(char* str) {
    char* begin = str;  //������ �������� �����
    int counter = 0;    //������� ����

    while (true) {
        //������� ������ - �����
        if (*str >= '0' && *str <= '9') {
            counter++;
            str++;
            continue;
        }

        //������� ������ - ����� �����
        if (*str == ' ' || *str == '\0') {
            //���� � ����� 1 �����
            if (counter == 1) {
                //����� ����� � �������
                while (begin < str) {
                    cout << *begin;
                    begin++;
                }
                cout << endl;
            }
            //���� ����� ������ - ��������� ���c�
            if (*str == '\0')
                break;
            //����� ���������� �����
            Print(++str);
            break;
        }

        //������� � ���������� �������
        str++;
    }
}

void main()
{
    char str[256];
    cout << "Enter sentence: ";
    cin.getline(str, 255);
    str[255] = '\0';
    Print(str);
    system("pause");
}