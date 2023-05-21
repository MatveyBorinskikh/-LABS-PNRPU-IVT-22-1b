#include "iostream"
#include "map"
#include "Container.h"
#include "custom_time.h"
using namespace std;

typedef multimap<double, double> Tmap;
typedef Tmap::iterator it;

Tmap make_multimap(int size) {
    Tmap m;
    double d;
    for (int i = 0; i < size; i++) {
        cout << "give us element" << endl;
        cin >> d;
        m.insert(make_pair((double)i, d));
    }
    return m;
}
void print_map(Tmap m) {
    for (pair i : m) {
        cout << i.first << " : " << i.second << endl;
    }
}
double Max(Tmap m) {
    auto i = m.begin();
    double max = (*i).second;
    while (i != m.end()) {
        if (max < (*i).second) max = (*i).second;
        i++;
    }
    return max;
};
pair<double, int> Min_and_n(Tmap m) {
    auto i = m.begin();
    int n = 0, counter = 0;
    double min = (*i).second;
    while (i != m.end()) {
        if (min > (*i).second) {
            min = (*i).second;
            n = counter;
        }
        i++;
        counter++;
    }
    return make_pair(min, n);
}
double average(Tmap m) {
    double avg = 0;
    int n = 0;
    for (auto i : m) {
        n++;
        avg += i.second;
    }
    avg /= n;
    return avg;
}

int main() {
    int n;
    cout << "Number of elements" << endl;
    cin >> n;
    Container<custom_time> v(n);
    v.Print();

    auto* max = new custom_time;
    *max = v.Max();
    cout << "Maximum is " << *max << endl;

    v.Add(0, max);
    v.Print();

    cout << "Delete minimum" << endl;
    v.Delete();
    v.Print();

    cout << "Sum with average value" << endl;
    v.Add_value();
    v.Print();
    return 0;
}