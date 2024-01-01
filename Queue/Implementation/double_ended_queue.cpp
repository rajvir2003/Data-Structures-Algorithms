#include<bits/stdc++.h>
using namespace std;

class DEqueue{
    private:
    int size;
    int* arr;
    int front;
    int rear;

    public:
    DEqueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        if(front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull(){
        if((rear+1)%size == front)
            return true;
        else
            return false;
    }

    bool push_front(int x){
        if(isFull()){
            return false;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(front == 0){
            front = size-1;
        }
        else{
            front = (front-1)%size;
        }
        arr[front] = x;
        return true;
    }

    bool push_rear(int x){
        if(isFull()){
            return false;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else{
            rear = (rear+1)%size;
        }
        arr[rear] = x;
        return true;
    }

    int pop_front(){
        int element = arr[front];
        if(isEmpty()){
            return -1;
        }
        else if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front+1)%size;
        }
        return element;
    }

    int pop_rear(){
        int element = arr[rear];
        if(isEmpty()){
            return -1;
        }
        else if(front == rear){
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size-1;
        }
        else{
            rear = (rear-1)%size;
        }
        return element;
    }

    int get_front(){
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int get_rear(){
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[rear];
        }
    }
};

int main(){
    DEqueue dq(5);
    dq.push_rear(5);
    dq.push_front(10);

    cout << "Front -> " << dq.get_front() << endl;
    cout << "Rear -> " << dq.get_rear() << endl;

    int ans = dq.pop_front();
    cout << "Deleted element is " << ans << endl;

    return 0;
}