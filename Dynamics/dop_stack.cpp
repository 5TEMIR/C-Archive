#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct stack
{
    char inf;
    stack *next;
};

void push(stack *&h, char x)
{
    stack *r = new stack; // создаем новый элемент
    r->inf = x;           // поле inf = x
    r->next = h;          // следующим элементов является h
    h = r;                // теперь r является головой
}

char pop(stack *&h)
{
    char i = h->inf; // значение первого элемента
    stack *r = h;    // указатель на голову стека
    h = h->next;     // переносим указатель на следующий элемент
    delete r;        // удаляем первый элемент
    return i;        // возвращаем значение
}

// проверка на операцию
bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C) // расстановка приоритетов у операций
{
    if (C == '(')
        return 1;
    else if (C == '-' || C == '+')
        return 2;
    else if (C == '*' || C == '/')
        return 3;
    return 0;
}

// инфикс в постфикс
string infixToPostfix(string infix)
{
    int l = infix.size();
    stack *char_stack = NULL;
    string output;
    for (int i = 0; i < l; i++)
    {
        // операнд записываем в результирующую строку
        if (isalpha(infix[i]) || isdigit(infix[i]))
        {
            output += infix[i];
        }
        // открывающую скобку записываем в стек
        else if (infix[i] == '(')
        {
            push(char_stack, '(');
        }
        // закрывающая скобка извлекаем элементы из стека и записываем в результирующую строку до тех пор, пока
        // не встретим открывающую скобку. Извлекаем открывающую скобку из стека. Открывающая и закрывающая скобки
        //  нигде не сохраняются.
        else if (infix[i] == ')')
        {
            while (char_stack->inf != '(')
            {
                char sup = pop(char_stack);
                output += sup;
            }
            pop(char_stack);
        }
        // знак операции
        else
        {
            // Если стек пуст, записываем знак операции в стек
            if (char_stack == NULL)
            {
                push(char_stack, infix[i]);
            }
            // Если приоритет текущего символа выше, чем приоритет элемента на вершине стека, то записываем текущий символ в стек
            else if (getPriority(infix[i]) > getPriority(char_stack->inf))
            {
                push(char_stack, infix[i]);
            }
            else
            {
                while (getPriority(infix[i]) <= getPriority(char_stack->inf))
                {                               // Если приоритет текущего символа меньше или равен приоритету элемента на вершине стека, то извлекаем из
                    char sup = pop(char_stack); // стека элементы и записываем их в результирующую строку. Продолжаем процесс до тех пор, пока приоритет
                    output += sup;              // текущего элемента не станет выше приоритета вершины стека (или стек не опустеет). После этого записываем
                    if (char_stack == NULL)     // текущий элемент в стек.
                        break;
                }
                push(char_stack, infix[i]);
            }
        }
    }
    while (char_stack)
    {
        char sup = pop(char_stack);
        output += sup;
    }
    return output;
}

string infixToPrefix(string infix)
{
    int l = infix.size();

    reverse(infix.begin(), infix.end()); // реверс строки

    for (int i = 0; i < l; i++)
    {

        if (infix[i] == '(') // исправляем скобки
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    string prefix = infixToPostfix(infix); // постфикс реверсной строки

    reverse(prefix.begin(), prefix.end()); // реверс постфикса

    return prefix; // получаем префикс
}

int main()
{
    string s = "5+(3+(2+4*(3-1)+2)/4+1)*4";
    cout << infixToPrefix(s) << endl;
    cout << "ghbdtn привет" << endl;
    return 0;
}
