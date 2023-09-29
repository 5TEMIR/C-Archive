#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    float a, b, h;
    const float eps = 0.00001;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "h = ";
    cin >> h;
    for (float x = a; x <= b; x += h)
    {
        if ((abs(x - 4.5) > eps) == 0)
        {
            cout << "x = " << x << " ";
            cout << "������� �� ����" << endl;
        }
        else if (x != 0 == 0)
        {
            cout << "x = " << x << " ";
            cout << "������ �� �������������� �����" << endl;
        }
        else if (x > 4 == 0)
        {
            cout << "x = " << x << " ";
            cout << "�������� �� ���������������� �����" << endl;
        }
        else
        {
            float f = sqrt(x * x - 1) / (log(2 * x - 8));
            cout << "f = ";
            cout << f << endl;
        }
    }
    return 0;
}