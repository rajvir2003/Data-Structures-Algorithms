#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int size;
    int top;
    int* arr;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(top < size-1){
            top++;
            arr[top] = element;
        }
        else{ 
            cout << "Stack Overflow" << endl;
        }
    }

    void pop(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
        }
        else{
            top--;
        }
    }

    int peek(){
        if(top > -1){
            return arr[top];
        }
        else{
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Stack st(5);
    st.push(45);
    st.push(76);
    st.push(23);
    st.push(98);
    st.push(100);
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    if(st.isEmpty()){
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Stack is not empty" << endl;
    }
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    
    cout << st.peek() << endl;

    return 0;
}