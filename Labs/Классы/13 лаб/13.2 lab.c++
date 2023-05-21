#include "iostream"
#include "stack"
#include "vector"
#include "custom_time.h"
#include "algorithm"
using namespace std;
typedef stack<custom_time*> TStack;
typedef vector<custom_time*> TVector;
custom_time s;

TStack make_stack(int n) {
    TStack st;
    for (int i = 0; i < n; i++) {
        auto* t = new custom_time;
        cin >> (*t);
        st.push(t);
    }
    return st;
}

TStack vector_to_stack(TVector& v) {
    TStack st;
    for (int i = v.size() - 1; i >= 0; i--) {
        st.push(v[i]);
    }
    return st;
}

TVector stack_to_vector(TStack& st) {
    TVector vec;
    while (!st.empty()) {
        vec.push_back(st.top());
        st.pop();
    }
    return vec;
}

void print_stack(TStack st) {
    TVector v = stack_to_vector(st);
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << *v[i] << " " << endl;
    }
    cout << endl;
    st = vector_to_stack(v);
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
    TStack st = make_stack(n);
    cout << endl;
    print_stack(st);

    TVector v = stack_to_vector(st);
    TVector::iterator i;
    i = max_element(v.begin(), v.end());
    s = *(*i);
    auto* new_value = new custom_time;
    cout << "maximum is " << *(*i) << endl;
    cout << "Provide new value" << endl;
    cin >> *new_value;
    replace_if(v.begin(), v.end(), Equal_to_s(), new_value);
    st = vector_to_stack(v);
    print_stack(st);

    v = stack_to_vector(st);
    i = min_element(v.begin(), v.end());
    s = *(*i);
    cout << "minimum is " << *(*i) << endl;
    v.erase(remove(v.begin(), v.end(), *i), v.end());
    st = vector_to_stack(v);
    print_stack(st);

    cout << "Sorting elements" << endl;
    v = stack_to_vector(st);
    sort(v.begin(), v.end(), Comp_less());
    st = vector_to_stack(v);
    print_stack(st);

    v = stack_to_vector(st);
    s = average(v);
    cout << "Adding average" << endl;
    cout << "Average is " << s << endl;
    for_each(v.begin(), v.end(), add_s);
    st = vector_to_stack(v);
    print_stack(st);
    return 0;
}