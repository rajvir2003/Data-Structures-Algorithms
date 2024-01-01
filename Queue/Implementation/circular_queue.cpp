#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
    private:
    int size;
    int* arr;
    int front;
    int rear;

    public:
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int data){
        // check is queue is full or not
        if((rear+1)%size == front){
            cout << "Queue is full" << endl;
            return;
        }
        else if(rear == -1 && front == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear+1)%size;
        }
        arr[rear] = data;
    }

    int dequeue(){
        int val = arr[front];
        // check if queue is empty or not
        if(front == -1 && rear == -1){
            return -1;
        }
        else if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%size;
        }
        return val;
    }
};

int main(){
    CircularQueue Q(5);
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    
    cout << "Deleted element: " << Q.dequeue() << endl;
    cout << "Deleted element: " << Q.dequeue() << endl;
    cout << "Deleted element: " << Q.dequeue() << endl;

    Q.enqueue(2);
    Q.enqueue(7);
    Q.enqueue(9);

    cout << "Deleted element: " << Q.dequeue() << endl;
    cout << "Deleted element: " << Q.dequeue() << endl;
    cout << "Deleted element: " << Q.dequeue() << endl;
    cout << "Deleted element: " << Q.dequeue() << endl;
    cout << "Deleted element: " << Q.dequeue() << endl;
    cout << "Deleted element: " << Q.dequeue() << endl;

    return 0;
}