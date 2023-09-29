#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

struct queue // очередь
{
    int inf;
    queue *next;
};

void push(queue *&h, queue *&t, int x) // вставка элемента в очередь
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

int pop(queue *&h, queue *&t) // удаление элемента из очереди
{
    queue *r = h;   // создаем указатель на голову
    int i = h->inf; // сохраняем значение головы
    h = h->next;    // сдвигаем указатель на следующий элемент
    if (!h)         // если удаляем последний элемент из очереди
        t = NULL;
    delete r; // удаляем первый элемент
    return i;
}

vector<vector<int>> input_adj_list(int N) // создание списка смежности
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

vector<int> walk_in_width(vector<vector<int>> Gr, int N, int A, int B) // обход в ширину
{
    queue *visits = NULL;
    queue *tail = NULL;
    vector<int> dist(N, N); // расстояния
    vector<int> p(N, -1);   // предки
    dist[A] = 0;            // дистанция до начала 0
    push(visits, tail, A);  // посетили
    while (visits)
    {
        int v = pop(visits, tail); // смотрим голову не
        for (int u : Gr[v])
        { // перебираем смежные вершины
            if (dist[u] > dist[v] + 1)
            {                          // смежная вершина далеко
                p[u] = v;              // помечаем предка
                dist[u] = dist[v] + 1; // обновляем дистанцию для смежной вершины
                push(visits, tail, u); // посетили
            }
        }
    }
    if (dist[B] == N) // пути нет - пусто
    {
        return {};
    }

    vector<int> path; // наш путь
    int t = B;
    while (t != -1)
    {
        path.push_back(t); // по предкам находим путь в обратном порядке
        t = p[t];
    }
    reverse(path.begin(), path.end()); // путь был в обратном порядке - переворачиваем
    return path;
}

int main()
{
    vector<vector<int>> Gr = input_adj_list(7);
    output_adj_list(Gr);
    cout << "start: ";
    int start;
    cin >> start;
    cout << "end: ";
    int end;
    cin >> end;
    vector<int> way = walk_in_width(Gr, 7, start, end);
    for (int i : way)
        cout << i << ' ';
}
