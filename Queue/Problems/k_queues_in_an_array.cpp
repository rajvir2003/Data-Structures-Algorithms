#include<bits/stdc++.h>
using namespace std;

class K_queues{
    public:
    int n;
    int k;
    int* arr;
    int* front;
    int* rear;
    int* next;
    int freeSpot;

    K_queues(int n, int k){
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        for(int i = 0; i < k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for(int i = 0; i < n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;

        freeSpot = 0;
    }

    void push(int data, int qn){
        // check overflow
        if(freeSpot == -1){
            cout << "No empty space is present" << endl;
            return;
        }

        int index = freeSpot;
        freeSpot = next[index];
        // for first element in queue
        if(front[qn-1] == -1){
            front[qn-1] = index;
        }
        else{
            // link new element to previous element
            next[rear[qn-1]] = index;
        }

        next[index] = -1;
        rear[qn-1] = index;
        arr[index] = data;
    }

    int pop(int qn){
        // check underflow
        if(front[qn-1] == -1){
            cout << "Queue is empty" << endl;
            return -1;
        }

        int index = front[qn-1];
        front[qn-1] = next[index];

        // manage freespot
        next[index] = freeSpot;
        freeSpot = index;
        
        return arr[index];
    }
};

int main(){
    K_queues q(9, 3);
    q.push(5,1);
    q.push(4,2);
    q.push(9,1);
    q.push(8,1);

    cout << "Element deleted is " << q.pop(1) << endl;
    cout << "Element deleted is " << q.pop(2) << endl;

    return 0;
}