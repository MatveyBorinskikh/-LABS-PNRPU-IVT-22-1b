#include "iostream"
#include <vector>
#include "cstdlib"
#include "Time.h"
using namespace std;

typedef vector<Time*> Vec;

Vec make_vector(int n) {
    Vec v;
    for (int i = 0; i < n; i++) {
        Time* t;
        t->set_minutes(rand() % 1000);
        t->set_seconds(rand() % 60);
        v.push_back(t);
    }
    return v;
}

void print_vector(const Vec& v) {
    for (auto i : v) { cout << *i << " "; }
    cout << endl;
}

Time max_elem(Vec v) {
    Time t_max = *v[0];
    for (int i = 1; i < v.size(); i++) {
        if (t_max < *v[i]) t_max = *v[i];
    }
    return Time(t_max);
}

void add_vector(Vec& v, Time* el, int pos) {
    v.insert(v.begin() + pos, el);
}

int min_elem_number(Vec v) {
    Time t_min = *v[0];
    int n = 0;
    for (int i = 1; i < v.size(); i++) {
        if (t_min > *v[i]) {
            t_min = *v[i];
            n = i;
        }
    }
    return n;
}

void delete_vector(Vec& v, int pos) {
    v.erase(v.begin() + pos);
}

Time average(Vec v) {
    Time t_avg = *v[0];
    for (int i = 1; i < v.size(); i++) {
        t_avg = t_avg + *v[i];
    }
    t_avg = t_avg / v.size();
    return Time(t_avg);
}

void add_number(Vec& v, Time t_add) {
    for (auto i : v) {
        *i = *i + t_add;
    }
}



int main() {
    try {
        vector<Time*> v;
        auto vi = v.begin();
        int n;
        cout << "How much elements we have?" << endl;
        cin >> n;
        v = make_vector(n);
        print_vector(v);
        Time* t;
        *t = max_elem(v);
        int pos;
        cout << "Where should I place maximum?" << endl;
        cin >> pos;
        if (pos > v.size()) throw 1;
        cout << "After adding element" << endl;
        add_vector(v, t, pos);
        print_vector(v);
        cout << "After deleting min element" << endl;
        int min_pos = min_elem_number(v);
        delete_vector(v, min_pos);
        print_vector(v);
        *t = average(v);
        add_number(v, *t);
        cout << "After adding average" << endl;
        print_vector(v);
    }
    catch (int) {
        cout << "error" << endl;
    }
    return 0;
}