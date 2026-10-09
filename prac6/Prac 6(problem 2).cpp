#include <iostream>
using namespace std;

class Node
{
public:
    string page;
    Node* next;

    Node(string p)
    {
        page = p;
        next = NULL;
    }
};

class Stack
{
    Node* top;

public:
    Stack()
    {
        top = NULL;
    }

    void visit(string page)
    {
        Node* newNode = new Node(page);

        newNode->next = top;
        top = newNode;

        cout << "Current page: " << top->page << endl;
    }

    void back()
    {
        if (top == NULL)
        {
            cout << "No history left" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;

        if (top == NULL)
            cout << "No page open" << endl;
        else
            cout << "Current page: " << top->page << endl;
    }
};

int main()
{
    Stack history;

    history.visit("Google");
    history.visit("YouTube");
    history.visit("GitHub");

    history.back();
    history.back();
    history.back();
    history.back();

    return 0;
}