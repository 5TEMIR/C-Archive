#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int d, m, y;
    string month[]{"января",
                   "февраля",
                   "марта",
                   "апреля",
                   "мая",
                   "июня",
                   "июля",
                   "августа",
                   "сентября",
                   "октября",
                   "ноября",
                   "декабря"};
    cout << "Введите дату\n";
    cin >> d >> m >> y;
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: // 31 день
        if (d <= 0 || d > 31)
            cout << "Неправильный день\n";
        else
            cout << d << " " << month[m - 1] << " " << y << " "
                 << "года" << endl
                 << "До конца месяца осталось дней: " << 31 - d;
        break;
    case 4:
    case 6:
    case 9:
    case 11: // 30 дней
        if (d <= 0 || d > 30)
            cout << "Неправильный день\n";
        else
            cout << d << " " << month[m - 1] << " " << y << " "
                 << "года" << endl
                 << "До конца месяца осталось дней: " << 30 - d;
        break;
    case 2:
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) //високосный год
            if (d <= 0 || d > 29)
                cout << "Неправильный день\n";
            else
                cout << d << " " << month[m - 1] << " " << y << " "
                     << "года" << endl
                     << "До конца месяца осталось дней: " << 29 - d;
        else //невисокосный
            if (d <= 0 || d > 28)
                cout << "Неправильный день\n";
            else
                cout << d << " " << month[m - 1] << " " << y << " "
                     << "года" << endl
                     << "До конца месяца осталось дней: " << 28 - d;
        break;
    default:
        cout << "Неправильный месяц\n";
    }
    return 0;
}