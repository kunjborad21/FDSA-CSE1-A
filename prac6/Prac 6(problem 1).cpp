#include <iostream>
using namespace std;

class Stack
{
    int* arr;
    int top;
    int capacity;

public:
    Stack(int n)
    {
        capacity = n;
        arr = new int[capacity];
        top = -1;
    }

    void push(int value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = value;

        cout << "Top tray: " << arr[top] << endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        top--;

        if (top == -1)
            cout << "Stack is empty" << endl;
        else
            cout << "Top tray: " << arr[top] << endl;
    }
};

int main()
{
    Stack s(3);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}