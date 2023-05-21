#include "iostream"
#include "vector"
#include "cstdlib"

using namespace std;

typedef vector<double>Vec;

Vec make_vector(int n) {
    Vec v;
    for (int i = 0; i < n; i++) {
        double d = rand() % 1000 - 500;
        v.push_back(d);
    }
    return v;
}

void print_vector(const Vec& v) {
    for (double i : v) cout << i << " ";
    cout << endl;
}

double max_elem(Vec v) {
    double max = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (max < v[i]) max = v[i];
    }
    return max;
}

void add_vector(Vec& v, double el, int pos) {
    v.insert(v.begin() + pos, el);
}

int min_elem_number(Vec v) {
    double min = v[0];
    int n = 0;
    for (int i = 1; i < v.size(); i++) {
        if (min > v[i]) {
            min = v[i];
            n = i;
        }
    }
    return n;
}

void delete_vector(Vec& v, int pos) {
    v.erase(v.begin() + pos);
}

double average(Vec v) {
    double d = v[0];
    for (int i = 1; i < v.size(); i++) {
        d += v[i];
    }
    d = d / (double)v.size();
    return d;
}

void add_number(Vec& v, double num) {
    for (double i : v) {
        i += num;
    }
}



int main() {
    try {
        vector<double> v;
        vector<double>::iterator vi = v.begin();
        int n;
        cout << "How much elements we have?" << endl;
        cin >> n;
        v = make_vector(n);
        print_vector(v);
        double d = max_elem(v);
        int pos;
        cout << "Where should I place maximum?" << endl;
        cin >> pos;
        if (pos > v.size()) throw 1;
        cout << "After adding element" << endl;
        add_vector(v, d, pos);
        print_vector(v);
        cout << "After deleting min element" << endl;
        int min_pos = min_elem_number(v);
        delete_vector(v, min_pos);
        print_vector(v);
        d = average(v);
        add_number(v, d);
        cout << "After adding average" << endl;
        print_vector(v);
    }
    catch (int) {
        cout << "error" << endl;
    }
    return 0;
}