#include <iostream>
using namespace std;

int **create(int n, int m) //создание массива
{
    int **massive = new int *[n]; //выделение памяти под массив
    for (int i = 0; i < n; i++)
        massive[i] = new int[m];
    for (int i = 0; i < n; i++) //заполняем массив
        for (int j = 0; j < m; j++)
        {
            cout << "massive[" << i << "][";
            cout << j << "]=";
            cin >> massive[i][j];
        }
    cout << endl
         << endl;
    return massive;
}

void print(int **massive, int n, int m) //вывод массива на экран
{
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << massive[i][j] << " ";
    cout << endl;
}

void change(int **a, int n, int m) //меняем строки местами
{
    int min = a[0][0], max = a[0][0]; //нач. знач. для min, max
    int n_min = 0, n_max = 0;         //номера строк
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] < min)
            { //первый min
                min = a[i][j];
                n_min = i; //номер строки c min
            }
            if (a[i][j] > max)
            { //последний max
                max = a[i][j];
                n_max = i; //номер строки c max
            }
        }
    for (int j = 0; j < m; j++) //обмен строк
        swap(a[n_min][j], a[n_max][j]);
}

int main()
{
    int n, m; //размерность массива
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    int **massive = create(n, m); //создание массива
    print(massive, n, m);         //вывод на экран
    change(massive, n, m);
    print(massive, n, m);
    return 0;
}