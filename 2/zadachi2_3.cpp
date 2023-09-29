#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int A;
    int X;
    int Y;
    cout << "Введите двузначное число\nA = ";
    cin >> A;
    cout << "Введите однозначное число\nX = ";
    cin >> X;
    cout << "Введите однозначное число\nY = ";
    cin >> Y;
    if (A < 10 || A > 99 || X <= 0 || X > 9 || Y <= 0 || Y > 9)
    {
        cout << "Неправильно введены данные\n";
    }
    else
    {
        int digit_1 = A / 10;
        int digit_2 = A % 10;
        int sum_digits = digit_1 + digit_2;
        int digit_1_new;
        int digit_2_new;
        if (sum_digits % X == 0)
        {
            if (digit_1 < Y)
            {
                digit_1_new = abs(digit_1 - 5);
                digit_2_new = abs(digit_2 - 5);
            }
            else if (digit_1 > Y)
            {
                digit_1_new = (digit_1 + 5) % 10;
                digit_2_new = (digit_2 + 5) % 10;
            }
            else
            {
                digit_1_new = (digit_1 + 2) % 10;
                digit_2_new = (digit_2 + 2) % 10;
            }
        }
        else
        {
            if (digit_1 < Y)
            {
                digit_1_new = abs(digit_1 - 4);
                digit_2_new = abs(digit_2 - 4);
            }
            else if (digit_1 > Y)
            {
                digit_1_new = (digit_1 + 4) % 10;
                digit_2_new = (digit_2 + 4) % 10;
            }
            else
            {
                digit_1_new = (digit_1 + 2) % 10;
                digit_2_new = (digit_2 + 2) % 10;
            }
        }
        cout << digit_1_new * 10 + digit_2_new << endl;
    }
    return 0;
}