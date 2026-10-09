#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void insertAtPosition(Node*& head, int value, int position)
{
    if (position < 1)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node* newNode = new Node(value);

    if (head == NULL)
    {
        if (position == 1)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            cout << "Invalid position" << endl;
            delete newNode;
        }
        return;
    }

    if (position == 1)
    {
        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            cout << "Invalid position" << endl;
            delete newNode;
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteStudent(Node*& head, int value)
{
    if (head == NULL)
    {
        cout << "Circle is empty" << endl;
        return;
    }

    if (head->data == value && head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    if (head->data == value)
    {
        Node* last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        Node* temp = head;
        head = head->next;
        last->next = head;

        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != head && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == head)
    {
        cout << "Student not found" << endl;
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;

    delete deleteNode;
}

void display(Node* head)
{
    if (head == NULL)
    {
        cout << "Circle is empty" << endl;
        return;
    }

    Node* temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while (temp != head);

    cout << endl;
}

int main()
{
    Node* head = NULL;

    insertEnd(head, 10);
    cout << "After joining 10: ";
    display(head);

    insertEnd(head, 20);
    cout << "After joining 20: ";
    display(head);

    insertEnd(head, 30);
    cout << "After joining 30: ";
    display(head);

    insertAtPosition(head, 15, 2);
    cout << "After inserting 15 at position 2: ";
    display(head);

    deleteStudent(head, 20);
    cout << "After student 20 leaves: ";
    display(head);

    return 0;
}