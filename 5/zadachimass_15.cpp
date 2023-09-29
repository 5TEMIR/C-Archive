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
        if (!(mas[i] % 2) && mas[i] > max)
            max = mas[i];
    bool HET = true;
    for (int i = 0; i < n; i++)
        if (mas[i] == max){
            cout << i << ' ';
            HET = false;
        }
    if (HET)
        cout << "четных элементов нет";
    return 0;
}