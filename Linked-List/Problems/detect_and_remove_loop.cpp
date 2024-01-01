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

// floyd's cycle detection algorithm
Node* detectLoop(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

Node* startNode(Node* head){
    Node* intersectionPoint = detectLoop(head);
    Node* slow = head;
    while(slow != intersectionPoint){
        slow = slow->next;
        intersectionPoint = intersectionPoint->next;
    }
    return slow;
}

Node* removeLoop(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* start = startNode(head);
    Node* ptr = start;
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return head;
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
    removeLoop(head);
    traversal(head);
    

    return 0;
}