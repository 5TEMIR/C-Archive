#include <iostream>
using namespace std;

template <typename X>
X **create(X c, int n, int m) //создание
{
    X **massive = new X *[n];
    for (int i = 0; i < n; i++)
        massive[i] = new X[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cout << "massive[" << i << "][" << j << "] = ";
            cin >> massive[i][j];
        }
    return massive;
}

template <typename X>
void print(X **massive, int n, int m) //вывод
{
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << massive[i][j] << " ";
}

template <typename X>
X **change(X **massive, int n, int m) //преобразование
{
    for (int i = 0; i < n / 2.0; i++)
        for (int j = 0; j < m; j++)
            swap(massive[i][j], massive[n - 1 - i][j]);
    return massive;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n, m;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    char c;
    do
    {
        cout << "Введите тип:\n1 - int\n2 - double\n3 - char\n4 - float\n";
        int k;
        cin >> k;
        switch (k)
        {
        case 1:
        {
            int c = 1;
            int **mas = create(c, n, m);
            cout << "INT:\n";
            print(mas, n, m);
            mas = change(mas, n, m);
            cout << "New:\n";
            print(mas, n, m);
            break;
        }
        case 2:
        {
            double c1 = 1;
            double **mas1 = create(c1, n, m);
            cout << "DOUBLE:\n";
            print(mas1, n, m);
            mas1 = change(mas1, n, m);
            cout << "New:\n";
            print(mas1, n, m);
            break;
        }
        case 3:
        {
            char c2 = '1';
            char **mas2 = create(c2, n, m);
            cout << "CHAR:\n";
            print(mas2, n, m);
            mas2 = change(mas2, n, m);
            cout << "New:\n";
            print(mas2, n, m);
            break;
        }
        case 4:
        {
            float c3 = 1;
            float **mas3 = create(c3, n, m);
            cout << "FLOAT:\n";
            print(mas3, n, m);
            mas3 = change(mas3, n, m);
            cout << "New:\n";
            print(mas3, n, m);
            break;
        }
        default:
            cout << "Неправильно введены данные\n";
        }
        cout << "Еще раз? Y - да, N - нет\n";
        cin >> c; // повторяем запуск программы пока не введем N
    } while (c != 'N');
    return 0;
}
/*
1 1 1
2 2 2
3 3 3
*/