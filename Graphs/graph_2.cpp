#include <iostream>
#include <fstream>
#include <list>
#include <map>

using namespace std;

map<int, list<int>> input_adj_list() // создание списка смежности
{
    ifstream in("input.txt");
    map<int, list<int>> l_Adj;
    int x, y;
    while (in.peek() != EOF)
    {
        in >> x >> y;
        auto it_x = l_Adj.find(x);
        bool fl = true;
        if (it_x != l_Adj.end())
        {
            for (auto it_y = it_x->second.begin(); it_y != it_x->second.end(); it_y++)
                if (*it_y == y)
                {
                    fl = false;
                    break;
                }
        }
        if (fl)
        {
            l_Adj[x].push_back(y);
            l_Adj[y].push_back(x);
        }
    }
    return l_Adj;
}

void output_adj_list(map<int, list<int>> l_Adj) // вывод списка смежности
{
    for (auto it = l_Adj.begin(); it != l_Adj.end(); it++)
    {
        cout << it->first << " : ";
        for (auto it_1 = it->second.begin(); it_1 != it->second.end(); it_1++)
            cout << *it_1 << "; ";
        cout << endl;
    }
    cout << endl;
}

void result(map<int, list<int>> &l_Adj, int A, int B) // Вставить в граф ребро, соединяющее вершины A и B
{
    if (!l_Adj.count(A) || !l_Adj.count(A))
        return;
    else
    {
        l_Adj[A].push_back(B);
        l_Adj[A].sort();
        l_Adj[A].unique();
        l_Adj[B].push_back(A);
        l_Adj[B].sort();
        l_Adj[B].unique();
    }
}

int main()
{
    map<int, list<int>> l_Adj = input_adj_list();
    output_adj_list(l_Adj);
    result(l_Adj, 0, 1);
    output_adj_list(l_Adj);
    return 0;
}