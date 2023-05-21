#include "custom_vector.h"
#include "custom_time.h"

template <class T> custom_vector<T>::custom_vector() { size = 0; }

template <class T> custom_vector<T>::custom_vector(int s) {
    size = s;
    data = vector<T*>();
    T t;
    cout << "Give us " << size << " members" << endl;
    for (int i = 0; i < size; i++) {
        T* t_point = new T;
        cin >> t;
        *t_point = t;
        data.push_back(t_point);
    }
}

template <class T>
custom_vector<T>::~custom_vector() {
    int t = data.size();
    for (int i = 0; i < t; i++) {
        data.pop_back();
    }
}

template <class T>
custom_vector<T>::custom_vector(const custom_vector& a) {
    size = a.size;
    data = vector<T*>(size);
    for (int i = 0; i < size; i++) {
        data.push_back(a.data[i]);
    }
}

template <class T>
custom_vector<T>& custom_vector<T>::operator=(const custom_vector& a) {
    size = a.size;
    if (!data.empty()) data.erase(data.begin(), data.end());
    data = vector<T*>(size);
    for (int i = 0; i < size; i++) {
        data.push_back(a.data[i]);
    }
    return *this;
}

template <class T>
T& custom_vector<T>::operator[](int index) {
    if (index < size) return *data[index];
    else std::cout << "Error. Out of bounds!" << std::endl;
}

template <class T>
int custom_vector<T>::operator()() { return size; }

template <class T>
custom_vector<T> custom_vector<T>::operator+(T& k) {
    custom_vector<T>tmp;
    for (int i = 0; i < size; i++) {
        *tmp.data[i] = *tmp.data[i] + *data[i] + k;
    }
    return tmp;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const custom_vector<T>& a) {
    for (int i = 0; i < a.size; i++) {
        out << *a.data[i] << " ";
    }
    return out;
}

template <class T>
std::istream& operator>>(std::istream& in, custom_vector<T>& a) {
    for (int i = 0; i < a.size; i++) {
        in >> *a.data[i];
    }
    return in;
}

template<class T>
void custom_vector<T>::Print() {
    for (int i = 0; i < data.size(); i++) {
        cout << *data[i] << " " << endl;
    }
    cout << endl;
}

template<class T>
int custom_vector<T>::min_pos() {
    T min = *data[0];
    int n = 0;
    for (int i = 0; i < size; i++) {
        if (min > *data[i]) {
            n = i;
            min = *data[i];
        }
    }
    return n;
}

template<class T>
T custom_vector<T>::average() {
    T t;
    for (int i = 0; i < size; i++) {
        t = t + *data[i];
    }
    t = t / size;
    return T(t);
}

template<class T>
T custom_vector<T>::max() {
    T max = *data[0];
    for (int i = 0; i < size; i++) {
        if (max < *data[i]) {
            max = *data[i];
        }
    }
    return T(max);
};

template<class T>
void custom_vector<T>::add_elem(T el, int pos) {
    T* t_point = new T;
    *t_point = el;
    data.insert(data.begin() + pos, t_point);
}

template<class T>
void custom_vector<T>::delete_elem(int pos) {
    data.erase(data.begin() + pos);
}

template<class T>
void custom_vector<T>::add_value(T el) {
    for (auto i : data) {
        *i = *i + el;
    }
}


template class custom_vector<custom_time>;