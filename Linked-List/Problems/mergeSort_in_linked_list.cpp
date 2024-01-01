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

Node* middle(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* first, Node* second){
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }

    Node* result = NULL;
    Node* resultTail = result;

    Node* temp1 = first;
    Node* temp2 = second;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            insert(result, resultTail, temp1->data);
            temp1 = temp1->next;
        }
        else{
            insert(result, resultTail, temp2->data);
            temp2 = temp2->next;
        }
    }

    while(temp1 != NULL){
        insert(result, resultTail, temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        insert(result, resultTail, temp2->data);
        temp2 = temp2->next;
    }

    return result;
}

Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* middleNode = middle(head);
    Node* mid = middleNode->next;
    middleNode->next = NULL;

    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);

    return merge(left,right);
}

int main(){
    Node* head = NULL;
    Node* tail = head;
    insert(head, tail, 9);
    insert(head, tail, 2);
    insert(head, tail, 7);
    insert(head, tail, 10);
    insert(head, tail, 1);
    insert(head, tail, 5);
    insert(head, tail, 4);
    traversal(head);

    Node* start = mergeSort(head);
    traversal(start);

    return 0;
}