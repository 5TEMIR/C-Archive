#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int>> input_adj_list(int N) // смежный список для ориентрованного графа
{
    ifstream in("input_topol.txt");
    map<int, vector<int>> l_Adj;
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
            if (l_Adj.find(y) == l_Adj.end())
            {
                l_Adj[y].push_back(0);
                auto it = l_Adj.find(y);
                it->second.erase(it->second.begin());
            }
        }
    }
    for (int i = 0; i < N; i++)
        sort(l_Adj[i].begin(), l_Adj[i].end());
    return l_Adj;
}

void output_adj_list(map<int, vector<int>> Gr) // вывод списка смежности
{
    for (int i = 0; i < Gr.size(); i++)
    {
        cout << i << ": ";
        for (int vertex_adj : Gr[i])
        {
            cout << vertex_adj << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

const int N = 9;
map<int, vector<int>> Gr = input_adj_list(N);
int used[N];
vector<int> order;

void dfs(int x) // топологическая сортировка ориентированного графа
{
    used[x] = 1; // посетили - отметили
    for (int i = 0; i < Gr[x].size(); i++)
    { // начинаем посещать смежные вершины
        if (used[Gr[x][i]] == 0)
        { // если не посещали, то запускаем рекурсивно функию
            dfs(Gr[x][i]);
        }
    }
    order.push_back(x); // после выхода из рекурсии, добавляем в порядок топологии
}

void result()
{
    output_adj_list(Gr); // вывод

    for (int i = 0; i < N; i++)
        used[i] = 0;

    for (int i = 0; i < N; i++) // проходим все непосещённые вершины
        if (used[i] == 0)
            dfs(i);
    for (int i = N - 1; i >= 0; i--) // вывод в обратном порядке
        cout << order[i] << ' ';
}

int main()
{
    result();
    return 0;
}