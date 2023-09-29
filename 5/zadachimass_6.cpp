#include <iostream>
#include <cmath>
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

    int X;
    bool HET = true;
    cout << "X = ";
    cin >> X;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] % X != 0)
        {
            cout << i << ' ';
            HET = false;
        }
    }
    if (HET)
        cout << "таких элементов нет";
    return 0;
}