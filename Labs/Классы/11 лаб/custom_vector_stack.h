#ifndef MAIN_CPP_CUSTOM_VECTOR_STACK_H
#define MAIN_CPP_CUSTOM_VECTOR_STACK_H
#include "iostream"
#include "stack"
#include "string"
#include "../../../custom_time.h"

using namespace std;

template <class T>
class custom_vector_stack {
protected:
    stack<T*> st;
    int size;
public:
    custom_vector_stack();
    ~custom_vector_stack();
    custom_vector_stack(int);
    custom_vector_stack(const custom_vector_stack<T>&);

    void Print();

    T max();
    void add_elem(T el, int pos);
    int min_pos();
    void delete_elem();
    T average();
    void add_value();
};



#endif //MAIN_CPP_CUSTOM_VECTOR_STACK_H