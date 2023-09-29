#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

vector<vector<int>> inFile()
{ // ввод из файла
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

void quickSort(vector<int> &x, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = x[(i + j) / 2];

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
        quickSort(temp, 0, N - 1);
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
