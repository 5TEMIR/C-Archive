#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct stack
{
    int inf;
    stack *next;
};

void push(stack *&h, int x)
{
    stack *r = new stack; // создаем новый элемент
    r->inf = x;           // поле inf = x
    r->next = h;          // следующим элементов является h
    h = r;                // теперь r является головой
}

int pop(stack *&h)
{
    int i = h->inf; // значение первого элемента
    stack *r = h;   // указатель на голову стека
    h = h->next;    // переносим указатель на следующий элемент
    delete r;       // удаляем первый элемент
    return i;       // возвращаем значение
}

vector<vector<int>> input_adj_list(int N) // смежный список для неориентированного графа
{
    ifstream in("input_Euler.txt");
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
    {
        sort(Gr[i].begin(), Gr[i].end());
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
    }
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

const int N = 6;
vector<vector<int>> l_Adj = input_adj_list(N);
// int pr[N];
// int used[N];

int vert_rate(vector<vector<int>> Gr, int vert) // степень вершины
{
    int rate = 0;
    for (int j = 0; j < Gr[vert].size(); j++)
        rate++;
    return rate;
}

void result()
{
    vector<int> res;

    int *rates = new int[N]; // определяем степеь каждой вершины
    for (int i = 0; i < N; i++)
        rates[i] = vert_rate(l_Adj, i);

    int v1 = -1, v2 = -1; // ставим флаги
    for (int i = 0; i < N; i++)
    {
        if (rates[i] % 2 != 0) // ищем вершины с нечетной степенью
        {
            if (v1 == -1)
                v1 = i;
            else if (v2 == -1)
                v2 = i;
            else
                break;
        }
    }

    if (v1 != -1) // есть вершины с нечетной степенью
    {
        l_Adj[v1].push_back(v2); // добовляем ребро
        l_Adj[v2].push_back(v1);
        sort(l_Adj[v1].begin(), l_Adj[v1].end());
        sort(l_Adj[v2].begin(), l_Adj[v2].end());
    }

    stack *visits = NULL; // начинаем посещать вершины
    push(visits, v1);

    while (visits)
    {
        int vert = visits->inf;          // смотрим голову
        if (vert_rate(l_Adj, vert) != 0) // есть степнь
        {
            int vert_adj = l_Adj[vert][0]; // находим смежную ей вершину
            push(visits, vert_adj);
            l_Adj[vert].erase(l_Adj[vert].begin()); // удаляем ребро
            l_Adj[vert_adj].erase(remove(l_Adj[vert_adj].begin(), l_Adj[vert_adj].end(), vert));
        }
        else // степени нет
        {
            res.push_back(vert); // добовляем в результат
            pop(visits);
        }
    }
    if (v1 != -1) // есть вершины с нечетной степенью, то есть наше фиктивное ребро
    {
        for (int i = 0; i + 1 < res.size(); i++)
        {
            if (res[i] == v1 && res[i + 1] == v2 || res[i] == v2 && res[i + 1] == v1)
            {
                vector<int> temp;
                for (int j = i + 1; j < res.size(); j++)
                    temp.push_back(res[j]);
                for (int j = 1; j <= i; j++)
                    temp.push_back(res[j]);
                res = temp;
            }
        }
    }
    bool Euler = true;
    for (vector<int> vert : l_Adj)
    {
        if (vert.size() != 0) // осталось ребро, значит граф зациклен
        {
            Euler = false;
            break;
        }
    }
    if (Euler) // вывод пути Эйлера
        for (int i : res)
            cout << i << ' ';
}

int main()
{
    output_adj_list(l_Adj);
    result();
    return 0;
}