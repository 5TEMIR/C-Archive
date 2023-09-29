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

void insert_after(list *&h, list *&t, list *r, int y)
{                       // вставляем после r
    list *p = new list; // создаем новый элемент
    p->inf = y;
    if (r == t)
    {                   // если вставляем после хвоста
        p->next = NULL; // вставляемый эл-т - последний
        p->prev = r;    // вставляем после r
        r->next = p;
        t = p; // теперь хвост - p
    }
    else
    {                      // вставляем в середину списка
        r->next->prev = p; // для следующего за r эл-та предыдущий - p
        p->next = r->next; // следующий за p - следующий за r
        p->prev = r;       // p вставляем после r
        r->next = p;
    }
}

void result(list *&h, list *&t) // после чисел, равных первому числу, вставляем максимальный элемент
{
    int first_elem = h->inf, max_elem = INT_MIN;

    list *p = h;
    while (p)                  // находим макс элемент
    {                          // пока не дошли до конца списка
        if (p->inf > max_elem) // сравнение
            max_elem = p->inf; // устанавливаем максимальный элемент
        p = p->next;           // переход к следующему элементу
    }

    list *p1 = h;
    while (p1)
    {                                         // пока не дошли до конца списка
        if (p1->inf == first_elem)            // если равен максимальному
            insert_after(h, t, p1, max_elem); // вставляем после него максимальный элемент
        p1 = p1->next;                        // переход к следующему элементу
    }
}

int main()
{
    int n, x;

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

    result(lis, tail);

    print(lis);
}

/*
13
2 8 2 1 6 8 8 1 2 2 8 2 1
*/