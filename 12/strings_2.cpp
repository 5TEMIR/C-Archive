// ƒано предложение, содержащие знаки препинани€. Ќайти самое длинное слово.

// I was born ready, but i need help

#include <iostream>

using namespace std;

int main()
{
    string str, word_cache, word;
    cout << "STRING: ";
    getline(cin, str); // ввод строки
    str += '.';
    int max_word = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (!isalpha(str[i]))
        {
            if (word_cache.length() > max_word) // нахождение самого длинного слова
            {
                word = word_cache; 
                max_word = word_cache.length();
            }
            word_cache.clear();
        }
        else if (isalpha(str[i])) // составление слова
        {
            word_cache += str[i];
        }
    }
    cout << word;
    return 0;
}