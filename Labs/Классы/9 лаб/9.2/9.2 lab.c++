#include "vector.h"
#include "error.h"
int main() {
    try {
        Vector x(2);
        Vector y;
        cout << x;
        cout << "N of?" << endl;
        int i;
        cin >> i;
        cout << x[i] << endl;
        y = x + 3;
        cout << y;
        --x;
        cout << x;
        --x;
        cout << x;
        --x;
    }
    catch (error e) { e.what(); };
    return 0;
}