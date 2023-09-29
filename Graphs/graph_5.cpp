#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

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

vector<vector<int>> input_adj_list(int N) // �������� ������ ���������
{
    ifstream in("input.txt");
    vector<vector<int>> Gr;
    Gr.resize(N);
    int x, y;
    while (in.peek() != EOF)
    {
        in >> x >> y;
        if (x > N || y > N)
            continue;
        else
        {
            Gr[x].push_back(y);
            Gr[y].push_back(x);
        }
    }
    for (int i = 0; i < N; i++)
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
    return Gr;
}

void output_adj_list(vector<vector<int>> Gr) // ����� ������ ���������
{
    for (int i = 0; i < Gr.size(); i++)
    {
        cout << i << ": ";
        for (int vertex_adj : Gr[i])
        {
            cout << vertex_adj << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> walk_in_width(vector<vector<int>> Gr, int N, int A, int B) // ����� � ������
{
    queue *visits = NULL;
    queue *tail = NULL;
    vector<int> dist(N, N); // ����������
    vector<int> p(N, -1);   // ������
    dist[A] = 0;            // ��������� �� ������ 0
    push(visits, tail, A);  // ��������
    while (visits)
    {
        int v = pop(visits, tail); // ������� ������ ��
        for (int u : Gr[v])
        { // ���������� ������� �������
            if (dist[u] > dist[v] + 1)
            {                          // ������� ������� ������
                p[u] = v;              // �������� ������
                dist[u] = dist[v] + 1; // ��������� ��������� ��� ������� �������
                push(visits, tail, u); // ��������
            }
        }
    }
    if (dist[B] == N) // ���� ��� - �����
    {
        return {};
    }

    vector<int> path; // ��� ����
    int t = B;
    while (t != -1)
    {
        path.push_back(t); // �� ������� ������� ���� � �������� �������
        t = p[t];
    }
    reverse(path.begin(), path.end()); // ���� ��� � �������� ������� - ��������������
    return path;
}

int main()
{
    vector<vector<int>> Gr = input_adj_list(7);
    output_adj_list(Gr);
    cout << "start: ";
    int start;
    cin >> start;
    cout << "end: ";
    int end;
    cin >> end;
    vector<int> way = walk_in_width(Gr, 7, start, end);
    for (int i : way)
        cout << i << ' ';
}
