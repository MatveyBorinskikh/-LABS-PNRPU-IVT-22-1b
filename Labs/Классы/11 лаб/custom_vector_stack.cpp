#include <vector>
#include "custom_vector_stack.h"
#include "../../../custom_time.h"

template <class T> custom_vector_stack<T>::custom_vector_stack() { size = 0; }
template <class T> custom_vector_stack<T>::custom_vector_stack(int s) {
    size = s;
    st = stack<T*>();
    T t;
    cout << "Give us " << size << " members" << endl;
    for (int i = 0; i < size; i++) {
        T* t_point = new T;
        cin >> t;
        *t_point = t;
        st.push(t_point);
    }
}
template <class T> custom_vector_stack<T>::~custom_vector_stack() {
    int t = st.size();
    for (int i = 0; i < t; i++) {
        st.pop();
    }
}
template<class T>custom_vector_stack<T>::custom_vector_stack(const custom_vector_stack<T>& a) {
    size = a.size;
    st = a.st;
}

template <class T> vector<T*> copy_stack_to_vec(stack<T*> s) {
    vector<T*> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}
template <class T> stack<T*> copy_vector_to_stack(vector<T*> v) {
    stack<T*> s;
    for (auto i : v) {
        s.push(i);
    }
    return s;
}

template<class T> void custom_vector_stack<T>::Print() {
    vector<T*> v = copy_stack_to_vec(st);
    while (!st.empty()) {
        cout << *st.top() << " " << endl;
        st.pop();
    }
    st = copy_vector_to_stack(v);
}

template<class T>
T custom_vector_stack<T>::max() {
    vector<T*> v = copy_stack_to_vec(st);
    T max = *st.top();
    while (!st.empty()) {
        if (max < *st.top()) max = *st.top();
        st.pop();
    }
    st = copy_vector_to_stack(v);
    return T(max);
};
template<class T>
void custom_vector_stack<T>::add_elem(T el, int pos) {
    vector<T*> v;
    int i = 1;
    while (!st.empty()) {
        custom_time t;
        t = *st.top();
        if (i == pos) v.push_back(&el);
        v.push_back(&t);
        st.pop();
        i++;
    }
    st = copy_vector_to_stack(v);
}

template<class T>
int custom_vector_stack<T>::min_pos() {
    vector<T*> v = copy_stack_to_vec(st);
    int min_n = 0;
    int n = 0;
    custom_time min = *st.top();
    st.pop();
    while (!st.empty()) {
        n++;
        if (min > *st.top()) {
            min = *st.top();
            min_n = n;
        }
        st.pop();
    }
    st = copy_vector_to_stack(v);
    return min_n;
}
template<class T>
void custom_vector_stack<T>::delete_elem() {
    int pos = min_pos();
    vector<T*> v;
    int i = 0;
    while (st.empty()) {
        T t = *st.top();
        if (i != pos) v.push_back(&t);
        st.pop();
        i++;
    }
    st = copy_vector_to_stack(v);
}

template<class T>
T custom_vector_stack<T>::average() {
    vector<T*> v = copy_stack_to_vec(st);
    T t = *st.top();
    st.pop();
    int n = 1;
    while (!st.empty()) {
        t = t + *st.top();
        st.pop();
        n++;
    }
    t = t / n;
    st = copy_vector_to_stack(v);
    return T(t);
}
template<class T>
void custom_vector_stack<T>::add_value() {
    T avg = average();
    vector<T*> v;
    while (!st.empty()) {
        T t = *st.top() + avg;
        v.push_back(&t);
        st.pop();
    }
    st = copy_vector_to_stack(v);
}

template class custom_vector_stack<custom_time>;