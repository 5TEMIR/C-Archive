#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "¬ведите два числа x и y, чтобы вычислить F(x,y)" << endl;
    float x, y;
    cout << " x = ";
    cin >> x;
    cout << " y = ";
    cin >> y;
    float f = sqrt((exp(pow(x, 2) + pow(y, 2)) + 5 * x) / cos(pow(x + y, 2))) / 3 + x / y;
    cout << "F(x,y) = " << f << endl;
    system("pause");
    return 0;
}