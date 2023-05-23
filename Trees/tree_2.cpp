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
{ // начальный узел
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void inorder(tree *tr) // симметричный обход (Л-К-П)
{
    if (tr)
    {
        inorder(tr->left);      // левое
        cout << tr->inf << ' '; // корень
        inorder(tr->right);     // правое
    }
}

void insert(tree *&tr, int x) // вставка
{
    tree *n = node(x);
    if (!tr)
        tr = n; // если дерево пустое - корень
    else
    {
        tree *y = tr;
        while (y)
        {                        // ищем куда вставлять
            if (n->inf > y->inf) // правая ветка
                if (y->right)
                    y = y->right;
                else
                {
                    n->parent = y; // узел становится правым ребенком
                    y->right = n;
                    break;
                }
            else if (n->inf < y->inf) // левая ветка
                if (y->left)
                    y = y->left;
                else
                {
                    n->parent = y; // узел становится левым ребенком
                    y->left = n;
                    break;
                }
        }
    }
}

vector<int> result(tree *node, vector<int> v, int key) // путь от корня до X
{
    if (node == NULL) // если корень, пути нет
        return v;
    v.push_back(node->inf); // вставляем шаг
    if (node->inf == key)
        return v; // вывод пути если дошли
    if (v.back() != key)
        v = result(node->left, v, key); // не дошли, продолжаем
        v = result(node->right, v, key);
    if (v.back() != key) // удаляем лишний шаг
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