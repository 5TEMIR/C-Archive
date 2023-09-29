#include <iostream>
#include <vector>
#include <algorithm>

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
    int x, n;
    cout << "n = ";
    cin >> n;

    for (int i = 0; i < n; i++) // заполнение контейнера
    {
        cout << "vec[" << i << "] = ";
        cin >> x;
        vec.push_back(x);
    }
    cout << "\n\n";

    output_vec(vec);

    int min = *min_element(vec.begin(), vec.end()); // мин контейнера

    vector<int>::iterator iter_remove = remove(vec.begin(), vec.end(), min); // удаление элемента
    vec.erase(iter_remove, vec.end());

    output_vec(vec);

    return 0;
}

/*
10
4 8 3 9 4 6 3 7 8 4
*/