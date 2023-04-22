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

    int a, b, sum = 0;
    cout << "Интервал:" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    for (a; a <= b; a++)
    {
        if (mas[a - 1] % 2 == 0)
            sum += mas[a - 1];
    }
    if (sum == 0)
        cout << "четных элементов нет";
    else
        cout << sum;
    return 0;
}