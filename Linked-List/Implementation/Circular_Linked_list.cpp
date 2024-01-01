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

void deleteNode(Node* &head, int element){

    if(head->data == element && head->next == head){
        head = NULL;
        return;
    }

    Node* prevNode = head;
    while(prevNode->next != head){
        prevNode = prevNode->next;
    }
    Node* currNode = head;

    // To delete the first/head node
    if(head->data == element){
        prevNode->next = currNode->next;
        head = currNode->next;
        delete currNode;
        return;
    }

    while(currNode->data != element){
        prevNode = prevNode->next;
        currNode = currNode->next;
    }
    prevNode->next = currNode->next;
    currNode->next = NULL;
    delete currNode;
}


int main(){
    Node* head = NULL;

    insertNode(head, 5, 3);
    insertNode(head, 3, 6);
    insertNode(head, 6, 9);
    insertNode(head, 3, 4);
    insertNode(head, 9, 12);
    insertNode(head, 6, 8);

    cout << "After Insertion: " << endl;
    traversal(head);

    deleteNode(head, 3);
    deleteNode(head, 8);
    deleteNode(head, 12);
    deleteNode(head, 9);
    deleteNode(head, 4);
    deleteNode(head, 6);

    cout << "After Deletion: " << endl;
    traversal(head);

    return 0;
}