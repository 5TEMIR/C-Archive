#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N, i, j;
    cout << "N = ";
    cin >> N;
    for (i = 3; N; i += 2) //���� ��� ������ N
    {
        float sq = sqrt(i);
        bool prime = true;
        for (j = 2; j <= sq; ++j) //���� ��� ���������� �������
            if (i % j == 0)
            {
                prime = false;
                break;
            }
        if (prime)
        {
            cout << i << ' ';
            --N;
        }
    }
    return 0;
}