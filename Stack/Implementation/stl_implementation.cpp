#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s;
    s.push(5);
    s.push(3);
    s.push(9);
    s.push(7);
    cout << "Top element is " << s.top() << endl;
    cout << "Size of stack is " << s.size() << endl;

    s.pop();
    cout << "Top element is " << s.top() << endl;
    cout << "Size of stack is " << s.size() << endl;
 
    if(s.empty()){
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Stack is not empty" << endl;
    }

    return 0;
}