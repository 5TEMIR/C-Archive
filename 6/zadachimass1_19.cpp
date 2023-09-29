#include <iostream>
using namespace std;

int **create(int n) //�������� �������
{
    int **massive = new int *[n]; //��������� ������ ��� ������
    int k = 0;
    for (int i = 0; i < n; i++)
        massive[i] = new int[n];
    for (int j = 0; j < n; j++) //��������� ������
        for (int i = 0; i < n; i++)
        {
            massive[abs((j % 2) * (n - 1) - i)][j] = k;
            k++;
        }

    return massive;
}

void print(int **massive, int n) //����� ������� �� �����
{
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < n; j++)
            cout << massive[i][j] << " ";
    cout << endl;
}

int main()
{
    int n, m; //����������� �������
    cout << "n = ";
    cin >> n;
    int **massive = create(n); //�������� �������
    print(massive, n);         //����� �� �����
    return 0;
}