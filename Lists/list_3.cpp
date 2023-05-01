#include <iostream>

using namespace std;

struct list
{
    int inf;
    list *prev;
    list *next;
};

void push(list *&h, list *&t, int x)
{
    list *p = new list;
    p->inf = x;
    p->next = nullptr;
    if (!h && !t)
    {
        p->prev = nullptr;
        h = p;
    }
    else
    {
        t->next = p;
        p->prev = t;
    }
    t = p;
}

void Swap(list *&Node1, list *&Node2)
{
    list *temp;
    temp = Node1->next;
    Node1->next = Node2->next;
    Node2->next = temp;

    if (Node1->next != NULL)
        Node1->next->prev = Node1;
    if (Node2->next != NULL)
        Node2->next->prev = Node2;

    temp = Node1->prev;
    Node1->prev = Node2->prev;
    Node2->prev = temp;

    if (Node1->prev != NULL)
        Node1->prev->next = Node1;
    if (Node2->prev != NULL)
        Node2->prev->next = Node2;
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

void QuickSort(list *h, list *t)
{
    if (t == h)
        return;

    int mn = INT_MAX, mx = INT_MIN;

    list *i = h;
    list *j = t;

    while (i != t)
    {
        mn = min(i->inf, mn);
        mx = max(i->inf, mx);
        i = i->next;
    }
    
    mn = min(i->inf, mn);
    mx = max(i->inf, mx);
    int mid = (mx + mn) / 2;
    i = h;
    while (i != j)
    {
        while (i->inf < mid && i != j)
            i = i->next;
        while (j->inf > mid && i != j)
            j = j->prev;
        if (i != j)
        {
            if (h == i && t == j)
                swap(h, t);
            else if (h == i)
                h = j;
            else if (t == j)
                t = i;
            Swap(i, j);
            swap(i, j);
            i = i->next;
        }
    }
    if (i == h)
    {
        QuickSort(i->next, t);
    }
    else if (j == t)
    {
        QuickSort(h, j->prev);
    }
    else
    {
        QuickSort(h, i->prev);
        QuickSort(i, t);
    }
}

int main()
{
    list *head = nullptr, *tail = nullptr;
    cout << "n = ";
    int n;
    cin >> n;
    cout << "List: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        push(head, tail, x);
    }
    QuickSort(head, tail);

    list *r = head;
    while (r)
    {
        head = r;
        r = r->prev;
    }

    cout << "Result: ";
    print(head);
}