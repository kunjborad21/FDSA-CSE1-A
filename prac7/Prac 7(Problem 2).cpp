#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node* next;

    Node(string n)
    {
        name = n;
        next = NULL;
    }
};

class Queue
{
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void arrive(string name)
    {
        Node* newNode = new Node(name);

        if (rear == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front patient: " << front->name << endl;
    }

    void attend()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow - No patients waiting" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == NULL)
            rear = NULL;

        if (front == NULL)
            cout << "Ward is empty" << endl;
        else
            cout << "Front patient: " << front->name << endl;
    }
};

int main()
{
    Queue q;

    q.arrive("Patient A");
    q.arrive("Patient B");
    q.arrive("Patient C");

    q.attend();
    q.attend();

    q.arrive("Patient D");

    q.attend();
    q.attend();
    q.attend();

    return 0;
}