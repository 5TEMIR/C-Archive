// ��� ����, ���������� ����� �� ���������� �����, ���������� ����. ������� � ����� ���� ������ �� �����������, � ������� ���������� ���������� ���� (� ���� �dd.mm.yyyy� ��� �dd month yyyy�).

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

vector<string> split(string str) // ���������� ����������� �� ����� � �������� �������
{
    vector<string> prfr;
    string word;
    for (int w = 0; w < str.length(); w++)
    {
        if (isalnum(str[w]))
            word += str[w];
        else if (!isalnum(str[w]) || w == str.length() - 1)
        {
            prfr.push_back(word);
            word.clear();
        }
    }
    return prfr;
}

bool ismonth(string str) // �������� ������ �� �����
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    bool month = false;
    string months[]{"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    for (int i = 0; i < 12; i++)
    {
        if (str == months[i])
        {
            month = true;
            break;
        }
    }
    return month;
}

int month_num(string month) // ����� ������
{
    transform(month.begin(), month.end(), month.begin(), ::tolower);
    string months[]{"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    int num_month;
    for (int i = 0; i < 12; i++)
    {
        if (months[i] == month)
        {
            num_month = i + 1;
            break;
        }
    }
    return num_month;
}

bool isnumber(string str) // �������� ������ �����
{
    bool number = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            number = false;
            break;
        }
    }
    return number;
}

bool date_correct(int d, int m, int y) // ������������ ����
{
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: // 31 ����
        if (d <= 0 || d > 31)
            return false;
        else
            return true;
        break;
    case 4:
    case 6:
    case 9:
    case 11: // 30 ����
        if (d <= 0 || d > 30)
            return false;
        else
            return true;
        break;
    case 2:
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) // ���������� ���
            if (d <= 0 || d > 29)
                return false;
            else
                return true;
        else // ������������
            if (d <= 0 || d > 28)
                return false;
            else
                return true;
        break;
    default:
        return false;
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string text, proffer;
    while (getline(fin, text))
    {
        bool date, date_v1, date_v2;
        for (int i = 0; i < text.length(); i++)
        {
            if (((text[i] == '.' || text[i] == '!' || text[i] == '?') && !isgraph(text[i + 1])) || i == text.length() - 1) // �������� �� ����� �����������
            {
                proffer += text[i];
                vector<string> v_prfr = split(proffer);
                date = false;
                for (int word = 0; word < v_prfr.size() - 2; word++) // ������� ����������� ��� ���������� ���
                {
                    date_v1 = isnumber(v_prfr[word]) && isnumber(v_prfr[word + 1]) && isnumber(v_prfr[word + 2]) &&
                              v_prfr[word].length() == 2 && v_prfr[word + 1].length() == 2 && v_prfr[word + 2].length() == 4; // dd.mm.yyyy
                    if (date_v1)
                        if (date_correct(stoi(v_prfr[word]), stoi(v_prfr[word + 1]), stoi(v_prfr[word + 2]))) // ������������ ����
                            date = true;
                        else
                        {
                            date = false;
                            break;
                        }
                    date_v2 = isnumber(v_prfr[word]) && ismonth(v_prfr[word + 1]) && isnumber(v_prfr[word + 2]) &&
                              v_prfr[word].length() == 2 && v_prfr[word + 2].length() == 4; // dd month yyyy
                    if (date_v2)
                        if (date_correct(stoi(v_prfr[word]), month_num(v_prfr[word + 1]), stoi(v_prfr[word + 2]))) // ������������ ����
                            date = true;
                        else
                        {
                            date = false;
                            break;
                        }
                }
                if (date)
                    fout << proffer << endl;
                proffer.clear();
                i++;
            }
            else
            {
                proffer += text[i]; // ����������� �����������
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}