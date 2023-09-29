#include <iostream>
using namespace std;

int **create(int n, int m) //создание массива
{
    int **massive = new int *[n]; //выделение пам€ти под массив
    for (int i = 0; i < n; i++)
        massive[i] = new int[m];
    for (int i = 0; i < n; i++) //заполн€ем массив
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

void delete_max(int **massive, int n, int m)
{
    int max = massive[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (massive[i][j] > max)
                max = massive[i][j];
    cout << "max = " << max << "\n\n";
    for (int j = 0; j < m; j++)
    {
        bool flag = false;
        for (int i = 0; i < n; i++)
            if (massive[i][j] == max)
            {
                flag = true;
                break;
            }
        if (flag)
        {
            for (int stol = j + 1; stol < m; stol++)
                for (int str = 0; str < n; str++)
                    massive[str][stol - 1] = massive[str][stol];
            m--;
            j--;
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
    delete_max(massive, n, m);
    return 0;
}
/*
4 5 8 2 1
2 4 1 3 9
4 3 7 2 3
9 9 2 7 4
4 6 8 1 3
*/