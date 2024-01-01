#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void traversal(Node* &head){
    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

Node* reverse(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

int main(){
    Node* head = new Node(5);
    Node* tail = head;

    insertAtTail(tail, 3);
    insertAtTail(tail, 8);
    insertAtTail(tail, 10);
    traversal(head);

    Node* start = reverse(head);
    traversal(start);
    
    return 0;
}