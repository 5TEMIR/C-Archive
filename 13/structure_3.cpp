#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Fraction
{
    int num;
    int den;
};

void reduce(Fraction &a) //сокращение 
{
    int copyOfNum = a.num;
    int copyOfDen = a.den;
    while (copyOfNum != copyOfDen)
    {
        copyOfNum < copyOfDen ? copyOfDen -= copyOfNum : copyOfNum -= copyOfDen;
    }
    a.num /= copyOfNum;
    a.den /= copyOfDen;
}

Fraction sum(Fraction a, Fraction b)//сумма
{
    Fraction c;
    c.num = a.num * b.den + b.num * a.den;
    c.den = a.den * b.den;
    if (c.num > 0)
        reduce(c);
    return c;
}

Fraction substraction(Fraction a, Fraction b)//разность
{
    Fraction c;
    c.num = a.num * b.den - b.num * a.den;
    c.den = a.den * b.den;
    if (c.num > 0)
        reduce(c);
    return c;
}

Fraction multiplication(Fraction a, Fraction b)// умножение
{
    Fraction c;
    c.num = a.num * b.num;
    c.den = a.den * b.den;
    if (c.num > 0)
        reduce(c);
    return c;
}

Fraction division(Fraction a, Fraction b) // деление
{
    Fraction c;
    c.num = a.num * b.den;
    c.den = a.den * b.num;
    if (c.num > 0)
        reduce(c);
    return c;
}

Fraction str2drob(string str_drob) // строка в дробь
{
    Fraction droby;
    string num_cache;
    for (int i = 0; i < str_drob.length(); i++)
    {
        if (str_drob[i] == '/')
        {
            droby.num = stoi(num_cache);
            num_cache.clear();
        }
        else if (i == str_drob.length() - 1)
        {
            num_cache += str_drob[i];
            droby.den = stoi(num_cache);
        }
        else
            num_cache += str_drob[i];
    }
    return droby;
}

int main()
{
    string str_drob;
    cout << "Drob 1 x/y: ";
    cin >> str_drob;
    cout << endl;
    Fraction drob_1 = str2drob(str_drob);
    char oper;
    cout << "Operations:\n+\n-\n*\n/\ns - socratit\nd - dec\np - pravilnay" << endl
         << endl;
    cin >> oper;
    cout << endl;
    switch (oper)
    {
    case '+':
    {
        cout << "Drob 2 x/y: ";
        cin >> str_drob;
        cout << endl;
        Fraction drob_2 = str2drob(str_drob);
        Fraction drob_3 = sum(drob_1, drob_2);
        cout << drob_1.num << '/' << drob_1.den << " + " << drob_2.num << '/' << drob_2.den << " = ";
        if (drob_3.num == drob_3.den)
            cout << '1' << endl;
        else if (drob_3.num == 0)
            cout << '0' << endl;
        else
            cout << drob_3.num << '/' << drob_3.den << endl;
        break;
    }
    case '-':
    {
        cout << "Drob 2 x/y: ";
        cin >> str_drob;
        cout << endl;
        Fraction drob_2 = str2drob(str_drob);
        Fraction drob_3 = substraction(drob_1, drob_2);
        cout << drob_1.num << '/' << drob_1.den << " - " << drob_2.num << '/' << drob_2.den << " = ";
        if (drob_3.num == drob_3.den)
            cout << '1' << endl;
        else if (drob_3.num == 0)
            cout << '0' << endl;
        else
            cout << drob_3.num << '/' << drob_3.den << endl;
        break;
    }
    case '*':
    {
        cout << "Drob 2 x/y: ";
        cin >> str_drob;
        cout << endl;
        Fraction drob_2 = str2drob(str_drob);
        Fraction drob_3 = multiplication(drob_1, drob_2);
        cout << drob_1.num << '/' << drob_1.den << " * " << drob_2.num << '/' << drob_2.den << " = ";
        if (drob_3.num == drob_3.den)
            cout << '1' << endl;
        else if (drob_3.num == 0)
            cout << '0' << endl;
        else
            cout << drob_3.num << '/' << drob_3.den << endl;
        break;
    }
    case '/':
    {
        cout << "Drob 2 x/y: ";
        cin >> str_drob;
        cout << endl;
        Fraction drob_2 = str2drob(str_drob);
        Fraction drob_3 = division(drob_1, drob_2);
        cout << drob_1.num << '/' << drob_1.den << " / " << drob_2.num << '/' << drob_2.den << " = ";
        if (drob_3.num == drob_3.den && drob_3.den != 0)
            cout << '1' << endl;
        else if (drob_3.num == 0 && drob_3.den != 0)
            cout << '0' << endl;
        else if (drob_3.den == 0)
            cout << "error" << endl;
        else
            cout << drob_3.num << '/' << drob_3.den << endl;
        break;
    }
    case 's': // сокращение
    {
        cout << drob_1.num << '/' << drob_1.den << " = ";
        if (drob_1.num > 0)
            reduce(drob_1);
        if (drob_1.num == drob_1.den)
            cout << '1' << endl;
        else if (drob_1.num == 0)
            cout << '0' << endl;
        else
            cout << drob_1.num << '/' << drob_1.den << endl;
        break;
    }
    case 'd': // десятичная
    {
        cout << drob_1.num << '/' << drob_1.den << " = ";
        if (drob_1.num == drob_1.den)
            cout << '1' << endl;
        else
            cout << (drob_1.num) * 1.0 / drob_1.den << endl;
        break;
    }
    case 'p': // правильная
    {
        cout << drob_1.num << '/' << drob_1.den << " = ";
        if (drob_1.num == drob_1.den)
            cout << '1' << endl;
        else if (drob_1.num < drob_1.den && drob_1.num != 0)
            cout << drob_1.num << '/' << drob_1.den << endl;
        else if (drob_1.num > drob_1.den)
            cout << drob_1.num / drob_1.den << ' ' << drob_1.num % drob_1.den << '/' << drob_1.den << endl;
        else if (drob_1.num == 0)
            cout << '0' << endl;
        break;
    }
    default:
        cout << "incorrect operation";
    }
    return 0;
}