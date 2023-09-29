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

vector<people> create_hash_table(vector<people> A, int M)
{
    vector<people> hash_table;
    hash_table.resize(M);
    for (int i = 0; i < A.size(); i++)
    {
        int k = A[i].DateOfBirth.yy % M; // ��������������� ����� �� �������
        int j = 0;
        for (int h = 0; h < M; h++)
        {
            int p = (k + j) % M; // �������� ����� ��������
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