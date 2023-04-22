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

void delete_min(int **massive, int n, int m)
{
    int min = massive[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (massive[i][j] < min)
                min = massive[i][j];
    cout << "min = " << min << "\n\n";
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < m; j++)
            if (massive[i][j] == min)
            {
                flag = true;
                break;
            }
        if (flag)
        {
            for (int str = i + 1; str < n; str++)
                for (int stol = 0; stol < m; stol++)
                    massive[str - 1][stol] = massive[str][stol];
            n--;
            i--;
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
    int **massive = create(n, m); //создание массива
    print(massive, n, m);         //вывод на экран
    delete_min(massive, n, m);
    return 0;
}
/*
4 5 8 2 1
2 4 1 3 2
4 3 7 2 3
9 5 2 7 4
4 6 8 1 3
*/