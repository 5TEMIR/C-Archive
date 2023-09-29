#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    float a, b, c;
    cout << "C������ ������������:" << endl;
    cin >> a >> b >> c;
    if (a > b) // ���������� ������
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
    if ((a + b > c && a + c > b && c + b > a) == 0) // �������������
        cout << "�� ���������� (�����������)";
    else
    {
        float p = (a + b + c) / 2.0;                     // ������������
        float S = sqrt(p * (p - a) * (p - b) * (p - c)); // �������
        float R = (a * b * c) / (4 * S);                 //������ ���������
        float r = S / p;                                 //������ ���������
        cout << "S = ";
        cout << S << endl;
        cout << "R = ";
        cout << R << endl;
        cout << "r = ";
        cout << r << endl;

        float eps = 0.00001;
        if (abs(a - b) < eps && abs(b - c) < eps) //��������������
        {
            cout << "���: ��������������" << endl;
            cout << "������: " << R + r << endl;
        }
        else if (abs(a * a + b * b - c * c) < eps) //�������������
        {
            if (abs(a - b) < eps || abs(a - c) < eps || abs(c - b) < eps) //�������������� � �������������
            {
                cout << "���: �������������� � �������������" << endl;
                cout << "������: " << a << " � " << b << endl;
                cout << "����������: " << c << endl;
                cout << "������: " << S / c * 2 << endl;
            }
            else //�������������
            {
                cout << "���: �������������" << endl;
                cout << "������: " << a << " � " << b << endl;
                cout << "����������: " << c << endl;
                cout << "������: " << S / c * 2 << endl;
                cout << "�������: " << c / 2.0 << endl;
            }
        }
        else if (abs(a - b) < eps || abs(a - c) < eps || abs(c - b) < eps) //��������������
        {
            if (abs(a * a + b * b - c * c) < eps) //�������������� � �������������
            {
                cout << "���: �������������� � �������������" << endl;
                cout << "������: " << a << " � " << b << endl;
                cout << "����������: " << c << endl;
                cout << "������: " << S / c * 2 << endl;
            }
            else //��������������
            {
                cout << "���: ��������������" << endl;
                if (abs(a - b) < eps)
                {
                    cout << "������� �������: " << a << " � " << b << endl;
                    cout << "���������: " << c << endl;
                    cout << "������: " << S / c * 2 << endl;
                }
                else if (abs(c - b) < eps)
                {
                    cout << "������� �������: " << b << " � " << c << endl;
                    cout << "���������: " << a << endl;
                    cout << "������: " << S / a * 2 << endl;
                }
                else if (abs(a - c) < eps)
                {
                    cout << "������� �������: " << a << " � " << c << endl;
                    cout << "���������: " << b << endl;
                    cout << "������: " << S / b * 2 << endl;
                }
            }
        }
        else
            cout << "���: ��������������" << endl;
    }
}