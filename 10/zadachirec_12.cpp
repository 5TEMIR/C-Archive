#include <iostream>
using namespace std;

int f(int Num)
{
    static int i = -1;
    int t;
    if (Num == 0)
        return 0;
    else
    {
        i++;
        cout << Num % 10 << " * 2^" << i << " = " << (Num % 10) * (1 << i) << endl;
        t = (Num % 10) * (1 << i) + f(Num / 10);
    }
    return t;
}

int main()
{
    int num;
    cout << "num = ";
    cin >> num;
    cout << f(num);
    return 0;
}