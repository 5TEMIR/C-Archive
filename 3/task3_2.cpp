#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N, i, j;
    cout << "N = ";
    cin >> N;
    for (i = 3; N; i += 2) //цикл для первых N
    {
        float sq = sqrt(i);
        bool prime = true;
        for (j = 2; j <= sq; ++j) //цикл для нахождения простых
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