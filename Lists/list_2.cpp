#include <iostream>

using namespace std;

struct list
{
    int inf;
    list *next;
    list *prev;
};

void push(list *&h, list *&t, int x)
{                       // вставка элемента в конец списка
    list *r = new list; // создаем новый элемент
    r->inf = x;
    r->next = NULL; // всегда последний
    if (!h && !t)
    {                   // если список пуст
        r->prev = NULL; // первый элемент
        h = r;          // это голова
    }
    else
    {
        t->next = r; // r - следующий для хвоста
        r->prev = t; // хвост - предыдущий для r
    }
    t = r; // r теперь хвост
}

void print(list *h)
{                // печать элементов списка
    list *p = h; // укзатель на голову
    while (p)
    { // пока не дошли до конца списка
        cout << p->inf << " ";
        p = p->next; // переход к следующему элементу
    }
}

void result(list *&h, list *&t, int x) // элементы меньше чем Х переносим влево, больше чем Х переносим вправо
{
    list *p = h;
    list *res = NULL;
    list *res_t = NULL;
    while (p)
    {
        if (p->inf < x)
        {
            push(res, res_t, p->inf);
        }
        p = p->next;
    }
    list *p1 = h;
    while (p1)
    {
        if (p1->inf >= x)
        {
            push(res, res_t, p1->inf);
        }
        p1 = p1->next;
    }
    h = res;
    t = res_t;
}

int main()
{
    int n, x, X;

    cout << "n = ";
    cin >> n;

    list *lis = NULL;
    list *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        cout << "lis[" << i << "] = ";
        cin >> x;
        push(lis, tail, x);
    }
    cout << "\n\n";

    cout << "X = ";
    cin >> X;

    result(lis, tail, X);

    print(lis);
}

/*
12
8 2 1 6 3 5 4 2 1 8 9 7
5
*/