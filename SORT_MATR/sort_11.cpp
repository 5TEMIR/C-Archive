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
{
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

void bubSort(vector<int> &x)
{
    for (int i = 0; i < x.size()-1; i++)
        for (int j = x.size() - 1; j > i; j--)
            if (x[j - 1] < x[j])
                swap(x[j - 1], x[j]);
}

int main()
{
    vector<vector<int>> x;
    x = inFile();
    int N = x.size();
    for (int k = 1; k < 2 * N - 2; k++)
    {
        vector<int> temp;
        for (int i = 0; i < N; i++)
        {
            if (k - i < N && k - i >= 0)
            {
                temp.push_back(x[i][k - i]);
            }
        }
        bubSort(temp);
        int L = 0;
        for (int i = 0; i < N; i++)
        {
            if (k - i < N && k - i >= 0)
            {
                x[i][k - i] = temp[L];
                L++;
            }
        }
        temp.clear();
    }
    print(x);
    return 0;
}
