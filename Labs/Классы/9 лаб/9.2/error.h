#ifndef MAIN_CPP_ERROR_H
#define MAIN_CPP_ERROR_H
#include "iostream"
#include "string"

class error {
    std::string str;
public:
    error(std::string s) { str = s; }
    void what() { std::cout << str << std::endl; }
};

#endif //MAIN_CPP_ERROR_H