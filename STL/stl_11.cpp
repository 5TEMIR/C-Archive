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
    vector<int> vec1;
    vector<int> vec2;
    int n1, n2, x;

    cout << "n1 = ";
    cin >> n1;
    cout << "\n";
    for (int i = 0; i < n1; i++) // заполнение контейнера
    {
        cout << "vec1[" << i << "] = ";
        cin >> x;
        vec1.push_back(x);
    }
    cout << "\n\n";

    cout << "n2 = ";
    cin >> n2;
    cout << "\n";
    for (int i = 0; i < n2; i++) // заполнение контейнера
    {
        cout << "vec2[" << i << "] = ";
        cin >> x;
        vec2.push_back(x);
    }
    cout << "\n\n";

    output_vec(vec1);

    output_vec(vec2);

    vector<int>::iterator iter_remove1 = remove_if(vec1.begin(), vec1.end(), [](int e)
                                                   { return e % 2 == 0; }); // удаление четных в первом
    vec1.erase(iter_remove1, vec1.end());

    output_vec(vec1);

    vector<int>::iterator iter_remove2 = remove_if(vec2.begin(), vec2.end(), [](int e)
                                                   { return e % 2 != 0; }); // удаление нечетных во втором
    vec2.erase(iter_remove2, vec2.end());

    output_vec(vec2);

    vec1.insert(vec1.end(), vec2.begin(), vec2.end()); // объединение

    sort(vec1.begin(), vec1.end()); // сортировка

    output_vec(vec1);

    return 0;
}

/*
10
4 8 3 9 4 6 3 7 8 4
15
5 9 5 2 7 5 8 3 9 3 5 7 4 5 8
*/