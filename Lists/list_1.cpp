#include <iostream>

using namespace std;

struct list
{
    int inf;
    list *next;
    list *prev;
};

void push(list *&h, list *&t, int x)
{                       // ������� �������� � ����� ������
    list *r = new list; // ������� ����� �������
    r->inf = x;
    r->next = NULL; // ������ ���������
    if (!h && !t)
    {                   // ���� ������ ����
        r->prev = NULL; // ������ �������
        h = r;          // ��� ������
    }
    else
    {
        t->next = r; // r - ��������� ��� ������
        r->prev = t; // ����� - ���������� ��� r
    }
    t = r; // r ������ �����
}

void print(list *h)
{                // ������ ��������� ������
    list *p = h; // �������� �� ������
    while (p)
    { // ���� �� ����� �� ����� ������
        cout << p->inf << " ";
        p = p->next; // ������� � ���������� ��������
    }
}

void insert_after(list *&h, list *&t, list *r, int y)
{                       // ��������� ����� r
    list *p = new list; // ������� ����� �������
    p->inf = y;
    if (r == t)
    {                   // ���� ��������� ����� ������
        p->next = NULL; // ����������� ��-� - ���������
        p->prev = r;    // ��������� ����� r
        r->next = p;
        t = p; // ������ ����� - p
    }
    else
    {                      // ��������� � �������� ������
        r->next->prev = p; // ��� ���������� �� r ��-�� ���������� - p
        p->next = r->next; // ��������� �� p - ��������� �� r
        p->prev = r;       // p ��������� ����� r
        r->next = p;
    }
}

void result(list *&h, list *&t) // ����� �����, ������ ������� �����, ��������� ������������ �������
{
    int first_elem = h->inf, max_elem = INT_MIN;

    list *p = h;
    while (p)                  // ������� ���� �������
    {                          // ���� �� ����� �� ����� ������
        if (p->inf > max_elem) // ���������
            max_elem = p->inf; // ������������� ������������ �������
        p = p->next;           // ������� � ���������� ��������
    }

    list *p1 = h;
    while (p1)
    {                                         // ���� �� ����� �� ����� ������
        if (p1->inf == first_elem)            // ���� ����� �������������
            insert_after(h, t, p1, max_elem); // ��������� ����� ���� ������������ �������
        p1 = p1->next;                        // ������� � ���������� ��������
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