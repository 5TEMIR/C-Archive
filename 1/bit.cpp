#include <iostream>
using namespace std;

int task1()
{
    /*
    a<<b  a*2^b
    */
    cout << "Task 1" << endl;
    int i;
    cout << "i = ";
    cin >> i;
    cout << "2^" << i << " = " << (1 << i) << endl;
    return 0;
}

int task2()
{
    /*
    4 100
    i=1 10
    100 | 10 = 110 6
    */
    cout << "Task 2" << endl;
    int n, i;
    cout << "n = ";
    cin >> n;
    cout << "i = ";
    cin >> i;
    cout << ((1 << i) | n) << endl;
    return 0;
}

int task3()
{
    /*
    14 1110
    i=2 100 ~ 011
    1110 & 011 = 1010 10
    */
    cout << "Task 3" << endl;
    int n, i;
    cout << "n = ";
    cin >> n;
    cout << "i = ";
    cin >> i;
    cout << ((~(1 << i)) & n) << endl;
    return 0;
}

int task4()
{
    /*
    5 101
    i=1 10
    101 ^ 10 = 111 7

    7 111
    i=1 10
    111 ^ 10 = 101 5
    */
    cout << "Task 4" << endl;
    int n, i;
    cout << "n = ";
    cin >> n;
    cout << "i = ";
    cin >> i;
    cout << ((1 << i) ^ n) << endl;
    return 0;
}

int task5()
{
    /*
    1101
    0010
    0011 & 1101 = 0001

    1110
    0001
    0000 & 1110 = 0000
    */
    setlocale(LC_ALL, "RUS");
    cout << "Task 5" << endl;
    int n;
    cout << "n = ";
    cin >> n;
    if ((((~n) | 1) & n) == 0)
        cout << "Четное" << endl;
    else
        cout << "Нечетное" << endl;
    return 0;
}

int main()
{
    int t;
    cout << "Task - ";
    cin >> t;
    switch (t)
    {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    case 4:
        task4();
        break;
    case 5:
        task5();
        break;
    default:
        cout << "Not found" << endl;
    }
    system("Pause");
    return 0;
}