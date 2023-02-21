#include <iostream>
#include <cstdarg>
#include <cstdlib>

int S(int n, ...)
{
    va_list vl;
    va_start(vl, n);

    int r = 0;

    for (int i = 0; i < n; i += 2)
        r += va_arg(vl, int) * va_arg(vl, int);

    va_end(vl);

    return r;
}

int main()
{
    std::cout << S(8, 1, 2, 3, 4, 5, 6, 7, 8) << " " << S(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << " " << S(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);

    return 0;
}