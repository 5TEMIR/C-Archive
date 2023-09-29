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

queue *result(queue *&h, queue *&t) // удаляем дубликаты, оставляя первое вхождение
{
    queue *h1 = NULL;
    queue *tail_h1 = NULL;
    queue *res = NULL;
    queue *tail_res = NULL;
    while (h)
    {
        int x = pop(h, t);      // удаляем первый элемент
        push(res, tail_res, x); // записываем в результат
        while (h)
        {
            int y = pop(h, t); // удаляем элемент из очереди
            if (x != y)
                push(h1, tail_h1, y); // записываем в новую очередь
        }
        h = h1; // переобозначаем указатели и хвост
        t = tail_h1;
        h1 = NULL;
        tail_h1 = NULL;
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
1 2 2 1 3 4 5 1 2 5 4 3 5
*/