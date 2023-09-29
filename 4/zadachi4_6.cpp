#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int N = 100;
    float x, eps = 0.00001;
    cout << "x = ";
    cin >> x;
    float a = x, S = 1;
    cout << left << setw(3) << "i"
         << "\t| " << setw(10) << "a"
         << "\t| " << setw(10) << "S" << endl;
    cout << left << setw(3) << "1"
         << "\t| " << setw(10) << a
         << "\t| " << setw(10) << S << endl;
    for (int i = 2; abs(a) > eps && i <= N; i++)
    {
        S += a;
        a *= x / i;
        if (a == 0)
        {
            cout << "Ряд расходящийся";
            break;
        }
        cout << left << setw(3) << i << "\t| " << setw(10) << a << "\t| " << setw(10) << S << endl;
    }
    return 0;
}