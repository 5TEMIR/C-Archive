// ���� �����������, ���������� ����� ����������. ����� ����� ������� �����.

// I was born ready, but i need help

#include <iostream>

using namespace std;

int main()
{
    string str, word_cache, word;
    cout << "STRING: ";
    getline(cin, str); // ���� ������
    str += '.';
    int max_word = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (!isalpha(str[i]))
        {
            if (word_cache.length() > max_word) // ���������� ������ �������� �����
            {
                word = word_cache; 
                max_word = word_cache.length();
            }
            word_cache.clear();
        }
        else if (isalpha(str[i])) // ����������� �����
        {
            word_cache += str[i];
        }
    }
    cout << word;
    return 0;
}