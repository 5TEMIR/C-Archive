#include <iostream>
using namespace std;

void task2()
{
    int n, X;
    cout << "n = ";
    cin >> n;
    cout << "X = ";
    cin >> X;
    cout << endl;

    float *massive = new float[n];
    for (int i = 0; i < n; i++)
    {
        float x;
        cout << "massive[" << i << "] = ";
        cin >> x;
        massive[i] = x;
    }
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << massive[i] << ' ';
    cout << "\n\n";

    for (int i = 0; i < n; i++)
    {
        if (massive[i] == X)
        {
            for (int j = i + 1; j < n; j++)
            {
                float b = massive[j];
                massive[j - 1] = b;
            }
            massive[n - 1] = 1.5;
            i--;
            n--;
        }
    }

    for (int i = 0; i < n; i++)
        cout << massive[i] << ' ';
    cout << endl;
}

int main()
{
    task2();
    return 0;
}