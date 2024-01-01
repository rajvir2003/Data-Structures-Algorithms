#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
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

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPos(Node* &head, Node* &tail, int data, int pos){
    if(pos == 1){
        insertAtHead(head, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* ptr = head;
    int count = 1;
    while(count < pos-1){
        ptr = ptr->next;
        count++;
    }
    if(ptr->next == NULL){
        insertAtTail(tail, data);
        return;
    }

    newNode->next = ptr->next;
    ptr->next->prev = newNode;
    ptr->next = newNode;
    newNode->prev = ptr;
}

void deleteAtPos(Node* &head, Node* &tail, int pos){
    if(pos == 1){
        Node* ptr = head;
        head = head->next;
        head->prev = NULL;
        delete ptr;
        return;
    }
    Node* prevNode = head;
    Node* currNode = head->next;
    int count = 1;
    while(count < pos-1){
        prevNode = prevNode->next;
        currNode = currNode->next;
        count++;
    }

    if(currNode->next == NULL){
        prevNode->next = NULL;
        currNode->prev = NULL;
        tail = prevNode;
        delete currNode;
        return;
    }

    prevNode->next = currNode->next;
    currNode->next->prev = prevNode;
    currNode->next = NULL;
    currNode->next = NULL;
    delete currNode;
}

int main(){
    Node* head = new Node(2);
    Node* tail = head;

    insertAtHead(head, 4);
    insertAtHead(head, 7);
    insertAtHead(head, 3);

    insertAtTail(tail, 5);
    insertAtTail(tail, 9);

    insertAtPos(head, tail, 12, 3);

    cout << "After Insertion: " << endl;
    traversal(head);

    deleteAtPos(head, tail, 1);
    deleteAtPos(head, tail, 2);
    deleteAtPos(head, tail, 5);


    cout << "After Deletion: " << endl;
    traversal(head);

    cout << "head->data : " << head->data << endl;
    cout << "tail->data : " << tail->data << endl;
    

    return 0;
}