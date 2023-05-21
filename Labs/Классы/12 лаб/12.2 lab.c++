#include "iostream"
#include "map"
#include "custom_time.h"
using namespace std;

typedef multimap<double, custom_time*> Tmap;
typedef Tmap::iterator it;

Tmap make_multimap(int size) {
    Tmap m;
    for (int i = 0; i < size; i++) {
        auto* time1p = new custom_time;
        cout << "give us element" << endl;
        cin >> *time1p;
        double d = i;
        m.insert(make_pair(d, time1p));
    }
    return m;
}

void print_map(Tmap m) {
    for (auto i : m) {
        cout << i.first << " : " << *(i.second) << endl;
    }
}

custom_time Max(Tmap m) {
    auto i = m.begin();
    custom_time max_t = *(*i).second;
    while (i != m.end()) {
        if (max_t < *(*i).second) max_t = *(*i).second;
        i++;
    }
    return { max_t };
};
pair<custom_time, int> Min_and_n(Tmap m) {
    auto i = m.begin();
    int n = 0, counter = 0;
    custom_time min_t = *(*i).second;
    while (i != m.end()) {
        if (min_t > *(*i).second) {
            min_t = *(*i).second;
            n = counter;
        }
        i++;
        counter++;
    }
    return make_pair(min_t, n);
}
custom_time average(Tmap m) {
    custom_time avg(0, 0);
    int n = 0;
    for (auto i : m) {
        n++;
        avg = avg + *i.second;
    }
    avg = avg / n;
    return { avg };
}

int main() {
    int n;
    cout << "Number of elements" << endl;
    cin >> n;
    Tmap m = make_multimap(n);
    print_map(m);

    auto* maxp = new custom_time;
    *maxp = Max(m);
    cout << "Maximum is " << *maxp << endl;
    m.insert(make_pair(0, maxp));
    print_map(m);

    int pos = Min_and_n(m).second;
    custom_time min;
    min = Min_and_n(m).first;
    cout << "Minimum is on position " << pos << " and it is equal to " << min << endl;
    for (auto i = m.begin(); i != m.end(); ++i) {
        if (*(i->second) == min) i = m.erase(i);
    }
    print_map(m);

    auto* avgp = new custom_time;
    *avgp = average(m);
    cout << "Average is " << *avgp << endl;
    for (auto i : m) {
        *i.second = *i.second + *avgp;
    }
    print_map(m);
    return 0;
}