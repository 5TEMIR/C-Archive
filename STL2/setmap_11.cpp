#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

bool isnumber(string str) // проверка строки число
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

int main()
{
    ifstream fin("input.txt");
    string text, word;
    getline(fin, text);
    text += " ";
    int digit, begin, end, pos = 0;

    begin = text.find_first_of("0123456789"); // находим первое число
    end = text.find_first_of(' ', begin);
    digit = stoi(text.substr(begin, end - begin));
    cout << digit << "\n\n";

    map<string, int> count;
    while (pos < text.length() - 1) // считаем количество слов
    {
        if (text.find_first_not_of("0123456789 ", pos) != -1)
        {
            begin = text.find_first_not_of(' ', pos); //
            end = text.find_first_of(' ', begin);     // собираем слово
            word = text.substr(begin, end - begin);   //
            if (!isnumber(word))
                count[word] += 1; // числа не надо считать, только слова
            pos += word.length() + 1;
        }
        else
            break;
    }

    for (auto iter = count.begin(); iter != count.end(); iter++) // сравниваем количество слов с первым числом
        if (iter->second == digit)
            cout << iter->first << ": " << iter->second << " ";

    return 0;
}
/*
fdkf hjghf jdhdhf jgj 2 dhfdfj jgjfg dgfhf jgfgh 3 gfggf hjghf gldfk jglsr 6 jgkfhswe jgjfg kgfkt fdjhfd 8
*/