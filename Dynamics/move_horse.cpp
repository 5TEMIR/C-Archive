#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

struct queue // очередь
{
    pair<int, int> inf;
    queue *next;
};

void push(queue *&h, queue *&t, pair<int, int> x) // вставка элемента в очередь
{
    queue *r = new queue; // создаем новый элемент
    r->inf = x;
    r->next = NULL; // всегда последний
    if (!h && !t)
    {              // если очередь пуста
        h = t = r; // это и голова и хвост
    }
    else
    {
        t->next = r; // r - следующий для хвоста
        t = r;       // теперь r - хвост
    }
}

pair<int, int> pop(queue *&h, queue *&t) // удаление элемента из очереди
{
    queue *r = h;              // создаем указатель на голову
    pair<int, int> i = h->inf; // сохраняем значение головы
    h = h->next;               // сдвигаем указатель на следующий элемент
    if (!h)                    // если удаляем последний элемент из очереди
        t = NULL;
    delete r; // удаляем первый элемент
    return i;
}

bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= 8 || y >= 8)
    {
        return false;
    }

    return true;
}

map<pair<int, int>, vector<pair<int, int>>> input_adj_list(int x, int y)
{
    map<pair<int, int>, vector<pair<int, int>>> Gr;
    int row[] = {1, 1, -1, -1, 2, 2, -2, -2}; // смещение в строке
    int col[] = {2, -2, 2, -2, 1, -1, 1, -1}; // смещение в стобце
    for (int k = 0; k < 8; k++)
    {
        int newX = x + row[k];
        int newY = y + col[k];
        if (isValid(newX, newY))
        {
            Gr[pair(x, y)].push_back(pair(newX, newY));
        }
    }

    auto iter = Gr.begin();
    auto end_iter = Gr.end();
    while (iter != end_iter)
    {
        for (pair<int, int> i : Gr[iter->first])
        {
            if (Gr.count(i) == 0)
            {
                for (int k = 0; k < 8; k++)
                {
                    int newX = i.first + row[k];
                    int newY = i.second + col[k];
                    if (isValid(newX, newY))
                    {
                        Gr[pair(i.first, i.second)].push_back(pair(newX, newY));
                    }
                }
            }
            else
                continue;
        }
        auto end_iter = Gr.end();
        iter++;
    }

    return Gr;
}

void output_adj_list(map<pair<int, int>, vector<pair<int, int>>> Gr) // вывод списка смежности
{
    for (auto iter = Gr.begin(); iter != Gr.end(); iter++)
    {
        cout << iter->first.first << iter->first.second << ": ";
        for (pair<int, int> i : Gr[iter->first])
            cout << i.first << i.second << ' ';
        cout << "\n\n";
    }
}

vector<pair<int, int>> walk_in_width(map<pair<int, int>, vector<pair<int, int>>> Gr, int N, int x_s, int y_s, int x_e, int y_e) // обход в ширину
{
    queue *visits = NULL;
    queue *tail = NULL;
    map<pair<int, int>, int> dist; // расстояния
    for (auto iter = Gr.begin(); iter != Gr.end(); iter++)
    {
        dist[iter->first] = N; // задаем максимальное расстояние для будущего сравнения
    }
    map<pair<int, int>, pair<int, int>> p; // предки
    dist[pair(x_s, y_s)] = 0;
    push(visits, tail, pair(x_s, y_s));
    while (visits)
    {
        pair<int, int> v = pop(visits, tail);
        for (pair<int, int> u : Gr[v])
        {
            if (dist[u] > dist[v] + 1)
            {
                p[u] = v;
                dist[u] = dist[v] + 1;
                push(visits, tail, u);
            }
        }
    }
    if (dist[pair(x_e, y_e)] == N) // пути нет - пусто
    {
        return {};
    }

    vector<pair<int, int>> path; // наш путь
    pair<int, int> t = pair(x_e, y_e);
    while (true)
    {
        path.push_back(t);
        if (p.count(t) != 0)
            t = p[t];
        else
            break;
    }
    reverse(path.begin(), path.end()); // путь был в обр порядке - переворачиваем
    return path;
}

int main()
{
    cout << "start: ";
    string start;
    cin >> start;
    cout << "end: ";
    string end;
    cin >> end;
    int x1, x2, y1, y2;
    string alfa = "ABCDEFGH";
    find(alfa.begin(), alfa.end(), start[0]);
    x1 = alfa.find(start[0]);
    y1 = start[1] - 48 - 1;
    x2 = alfa.find(end[0]);
    y2 = end[1] - 48 - 1;
    map<pair<int, int>, vector<pair<int, int>>> Gr = input_adj_list(x1, y1);
    //output_adj_list(Gr);
    vector<pair<int, int>> way = walk_in_width(Gr, Gr.size(), x1, y1, x2, y2);
    for (pair<int, int> i : way)
        cout << alfa[i.first] << i.second + 1 << ' ';
}

/*
A2
E6
*/