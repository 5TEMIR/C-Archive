#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string text;
    cout << "TEXT: ";
    getline(cin, text); // ввод строки

    set<string> vopr_vosk, pov, result;
    string razd = "!?.", temp, word;
    char tmp;
    int k, k1, pos = 0, pos1 = 0;

    while (pos < text.length() - 1)
    {
        k = text.find_first_of(razd, pos); // находим предложение и знак
        tmp = text[k];
        temp = text.substr(pos, k - pos);
        temp += " ";
        pos1 = 0;
        while (pos1 < temp.length() - 1) // перебираем каждое слово предложения
        {
            k1 = temp.find_first_of(' ', pos1);
            word = temp.substr(pos1, k1 - pos1);
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            switch (tmp)
            {
            case '.':
                pov.insert(word); // добовляем слово в нужное множество
                break;
            case '!':
            case '?':
                vopr_vosk.insert(word);
                break;
            }
            pos1 += word.length() + 1;
        }
        pos += temp.length() + 1;
    }

    set_difference(pov.begin(), pov.end(), vopr_vosk.begin(), vopr_vosk.end(), inserter(result, result.begin())); // слова которые встречаются только в повест предл

    razd = "!?. ";
    map<string, int> count;
    for (auto iter = result.begin(); iter != result.end(); iter++) //подсчитываем слова
    {
        pos = 0;
        count[*iter] = 0;
        while (pos < text.length() - 1)
        {
            k = text.find_first_not_of(razd, pos);
            k1 = text.find_first_of(razd, k);
            word = text.substr(k, k1 - k);
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (*iter == word)
                count[*iter] += 1;
            pos += word.length() + 1;
        }
    }

    for (auto iter = count.begin(); iter != count.end(); iter++)
        cout << iter->first << ": " << iter->second << " ";

    return 0;
}
/*
fdggf ffgdfg gfdfgh fdff. fhdjfdf fdfdf fd fhff ddfdf! fdfdfg fhdhrjghf dfdh? fdggf ffgdfg gfdfgh fdff. fhdjfdf fdfdf fd fhff ddfdf! fdfdfg fhdhrjghf dfdh?
*/