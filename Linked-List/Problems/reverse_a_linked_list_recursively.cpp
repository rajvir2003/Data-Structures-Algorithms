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

// void reverse(Node* &head,Node* curr, Node* prev){
//     // base case 
//     if(curr == NULL){
//         head = prev;
//         return;
//     }

//     reverse(head, curr->next, curr);
//     curr->next = prev;
// }

Node* reverse(Node* curr, Node* prev){
    if(curr == NULL){
        return prev;
    }

    Node* forward = curr->next;
    curr->next = prev;
    return reverse(forward, curr);
}

int main(){
    Node* head = new Node(2);
    Node* tail = head;
    
    insertAtTail(tail, 4);
    insertAtTail(tail, 7);
    insertAtTail(tail, 9);
    insertAtTail(tail, 12);
    insertAtTail(tail, 16);
    traversal(head);

    Node* start = reverse(head, NULL);
    traversal(start);
    
    return 0;
}