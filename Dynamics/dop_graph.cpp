#include <iostream>
#include <vector>

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

struct stack
{
    char inf;
    stack *next;
};

void push(stack *&h, char x)
{
    stack *r = new stack; // создаем новый элемент
    r->inf = x;           // поле inf = x
    r->next = h;          // следующим элементов является h
    h = r;                // теперь r является головой
}

char pop(stack *&h)
{
    char i = h->inf; // значение первого элемента
    stack *r = h;    // указатель на голову стека
    h = h->next;     // переносим указатель на следующий элемент
    delete r;        // удаляем первый элемент
    return i;        // возвращаем значение
}

vector<vector<int>> input_adj_list()
{
    int vertex_n;
    cout << "N = ";
    cin >> vertex_n; // вводим количество вершин
    vector<vector<int>> Gr;
    Gr.resize(vertex_n);
    for (int i = 0; i < vertex_n; i++)
    {
        int vertex_n_adj;
        cout << i << ": ";
        cin >> vertex_n_adj; // вводим количество смежных вершин
        Gr[i].resize(vertex_n_adj);
        for (int j = 0; j < vertex_n_adj; j++)
        {
            cin >> Gr[i][j];
        }
    }
    cout << endl;
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

void walk_in_width(vector<vector<int>> Gr, int N, int x) // обход в ширину
{
    queue *visits = NULL;
    queue *tail = NULL;
    int A[N];
    for (int i = 0; i < N; i++)
        A[i] = 0;
    A[x] = 1;
    cout << x << ' ';
    push(visits, tail, x);
    while (visits)
    {
        x = pop(visits, tail);
        for (int i = 0; i < Gr[x].size(); i++)
        {
            if (A[Gr[x][i]] == 0)
            {
                int y;
                y = Gr[x][i];
                A[y] = 1;
                push(visits, tail, y);
                cout << y << ' ';
            }
        }
    }
    cout << endl;
}

void walk_in_depth(vector<vector<int>> Gr, int N, int x) // обход в глубину
{
    stack *visits = NULL;
    int A[N];
    for (int i = 0; i < N; i++)
        A[i] = 0;
    A[x] = 1;
    push(visits, x);
    cout << x << ' ';
    while (visits)
    {
        bool fl = false;
        int y;
        x = visits->inf;
        for (int i = 0; i < Gr[x].size(); i++)
        {
            if (A[Gr[x][i]] == 0)
            {
                y = Gr[x][i];
                fl = true;
                break;
            }
        }
        if (fl == true)
        {
            A[y] = 1;
            push(visits, y);
            cout << y << ' ';
        }
        else
            pop(visits);
    }
}

int main()
{
    vector<vector<int>> Gr = input_adj_list();
    output_adj_list(Gr);
    cout << "BFS" << endl;
    walk_in_width(Gr, Gr.size(), 0);
    cout << "DFS" << endl;
    walk_in_depth(Gr, Gr.size(), 0);
    return 0;
}

/* всё копируем и вставляем, пример из лекции
7
4 1 2 4 5
2 0 3
2 0 5
1 1
2 0 6
3 0 2 6
2 4 5
*/