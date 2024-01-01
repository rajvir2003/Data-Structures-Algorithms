#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next= NULL;
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
    head = newNode;

}

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    ptr->next = newNode;
}

void insertAtPosition(Node* &head, int data, int pos){
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

    newNode->next = ptr->next;
    ptr->next = newNode;
}

void deleteAtPosition(Node* &head, int pos){
    if(pos == 1){
        Node* ptr = head;
        head = head->next;
        delete ptr;
        return;
    }

    Node* prev = head;
    Node* curr = head->next;
    int count = 1;
    while(count < pos-1){
        prev = prev->next;
        curr = curr->next;
        count++;
    }

    prev->next = curr->next;
    delete curr;
}

int main(){
    Node* head = new Node(5);
    
    insertAtHead(head, 7);
    insertAtHead(head, 2);
    insertAtHead(head, 9);

    insertAtTail(head, 10);
    insertAtTail(head, 15);

    insertAtPosition(head, 18, 5);
    insertAtPosition(head, 20, 8);
    insertAtPosition(head, 3, 1);

    cout << "After Insertion: ";
    traversal(head);

    deleteAtPosition(head, 1);
    deleteAtPosition(head, 5);
    deleteAtPosition(head, 7);

    cout << "After Deletion: ";
    traversal(head);
    
    return 0;
}