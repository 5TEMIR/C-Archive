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

bool isPrime(int n) // �������� �� ������� �����
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

stack *result(stack *&h, int new_num) // ��������� ����� ����� ����� ���� �������
{
    stack *res = NULL; // �������������
    while (h) // ���������� ���� ����
    {
        int x = pop(h); // ����� ������
        if (isPrime(x))
            push(res, new_num); // ���� ������� - ������ �����
        push(res, x); // ��������� ������
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

    stack *res = result(numbers, new_num); // ��������� ����� ����� ����� ���� �������
    reverse(res); // �������������� ��� ������
    while (res)
        cout << pop(res); // �����
    return 0;
}
/*
9
1 2 3 4 5 6 7 8 9
0
*/