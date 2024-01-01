#include<bits/stdc++.h>
using namespace std;

void stackTraversal(stack<int> s){
    if(s.empty()){
        return;
    }

    cout << s.top() << " ";
    s.pop();
    stackTraversal(s);
}

void insertSorted(stack<int> &stack, int num){
    if(stack.empty() || stack.top() < num){
        stack.push(num);
        return;
    }

    int top = stack.top();
    stack.pop();
    insertSorted(stack, num);
    stack.push(top);
}

void sortStack(stack<int> &stack){
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();
    sortStack(stack);
    insertSorted(stack, num);
}

int main(){
    stack<int> s;
    s.push(7);
    s.push(-2);
    s.push(4);
    s.push(10);
    s.push(3);
    stackTraversal(s);
    cout << endl;

    sortStack(s);
    stackTraversal(s);
    cout << endl;

    return 0;
}