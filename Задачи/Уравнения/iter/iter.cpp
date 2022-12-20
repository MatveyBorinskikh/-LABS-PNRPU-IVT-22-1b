//f(x)=3*sin(sqrt(x))*0,35-3,8; [2;3]
//f'(x)=0,525*(cos(sqrt(x)))/(sqrt(x));
//f''(x)=-0,2625*(sin(sqrt(x))/x)-0,2625*cos(sqrt(x))/x^(3/2));
// ? = -1/20 = -0.2

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    float x, xPrev;
    double lambda = -0.2;
    x = 2;
    xPrev = 0;
    double eps = 0.000001;

    while (abs(x - xPrev) > eps)
    {
        xPrev = x;
        x = lambda * (3 * sin(pow(xPrev, 0.5)) + 0.35 - 3.8) + xPrev;
    }
    cout << "Корень по методу итераций: " << x << endl;
    return 0;
}