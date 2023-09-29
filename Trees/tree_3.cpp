#include <iostream>

using namespace std;

struct tree
{
    int inf;
    tree *left;
    tree *right;
};

tree *node(int x)
{
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    return n;
}

void create(tree *&tr, int n)
{
    int x;
    if (n > 0)
    {
        cin >> x;
        tr = node(x);
        int nl = n / 2;      // � ����� ��������� ����� �������� �� ���������� ������ �����
        int nr = n - nl - 1; // � ������ �������� � ������� �����
        create(tr->left, nl);
        create(tr->right, nr); // ���������� ��������� ������ ������� � ����� �����
    }
}

void preorder(tree *tr) // ������ �����
{

    if (tr)
    {
        cout << tr->inf << " ";
        preorder(tr->left);
        preorder(tr->right);
    }
}

void find(tree *tr, int &count)
{
    if (tr)
    {
        if (tr->left == NULL && tr->right == NULL) // ���������� ������� ������ ��� ����
        {
            count += 1;
        }
        else
        {
            find(tr->left, count); // ����������� �����
            find(tr->right, count);
        }
    }
}

int main()
{
    tree *tr = NULL;
    int n, x, count = 0;
    cout << "n = ";
    cin >> n;
    cout << endl;
    cout << "Nodes: ";
    create(tr, n);
    cout << endl;
    cout << "Nodes: ";
    preorder(tr);
    cout << endl
         << endl;
    find(tr, count);
    cout << "Leaves: " << count;
}
/*
10
4 5 3 7 8 6 9 1 2 0

*/
