#include <iostream>
#include <cmath>
using namespace std;

void print(int n, char a) //печать n символов a
{
    for (int i = 0; i < n; i++)
        cout << a;
}

void F(int p, int n, char a, int N) // p - пробелов, n - символов
{
    if (n <= N)
    {
        print(p, ' ');             //печать пробелов
        print(n, a);               //печать цифр
        cout << endl;              //переход на следующую строку
        F(p - 1, n + 2, a + 2, N); //вызов функции дл€ следующей строки
        print(p, ' ');             //нижн€€ часть
        print(n, a);
        cout << endl;
    }
}

int main()
{
    int N;
    do
    {
        cout << "Input N <= 9" << endl; //ввод данных
        cin >> N;
    } while (N > 9);
    if (N % 2 == 0)
        N--;
    F(N / 2, 1, '1', N); //вызов функции
    return 0;
}
