#ifndef MAIN_CPP_FILE_WORK_H
#define MAIN_CPP_FILE_WORK_H

#include "Time.h"
#include "iostream"
#include "fstream"
#include "string"

int make_file(const char* f_name) {
    std::fstream stream(f_name, std::ios::out | std::ios::trunc);
    if (!stream) return -1;
    int n;
    Time t;
    std::cout << "How much?" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> t;
        stream << t << std::endl;
    }
    stream.close();
    return n;
}

int print_file(char* f_name) {
    std::fstream stream(f_name, std::ios::in);
    if (!stream) return -1;
    int i = 0;
    Time t;
    while (stream >> t) {
        std::cout << t << std::endl;
        i++;
    }
    stream.close();
    return i;
}

int del_file(const char* f_name, int k) {
    std::fstream temp("temp", std::ios::out);
    std::fstream stream(f_name, std::ios::in);
    if (!stream) return -1;
    Time t; int i = 0;
    while (stream >> t) {
        if (stream.eof()) break;
        i++;
        if (i != k) temp << t;
    }
    stream.close();
    remove(f_name);
    rename("temp", f_name);
    return i;
}

int add_file(const char* f_name, int k, Time t) {
    std::fstream temp("temp", std::ios::out);
    std::fstream stream(f_name, std::ios::in);
    if (!stream) return -1;
    Time t_local; int i = 0; int l = 0;
    while (stream >> t_local) {
        if (stream.eof()) break;
        i++;
        if (i == k) {
            temp << t;
            l++;
        }
        temp << t_local;
    }
    stream.close();
    remove(f_name);
    rename("temp", f_name);
    return l;
}

int add_end(const char* f_name, Time t) {
    std::fstream stream(f_name, std::ios::app);
    if (!stream) return -1;
    stream << t;
    return 1;
}

int change_file(const char* f_name, int k, Time t) {
    std::fstream temp("temp", std::ios::out);
    std::fstream stream(f_name, std::ios::in);
    if (!stream) return -1;
    Time t_local; int i = 0; int l = 0;
    char x;
    while (stream >> t_local) {
        if (stream.eof()) break;
        i++;
        if (i == k) {
            std::cout << t << " is changing. Continue [y/n]?" << std::endl;
            std::cin >> x;
            if (x == 'n' || x == 'N') break;
            temp << t;
            l++;
        }
        else temp << t_local;
    }
    stream.close();
    remove(f_name);
    rename("temp", f_name);
    return l;
}

int del_file_equal(const char* f_name, Time t) {
    std::fstream temp("temp", std::ios::out);
    std::fstream stream(f_name, std::ios::in);
    if (!stream) return -1;
    Time t_current; int i = 0;
    while (stream >> t_current) {
        if (stream.eof()) break;
        i++;
        if ((t != t_current)) temp << t;
    }
    stream.close();
    remove(f_name);
    rename("temp", f_name);
    return i;
}

int change_file_90sec(const char* f_name) {
    std::fstream temp("temp", std::ios::out);
    std::fstream stream(f_name, std::ios::in);
    if (!stream) return -1;
    Time t_local;
    Time t_additional(1, 30);
    while (stream >> t_local) {
        if (stream.eof()) break;
        temp << t_local + t_additional;
    }
    stream.close();
    remove(f_name);
    rename("temp", f_name);
    return 1;
}

int add_file_several(const char* f_name, int k, int N) {
    std::fstream temp("temp", std::ios::out);
    std::fstream stream(f_name, std::ios::in);
    if (!stream) return -1;
    Time t_local; int i = 0;
    while (stream >> t_local) {
        if (stream.eof()) break;
        i++;
        if (i == k) {
            Time t_new;
            for (int j = 0; j < N; j++) {
                std::cin >> t_new;
                temp << t_new;
            }
        }
        temp << t_local;
    }
    stream.close();
    remove(f_name);
    rename("temp", f_name);
    return N;
}

#endif //MAIN_CPP_FILE_WORK_H