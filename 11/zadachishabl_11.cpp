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
    cout << endl;
    return massive;
}

template <typename X>
X *create_x_str(X c, int m) //создание
{
    X *massive = new X[m];
    for (int i = 0; i < m; i++)
    {
        cout << "massive_x[" << i << "] = ";
        cin >> massive[i];
    }
    cout << endl;
    return massive;
}

template <typename X>
void print(X **massive, int n, int m) //вывод
{
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << massive[i][j] << " ";
    cout << endl;
}

template <typename X>
void print_x_str(X *massive, int m) //вывод
{
    for (int j = 0; j < m; j++)
        cout << massive[j] << " ";
    cout << "\n\n";
}

template <typename X>
X **change(X **massive, int n, int m, X *massive_x_str) //преобразование
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
                massive[i][j] = massive_x_str[j];
        }
    }
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
            int *mas_x = create_x_str(c, m);
            cout << "INT:\n";
            print(mas, n, m);
            print_x_str(mas_x, m);
            mas = change(mas, n, m, mas_x);
            cout << "New:\n";
            print(mas, n, m);
            break;
        }
        case 2:
        {
            double c1 = 1;
            double **mas1 = create(c1, n, m);
            double *mas_x = create_x_str(c1, m);
            cout << "DOUBLE:\n";
            print(mas1, n, m);
            print_x_str(mas_x, m);
            mas1 = change(mas1, n, m, mas_x);
            cout << "New:\n";
            print(mas1, n, m);
            break;
        }
        case 3:
        {
            char c2 = '1';
            char **mas2 = create(c2, n, m);
            char *mas_x = create_x_str(c2, m);
            cout << "CHAR:\n";
            print(mas2, n, m);
            print_x_str(mas_x, m);
            mas2 = change(mas2, n, m, mas_x);
            cout << "New:\n";
            print(mas2, n, m);
            break;
        }
        case 4:
        {
            float c3 = 1;
            float **mas3 = create(c3, n, m);
            float *mas_x = create_x_str(c3, m);
            cout << "FLOAT:\n";
            print(mas3, n, m);
            print_x_str(mas_x, m);
            mas3 = change(mas3, n, m, mas_x);
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
5 5 5

1 1 1
2 2 2
3 3 3
*/