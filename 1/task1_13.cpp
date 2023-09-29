#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Введите двухзначное целое число x" << endl;
    int x;
    cout << "x = ";
    cin >> x;
    int digit_1_old = x / 10;
    int digit_2_old = x % 10;
    int digit_1_new = 31 % digit_1_old;
    int digit_3_new = 31 % digit_2_old;
    int digit_2_new = 48 % digit_1_old;
    int digit_4_new = 48 % digit_2_old;
    int new_number = digit_1_new * 1000 + digit_2_new * 100 + digit_3_new * 10 + digit_4_new;
    cout << "Новое число y = " << new_number << endl;
    system("pause");
    return 0;
}