#include <iostream>
using namespace std;

int **create(int n, int m) //�������� �������
{
    int **massive = new int *[n]; //��������� ������ ��� ������
    for (int i = 0; i < n; i++)
        massive[i] = new int[m];
    for (int i = 0; i < n; i++) //��������� ������
        for (int j = 0; j < m; j++)
        {
            cout << "massive[" << i << "][";
            cout << j << "]=";
            cin >> massive[i][j];
        }
    cout << endl
         << endl;
    return massive;
}

void print(int **massive, int n, int m) //����� ������� �� �����
{
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << massive[i][j] << " ";
    cout << endl;
}

void change(int **a, int n, int m) //������ ������ �������
{
    int min = a[0][0], max = a[0][0]; //���. ����. ��� min, max
    int n_min = 0, n_max = 0;         //������ �����
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] < min)
            { //������ min
                min = a[i][j];
                n_min = i; //����� ������ c min
            }
            if (a[i][j] > max)
            { //��������� max
                max = a[i][j];
                n_max = i; //����� ������ c max
            }
        }
    for (int j = 0; j < m; j++) //����� �����
        swap(a[n_min][j], a[n_max][j]);
}

int main()
{
    int n, m; //����������� �������
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    int **massive = create(n, m); //�������� �������
    print(massive, n, m);         //����� �� �����
    change(massive, n, m);
    print(massive, n, m);
    return 0;
}