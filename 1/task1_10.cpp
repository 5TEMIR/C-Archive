#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Введите два числа x и y, чтобы вычислить F(x,y)" << endl;
    float x, y;
    cout << " x = ";
    cin >> x;
    cout << " y = ";
    cin >> y;
    float f = sqrt(cos(exp(sqrt(y+x))/pow(sin(sqrt(pow(x,2)-pow(y,2))),2)));
    cout << "F(x,y) = " << f << endl;
    system("pause");
    return 0;
}