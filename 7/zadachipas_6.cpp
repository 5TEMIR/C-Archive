#include <iostream>
using namespace std;

int *create(int n) //создание массива
{
    int *massive = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        cout << "massive[" << i << "] = ";
        cin >> massive[i];
    }
    cout << endl;
    return massive;
}

void print(int *massive, int n) //вывод массива на экран
{
    for (int i = 0; i < n + 1; i++)
        cout << massive[i] << " ";
    cout << endl;
}

void new_mnogochlen(int *massive, int *massive2, int n) //новый многочлен
{
    for (int k = 0; k < 2 + n + 1; k++)
    {
        float S = 0;
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < 2 + 1; j++)
                if (i + j == k)
                    S += massive[i] * massive2[j];
        cout << S << " ";
    }
}
int main()
{
    int n, A;
    cout << "A = ";
    cin >> A;
    int mnogochlen[] = {-A, 0, 1};
    cout << "n = ";
    cin >> n;
    int *massive = create(n);
    print(massive, n);
    new_mnogochlen(massive, mnogochlen, n);
    return 0;
}