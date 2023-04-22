#include <iostream>
using namespace std;

void task8()
{
    int n;
    cout << "n = ";
    cin >> n;
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

    int min = INT_MAX;
    for (int i = 0; i < n; i++)
        if (massive[i] < min)
            min = massive[i];
    cout << "min = " << min << "\n\n";

    for (int i = 0; i < n; i++)
    {
        if (massive[i] == min)
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
    task8();
    return 0;
}