//f(x)=3*sin(sqrt(x))*0,35-3,8; [2;3]
//f'(x)=0,525*(cos(sqrt(x)))/(sqrt(x));
//f''(x)=-0,2625*(sin(sqrt(x))/x)-0,2625*cos(sqrt(x))/x^(3/2));

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    float x, xPrev;
    // f(b) * f''(b) < 0 => x0 = a;
    x = 2;
    xPrev = 0;
    double eps = 0.000001;

    while (abs(x - xPrev) > eps)
    {
        xPrev = x;
        x = xPrev - ((3 * sin(sqrt(xPrev)) * 0.35 - 3.8) / (0.525 * (cos(sqrt(xPrev))) / (sqrt(xPrev))));
    }
    cout << "Корень: " << x << endl;
    return 0;
}