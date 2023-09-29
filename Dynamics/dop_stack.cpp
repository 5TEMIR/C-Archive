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
    stack *r = new stack; // ������� ����� �������
    r->inf = x;           // ���� inf = x
    r->next = h;          // ��������� ��������� �������� h
    h = r;                // ������ r �������� �������
}

char pop(stack *&h)
{
    char i = h->inf; // �������� ������� ��������
    stack *r = h;    // ��������� �� ������ �����
    h = h->next;     // ��������� ��������� �� ��������� �������
    delete r;        // ������� ������ �������
    return i;        // ���������� ��������
}

// �������� �� ��������
bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C) // ����������� ����������� � ��������
{
    if (C == '(')
        return 1;
    else if (C == '-' || C == '+')
        return 2;
    else if (C == '*' || C == '/')
        return 3;
    return 0;
}

// ������ � ��������
string infixToPostfix(string infix)
{
    int l = infix.size();
    stack *char_stack = NULL;
    string output;
    for (int i = 0; i < l; i++)
    {
        // ������� ���������� � �������������� ������
        if (isalpha(infix[i]) || isdigit(infix[i]))
        {
            output += infix[i];
        }
        // ����������� ������ ���������� � ����
        else if (infix[i] == '(')
        {
            push(char_stack, '(');
        }
        // ����������� ������ ��������� �������� �� ����� � ���������� � �������������� ������ �� ��� ���, ����
        // �� �������� ����������� ������. ��������� ����������� ������ �� �����. ����������� � ����������� ������
        //  ����� �� �����������.
        else if (infix[i] == ')')
        {
            while (char_stack->inf != '(')
            {
                char sup = pop(char_stack);
                output += sup;
            }
            pop(char_stack);
        }
        // ���� ��������
        else
        {
            // ���� ���� ����, ���������� ���� �������� � ����
            if (char_stack == NULL)
            {
                push(char_stack, infix[i]);
            }
            // ���� ��������� �������� ������� ����, ��� ��������� �������� �� ������� �����, �� ���������� ������� ������ � ����
            else if (getPriority(infix[i]) > getPriority(char_stack->inf))
            {
                push(char_stack, infix[i]);
            }
            else
            {
                while (getPriority(infix[i]) <= getPriority(char_stack->inf))
                {                               // ���� ��������� �������� ������� ������ ��� ����� ���������� �������� �� ������� �����, �� ��������� ��
                    char sup = pop(char_stack); // ����� �������� � ���������� �� � �������������� ������. ���������� ������� �� ��� ���, ���� ���������
                    output += sup;              // �������� �������� �� ������ ���� ���������� ������� ����� (��� ���� �� ��������). ����� ����� ����������
                    if (char_stack == NULL)     // ������� ������� � ����.
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

    reverse(infix.begin(), infix.end()); // ������ ������

    for (int i = 0; i < l; i++)
    {

        if (infix[i] == '(') // ���������� ������
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    string prefix = infixToPostfix(infix); // �������� ��������� ������

    reverse(prefix.begin(), prefix.end()); // ������ ���������

    return prefix; // �������� �������
}

int main()
{
    string s = "5+(3+(2+4*(3-1)+2)/4+1)*4";
    cout << infixToPrefix(s) << endl;
    cout << "ghbdtn ������" << endl;
    return 0;
}
