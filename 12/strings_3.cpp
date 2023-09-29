// Дано предложение. Вывести слова, содержащие наибольшее количество различных букв.

// Niccol Paganini was born in Genoa on 27 October 1782, the third of the six children of Antonio and Teresa Paganini.

#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int dif_num(string s) // количество различных букв
{
    int k, p;
    int l = s.length();
    sort(s.begin(), s.end());
    k = p = 0;
    for (int i = p; i < l; i++)
    {
        if (s[i] == s[i + 1])
            k++;
        else
            p = k;
    }
    return l - k;
}

int main()
{
    string str, word_cache;
    cout << "STRING: ";
    getline(cin, str);
    str += '.';
    int max_word = 0, count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (!isalpha(str[i]))
        {
            count = dif_num(word_cache);
            if (count > max_word) // нахождение макс кол различных букв
                max_word = count;
            word_cache.clear();
        }
        else if (isalpha(str[i])) // составление слова
            word_cache += str[i];
    }
    cout << "WORDS:" << endl;
    for (int i = 0; i < str.length(); i++)
    {
        if (!isalpha(str[i]))
        {
            count = dif_num(word_cache);
            if (count == max_word)
                cout << word_cache << endl;
            word_cache.clear();
        }
        else if (isalpha(str[i]))
            word_cache += str[i];
    }
    return 0;
}