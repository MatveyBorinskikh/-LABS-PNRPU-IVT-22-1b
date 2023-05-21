#include <stack>
#include "custom_time.h"
#include "vector"

using namespace std;

typedef stack<custom_time*>st;
typedef vector<custom_time*>vec;

st make_stack(int n) {
    st s;
    auto* t = new custom_time;
    for (int i = 0; i < n; i++) {
        cin >> *t;
        s.push(t);
    }
    return s;
}

vec copy_stack_to_vec(st s) {
    vec v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}

st copy_vector_to_stack(vec v) {
    st s;
    for (auto i : v) {
        s.push(i);
    }
    return s;
}

void print_stack(st& s) {
    vec v = copy_stack_to_vec(s);
    while (!s.empty()) {
        cout << *s.top() << endl;
        s.pop();
    }
    s = copy_vector_to_stack(v);
}

int min_number(st& s) {
    vec v = copy_stack_to_vec(s);
    int min_n = 0;
    int n = 0;
    custom_time min = *s.top();
    s.pop();
    while (!s.empty()) {
        n++;
        if (min > *s.top()) {
            min = *s.top();
            min_n = n;
        }
        s.pop();
    }
    s = copy_vector_to_stack(v);
    return min_n;
}

custom_time max(st& s) {
    vec v = copy_stack_to_vec(s);
    custom_time max = *s.top();
    s.pop();
    while (!s.empty()) {
        if (max < *s.top()) {
            max = *s.top();
        }
        s.pop();
    }
    s = copy_vector_to_stack(v);
    return { max };
}

custom_time average(st& s) {
    vec v = copy_stack_to_vec(s);
    int n = 0;
    custom_time avg = *s.top();
    s.pop();
    while (!s.empty()) {
        n++;
        avg = avg + *s.top();
        s.pop();
    }
    s = copy_vector_to_stack(v);
    avg = avg / n;
    return { avg };
}

void add_element(st& s, custom_time el, int pos) {
    vec v;
    int i = 1;
    while (!s.empty()) {
        custom_time t;
        t = *s.top();
        if (i == pos) v.push_back(&el);
        v.push_back(&t);
        s.pop();
        i++;
    }
    s = copy_vector_to_stack(v);
}
#include "custom_time.h"
#include "custom_vector_stack.h"

using namespace std;
int main() {
    custom_vector_stack<custom_time> v(3);
    v.Print();
    custom_time t = v.max();
    cout << "Maximum is " << t << endl;
    cout << "Add maximum " << endl;
    cout << "on which position?" << endl;
    int pos;
    cin >> pos;
    v.add_elem(t, pos);
    v.Print();
    cout << "Minimum is " << v.min_pos() << "th element" << endl;
    cout << "Delete mimimum " << endl;
    v.delete_elem();
    v.Print();
    cout << "Sum with average value" << endl;
    t = v.average();
    cout << "Average is " << t << endl;
    v.add_value();
    v.Print();
    return 0;
}