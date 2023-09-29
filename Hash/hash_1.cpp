#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct date
{ // дата
    int dd, mm, yy;
};

struct people
{                     // данные о человеке
    string Surname;   // фамилия
    string Position;  // должность
    date DateOfBirth; // дата рождения
    int XP;           // стаж работы
    int Salary;       // зарплата
};

date Str_to_Date(string str)
{ // из строки в дату
    date x;
    string temp = str.substr(0, 2); // день
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2); // месяц
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4); // год
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
{                       // вставка элемента в конец списка
    list *r = new list; // создаем новый элемент
    r->inf = x;
    r->next = NULL; // всегда последний
    if (!h && !t)
    {                   // если список пуст
        r->prev = NULL; // первый элемент
        h = r;          // это голова
    }
    else
    {
        t->next = r; // r - следующий для хвоста
        r->prev = t; // хвост - предыдущий для r
    }
    t = r; // r теперь хвост
}

void del_node(list *&h, list *&t, list *r)
{                         // удаляем после r
    if (r == h && r == t) // единственный элемент списка
        h = t = NULL;
    else if (r == h)
    {                // удаляем голову списка
        h = h->next; // сдвигаем голову
        h->prev = NULL;
    }
    else if (r == t)
    {                // удаляем хвост списка
        t = t->prev; // сдвигаем хвост
        t->next = NULL;
    }
    else
    {
        r->next->prev = r->prev; // для следующего от r предыдущим становится r->prev
        r->prev->next = r->next; // для предыдущего от r следующим становится r->next
    }
    delete r; // удаляем r
}

void print(list *h)
{                // печать элементов списка
    list *p = h; // укзатель на голову
    while (p)
    { // пока не дошли до конца списка
        cout << p->inf.Surname << " have " << p->inf.Salary << "; ";
        p = p->next; // переход к следующему элементу
    }
}

ifstream in("input.txt");

vector<people> inFile()
{ // ввод из файла
    vector<people> x;
    people temp;
    while (in.peek() != EOF)
    {
        in >> temp.Surname;  // фамилия
        in >> temp.Position; // позиция
        string tmp;          // дата рождения
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.XP;     // стаж работы
        in >> temp.Salary; // зарплата
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
        int k = A[i].Salary % M; // метод деления по зарплате
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