#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void output_vec(vector<int> vctr)
{
    for (vector<int>::iterator iter = vctr.begin(); iter != vctr.end(); iter++) // вывод контейнера
        cout << *iter << " ";
    cout << "\n\n";
}

int main()
{
    vector<int> vec;
    int x, n, X;
    cout << "n = ";
    cin >> n;
    cout << "\n";

    for (int i = 0; i < n; i++) // заполнение контейнера
    {
        cout << "vec[" << i << "] = ";
        cin >> x;
        vec.push_back(x);
    }
    cout << "\n\n";

    output_vec(vec);

    cout << "X = ";
    cin >> X;
    cout << "\n";

    vector<int> temp(vec); // копия вектора
    replace_if(
        temp.begin(), temp.end(), [X](int x)
        { return x % X != 0; },
        0);                                                                // замена
    cout << "sum = " << accumulate(temp.begin(), temp.end(), 0) << "\n\n"; // сумма элементов кратные X

    int min = *min_element(vec.begin(), vec.end()); // мин контейнера
    cout << "min = " << min << "\n\n";

    int max = *max_element(vec.begin(), vec.end()); // макс контейнера
    replace_if(                                     // замена четных на макс
        vec.begin(), vec.end(), [](int x)
        { return x % 2 == 0; },
        max);

    output_vec(vec);

    return 0;
}

/*
10
4 8 3 9 4 6 3 7 8 4
*/