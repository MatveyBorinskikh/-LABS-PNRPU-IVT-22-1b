#ifndef MAIN_CPP_VECTOR_H
#define MAIN_CPP_VECTOR_H

#include "iostream"
#define MAX_SIZE 20
using namespace std;

class Vector {
    int size;
    int* beg;
public:
    Vector() { size = 0; beg = nullptr; }
    Vector(int);
    Vector(int, int*);
    Vector(const Vector&);
    ~Vector();
    const Vector& operator=(const Vector&);
    int operator[](int);
    Vector operator+(int a);
    Vector operator--();
    friend ostream& operator<<(ostream&, const Vector&);
    friend istream& operator>>(istream&, Vector&);
};

#endif //MAIN_CPP_VECTOR_H