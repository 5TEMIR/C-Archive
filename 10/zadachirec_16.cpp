#include <iostream>
#include <cmath>
using namespace std;

void print(int n, char a) //������ n �������� a
{
    for (int i = 0; i < n; i++)
        cout << a;
}

void F(int p, int n, char a, int N) // p - ��������, n - ��������
{
    if (n <= N)
    {
        print(p, ' ');             //������ ��������
        print(n, a);               //������ ����
        cout << endl;              //������� �� ��������� ������
        F(p - 1, n + 2, a + 2, N); //����� ������� ��� ��������� ������
        print(p, ' ');             //������ �����
        print(n, a);
        cout << endl;
    }
}

int main()
{
    int N;
    do
    {
        cout << "Input N <= 9" << endl; //���� ������
        cin >> N;
    } while (N > 9);
    if (N % 2 == 0)
        N--;
    F(N / 2, 1, '1', N); //����� �������
    return 0;
}
