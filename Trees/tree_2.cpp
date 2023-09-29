#include <iostream>
#include <vector>

using namespace std;

struct tree
{
    int inf;
    tree *left;
    tree *right;
    tree *parent;
};

tree *node(int x)
{ // ��������� ����
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void inorder(tree *tr) // ������������ ����� (�-�-�)
{
    if (tr)
    {
        inorder(tr->left);      // �����
        cout << tr->inf << ' '; // ������
        inorder(tr->right);     // ������
    }
}

void insert(tree *&tr, int x) // �������
{
    tree *n = node(x);
    if (!tr)
        tr = n; // ���� ������ ������ - ������
    else
    {
        tree *y = tr;
        while (y)
        {                        // ���� ���� ���������
            if (n->inf > y->inf) // ������ �����
                if (y->right)
                    y = y->right;
                else
                {
                    n->parent = y; // ���� ���������� ������ ��������
                    y->right = n;
                    break;
                }
            else if (n->inf < y->inf) // ����� �����
                if (y->left)
                    y = y->left;
                else
                {
                    n->parent = y; // ���� ���������� ����� ��������
                    y->left = n;
                    break;
                }
        }
    }
}

vector<int> result(tree *node, vector<int> v, int key) // ���� �� ����� �� X
{
    if (node == NULL) // ���� ������, ���� ���
        return v;
    v.push_back(node->inf); // ��������� ���
    if (node->inf == key)
        return v; // ����� ���� ���� �����
    if (v.back() != key)
        v = result(node->left, v, key); // �� �����, ����������
        v = result(node->right, v, key);
    if (v.back() != key) // ������� ������ ���
        v.pop_back();
    return v;
}

int main()
{
    int n, x, X;
    cout << "n = ";
    cin >> n;
    tree *tr = NULL;
    cout << "Nodes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insert(tr, x);
    }
    cout << "Nodes: ";
    inorder(tr);
    cout << endl;
    cout << "X = ";
    cin >> X;
    cout << "Nodes: ";
    vector<int> path;
    path = result(tr, path, X);
    for (int i : path)
        cout << i << " ";
}
/*
10
5 3 7 1 9 4 2 8 6 0
            5
         /     \         
        3       7
       / \    /  \
      1   4   6   9
     / \         /
    0   2       8
*/