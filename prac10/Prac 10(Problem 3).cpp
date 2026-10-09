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

    int hash1(int key)
    {
        return key % 10;
    }

    int hash2(int key)
    {
        return 7 - (key % 7);
    }

    void insert(int key)
    {
        int index1 = hash1(key);
        int jump = hash2(key);

        for (int i = 0; i < 10; i++)
        {
            int index = (index1 + i * jump) % 10;

            if (table[index] == -1)
            {
                table[index] = key;
                return;
            }
        }

        cout << "Table is full or position cannot be found" << endl;
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
    cout << "Enter number of student IDs: ";
    cin >> n;

    cout << "Enter student IDs: ";

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