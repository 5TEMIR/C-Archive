#include <iostream>
using namespace std;

int **create(int n, int m) //создание массива
{
    int **massive = new int *[2 * n]; //выделение памяти под массив
    for (int i = 0; i < 2 * n; i++)
        massive[i] = new int[m];
    for (int i = 0; i < n; i++) //заполняем массив
        for (int j = 0; j < m; j++)
        {
            cout << "massive[" << i << "][";
            cout << j << "]=";
            cin >> massive[i][j];
        }
    cout << "\n\n";
    return massive;
}

void print(int **massive, int n, int m) //вывод массива на экран
{
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << massive[i][j] << " ";
    cout << endl;
}

int *create_x(int n) //создание массива
{
    int *massive = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "X[" << i << "] = ";
        cin >> massive[i];
    }
    cout << endl;
    return massive;
}

void print_x(int *massive, int n) //вывод массива на экран
{
    for (int i = 0; i < n; i++)
        cout << massive[i] << " ";
    cout << "\n\n";
}

void past(int **massive, int n, int m, int *X)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
            if (massive[i][j] < 0)
            {
                flag = false;
                break;
            }
        if (flag)
        {
            for (int str = n; str > i + 1; str--)
                for (int stol = 0; stol < m; stol++)
                    massive[str][stol] = massive[str - 1][stol];
            for (int stol = 0; stol < m; stol++)
                massive[i + 1][stol] = X[stol];
            n++;
            i++;
        }
    }
    print(massive, n, m);
}

int main()
{
    int n, m; //размерность массива
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    cout << endl;
    int *X = create_x(m);
    int **massive = create(n, m); //создание массива
    print_x(X, m);
    print(massive, n, m); //вывод на экран
    past(massive, n, m, X);
    return 0;
}
/*
0 0 0 0 0

1 1 1 1 1
-2 2 -2 2 2
3 3 -3 3 3
4 4 4 4 4
5 5 5 5 5
*/