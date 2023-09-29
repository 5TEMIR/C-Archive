#include <iostream>
using namespace std;

void task12()
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
        if (massive[i] == x)
        {
            for (int j = n; j > i + 1; j--)
            {
                massive[j] = massive[j - 1];
            }
            massive[i + 1] = y;
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
    task12();
    return 0;
}
// 1 5 1 3 2 1 8 3
// 1 1 3 1 1