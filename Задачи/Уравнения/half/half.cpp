//f(x)=3*sin(sqrt(x))*0,35-3,8; [2;3]
//f'(x)=0,525*(cos(sqrt(x)))/(sqrt(x));
//f''(x)=-0,2625*(sin(sqrt(x))/x)-0,2625*cos(sqrt(x))/x^(3/2));

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    float a, b, c;
    float fA, fB, fC;
    double eps = 0.000001;
    a = 2;
    b = 3;
    while (b - a > eps)
    {
        c = (a + b) / 2;
        fA = (3 * sin(pow(a, (0.5))) + 0.35 - 3.8);
        fB = (3 * sin(pow(b, (0.5))) + 0.35 - 3.8);
        fC = (3 * sin(pow(c, (0.5))) + 0.35 - 3.8);
        if (fA * fC < 0) { b = c; }
        else if (fC * fB < 0) { a = c; }
        else { cout << "Что-то не то!" << endl; }
    }
    cout << "Корни: " << a << "; " << b << endl;
    return 0;
}