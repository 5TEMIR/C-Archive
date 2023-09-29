// Дана строка, содержащая латинские буквы, цифры и пробелы. Найти максимальную четную цифру.

// I was4 bo3rn 8ready 5and str6ong

#include <iostream>

using namespace std;

int main()
{
    string str;
    cout << "STRING: ";
    getline(cin, str); // ввод строки
    int max_digit = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) && !((str[i] - '0') % 2) && (str[i] - '0') > max_digit) // проверка символа на цифру
            max_digit = str[i] - '0';
    }
    cout << "max digit: " << max_digit;
    return 0;
}