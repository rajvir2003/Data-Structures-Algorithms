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

Node* merge(Node* first, Node* second){
    Node* curr1 = first;
    Node* next1 = first->next;
    Node* curr2 = second;
    Node* next2 = second->next;
    while(next1 != NULL && curr2 != NULL){
        if((curr1->data <= curr2->data) && (next1->data >= curr2->data)){
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->next;
        }
    }
    if(curr2 != NULL){
        curr1->next = curr2;
    }
    return first;
}

int main(){
    Node* first = NULL;
    Node* tail1 = first;
    insert(first, tail1, 1);
    insert(first, tail1, 4);
    insert(first, tail1, 6);
    insert(first, tail1, 7);
    traversal(first);

    Node* second = NULL;
    Node* tail2 = second;
    insert(second, tail2, 2);
    insert(second, tail2, 3);
    insert(second, tail2, 5);
    insert(second, tail2, 7);
    insert(second, tail2, 8);
    insert(second, tail2, 10);
    traversal(second);

    Node* third = NULL;
    if(first->data < second->data){
        third = merge(first, second);
    }
    else{
        third = merge(second, first);
    }

    traversal(third);

    return 0;
}