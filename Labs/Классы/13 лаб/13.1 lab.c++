#include "iostream"
#include "vector"
#include "custom_time.h"
#include "algorithm"

using namespace std;
typedef vector<custom_time*> TVector;
custom_time s;

TVector make_vector(int n) {
    TVector v;
    for (int i = 0; i < n; i++) {
        auto* t = new custom_time;
        cin >> (*t);
        v.push_back(t);
    }
    return v;
}

void print_vector(TVector v) {
    for (auto& i : v) {
        cout << *i << endl;
    }
    cout << endl;
}



struct Equal_to_s {
    bool operator ()(custom_time* t) {
        return (*t) == s;
    }
};

struct Comp_less {
    bool operator ()(custom_time* t1, custom_time* t2) {
        return (*t1) > (*t2);
    }
};

void add_s(custom_time* t) {
    *t = *t + s;
};

custom_time average(TVector v) {
    custom_time t;
    for (auto* i : v) {
        t = t + *i;
    }
    return t / v.size();
}

int main() {
    int n;
    cout << "How much elements we have?" << endl;
    cin >> n;
    TVector v = make_vector(n);
    cout << endl;
    print_vector(v);

    TVector::iterator i;
    i = max_element(v.begin(), v.end());
    s = *(*i);
    auto* new_value = new custom_time;
    cout << "maximum is " << *(*i) << endl;
    cout << "Provide new value" << endl;
    cin >> *new_value;
    replace_if(v.begin(), v.end(), Equal_to_s(), new_value);
    print_vector(v);

    i = min_element(v.begin(), v.end());
    s = *(*i);
    cout << "minimum is " << *(*i) << endl;
    v.erase(remove(v.begin(), v.end(), *i), v.end());
    print_vector(v);

    cout << "Sorting elements" << endl;
    sort(v.begin(), v.end(), Comp_less());
    print_vector(v);

    s = average(v);
    cout << "Adding average" << endl;
    cout << "Average is " << s << endl;
    for_each(v.begin(), v.end(), add_s);
    print_vector(v);
    return 0;
}