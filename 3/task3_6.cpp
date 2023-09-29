#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, p, q;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    int i = 0;
    while (i < a) //частное
    {
        i += b;
        p++;
    }
    if (i != a)
        p--;
    cout << "p = ";
    cout << p << endl;
    i = 0;
    while (i < a) //остаток
        i += b;
    if (i == a)
        q = 0;
    else
        q = a - (i - b);
    cout << "q = ";
    cout << q << endl;
    return 0;
}