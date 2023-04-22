#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int N = 1000;
    float chis = 2.0, znam = 1.0;
    float proiz = 1, proiz_back = 2, eps = 0.01;
    cout << left << setw(3) << "n"
         << "\t|" << setw(10) << "proiz"
         << "\t|" << setw(10) << "a" << endl;
    for (int i = 1; abs(proiz - proiz_back) > eps && i <= N; i++)
    {
        proiz_back = proiz;
        proiz *= (chis / znam);
        if (i % 2 == 0)
            chis += 2;
        else
            znam += 2;
        cout << left << setw(3) << i << "\t|" << setw(10) << proiz << "\t|" << setw(10) << abs(proiz - proiz_back) << endl;
    }
    return 0;
}