#include "custom_time.h"
#include "custom_vector.h"

using namespace std;

int main() {
    custom_vector<custom_time> v(5);
    cout << "First vector is" << endl;
    v.Print();
    custom_time max = v.max();
    cout << "Maximum is " << max << endl;
    cout << "Position" << endl;
    int p;
    cin >> p;
    v.add_elem(max, p);
    cout << "After addition " << endl;
    v.Print();
    p = v.min_pos();
    v.delete_elem(p);
    cout << "After deletion" << endl;
    v.Print();
    custom_time avg = v.average();
    v.add_value(avg);
    cout << "After adding average value" << endl;
    v.Print();
    return 0;
}