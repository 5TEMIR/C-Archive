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
    for (auto iter = vctr.begin(); iter != vctr.end(); iter++) // ����� �����
        cout << (*iter).second << ' ';
    cout << "\n\n";
}

void output_alphabet(map<char, int> alphabet)
{
    for (auto iter = alphabet.begin(); iter != alphabet.end(); iter++) // ����� ��������
        if (iter->second == 0)
            cout << iter->first << ' ';
        else
            cout << '_' << ' ';
    cout << "\n\n";
}

int RandomNum(int max)
{
    // ���������� ��������� ��������� �����
    srand(time(NULL));

    // �������� ��������� �����
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
    for (char s = '�'; s != '�' + 1; s++) // �������� � ����� ��������
        alphabet[s] = 0;
    output_alphabet(alphabet);

    vector<string> words = {
        "���",
        "�������",
        "�����",
        "����",
        "�����",
        "����",
        "����",
        "������",
        "�����",
        "�����",
        "������",
        "����",
        "����",
        "������",
        "����",
        "�������",
        "���",
        "������",
        "�������",
        "������",
        "�������",
        "���",
        "�����",
        "���������",
        "�����",
        "�����",
        "�������",
        "��������",
        "�����",
        "�������",
    };
    string WORD = words[RandomNum(words.size() - 1)]; // ����������� �����
    transform(WORD.begin(), WORD.end(), WORD.begin(), ::toupper);

    int move = 0, max_move = WORD.length() + WORD.length() / 2, count = 0;
    bool win = false;

    vector<pair<char, char>> find_word; // ������� ����� �� _
    for (int i = 0; i < WORD.length(); i++)
        find_word.push_back(make_pair(WORD[i], '_'));

    output_vec(find_word);

    cout << "����: " << move << '\n';
    cout << "�����������: " << max_move << "\n\n";

    while (true)
    {
        string letter_or_word;
        cout << "-- ";
        cin >> letter_or_word;
        system("cls");
        transform(letter_or_word.begin(), letter_or_word.end(), letter_or_word.begin(), ::toupper);
        if (letter_or_word.length() == 1 && move < max_move) // ������� �����
        {
            if (alphabet.count(letter_or_word[0]) == 0) // ������� ������� � ��������
            {
                cout << "����� ����� ��� � ��������";
            }
            else // ������ ���� � ��������
            {
                move += 1;
                if (alphabet[letter_or_word[0]] == 0)
                {
                    alphabet[letter_or_word[0]] = 1; // �������� �����
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
                            cout << "�� ��������"; // ������ ������ ������� ���� ����
                            win = true;
                        }
                    }
                    else
                    {
                        cout << "����� ����� ��� � �����";
                    }
                }
                else
                {
                    cout << "��� ����� ��� ����������"; // ���� ��������, �������������
                }
            }
            cout << "\n\n";
            output_alphabet(alphabet);
            output_vec(find_word);
            cout << "����: " << move << '\n';
            cout << "�����������: " << max_move << "\n\n";
            if (win)
                break;
        }
        else if (letter_or_word.length() > 1 && move < max_move) // ������� �����
        {
            move += 1;
            if (letter_or_word == WORD)
            {
                cout << "�� ��������";
                for (int i = 0; i < WORD.length(); i++)
                    find_word[i].second = find_word[i].first; // ������ ������ ������� �����
                win = true;
            }
            else
            {
                cout << "�� �� �������";
            }
            cout << "\n\n";
            output_alphabet(alphabet);
            output_vec(find_word);
            cout << "����: " << move << '\n';
            cout << "�����������: " << max_move << "\n\n";
            if (win)
                break;
        }
        if (move == max_move && count != WORD.length()) // ���� ����������� ����� �� �������
        {
            system("cls");
            cout << "�� ���������";
            for (int i = 0; i < WORD.length(); i++)
                find_word[i].second = find_word[i].first;
            cout << "\n\n";
            output_alphabet(alphabet);
            output_vec(find_word);
            cout << "����: " << move << '\n';
            cout << "�����������: " << max_move << "\n\n";
            break;
        }
    }
    return 0;
}