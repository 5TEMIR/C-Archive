#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Введите четырехзначное целое число x" << endl;
    int x;
    cout << "x = ";
    cin >> x;
    int digit_1_old = x / 1000;
    int digit_2_old = x / 100 % 10;
    int digit_3_old = x / 10 % 10;
    int digit_4_old = x % 10;
    int digit_1_new = (digit_1_old + digit_2_old) % 10;
    int digit_2_new = (digit_2_old + digit_3_old) % digit_1_old;
    int digit_3_new = (digit_1_old + digit_2_old + digit_3_old + digit_4_old) % digit_1_old;
    int digit_4_new = abs(digit_2_old - digit_4_old);
    int new_number = digit_1_new * 1000 + digit_2_new * 100 + digit_3_new * 10 + digit_4_new;
    cout << "Новое число y = " << new_number << endl;
    system("pause");
    return 0;
}