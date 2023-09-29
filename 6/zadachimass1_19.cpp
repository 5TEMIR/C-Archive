#include <iostream>
using namespace std;

int **create(int n) //создание массива
{
    int **massive = new int *[n]; //выделение пам€ти под массив
    int k = 0;
    for (int i = 0; i < n; i++)
        massive[i] = new int[n];
    for (int j = 0; j < n; j++) //заполн€ем массив
        for (int i = 0; i < n; i++)
        {
            massive[abs((j % 2) * (n - 1) - i)][j] = k;
            k++;
        }

    return massive;
}

void print(int **massive, int n) //вывод массива на экран
{
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < n; j++)
            cout << massive[i][j] << " ";
    cout << endl;
}

int main()
{
    int n, m; //размерность массива
    cout << "n = ";
    cin >> n;
    int **massive = create(n); //создание массива
    print(massive, n);         //вывод на экран
    return 0;
}