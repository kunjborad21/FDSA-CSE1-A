#include <iostream>
using namespace std;

class Node
{
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s)
    {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

void insertBeginning(Node*& head, string song)
{
    Node* newNode = new Node(song);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertEnd(Node*& head, string song)
{
    Node* newNode = new Node(song);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(Node*& head, string givenSong, string newSong)
{
    Node* temp = head;

    while (temp != NULL && temp->song != givenSong)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Song not found" << endl;
        return;
    }

    Node* newNode = new Node(newSong);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteFirst(Node*& head)
{
    if (head == NULL)
    {
        cout << "Playlist is empty" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    delete temp;
}

int countSongs(Node* head)
{
    int count = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->song << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;

    insertBeginning(head, "Song1");
    cout << "After insert beginning: ";
    display(head);

    insertEnd(head, "Song2");
    cout << "After insert end: ";
    display(head);

    insertEnd(head, "Song4");
    cout << "After insert end: ";
    display(head);

    insertAfter(head, "Song2", "Song3");
    cout << "After inserting Song3 after Song2: ";
    display(head);

    cout << "Number of songs: " << countSongs(head) << endl;

    deleteFirst(head);
    cout << "After deleting first song: ";
    display(head);

    return 0;
}