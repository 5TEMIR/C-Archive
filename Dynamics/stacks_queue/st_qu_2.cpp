#include <limits>
#include <iostream>

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

queue *result(queue *&h, queue *&t)
{
    queue *h1 = NULL;
    queue *tail_h1 = NULL;
    queue *res = NULL;
    queue *tail_res = NULL;
    int min_num = INT_MAX, chet_elem;
    while (h)
    {
        int x = pop(h, t);
        if (x < min_num)
            min_num = x;
        if (x % 2 == 0)
            chet_elem = x;
        push(h1, tail_h1, x);
    }
    while (h1)
    {
        int y = pop(h1, tail_h1);
        push(res, tail_res, y);
        if (y == min_num)
            push(res, tail_res, chet_elem);
    }
    return res;
}

int main()
{
    int n, x;

    cout << "n = ";
    cin >> n;
    cout << endl;

    queue *numbers = NULL; // заполняем очередь
    queue *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        cout << "queue[" << i << "] = ";
        cin >> x;
        push(numbers, tail, x);
    }
    cout << "\n\n";

    queue *res = result(numbers, tail);
    while (res)
        cout << pop(res, tail) << ' '; // вывод
    return 0;
}
/*
13
2 8 2 1 6 8 8 1 2 2 8 2 1
*/