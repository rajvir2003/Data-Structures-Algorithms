#include<bits/stdc++.h>
using namespace std;

// reverse using stack
// void reverse(queue<int> &q){
//     stack<int> st;
//     while(!q.empty()){
//         st.push(q.front());
//         q.pop();
//     }

//     while(!st.empty()){
//         q.push(st.top());
//         st.pop();
//     }
// }

// reverse using recursion
void reverse(queue<int> &q){
    if(q.empty()){
        return;
    }

    int front = q.front();
    q.pop();
    reverse(q);
    q.push(front);
}

int main(){
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    cout << "Before reversal: " << endl;
    cout << "front -> " << q.front() << endl;
    cout << "rear -> " << q.back() << endl;

    reverse(q);
    cout << "After reversal: " << endl;
    cout << "front -> " << q.front() << endl;
    cout << "rear -> " << q.back() << endl;

    return 0;
}