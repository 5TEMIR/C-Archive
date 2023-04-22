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
            massive[i][j] = i + 1;
        }
    return massive;
}

void print(int **massive, int n, int m) //вывод массива на экран
{
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << massive[i][j] << " ";
    cout << endl;
}

void change(int **massive, int n, int m) //преобразование массива
{
    for (int i = 0; i < n / 2.0; i++)
        for (int j = 0; j < m; j++)
            swap(massive[i][j], massive[n - 1 - i][j]);
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