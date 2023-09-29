#include <iostream>

using namespace std;

struct stack
{
    int inf;
    stack *next;
};

void push(stack *&h, int x)
{
    stack *r = new stack; // создаем новый элемент
    r->inf = x;           // поле inf = x
    r->next = h;          // следующим элементов является h
    h = r;                // теперь r является головой
}

int pop(stack *&h)
{
    int i = h->inf; // значение первого элемента
    stack *r = h;   // указатель на голову стека
    h = h->next;    // переносим указатель на следующий элемент
    delete r;       // удаляем первый элемент
    return i;       // возвращаем значение
}

void reverse(stack *&h)
{
    stack *head1 = NULL;     // инициализация буферного стека
    while (h)                // пока стек не пуст
        push(head1, pop(h)); // переписываем из одного стека в другой
    h = head1;               // переобозначаем указатели
}

bool isPrime(int n) // проверка на простое число
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

stack *result(stack *&h, int new_num) // вставляем новое число после всех простых
{
    stack *res = NULL; // инициализация
    while (h) // перебираем весь стэк
    {
        int x = pop(h); // берем голову
        if (isPrime(x))
            push(res, new_num); // если простое - ставим число
        push(res, x); // вставляем голову
    }
    reverse(res); // переворачиваем стэк
    return res;
}

int main()
{
    int n, x, new_num;

    cout << "n = ";
    cin >> n;

    stack *numbers = NULL; // заполняем стэк
    for (int i = 0; i < n; i++)
    {
        cout << "stack[" << i << "] = ";
        cin >> x;
        push(numbers, x);
    }

    cout << "new num = "; // ввод нового числа
    cin >> new_num;

    stack *res = result(numbers, new_num); // вставляем новое число после всех простых
    reverse(res); // переворачиваем для вывода
    while (res)
        cout << pop(res); // вывод
    return 0;
}
/*
9
1 2 3 4 5 6 7 8 9
0
*/