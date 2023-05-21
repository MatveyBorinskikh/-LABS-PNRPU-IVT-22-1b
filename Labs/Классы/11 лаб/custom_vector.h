#ifndef MAIN_CPP_CUSTOM_VECTOR_H
#define MAIN_CPP_CUSTOM_VECTOR_H
#include "iostream"
#include "vector"
#include "string"
#include "custom_time.h"

using namespace std;

template <class T>
class custom_vector {
protected:
    vector<T*> data;
    int size;
public:
    custom_vector();
    ~custom_vector();
    custom_vector(int);
    custom_vector(const custom_vector<T>&);
    custom_vector& operator=(const custom_vector<T>& a);
    T& operator[](int index);
    custom_vector<T> operator+(T&);
    int operator()();
    friend ostream& operator<< (std::ostream&, const custom_vector<T>& a);
    friend istream& operator>> (std::istream&, custom_vector<T>& a);
    void Print();
    T average();
    int min_pos();
    T max();
    void add_elem(T el, int pos);
    void delete_elem(int pos);
    void add_value(T el);
};


#endif //MAIN_CPP_CUSTOM_VECTOR_H