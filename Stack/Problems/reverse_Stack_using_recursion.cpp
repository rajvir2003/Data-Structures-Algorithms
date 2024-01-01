#include<bits/stdc++.h>
using namespace std;

void StackTraversal(stack<int> s){
    if(s.empty()){
        return;
    }

    cout << s.top() << " ";
    s.pop();
    StackTraversal(s);
}

void insertAtBottom(stack<int>& s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(num);
}

void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, num);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Orignal Stack: " << endl;
    StackTraversal(s);
    cout << endl; 

    reverse(s);
    cout << "Reversed Stack: " << endl;
    StackTraversal(s);

    return 0;
}