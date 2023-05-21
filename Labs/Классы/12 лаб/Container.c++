#include "Container.h"
#include "custom_time.h"

template<class T>
Container<T>::Container(int n) {
    for (int i = 0; i < n; i++) {
        T* ptr = new T;
        cin >> *ptr;
        multimap1.insert(make_pair((double)i, ptr));
    }
    size = multimap1.size();
}
template<class T>
void Container<T>::Print() {
    for (pair i : multimap1) {
        cout << i.first << " : " << *(i.second) << endl;
    }
}

template<class T>
T Container<T>::average() {
    T t;
    for (auto i : multimap1) {
        t = t + *(i.second);
    }
    return { t / multimap1.size() };
}

template<class T>
T Container<T>::Max() {
    auto i = multimap1.begin();
    int n = 0, k = 0;
    T max = *(i->second);
    while (i != multimap1.end()) {
        if (max < *(i->second)) {
            max = *(i->second);
            n = k;
        }
        i++;
        k++;
    }
    return { max };
}

template<class T>
pair<int, T> Container<T>::Min() {
    auto i = multimap1.begin();
    int n = 0, counter = 0;
    T min_t = *(*i).second;
    while (i != multimap1.end()) {
        if (min_t > *(*i).second) {
            min_t = *(*i).second;
            n = counter;
        }
        i++;
        counter++;
    }
    return make_pair(n, min_t);
}

template<class T>
void Container<T>::Delete() {
    int pos = Min().first;
    T min;
    min = Min().second;
    cout << "Minimum is on position " << pos << " and it is equal to " << min << endl;
    for (auto i = multimap1.begin(); i != multimap1.end(); ++i) {
        custom_time t = *(i->second);
        if (t == min) i = multimap1.erase(i);
    }
}

template<class T>
void Container<T>::Add_value() {
    T avg = average();
    cout << "Average is " << avg << endl;
    for (auto i : multimap1) {
        *(i.second) = *(i.second) + avg;
    }
}

template class Container<custom_time>;