#include "iostream"
#include "set"
#include "custom_time.h"
#include "algorithm"
using namespace std;

auto cmp = [](custom_time* a, custom_time* b) {
    return *a < *b;
};

typedef set<custom_time*, decltype(cmp)> TSet;
custom_time t_glob;

TSet make_set(int n) {
    TSet s;
    for (int i = 0; i < n; i++) {
        auto* t1 = new custom_time;
        cin >> *t1;
        s.insert(t1);
    }
    return s;
}

void print_set(TSet s) {
    for (auto* i : s) {
        cout << *i << " " << endl;
    }
    cout << endl;
}

struct Equal_to_glob {
    bool operator ()(custom_time* t) {
        return (*t) == t_glob;
    }
};

struct Comp_less {
    bool operator ()(custom_time* t1, custom_time* t2) {
        return (*t1) > (*t2);
    }
};

void add_glob(custom_time* t) {
    *t = *t + t_glob;
};

custom_time average(TSet s) {
    custom_time t;
    for (auto* i : s) {
        t = t + *i;
    }
    return t / s.size();
}

int main() {
    int n;
    cout << "How much elements we have?" << endl;
    cin >> n;
    TSet s = make_set(n);
    cout << endl;
    print_set(s);

    TSet::iterator i;
    i = max_element(s.begin(), s.end());
    t_glob = *(*i);
    auto* new_t = new custom_time;
    cout << "maximum is " << *(*i) << endl;
    cout << "Provide new value" << endl;
    cin >> *new_t;
    s.erase(i);
    s.insert(new_t);
    print_set(s);

    i = min_element(s.begin(), s.end());
    t_glob = *(*i);
    cout << "minimum is " << *(*i) << endl;
    s.erase(i);
    print_set(s);

    cout << "Sorting elements is done automatically,but because we put pointers we must use some trick" << endl;
    print_set(s);

    t_glob = average(s);
    cout << "Adding average" << endl;
    cout << "Average is " << t_glob << endl;
    for_each(s.begin(), s.end(), add_glob);
    print_set(s);
    return 0;
}