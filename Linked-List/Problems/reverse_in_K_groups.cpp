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

void insert(Node* &head, int data){
    Node* newNode = new Node(data);
    
    newNode->next = head;
    head = newNode;
}

bool isPossible(Node* &head, int k){
    Node* ptr = head;
    int count = 0;
    while(ptr != NULL){
        ptr = ptr->next;
        count++;
    }
    
    if(count >= k){
        return true;
    }
    else{
        return false;
    }
}
Node* reverseInKgroups(Node* head, int k){
    if(head->next == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    int count = 0;
    while(count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(curr != NULL){
        if(isPossible(curr, k)){
            head->next = reverseInKgroups(curr, k);
        }
        else{
            head->next = curr;
        }
    }

    return prev;
}

int main(){
    Node* head = new Node(5);
    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    // insert(head, 0);

    traversal(head);

    int k = 3;
    Node* start = reverseInKgroups(head, k);
    traversal(start);

    return 0;
}