#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};


Node* head = NULL;  // front of the queue
Node* tail = NULL;  // end of the queue


Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void insertFront(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}


void insertEnd(int value) {
    Node* newNode = createNode(value);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}


void insertAtPosition(int value, int position) {
    if (position <= 0) {
        insertFront(value);
        return;
    }

    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        insertEnd(value);
        return;
    }

    Node* newNode = createNode(value);
    Node* beforeTemp = temp->prev;

    newNode->next = temp;
    newNode->prev = beforeTemp;
    temp->prev = newNode;

    if (beforeTemp == NULL) {
        head = newNode;
    } else {
        beforeTemp->next = newNode;
    }
}

void deleteByValue(int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Value " << value << " not found in queue. Nothing deleted.\n";
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; 
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;
    }

    delete temp;
}

void printForward() {
    cout << "Front to Back: ";
    Node* temp = head;
    if (temp == NULL) {
        cout << "(queue is empty)";
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void printReverse() {
    cout << "Back to Front: ";
    Node* temp = tail;
    if (temp == NULL) {
        cout << "(queue is empty)";
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
int main() {

    insertEnd(101);
    insertEnd(102);
    insertEnd(103);
    insertFront(999);     
    insertAtPosition(555, 2); 
    cout << "----- Initial Queue -----\n";
    printForward();

    cout << "\n----- Deleting patient 102 -----\n";
    deleteByValue(102);
    printForward();

    cout << "\n----- Deleting patient 999 (front) -----\n";
    deleteByValue(999);
    printForward();

    cout << "\n----- Trying to delete a value that doesn't exist (777) -----\n";
    deleteByValue(777);

    cout << "\n----- End of Day Audit (Reverse Print) -----\n";
    printReverse();

    cout << "\n----- Full Queue Front to Back -----\n";
    printForward();

    return 0;
}