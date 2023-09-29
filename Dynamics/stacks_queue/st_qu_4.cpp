#include <iostream>

using namespace std;

struct stack
{
    int inf;
    stack *next;
};

void push(stack *&h, int x)
{
    stack *r = new stack; // ������� ����� �������
    r->inf = x;           // ���� inf = x
    r->next = h;          // ��������� ��������� �������� h
    h = r;                // ������ r �������� �������
}

int pop(stack *&h)
{
    int i = h->inf; // �������� ������� ��������
    stack *r = h;   // ��������� �� ������ �����
    h = h->next;    // ��������� ��������� �� ��������� �������
    delete r;       // ������� ������ �������
    return i;       // ���������� ��������
}

void reverse(stack *&h)
{
    stack *head1 = NULL;     // ������������� ��������� �����
    while (h)                // ���� ���� �� ����
        push(head1, pop(h)); // ������������ �� ������ ����� � ������
    h = head1;               // �������������� ���������
}

stack *result(stack *&h, int new_num) // ��������� ����� ����� ����� ���������� ��������� ��������
{
    stack *res = NULL; // �������������
    stack *h1 = NULL;
    int nechet_elem;
    bool paste = false; // �������� �� ������� ������ �����
    while (h)
    {
        int x = pop(h);
        if (x % 2 != 0 && !paste) // ���� �������� � �� ���������
        {
            push(res, new_num); // ��������� ������� �����
            paste = true;       // � ��������
        }
        push(res, x); // ����� ��������� ������� �� ����������� �����
    }
    reverse(res); // �������������� ����
    return res;
}

int main()
{
    int n, x, new_num;

    cout << "n = ";
    cin >> n;

    stack *numbers = NULL; // ��������� ����
    for (int i = 0; i < n; i++)
    {
        cout << "stack[" << i << "] = ";
        cin >> x;
        push(numbers, x);
    }

    cout << "new num = "; // ���� ������ �����
    cin >> new_num;

    stack *res = result(numbers, new_num); // ��������� ����� ����� ����� ���������� ��������� ��������
    reverse(res);                          // �������������� ��� ������
    while (res)
        cout << pop(res); // �����
    return 0;
}
/*
8
1 2 3 4 5 6 6 8
0
*/