#include <iostream>
using namespace std;

int main()
{
    int n_strok = 10;
    int n_elem = 1;
    for (int i = 1; i <= n_strok; i++)
    {
        for (int j = 1; j <= n_elem; j++)
            cout << i - i % n_elem << " ";
        cout << endl;
        if (i % 2 == 0)
            n_elem++;
    }
    return 0;
}