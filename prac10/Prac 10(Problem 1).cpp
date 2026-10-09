#include <iostream>
using namespace std;

class HashTable
{
    int table[10];

public:
    HashTable()
    {
        for (int i = 0; i < 10; i++)
        {
            table[i] = -1;
        }
    }

    void insert(int value)
    {
        int index = value % 10;
        int start = index;

        while (table[index] != -1)
        {
            index = (index + 1) % 10;

            if (index == start)
            {
                cout << "Table is full" << endl;
                return;
            }
        }

        table[index] = value;
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "Slot " << i << ": " << table[i] << endl;
        }
    }
};

int main()
{
    HashTable h;

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    cout << "Enter registration numbers: ";

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        h.insert(value);
    }

    cout << endl;
    h.display();

    return 0;
}