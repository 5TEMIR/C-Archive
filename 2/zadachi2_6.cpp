#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    float x;
    cout << "x = ";
    cin >> x;
    if ((x >= -5) == 0)
    {
        cout << "������ �� �������������� �����";
    }
    else if ((x != 4 & x != -4 & x != 2) == 0)
    {
        cout << "������� �� ����";
    }
    else if ((x < -1 || x > 1) == 0)
    {
        cout << "�������� �� �������������� �����";
    }
    else
    {
        float F = (sin(log(x * x - 1)) / (x * x - 16)) + sqrt(x + 5) / sqrt(x * x - 4 * x + 4);
        cout << "F(x) = " << F << endl;
    }
}