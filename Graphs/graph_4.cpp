#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

using namespace std;

vector<vector<int>> input_adj_list(int N)
{
    ifstream in("input.txt");
    vector<vector<int>> Gr;
    Gr.resize(N);
    int x, y;
    while (in.peek() != EOF)
    {
        in >> x >> y;
        if (x > N || y > N)
            continue;
        else
        {
            Gr[x].push_back(y);
            Gr[y].push_back(x);
        }
    }
    for (int i = 0; i < N; i++)
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
    return Gr;
}

void output_adj_list(vector<vector<int>> Gr) // вывод списка смежности
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

const int N = 7;
vector<vector<int>> Gr = input_adj_list(N);
int pr[N];
int used[N];
vector<vector<int>> cycles;
vector<vector<int>> cycles_sort;

void add_cycles(int start, int end)
{
    int cur = end;
    vector<int> tmp;
    while (cur != start)
    {
        tmp.push_back(cur);
        cur = pr[cur];
    }
    tmp.push_back(start);
    reverse(tmp.begin(), tmp.end());
    cycles.push_back(tmp);
    sort(tmp.begin(), tmp.end());
    cycles_sort.push_back(tmp);
}

void find_cycles(int x)
{
    used[x] = 1;
    for (int i = 0; i < Gr[x].size(); i++)
    {
        if (pr[Gr[x][i]] == x)
            continue;
        if (used[Gr[x][i]] == 0)
        {
            pr[Gr[x][i]] = x;
            find_cycles(Gr[x][i]);
        }
        else if (used[Gr[x][i]] == 1)
            add_cycles(Gr[x][i], x);
    }
    used[x] = 0;
}

void result()
{
    output_adj_list(Gr);
    
    for (int i = 0; i < N; i++)
    {
        pr[i] = -1;
        used[i] = 0;
    }
    find_cycles(0);
    
    map<vector<int>, int> CYCLES;
    for (int i = 0; i < cycles_sort.size(); i++)
    {
        if (cycles_sort[i].size() > 2 && CYCLES.count(cycles_sort[i]) == 0)
        {
            CYCLES[cycles_sort[i]] = i;
        }
    }
    for (auto it = CYCLES.begin(); it != CYCLES.end(); it++)
    {
        int i = it->second;
        cout << "cycle: ";
        for (int j = 0; j < cycles[i].size(); j++)
        {
            cout << cycles[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    result();
    return 0;
}