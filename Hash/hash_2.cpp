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

vector<people> create_hash_table(vector<people> A, int M)
{
    vector<people> hash_table;
    hash_table.resize(M);
    for (int i = 0; i < A.size(); i++)
    {
        int k = A[i].DateOfBirth.yy % M; // вспомогательный метод по делению
        int j = 0;
        for (int h = 0; h < M; h++)
        {
            int p = (k + j) % M; // основной метод линейный
            if (hash_table[p].DateOfBirth.yy == 0)
            {
                hash_table[p] = A[i];
                break;
            }
            else
                j++;
        }
    }
    return hash_table;
}

void output_hash_table(vector<people> hash_table)
{
    for (int i = 0; i < hash_table.size(); i++)
    {
        cout << i << "| " << hash_table[i].Surname << " " << hash_table[i].DateOfBirth.dd << " " << hash_table[i].DateOfBirth.mm << " " << hash_table[i].DateOfBirth.yy << endl;
    }
    cout << endl;
}

people find_element_hash_table(vector<people> hash_table, int X)
{
    int k = X % hash_table.size();
    if (hash_table[k].DateOfBirth.yy != X)
    {
        for (int i = 1; i < hash_table.size(); i++)
        {
            if (hash_table[k + i].DateOfBirth.yy == X)
            {
                break;
                return hash_table[k + i];
            }
        }
    }
    else
        return hash_table[k];
    return hash_table[k];
}

void result()
{
    vector<people> A = inFile();

    vector<people> hash_table = create_hash_table(A, 25);

    output_hash_table(hash_table);

    int year;

    cout << "Find by year of birth: ";
    cin >> year;
    people f_e_h = find_element_hash_table(hash_table, year);
    cout << f_e_h.Surname << " " << f_e_h.Position << " " << f_e_h.XP << " " << f_e_h.Salary << " "
         << "\n\n";
}

int main()
{
    result();
    return 0;
}