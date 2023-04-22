#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void output_vec(vector<int> vctr)
{
    for (vector<int>::iterator iter = vctr.begin(); iter != vctr.end(); iter++) // вывод контейнера
        cout << *iter << " ";
    cout << "\n\n";
}

set<int> set_n(int n) //разделения числа на цифры
{
    set<int> S;
    while (n != 0)
    {
        S.insert(n % 10);
        n /= 10;
    }
    return S;
}

int main()
{
    vector<int> input;
    int x, n;
    cout << "n = ";
    cin >> n;

    for (int i = 0; i < n; i++) // заполнение контейнера
    {
        cout << "input[" << i << "] = ";
        cin >> x;
        input.push_back(x);
    }
    cout << "\n\n";

    output_vec(input);

    set<int> digits, double_digits, other_digits, result;
    for (auto iter = input.begin(); iter != input.end(); iter++) //находим цифры из двузначных чисел и цифры из остальных чисел
    {
        digits = set_n(*iter);
        if (*iter > 9 && *iter <= 99)
            double_digits.insert(digits.begin(), digits.end());
        else
            other_digits.insert(digits.begin(), digits.end());
    }

    set_difference(double_digits.begin(), double_digits.end(), other_digits.begin(), other_digits.end(), inserter(result, result.begin())); // находим разность
    for (auto iter = result.begin(); iter != result.end(); iter++)
        cout << *iter << " ";

    return 0;
}
/*
8
1 15 124 33 28 1473 176 143
*/