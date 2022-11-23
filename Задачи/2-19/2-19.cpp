#include <iostream>
int main()
{
    setlocale(LC_ALL, "Rus");
    int n, s = 0, colvo = 0, chislo = 1;
    std::cout << "¬ведите до какого числа желаете вычислить: " << std::endl;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (colvo == 0)
        {
            s += chislo;
            colvo = 2;
        }
        else if (colvo == 2)
        {
            s += chislo;
            colvo = 3;
        }
        else if (colvo == 3)
        {
            s += chislo * (-1);
            colvo = 0;
        }
        chislo++;
    }
    std::cout << "—умма чисел: " << s << std::endl;
}