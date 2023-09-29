#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "n = ";
    cin >> n;
    int **a = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        a[i] = new int[i + 1];
    //заполняю массив треугольника паскаля
    a[0][0] = 1;
    a[1][0] = a[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i][0] = 1;
        for (int j = 1; j < i; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        a[i][i] = 1;
    }
    //вывод коэффициентов
    for (int j = 0; j <= n; j++)
        cout << a[n][j] << " ";
    return 0;
}