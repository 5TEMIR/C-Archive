#include <iostream>

using namespace std;

struct queue // �������
{
    int inf;
    queue *next;
};

void push(queue *&h, queue *&t, int x) // ������� �������� � �������
{
    queue *r = new queue; // ������� ����� �������
    r->inf = x;
    r->next = NULL; // ������ ���������
    if (!h && !t)
    {              // ���� ������� �����
        h = t = r; // ��� � ������ � �����
    }
    else
    {
        t->next = r; // r - ��������� ��� ������
        t = r;       // ������ r - �����
    }
}

int pop(queue *&h, queue *&t) // �������� �������� �� �������
{
    queue *r = h;   // ������� ��������� �� ������
    int i = h->inf; // ��������� �������� ������
    h = h->next;    // �������� ��������� �� ��������� �������
    if (!h)         // ���� ������� ��������� ������� �� �������
        t = NULL;
    delete r; // ������� ������ �������
    return i;
}

queue *result(queue *&h, queue *&t) // ������� ���������, �������� ������ ���������
{
    queue *h1 = NULL;
    queue *tail_h1 = NULL;
    queue *res = NULL;
    queue *tail_res = NULL;
    while (h)
    {
        int x = pop(h, t);      // ������� ������ �������
        push(res, tail_res, x); // ���������� � ���������
        while (h)
        {
            int y = pop(h, t); // ������� ������� �� �������
            if (x != y)
                push(h1, tail_h1, y); // ���������� � ����� �������
        }
        h = h1; // �������������� ��������� � �����
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

    queue *numbers = NULL; // ��������� �������
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
        cout << pop(res, tail) << ' '; // �����
    return 0;
}
/*
13
1 2 2 1 3 4 5 1 2 5 4 3 5
*/