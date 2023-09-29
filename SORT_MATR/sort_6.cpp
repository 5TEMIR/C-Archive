#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

vector<vector<int>> inFile()
{ // גגמה טח פאיכא
    vector<vector<int>> x;
    vector<int> temp;
    char symbol;
    while (!in.eof())
    {
        in.get(symbol);
        if (isdigit(symbol))
            temp.push_back(symbol - '0');
        else if (symbol == '\n')
        {
            x.push_back(temp);
            temp.clear();
        }
    }
    temp.pop_back();
    x.push_back(temp);
    return x;
}

void print(vector<vector<int>> x)
{
    for (vector<int> vctr : x)
    {
        for (int elem : vctr)
            out << setw(3) << left << elem;
        out << left << endl;
    }
}

void shellSort_1(vector<int> &x)
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
        i += 2;
        step = N / i;
    }
}

void shellSort_2(vector<int> &x)
{
    int i = 2, j, N = x.size();
    int step = N / i;
    while (step >= 1)
    {
        for (int ind = 0; ind < N - step; ind++)
        {
            j = ind;
            while (j >= 0 && x[j] < x[j + step])
            {
                swap(x[j], x[j + step]);
                j = j - step;
            }
        }
        i += 2;
        step = N / i;
    }
}

int main()
{
    vector<vector<int>> x;
    x = inFile();
    int i = 0, N = x.size();
    while (i < N)
    {
        vector<int> temp;
        int j = 0;
        while (j < N)
        {
            temp.push_back(x[j][i]);
            j++;
        }
        if (i%2==0)
            shellSort_1(temp);
        else
            shellSort_2(temp);
        j = 0;
        while (j < N)
        {
            x[j][i] = temp[j];
            j++;
        }
        i++;
    }
    print(x);
    return 0;
}
