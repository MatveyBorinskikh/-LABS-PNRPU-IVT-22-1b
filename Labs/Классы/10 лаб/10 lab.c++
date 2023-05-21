#include "Time.h"
#include "iostream"
#include "fstream"
#include "string"
#include "file_work.h"

int main() {
    Time t1;
    std::cin >> t1;
    std::cout << t1 << std::endl;
    Time t2;
    t2 = t1;
    std::cout << t2 << std::endl;
    Time t3;
    int k, c, n;
    Time t_example;
    do {
        std::cout << "1. Make file" << std::endl;
        std::cout << "2. Print file" << std::endl;
        std::cout << "3. Delete record from file" << std::endl;
        std::cout << "4. Add record to file" << std::endl;
        std::cout << "5. Change record in file" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cin >> c;
        char filename[30];
        switch (c) {
        case 1:
            std::cout << "File name?" << std::endl;
            std::cin >> filename;
            k = make_file(filename);
            if (k < 0) std::cout << "Can not make file" << std::endl;
            break;
        case 2:
            std::cout << "File name?" << std::endl;
            std::cin >> filename;
            k = print_file(filename);
            if (k == 0) std::cout << "Empty file" << std::endl;
            if (k < 0) std::cout << "Can not make file" << std::endl;
            break;
        case 3:
            std::cout << "File name?" << std::endl;
            std::cin >> filename;
            std::cout << "N of record?" << std::endl;
            std::cin >> n;
            k = del_file(filename, n);
            if (k < 0) std::cout << "Can't read the file" << std::endl;
            break;
        case 4:
            std::cout << "File name?" << std::endl;
            std::cin >> filename;
            std::cout << "N of record?" << std::endl;
            std::cin >> n;
            std::cout << "New time" << std::endl;
            std::cin >> t_example;
            k = add_file(filename, n, t_example);
            if (k < 0) std::cout << "Can't read the file" << std::endl;
            if (k == 0) k = add_end(filename, t_example);
            break;
        case 5:
            std::cout << "File name?" << std::endl;
            std::cin >> filename;
            std::cout << "N of record?" << std::endl;
            std::cin >> n;
            std::cout << "New time" << std::endl;
            std::cin >> t_example;
            k = change_file(filename, n, t_example);
            if (k < 0) std::cout << "Can't read the file" << std::endl;
            if (k == 0) std::cout << "No such record" << std::endl;
            break;
        }
    } while (c != 0);

    return 0;
}