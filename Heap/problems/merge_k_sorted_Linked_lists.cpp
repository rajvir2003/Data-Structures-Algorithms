#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insert(node* &head, node* &tail, int data){
    node* newNode = new node(data);

    if(head == NULL){
        head = newNode;
        tail = head;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void traverseLL(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;
}

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

node* mergeKlinkedLists(vector<node*> &arr, int k){
    priority_queue<node*, vector<node*>, compare> minHeap;
    for(int i = 0; i < k; i++){
        minHeap.push(arr[i]);
    }

    node* head = NULL;
    node* tail = NULL;
    while(!minHeap.empty()){
        if(head == NULL){
            head = minHeap.top();
            tail = head;
            minHeap.pop();
            if(head->next != NULL){
                minHeap.push(head->next);
            }
        }
        else{
            tail->next = minHeap.top();
            minHeap.pop();
            tail = tail->next;
            if(tail->next != NULL){
                minHeap.push(tail->next);
            }
        }
    }
    return head;
}

int main(){
    node* head1 = NULL;
    node* tail1 = NULL;
    insert(head1, tail1, 2);
    insert(head1, tail1, 8);
    insert(head1, tail1, 10);

    node* head2 = NULL;
    node* tail2 = NULL;
    insert(head2, tail2, 1);
    insert(head2, tail2, 3);
    insert(head2, tail2, 5);
    insert(head2, tail2, 7);

    node* head3 = NULL;
    node* tail3 = NULL;
    insert(head3, tail3, 4);
    insert(head3, tail3, 6);
    insert(head3, tail3, 9);

    vector<node*> arr = {head1, head2, head3};
    int k = arr.size();

    node* head = mergeKlinkedLists(arr, k);
    traverseLL(head);

    return 0;
}