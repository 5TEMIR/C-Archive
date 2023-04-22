#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 1 or n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int factorial_for(int n)
{
    if (n == 1 or n == 0)
        return 1;
    else
    {
        int fact = 1;
        for (int i = 2; i <= n; i++)
            fact *= i;
        return fact;
    }
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    cout << n << "! = " << factorial(n) << endl;
    cout << n << "! = " << factorial_for(n) << endl;
    return 0;
}