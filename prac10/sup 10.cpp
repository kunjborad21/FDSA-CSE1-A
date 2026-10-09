#include <iostream>
#include <vector>
using namespace std;

class Student
{
public:
    int id;
    int score;

    Student()
    {
        id = -1;
        score = -1;
    }

    Student(int i, int s)
    {
        id = i;
        score = s;
    }
};

class HashTable
{
    int size;
    Student linearTable[10];
    vector<Student> chainTable[10];

public:
    HashTable()
    {
        size = 10;
    }

    int hashFunction(int id)
    {
        return id % size;
    }

    void insertLinear(int id, int score)
    {
        int index = hashFunction(id);
        int start = index;

        while (linearTable[index].id != -1)
        {
            index = (index + 1) % size;

            if (index == start)
            {
                cout << "Linear table is full" << endl;
                return;
            }
        }

        linearTable[index] = Student(id, score);
    }

    void insertChaining(int id, int score)
    {
        int index = hashFunction(id);

        chainTable[index].push_back(Student(id, score));
    }

    void displayLinear()
    {
        cout << "\nLinear Probing:\n";

        for (int i = 0; i < size; i++)
        {
            cout << "Slot " << i << ": ";

            if (linearTable[i].id == -1)
            {
                cout << "Empty";
            }
            else
            {
                cout << "ID = " << linearTable[i].id
                     << ", Score = " << linearTable[i].score;
            }

            cout << endl;
        }
    }

    void displayChaining()
    {
        cout << "\nSeparate Chaining:\n";

        for (int i = 0; i < size; i++)
        {
            cout << "Slot " << i << ": ";

            if (chainTable[i].empty())
            {
                cout << "Empty";
            }
            else
            {
                for (int j = 0; j < chainTable[i].size(); j++)
                {
                    cout << "(ID = " << chainTable[i][j].id
                         << ", Score = " << chainTable[i][j].score << ") ";
                }
            }

            cout << endl;
        }
    }
};

int main()
{
    HashTable h;

    int n;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter student ID and score:\n";

    for (int i = 0; i < n; i++)
    {
        int id, score;

        cin >> id >> score;

        h.insertLinear(id, score);
        h.insertChaining(id, score);
    }

    h.displayLinear();
    h.displayChaining();

    return 0;
}