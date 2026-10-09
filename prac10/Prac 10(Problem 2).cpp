#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class HashTable
{
    stack<int> table[10];

public:
    void insert(int value)
    {
        int index = value % 10;
        table[index].push(value);
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "Shelf " << i << ": ";

            if (table[i].empty())
            {
                cout << "Empty";
            }
            else
            {
                stack<int> temp = table[i];

                while (!temp.empty())
                {
                    cout << temp.top() << " ";
                    temp.pop();
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
    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book codes: ";

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