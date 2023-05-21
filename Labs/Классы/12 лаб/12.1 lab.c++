#include "iostream"
#include "map"
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
    Tmap m = make_multimap(n);
    print_map(m);

    double max = Max(m);
    cout << "Maximum is " << max << endl;
    m.insert(make_pair((double)m.size(), max));
    print_map(m);

    int pos = Min_and_n(m).second;
    double min = Min_and_n(m).first;
    cout << "Minimum is on position " << pos << " and it is equal to " << min << endl;
    m.erase(m.begin());
    for (auto i = m.begin(); i != m.end(); ++i) {
        double d = i->second;
        if (d == min) m.erase(i);
    }
    print_map(m);

    double avg = average(m);
    cout << "Average is " << avg;
    for (auto i : m) {
        i.second += avg;
    }
    print_map(m);
    return 0;
}