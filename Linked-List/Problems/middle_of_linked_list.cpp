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

void insert(Node* &tail, int data){
    Node* newNode = new Node(data);

    tail->next = newNode;
    tail = newNode;
}

Node* middleNode(Node* &head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

int main(){
    Node* head = new Node(54);
    Node* tail = head;

    insert(tail, 23);
    insert(tail, 87);
    insert(tail, 45);
    insert(tail, 92);
    insert(tail, 100);

    traversal(head);

    Node* middle = middleNode(head);
    cout << middle->data << endl;

    return 0;
}