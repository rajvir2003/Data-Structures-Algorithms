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

// for removing elements in sorted linked list
Node* removeDuplicates1(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* p = head;
    Node* q = head->next;
    while(q != NULL){
        if(p->data == q->data){
            p->next = q->next;
            q = q->next;
        }
        else{
            p = p->next;
            q = q->next;
        }
    }
    return head;
}

// for removing elements from unsorted linked list
Node* removeDuplicates2(Node* head){
    map<int, bool> visited;
    Node* p = head;
    Node* q = head->next;
    visited[p->data] = true;
    while(q != NULL){
        if(visited[q->data]){
            p->next = q->next;
            q = q->next;
        }
        else{
            visited[q->data] = true;
            p = p->next;
            q = q->next;
        }
    }
    return head;
}

int main(){
    Node* head = new Node(1);
    Node* tail = head;

    /*
    // sorted linked list
    insert(tail, 2);
    insert(tail, 2);
    insert(tail, 4);
    insert(tail, 4);
    insert(tail, 4);
    traversal(head);

    Node* start = removeDuplicates1(head);
    traversal(start);
    */

    // un-sorted linked list
    insert(tail, 5);
    insert(tail, 2);
    insert(tail, 9);
    insert(tail, 1);
    insert(tail, 2);
    insert(tail, 5);
    insert(tail, 8);
    traversal(head);

    Node* start = removeDuplicates2(head);
    traversal(start);

    return 0;
}