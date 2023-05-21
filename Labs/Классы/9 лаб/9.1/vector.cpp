#include "Vector.h"
#include <stdexcept>

Vector::Vector(int s) {
    if (s > MAX_SIZE) throw 1;
    size = s;
    beg = new int[s];
    for (int i = 0; i < s; i++) {
        beg[i] = 0;
    }
}

Vector::Vector(int s, int* arr) {
    if (s > MAX_SIZE) throw 1;
    size = s;
    beg = new int[s];
    for (int i = 0; i < s; i++) {
        beg[i] = arr[i];
    }
}

Vector::~Vector() {
    if (beg != nullptr) delete[]beg;
}

Vector::Vector(const Vector& v) {
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++) {
        beg[i] = v.beg[i];
    }
}

const Vector& Vector::operator=(const Vector& v) {
    if (&v == this) return *this;
    if (beg != nullptr) delete[] beg;
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++) {
        beg[i] = v.beg[i];
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    if (v.size == 0) out << "Empty vector" << endl;
    for (int i = 0; i < v.size; i++) out << v.beg[i] << " ";
    out << endl;
    return out;
}

std::istream& operator>>(std::istream& in, Vector& v) {
    for (int i = 0; i < v.size; i++) {
        in >> v.beg[i];
    }
    return in;
}

int Vector::operator[](int i) {
    if (i < 0) throw 2;
    if (i >= size) throw domain_error("Vector length is more than maximum size");
    return beg[i];
}

Vector Vector::operator+(int a) {
    if (size + 1 == MAX_SIZE) throw 4;
    Vector tmp(size + 1, beg);
    tmp.beg[size] = a;
    return tmp;
}

Vector Vector::operator--() {
    if (size == 0) throw 5;
    if (size == 1) {
        size = 0;
        delete[]beg;
        beg = nullptr;
        return *this;
    }
    Vector tmp(size, beg);
    delete[]beg;
    size--;
    beg = new int[size];
    for (int i = 0; i < size; i++) {
        beg[i] = tmp.beg[i];
    }
    return *this;
}