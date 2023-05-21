#ifndef MAIN_CPP_CONTAINER_H
#define MAIN_CPP_CONTAINER_H

#include "iostream"
#include "map"
using namespace std;

template <class T>
class Container {
    multimap<double, T*> multimap1;
    int size;
public:
    Container() { size = 0; };
    Container(int);
    ~Container() = default;
    void Print();
    T average();
    pair<int, T> Min();
    T Max();
    void Add(double d, T* el) { multimap1.insert(make_pair(d, el)); }
    void Delete();
    void Add_value();
};

#endif //MAIN_CPP_CONTAINER_H