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
    if(head == NULL){
        cout << "Empty List" << endl;
        return;
    }

    Node* ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
    
}

void insertNode(Node* &head, int element, int data){

    if(head == NULL){
        Node* newNode = new Node(data);
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* newNode = new Node(data);
    Node* ptr = head;
    while(ptr->data != element){
        ptr = ptr->next;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

bool isCircular(Node* &head){
    Node* ptr = head->next;
    while(ptr != NULL && ptr != head){
        ptr = ptr->next;
    }

    if(ptr == head){
        return true;
    }
    return false;
}

int main(){
    Node* head = NULL;

    insertNode(head, 5, 3);
    insertNode(head, 3, 6);
    insertNode(head, 6, 9);
    insertNode(head, 3, 4);
    insertNode(head, 9, 12);
    insertNode(head, 6, 8);

    traversal(head);

    if(isCircular(head)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}