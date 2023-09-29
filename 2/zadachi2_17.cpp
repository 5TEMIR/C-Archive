#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    float a, b, c;
    cout << "Cтороны треугольника:" << endl;
    cin >> a >> b >> c;
    if (a > b) // сортировка сторон
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
    if ((a + b > c && a + c > b && c + b > a) == 0) // существование
        cout << "Не существует (Вырожденный)";
    else
    {
        float p = (a + b + c) / 2.0;                     // полупериметр
        float S = sqrt(p * (p - a) * (p - b) * (p - c)); // площадь
        float R = (a * b * c) / (4 * S);                 //радиус описанной
        float r = S / p;                                 //радиус вписанной
        cout << "S = ";
        cout << S << endl;
        cout << "R = ";
        cout << R << endl;
        cout << "r = ";
        cout << r << endl;

        float eps = 0.00001;
        if (abs(a - b) < eps && abs(b - c) < eps) //равносторонний
        {
            cout << "Тип: равносторонний" << endl;
            cout << "Высота: " << R + r << endl;
        }
        else if (abs(a * a + b * b - c * c) < eps) //прямоугольный
        {
            if (abs(a - b) < eps || abs(a - c) < eps || abs(c - b) < eps) //равнобедренный и прямоугольный
            {
                cout << "Тип: равнобедренный и прямоугольный" << endl;
                cout << "Катеты: " << a << " и " << b << endl;
                cout << "Гипотенуза: " << c << endl;
                cout << "Высота: " << S / c * 2 << endl;
            }
            else //прямоугольный
            {
                cout << "Тип: прямоугольный" << endl;
                cout << "Катеты: " << a << " и " << b << endl;
                cout << "Гипотенуза: " << c << endl;
                cout << "Высота: " << S / c * 2 << endl;
                cout << "Медиана: " << c / 2.0 << endl;
            }
        }
        else if (abs(a - b) < eps || abs(a - c) < eps || abs(c - b) < eps) //равнобедренный
        {
            if (abs(a * a + b * b - c * c) < eps) //равнобедренный и прямоугольный
            {
                cout << "Тип: равнобедренный и прямоугольный" << endl;
                cout << "Катеты: " << a << " и " << b << endl;
                cout << "Гипотенуза: " << c << endl;
                cout << "Высота: " << S / c * 2 << endl;
            }
            else //равнобедренный
            {
                cout << "Тип: равнобедренный" << endl;
                if (abs(a - b) < eps)
                {
                    cout << "Боковые стороны: " << a << " и " << b << endl;
                    cout << "Основание: " << c << endl;
                    cout << "Высота: " << S / c * 2 << endl;
                }
                else if (abs(c - b) < eps)
                {
                    cout << "Боковые стороны: " << b << " и " << c << endl;
                    cout << "Основание: " << a << endl;
                    cout << "Высота: " << S / a * 2 << endl;
                }
                else if (abs(a - c) < eps)
                {
                    cout << "Боковые стороны: " << a << " и " << c << endl;
                    cout << "Основание: " << b << endl;
                    cout << "Высота: " << S / b * 2 << endl;
                }
            }
        }
        else
            cout << "Тип: разносторонний" << endl;
    }
}