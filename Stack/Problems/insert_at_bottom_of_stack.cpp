#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(num);
}

void stackTraversal(stack<int> s){
    if(s.empty()){
        return;
    }
    cout << s.top() << endl;
    s.pop();
    stackTraversal(s);
}

int main(){
    stack<int> s;
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(5);

    int element = 9;
    insertAtBottom(s, element);

    stackTraversal(s);

    return 0;
}