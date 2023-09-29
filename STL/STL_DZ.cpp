#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

void output_vec(vector<pair<char, char>> vctr)
{
    for (auto iter = vctr.begin(); iter != vctr.end(); iter++) // вывод слова
        cout << (*iter).second << ' ';
    cout << "\n\n";
}

void output_alphabet(map<char, int> alphabet)
{
    for (auto iter = alphabet.begin(); iter != alphabet.end(); iter++) // вывод алфавита
        if (iter->second == 0)
            cout << iter->first << ' ';
        else
            cout << '_' << ' ';
    cout << "\n\n";
}

int RandomNum(int max)
{
    // Установить генератор случайных чисел
    srand(time(NULL));

    // Получить случайное число
    int num = rand() % (max + 1);

    return num;
}

int main()
{
    system("chcp 1251");
    system("cls");
    cout << "\n\n";
    setlocale(LC_ALL, "rus");
    map<char, int> alphabet;
    for (char s = 'А'; s != 'Я' + 1; s++) // создание и вывод алфавита
        alphabet[s] = 0;
    output_alphabet(alphabet);

    vector<string> words = {
        "год",
        "человек",
        "время",
        "дело",
        "жизнь",
        "день",
        "рука",
        "работа",
        "слово",
        "место",
        "вопрос",
        "лицо",
        "глаз",
        "страна",
        "друг",
        "сторона",
        "дом",
        "случай",
        "ребенок",
        "голова",
        "система",
        "вид",
        "конец",
        "отношение",
        "город",
        "часть",
        "женщина",
        "проблема",
        "земля",
        "решение",
    };
    string WORD = words[RandomNum(words.size() - 1)]; // сгенерируем слово
    transform(WORD.begin(), WORD.end(), WORD.begin(), ::toupper);

    int move = 0, max_move = WORD.length() + WORD.length() / 2, count = 0;
    bool win = false;

    vector<pair<char, char>> find_word; // заменим буквы на _
    for (int i = 0; i < WORD.length(); i++)
        find_word.push_back(make_pair(WORD[i], '_'));

    output_vec(find_word);

    cout << "Ходы: " << move << '\n';
    cout << "Ограничение: " << max_move << "\n\n";

    while (true)
    {
        string letter_or_word;
        cout << "-- ";
        cin >> letter_or_word;
        system("cls");
        transform(letter_or_word.begin(), letter_or_word.end(), letter_or_word.begin(), ::toupper);
        if (letter_or_word.length() == 1 && move < max_move) // угадаем букву
        {
            if (alphabet.count(letter_or_word[0]) == 0) // наличие символа в алфавите
            {
                cout << "Такой буквы нет в алфавите";
            }
            else // символ есть в алфавите
            {
                move += 1;
                if (alphabet[letter_or_word[0]] == 0)
                {
                    alphabet[letter_or_word[0]] = 1; // помечаем букву
                    if (WORD.find(letter_or_word[0]) != WORD.npos)
                    {
                        for (int i = 0; i < WORD.length(); i++)
                            if (find_word[i].first == letter_or_word[0])
                            {
                                find_word[i].second = find_word[i].first;
                                count += 1;
                            }
                        if (count == WORD.length())
                        {
                            cout << "Вы выиграли"; // победа засчет отгадки всех букв
                            win = true;
                        }
                    }
                    else
                    {
                        cout << "Такой буквы нет в слове";
                    }
                }
                else
                {
                    cout << "Эта буква уже выбиралась"; // если выбирали, предупреждаем
                }
            }
            cout << "\n\n";
            output_alphabet(alphabet);
            output_vec(find_word);
            cout << "Ходы: " << move << '\n';
            cout << "Ограничение: " << max_move << "\n\n";
            if (win)
                break;
        }
        else if (letter_or_word.length() > 1 && move < max_move) // угадаем слово
        {
            move += 1;
            if (letter_or_word == WORD)
            {
                cout << "Вы выиграли";
                for (int i = 0; i < WORD.length(); i++)
                    find_word[i].second = find_word[i].first; // победа засчет отгадки слова
                win = true;
            }
            else
            {
                cout << "Вы не угадали";
            }
            cout << "\n\n";
            output_alphabet(alphabet);
            output_vec(find_word);
            cout << "Ходы: " << move << '\n';
            cout << "Ограничение: " << max_move << "\n\n";
            if (win)
                break;
        }
        if (move == max_move && count != WORD.length()) // ходы закончились слово не угадано
        {
            system("cls");
            cout << "Вы проиграли";
            for (int i = 0; i < WORD.length(); i++)
                find_word[i].second = find_word[i].first;
            cout << "\n\n";
            output_alphabet(alphabet);
            output_vec(find_word);
            cout << "Ходы: " << move << '\n';
            cout << "Ограничение: " << max_move << "\n\n";
            break;
        }
    }
    return 0;
}