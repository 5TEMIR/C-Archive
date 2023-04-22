#include <iostream>
using namespace std;

int polinom_ermit(int x, int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return 2 * x;
    else
        return 2 * x * polinom_ermit(x, n - 1) - 2 * (n - 1) * polinom_ermit(x, n - 2);
}

int polinom_ermit_for(int x, int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return 2 * x;
    else
    {
        int n_0 = 1, n_1 = 2 * x, n_2;
        for (int i = 2; i <= n; i++)
        {
            n_2 = 2 * x * n_1 - 2 * (i - 1) * n_0;
            n_0 = n_1;
            n_1 = n_2;
        }
        return n_2;
    }
}

int main()
{
    int x, n;
    cout << "x = ";
    cin >> x;
    cout << "n = ";
    cin >> n;
    cout << polinom_ermit(x, n) << endl;
    cout << polinom_ermit_for(x, n) << endl;
    return 0;
}