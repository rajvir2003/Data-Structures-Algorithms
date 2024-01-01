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

Node* sort(Node* head){
    Node* ptr = head;
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    while(ptr != NULL){
        if(ptr->data == 0){
            zeroCount++;
        }
        else if(ptr->data == 1){
            oneCount++;
        }
        else if(ptr->data == 2){
            twoCount++;
        }
        ptr = ptr->next;
    }

    ptr = head;
    while(ptr != NULL){
        if(zeroCount != 0){
            ptr->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            ptr->data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            ptr->data = 2;
            twoCount--;
        }
        ptr = ptr->next;
    }
    return head;
}

int main(){
    Node* head = NULL;
    Node* tail = head;

    insert(head, tail, 1);
    insert(head, tail, 0);
    insert(head, tail, 2);
    insert(head, tail, 1);
    insert(head, tail, 2);
    traversal(head);

    Node* start = sort(head);
    traversal(start);

    return 0;
}