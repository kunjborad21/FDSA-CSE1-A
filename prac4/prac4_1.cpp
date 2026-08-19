#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = NULL;
    }
};

// Insert at beginning
node* insertHead(node* &head, int X){
    node* temp = new node(X);
    temp->next = head;
    head = temp;
    return temp;
}

// Insert at end
node* insertEnd(node* &head, int x){
    if(head == NULL){
        return new node(x);
    }

    node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    node* nextnode = new node(x);
    temp->next = nextnode;

    return head;
}

// Insert at kth position
node* insertKth(node* &head, int x, int k){

    // If position is 1
    if(k == 1){
        return insertHead(head, x);
    }

    node* temp = head;

    // Go to (k-1)th node
    for(int i = 1; i < k-1 && temp != NULL; i++){
        temp = temp->next;
    }

    // If position is invalid
    if(temp == NULL){
        cout << "Invalid position" << endl;
        return head;
    }

    node* nextnode = new node(x);

    nextnode->next = temp->next;
    temp->next = nextnode;

    return head;
}

// Display linked list
void display(node* head)
{
    node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main(){

    int arr[] = {1,2,3,4};
    int n = 4;

    // Create linked list
    node* head = new node(arr[0]);
    node* temp = head;

    for(int i = 1; i < n; i++){
        temp->next = new node(arr[i]);
        temp = temp->next;
    }

    // Insert at beginning
    head = insertHead(head, 100);
    display(head);

    // Insert at end
    head = insertEnd(head, 50);
    display(head);

    // Insert 200 at 3rd position
    head = insertKth(head, 200, 3);
    display(head);

    return 0;
}