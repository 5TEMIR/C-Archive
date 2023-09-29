#include <iostream>

using namespace std;

enum StatusEr
{
    OK,
    Err
};

enum OperationsListStudent
{
    SwapNaprav,
    SledCourse,
    WriteDiplom,
    ProtectDiplom,
    trueOtchislenie
};

class student
{
private:
    int Status;                                               // ����� �� ������ ������
    string FIO;                                               // ���
    int NumberZachet;                                         // ����� �������
    int Course;                                               // ����
    int Naprav;                                               // �����������
    int NumberGroup;                                          // ����� ������
    int NumGroup() { return Course * 100 + Naprav * 10 + 1; } // �������� ������ ������
    bool ReadyDiplom = false;                                 // ������� ��������� ������
    bool ProtectionDiplom = false;                            // ������ �������

public:
    student(int NZ, int N, string F)
    {
        if (NZ > 0 && 1 < N < 10 && F != "")
        {
            Status = OK;
            FIO = F;
            NumberZachet = NZ;
            Course = 1;
            Naprav = N;
            NumberGroup = NumGroup();
        }
        else
        {
            Status = Err;
            FIO = "";
            NumberZachet = 0;
            Course = 0;
            Naprav = 0;
            NumberGroup = 0;
        }
    }
    student()
    {
        Status = Err;
        FIO = "";
        NumberZachet = 0;
        Course = 0;
        Naprav = 0;
        NumberGroup = 0;
    }
    ~student() {}

    int getStatus() { return Status; } // �������
    string getFIO() { return FIO; }
    int getNumberZachet() { return NumberZachet; }
    int getNumberGroup() { return NumberGroup; }
    int getCourse() { return Course; }
    int getNaprav() { return Naprav; }
    bool getReadyDiplom() { return ReadyDiplom; }
    bool getProtectionDiplom() { return ProtectionDiplom; }

    void SwapNaprav(int N) // ����� ������� �����������
    {
        if (Status == OK)
        {
            Naprav = N;
            NumberGroup = NumGroup();
        }
    }

    void SledCourse() // ����� ������� �� ��������� ����
    {
        if (Status == OK)
        {
            if (Course < 4)
            {
                Course += 1;
                NumberGroup = NumGroup();
            }
        }
    }

    void WriteDiplom()
    {
        if (Status == OK)
            ReadyDiplom = true;
    }

    void ProtectDiplom() // ����� �������� ������
    {
        if (Status == OK)
        {
            if (Course == 4 && ReadyDiplom)
                ProtectionDiplom = true;
            else if (Course != 4)
                cout << "�� �� �����, ��� 4�� �����\n";
            else
                cout << "�� �� �����\n";
        }
    }

    void trueOtchislenie() // ����� ��������� �����������
    {
        if (Status == OK)
        {
            if (ProtectionDiplom)
                cout << "����������� � ���������� �����������, " << FIO << "!\n";
            else
                cout << "�� �� �����, ������ ���� ������\n";
        }
    }

    bool operator==(student &s) // ��������� ��������� �� ������ �������
    {
        return (NumberZachet == s.getNumberZachet());
    }

    friend ostream &operator<<(ostream &out, student s) // ����� ����
    {
        out << "���: " << s.FIO << endl
            << "����: " << s.Course << endl
            << "�����������: " << s.Naprav << endl
            << "������: " << s.NumberGroup << endl
            << "������� �" << s.NumberZachet << endl;
        return out;
    }
};

struct node
{
    student *inf;
    node *next;
    node *prev;
};

class List
{
private:
    node *head;
    node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void push(student *s)
    {
        if (!find(*s))
        {
            node *r = new node;
            r->inf = s;
            r->next = NULL;
            if (!head && !tail)
            {
                r->prev = NULL;
                head = r;
            }
            else
            {
                tail->next = r;
                r->prev = tail;
            }
            tail = r;
        }
    }

    bool find(student s)
    {
        node *r = head;
        while (r != NULL)
        {
            if (*(r->inf) == s)
                return true;
            r = r->next;
        }
        return false;
    }

    void erase(student s)
    {
        node *r = head;
        while (r != NULL)
        {
            if (*(r->inf) == s)
                break;
            r = r->next;
        }
        node *&h = head;
        node *&t = tail;
        if (r == h && r == t) // ������������ ������� ������
            h = t = NULL;
        else if (r == h)
        {                // ������� ������ ������
            h = h->next; // �������� ������
            h->prev = NULL;
        }
        else if (r == t)
        {                // ������� ����� ������
            t = t->prev; // �������� �����
            t->next = NULL;
        }
        else
        {
            r->next->prev = r->prev; // ��� ���������� �� r ���������� ���������� r->prev
            r->prev->next = r->next; // ��� ����������� �� r ��������� ���������� r->next
        }
        delete r; // ������� r
    }

    void insert(student A, student *B) // ��������� ����� A
    {
        node *r = head;
        while (r != NULL)
        {
            if (*(r->inf) == A)
                break;
            r = r->next;
        }
        node *&h = head;
        node *&t = tail;
        node *p = new node; // ������� ����� �������
        p->inf = B;
        if (r == t)
        {                   // ���� ��������� ����� ������
            p->next = NULL; // ����������� ��-� - ���������
            p->prev = r;    // ��������� ����� r
            r->next = p;
            t = p; // ������ ����� - p
        }
        else
        {                      // ��������� � �������� ������
            r->next->prev = p; // ��� ���������� �� r ��-�� ���������� - p
            p->next = r->next; // ��������� �� p - ��������� �� r
            p->prev = r;       // p ��������� ����� r
            r->next = p;
        }
    }

    void execute(int oper) // ���������� �������� �������� ��� ������ ��������� ������
    {
        node *r = head;
        switch (oper)
        {
        case 0:
            int N;
            cout << "�����������: ";
            cin >> N;
            while (r != NULL)
            {
                r->inf->SwapNaprav(N);
                r = r->next;
            }
            break;
        case 1:
            while (r != NULL)
            {
                r->inf->SledCourse();
                r = r->next;
            }
            break;
        case 2:
            while (r != NULL)
            {
                r->inf->WriteDiplom();
                r = r->next;
            }
            break;
        case 3:
            while (r != NULL)
            {
                r->inf->ProtectDiplom();
                r = r->next;
            }
            break;
        case 4:
            while (r != NULL)
            {
                r->inf->trueOtchislenie();
                r = r->next;
            }
            break;
        }
    }

    void print() // ����� ��������� ������
    {
        node *r = head;
        while (r != NULL)
        {
            cout << *(r->inf);
            r = r->next;
        }
        cout << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    student s1(20222649, 1, "����������� ������ ����������");
    cout << s1;
    cout << s1.getNumberGroup() << endl;
    s1.SwapNaprav(5);
    cout << s1.getNumberGroup() << endl;
    s1.SledCourse();
    cout << s1.getNumberGroup() << endl;
    s1.SledCourse();
    cout << s1.getNumberGroup() << endl;
    s1.SledCourse();
    cout << s1.getNumberGroup() << endl;
    s1.trueOtchislenie();
    s1.ProtectDiplom();
    s1.WriteDiplom();
    s1.ProtectDiplom();
    s1.trueOtchislenie();

    student s2(20222650, 5, "����������� ������ ����������");
    cout << s2.getNumberGroup() << endl;
    s2.SledCourse();
    s2.SledCourse();
    s2.SledCourse();
    cout << s2.getNumberGroup() << endl;
    // s2.WriteDiplom();
    s2.ProtectDiplom();

    student s3(0, 10, "");
    cout << s3;
    s3.ProtectDiplom();

    student s4(20222650, 3, "����������� ������ ����������");
    student s4(20222650, 3, "����������� ������ ����������");

    List group;
    group.push(&s1);
    group.push(&s2);
    group.push(&s4);
    group.print();
    group.erase(s4);
    group.print();
    group.push(&s4);

    student s5(20222652, 3, "�������� ���� �����������");
    group.insert(s2, &s5);
    group.print();

    group.execute(trueOtchislenie);
    group.print();
}