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
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = head;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
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

Node* addTwoLists(Node* first, Node* second){
    first = reverse(first);
    second = reverse(second);

    Node* sumhead = NULL;
    Node* sumtail = sumhead;
    int carry = 0;

    while(first != NULL && second != NULL){
        int sum = first->data + second->data + carry;
        int digit = sum % 10;
        carry = sum / 10;
        insert(sumhead, sumtail, digit);
        first = first->next;
        second = second->next;
    }

    while(first != NULL){
        int sum = first->data + carry;
        int digit = sum % 10;
        carry = sum / 10;
        insert(sumhead, sumtail, digit);
        first = first->next;
    }

    while(second != NULL){
        int sum = second->data + carry;
        int digit = sum % 10;
        carry = sum / 10;
        insert(sumhead, sumtail, digit);
        second = second->next;
    }

    while(carry != 0){
        int sum = carry;
        int digit = sum % 10;
        insert(sumhead, sumtail, digit);
        carry = carry / 10;
    }

    sumhead = reverse(sumhead);
    return sumhead;
}

int main(){
    // first linked list
    Node* first = NULL;
    Node* tail1 = first;
    insert(first, tail1, 4);
    insert(first, tail1, 5);
    insert(first, tail1, 2);
    insert(first, tail1, 3);
    traversal(first);

    // second linked list
    Node* second = NULL;
    Node* tail2 = second;
    insert(second, tail2, 4);
    insert(second, tail2, 7);
    insert(second, tail2, 7);
    traversal(second);

    // answer linked list
    Node* answer = addTwoLists(first, second);
    traversal(answer);

    return 0;
}