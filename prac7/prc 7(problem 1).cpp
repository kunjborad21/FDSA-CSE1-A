#include <iostream>
using namespace std;

class Queue
{
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int n)
    {
        capacity = n;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        count = 0;
    }

    void join(int token)
    {
        if (count == capacity)
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % capacity;
        arr[rear] = token;
        count++;

        cout << "Front token: " << arr[front] << endl;
    }

    void serve()
    {
        if (count == 0)
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        front = (front + 1) % capacity;
        count--;

        if (count == 0)
        {
            front = -1;
            rear = -1;
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Front token: " << arr[front] << endl;
        }
    }
};

int main()
{
    Queue q(3);

    q.join(101);
    q.join(192);
    q.join(113);
    q.join(104);

    q.serve();
    q.serve();

    q.join(104);
    q.join(195);

    q.serve();
    q.serve();
    q.serve();
    q.serve();

    return 0;
}