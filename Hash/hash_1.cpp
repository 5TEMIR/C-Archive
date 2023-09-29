#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct date
{ // ����
    int dd, mm, yy;
};

struct people
{                     // ������ � ��������
    string Surname;   // �������
    string Position;  // ���������
    date DateOfBirth; // ���� ��������
    int XP;           // ���� ������
    int Salary;       // ��������
};

date Str_to_Date(string str)
{ // �� ������ � ����
    date x;
    string temp = str.substr(0, 2); // ����
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2); // �����
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4); // ���
    x.yy = atoi(temp.c_str());
    return x;
}

struct list
{
    people inf;
    list *next;
    list *prev;
};

void push(list *&h, list *&t, people x)
{                       // ������� �������� � ����� ������
    list *r = new list; // ������� ����� �������
    r->inf = x;
    r->next = NULL; // ������ ���������
    if (!h && !t)
    {                   // ���� ������ ����
        r->prev = NULL; // ������ �������
        h = r;          // ��� ������
    }
    else
    {
        t->next = r; // r - ��������� ��� ������
        r->prev = t; // ����� - ���������� ��� r
    }
    t = r; // r ������ �����
}

void del_node(list *&h, list *&t, list *r)
{                         // ������� ����� r
    if (r == h && r == t) // ������������ ������� ������
        h = t = NULL;
    else if (r == h)
    {                // ������� ������ ������
        h = h->next; // �������� ������
        h->prev = NULL;
    }
    else if (r == t)
    {                // ������� ����� ������
        t = t->prev; // �������� �����
        t->next = NULL;
    }
    else
    {
        r->next->prev = r->prev; // ��� ���������� �� r ���������� ���������� r->prev
        r->prev->next = r->next; // ��� ����������� �� r ��������� ���������� r->next
    }
    delete r; // ������� r
}

void print(list *h)
{                // ������ ��������� ������
    list *p = h; // �������� �� ������
    while (p)
    { // ���� �� ����� �� ����� ������
        cout << p->inf.Surname << " have " << p->inf.Salary << "; ";
        p = p->next; // ������� � ���������� ��������
    }
}

ifstream in("input.txt");

vector<people> inFile()
{ // ���� �� �����
    vector<people> x;
    people temp;
    while (in.peek() != EOF)
    {
        in >> temp.Surname;  // �������
        in >> temp.Position; // �������
        string tmp;          // ���� ��������
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.XP;     // ���� ������
        in >> temp.Salary; // ��������
        x.push_back(temp);
    }
    return x;
}

vector<pair<list *, list *>> create_hash_table(vector<people> A, int M)
{
    vector<pair<list *, list *>> hash_table;
    hash_table.resize(M);
    for (int i = 0; i < A.size(); i++)
    {
        int k = A[i].Salary % M; // ����� ������� �� ��������
        push(hash_table[k].first, hash_table[k].second, A[i]);
    }
    return hash_table;
}

void output_hash_table(vector<pair<list *, list *>> hash_table)
{
    for (int i = 0; i < hash_table.size(); i++)
    {
        print(hash_table[i].first);
        cout << endl;
    }
    cout << endl;
}

list *find_element_hash_table(vector<pair<list *, list *>> hash_table, int X)
{
    int k = X % hash_table.size();
    list *p = hash_table[k].first;
    while (p)
    {
        if (p->inf.Salary == X)
            break;
        p = p->next;
    }
    return p;
}

void delete_element_hash_table(vector<pair<list *, list *>> &hash_table, int X)
{
    int k = X % hash_table.size();
    list *p = hash_table[k].first;
    while (p)
    {
        if (p->inf.Salary == X)
        {
            del_node(hash_table[k].first, hash_table[k].second, p);
            break;
        }
        p = p->next;
    }
}

void result()
{
    vector<people> A = inFile();

    vector<pair<list *, list *>> hash_table = create_hash_table(A, 3);

    output_hash_table(hash_table);

    int salary;

    cout << "Find by salary: ";
    cin >> salary;
    list *f_e_h = find_element_hash_table(hash_table, salary);
    cout << f_e_h->inf.Surname << " " << f_e_h->inf.Position << " " << f_e_h->inf.XP << " " << f_e_h->inf.Salary << " " << "\n\n";

    cout << "Delete by salary: ";
    cin >> salary;
    delete_element_hash_table(hash_table, salary);
    output_hash_table(hash_table);
}

int main()
{
    result();
    return 0;
}