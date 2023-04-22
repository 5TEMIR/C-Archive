#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    float y1 = 0.5, y2 = 0.4;
    cout << "n\t| y" << endl;
    cout << 1 << "\t| " << y1 << endl;
    cout << 2 << "\t| " << y2 << endl;
    for (int i = 3; i <= n; i++)
    {
        float Yn = 1.0 / 2 * y2 + 1.0 / 3 * y1;
        cout << i << "\t| " << Yn << endl;
        y1 = y2;
        y2 = Yn;
    }
    return 0;
}