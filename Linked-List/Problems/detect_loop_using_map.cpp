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
    do{
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != NULL && ptr != head);
    
    cout << endl;
}

void insert(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

Node* detectLoop(Node* head){
    map<Node*, bool> visited;
    Node* ptr = head;
    while(ptr != NULL){
        if(visited[ptr]){
            return ptr;
        }
        visited[ptr] = true;
        ptr = ptr->next;
    }
    return NULL;
}

int main(){
    Node* head = new Node(2);
    Node* tail = head;
    insert(tail, 5);
    insert(tail, 9);
    insert(tail, 13);
    insert(tail, 7);
    traversal(head);

    tail->next = head->next->next;
    Node* ans = detectLoop(head);
    cout << ans->data << endl;

    return 0;
}