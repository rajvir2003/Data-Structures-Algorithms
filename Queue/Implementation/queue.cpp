#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
    int size;
    int* arr;
    int front;
    int rear;

    public:
    // initializing constructor
    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty(){
        if(front == rear)
            return true;
        else
            return false;
    }

    void enqueue(int data){
        if(rear == size){
            cout << "Queue is full" << endl;
            return;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){
        if(front == rear){
            return -1;
        }
        else{
            int val = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return val;
        }
    }

    int frontElement(){
        if(front == rear)
            return -1;
        else
            return arr[front];
    }
};

int main(){
    Queue q(5);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);

    cout << "front -> " << q.frontElement() << endl;
    q.dequeue();
    cout << "front -> " << q.frontElement() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    if(q.isEmpty()){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Queue is not empty" << endl;
    }

    return 0;
}