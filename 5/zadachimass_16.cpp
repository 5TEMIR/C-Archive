#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int n;
    cout << "n = ";
    cin >> n;
    int *mas = new int[n];
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
    {
        mas[i] = rand() % 15;
        cout << mas[i] << " ";
    }
    cout << endl;

    int max = INT_MIN;
    for (int i = 0; i < n; i++)
        if (mas[i] > max)
            max = mas[i];
    cout << max << endl;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
        if (mas[i] < min)
            min = mas[i];
    cout << min << endl;

    int i_max, i_min;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] == max)
        {
            i_max = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (mas[i] == min)
        {
            i_min = i;
            break;
        }
    }

    mas[i_min] = max;
    mas[i_max] = min;
    
    for (int i = 0; i < n; i++)
        cout << mas[i] << ' ';
    return 0;
}