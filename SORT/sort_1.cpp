#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

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

void print(people x)
{                                          // ����� � ����
    out << setw(10) << left << x.Surname;  // �� ������ ����, 10 ������� ��� �������
    out << left << setw(10) << x.Position; // 20 ������� ��� ���������
    if (x.DateOfBirth.dd < 10)
        out << left << '0' << x.DateOfBirth.dd << '.'; // ��������� 0
    else
        out << left << x.DateOfBirth.dd << '.';
    if (x.DateOfBirth.mm < 10)
        out << '0' << x.DateOfBirth.mm << '.';
    else
        out << x.DateOfBirth.mm << '.';
    out << left << setw(6) << x.DateOfBirth.yy;  // �� ��� 6 �������
    out << left << setw(4) << x.XP;              // ����
    out << left << setw(10) << x.Salary << endl; // ��������
}

bool operator<(people a, people b)
{ // �������������� �������� < � ����������� � ��������
    if (a.Salary < b.Salary)
        return true;
    return false;
}

bool operator>(people a, people b)
{ // �������������� �������� < � ����������� � ��������
    if (a.Salary > b.Salary)
        return true;
    return false;
}

void quickSort(vector<people> &x, int low, int high)
{
    int i = low;
    int j = high;
    people pivot = x[(i + j) / 2];

    while (i <= j)
    {
        while (x[i] < pivot)
            i++;
        while (x[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(x[i], x[j]);
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(x, low, j);
    if (i < high)
        quickSort(x, i, high);
}

int main()
{
    vector<people> x;
    x = inFile();
    quickSort(x, 0, x.size() - 1);
    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;
}
