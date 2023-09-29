#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

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

bool operator>(people a, people b)
{ // �������������� �������� > � ����������� � ��������
    if (a.Surname > b.Surname)
        return true;
    if (a.Surname == b.Surname && a.Position > b.Position)
        return true;
    return false;
}

void shellSort(vector<people> &x)
{
    int i = 2, j, N = x.size();
    int step = N / i;
    while (step >= 1)
    {
        for (int ind = 0; ind < N - step; ind++)
        {
            j = ind;
            while (j >= 0 && x[j] > x[j + step])
            {
                swap(x[j], x[j + step]);
                j = j - step;
            }
        }
        i+=2;
        step = N / i;
    }
}

int main()
{
    vector<people> x;
    x = inFile();
    shellSort(x);
    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;
}
