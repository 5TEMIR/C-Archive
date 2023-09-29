#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int d, m, y;
    string month[]{"������",
                   "�������",
                   "�����",
                   "������",
                   "���",
                   "����",
                   "����",
                   "�������",
                   "��������",
                   "�������",
                   "������",
                   "�������"};
    cout << "������� ����\n";
    cin >> d >> m >> y;
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: // 31 ����
        if (d <= 0 || d > 31)
            cout << "������������ ����\n";
        else
            cout << d << " " << month[m - 1] << " " << y << " "
                 << "����" << endl
                 << "�� ����� ������ �������� ����: " << 31 - d;
        break;
    case 4:
    case 6:
    case 9:
    case 11: // 30 ����
        if (d <= 0 || d > 30)
            cout << "������������ ����\n";
        else
            cout << d << " " << month[m - 1] << " " << y << " "
                 << "����" << endl
                 << "�� ����� ������ �������� ����: " << 30 - d;
        break;
    case 2:
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) //���������� ���
            if (d <= 0 || d > 29)
                cout << "������������ ����\n";
            else
                cout << d << " " << month[m - 1] << " " << y << " "
                     << "����" << endl
                     << "�� ����� ������ �������� ����: " << 29 - d;
        else //������������
            if (d <= 0 || d > 28)
                cout << "������������ ����\n";
            else
                cout << d << " " << month[m - 1] << " " << y << " "
                     << "����" << endl
                     << "�� ����� ������ �������� ����: " << 28 - d;
        break;
    default:
        cout << "������������ �����\n";
    }
    return 0;
}