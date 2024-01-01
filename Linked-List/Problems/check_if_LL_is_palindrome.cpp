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

void traversal(Node* head){
    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void insert(Node* &head, Node* &tail, int data){
    if(tail == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = head;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* reverse(Node* head){
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
    Node* head = NULL;
    Node* tail = head;
    insert(head, tail, 3);
    insert(head, tail, 2);
    insert(head, tail, 1);
    insert(head, tail, 1);
    insert(head, tail, 2);
    insert(head, tail, 3);
    traversal(head);

    Node* middle = getMid(head);
    middle = middle->next;
    Node* ptr2 = reverse(middle);

    Node* ptr = head;
    while(ptr2 != NULL){
        if(ptr->data != ptr2->data){
            cout << "Not a palindrome" << endl;
            return 0;
        }
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    cout << "It is a palindrome" << endl;


    return 0;
}