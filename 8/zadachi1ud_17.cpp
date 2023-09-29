#include <iostream>
using namespace std;

void task17()
{
    int n, x, y;
    cout << "n = ";
    cin >> n;
    int m = 2 * n;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << "\n\n";
    //создание
    int *massive = new int[m];
    for (int i = 0; i < n; i++)
    {
        cout << "massive[" << i << "] = ";
        cin >> massive[i];
    }
    cout << "\n\n";
    //вывод
    for (int i = 0; i < n; i++)
        cout << massive[i] << ' ';
    cout << "\n\n";
    //вставка
    for (int i = 0; i < n; i++)
    {
        if (massive[i] % 10 == x)
        {
            for (int j = n; j > i; j--)
            {
                massive[j] = massive[j - 1];
            }
            massive[i] = y;
            n++;
            i++;
        }
    }
    //вывод
    for (int i = 0; i < n; i++)
        cout << massive[i] << ' ';
    cout << endl;
}

int main()
{
    task17();
    return 0;
}
// 11 5 31 3 2 11 8 3
// 21 11 3 41 11

// 4 8 15 17