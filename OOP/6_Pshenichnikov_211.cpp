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
    int Status;                                               // верно ли создан объект
    string FIO;                                               // ФИО
    int NumberZachet;                                         // номер зачётки
    int Course;                                               // курс
    int Naprav;                                               // направление
    int NumberGroup;                                          // номер группы
    int NumGroup() { return Course * 100 + Naprav * 10 + 1; } // создание номера группы
    bool ReadyDiplom = false;                                 // готовая дипломная работа
    bool ProtectionDiplom = false;                            // защита диплома

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

    int getStatus() { return Status; } // геттеры
    string getFIO() { return FIO; }
    int getNumberZachet() { return NumberZachet; }
    int getNumberGroup() { return NumberGroup; }
    int getCourse() { return Course; }
    int getNaprav() { return Naprav; }
    bool getReadyDiplom() { return ReadyDiplom; }
    bool getProtectionDiplom() { return ProtectionDiplom; }

    void SwapNaprav(int N) // метод сменить направление
    {
        if (Status == OK)
        {
            Naprav = N;
            NumberGroup = NumGroup();
        }
    }

    void SledCourse() // метод перейти на следующий курс
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

    void ProtectDiplom() // метод защитить диплом
    {
        if (Status == OK)
        {
            if (Course == 4 && ReadyDiplom)
                ProtectionDiplom = true;
            else if (Course != 4)
                cout << "Ты не готов, жди 4го курса\n";
            else
                cout << "Ты не готов\n";
        }
    }

    void trueOtchislenie() // метод правильно отчислиться
    {
        if (Status == OK)
        {
            if (ProtectionDiplom)
                cout << "Поздравляем с правильным отчислением, " << FIO << "!\n";
            else
                cout << "Ты не готов, защити свой диплом\n";
        }
    }

    bool operator==(student &s) // сравнение студентов по номеру зачётки
    {
        return (NumberZachet == s.getNumberZachet());
    }

    friend ostream &operator<<(ostream &out, student s) // вывод инфы
    {
        out << "ФИО: " << s.FIO << endl
            << "Курс: " << s.Course << endl
            << "Направление: " << s.Naprav << endl
            << "Группа: " << s.NumberGroup << endl
            << "Зачётка №" << s.NumberZachet << endl;
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
        if (r == h && r == t) // единственный элемент списка
            h = t = NULL;
        else if (r == h)
        {                // удаляем голову списка
            h = h->next; // сдвигаем голову
            h->prev = NULL;
        }
        else if (r == t)
        {                // удаляем хвост списка
            t = t->prev; // сдвигаем хвост
            t->next = NULL;
        }
        else
        {
            r->next->prev = r->prev; // для следующего от r предыдущим становится r->prev
            r->prev->next = r->next; // для предыдущего от r следующим становится r->next
        }
        delete r; // удаляем r
    }

    void insert(student A, student *B) // вставляем после A
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
        node *p = new node; // создаем новый элемент
        p->inf = B;
        if (r == t)
        {                   // если вставляем после хвоста
            p->next = NULL; // вставляемый эл-т - последний
            p->prev = r;    // вставляем после r
            r->next = p;
            t = p; // теперь хвост - p
        }
        else
        {                      // вставляем в середину списка
            r->next->prev = p; // для следующего за r эл-та предыдущий - p
            p->next = r->next; // следующий за p - следующий за r
            p->prev = r;       // p вставляем после r
            r->next = p;
        }
    }

    void execute(int oper) // выполнения заданной операции над каждым элементом списка
    {
        node *r = head;
        switch (oper)
        {
        case 0:
            int N;
            cout << "Направление: ";
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

    void print() // вывод элементов списка
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
    student s1(20222649, 1, "Пшеничников Стемир Михайлович");
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

    student s2(20222650, 5, "Пшеничников Богдан Михайлович");
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

    student s4(20222650, 3, "Пшеничников Михаил Николаевич");

    List group;
    group.push(&s1);
    group.push(&s2);
    group.push(&s4);
    group.print();
    group.erase(s4);
    group.print();
    group.push(&s4);

    student s5(20222652, 3, "Марголин Ефим Григорьевич");
    group.insert(s2, &s5);
    group.print();

    group.execute(trueOtchislenie);
    group.print();
}