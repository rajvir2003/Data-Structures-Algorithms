#include<bits/stdc++.h>
using namespace std;

int main(){
    // initializing an empty stack
    stack <string> s;

    // pushing elements in the stack
    s.push("Tony");
    s.push("Steve");
    s.push("Thor");
    s.push("Hulk");
    cout << "Value at top is " << s.top() << endl;
    cout << "Size of stack is " << s.size() << endl;

    // poping elements from the stack
    s.pop();
    cout << "Value at top is " << s.top() << endl;
    cout << "Size of stack is " << s.size() << endl;
    
    
    return 0;
}