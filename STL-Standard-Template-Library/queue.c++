#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;

    q.push(23);
    q.push(54);
    q.push(69);
    q.push(87);
    cout << "Front element of queue is " << q.front() << endl;
    cout << "Size of queue is " << q.size() << endl;
    
    q.pop();
    q.pop();

    cout << "Front element of queue after popingis " << q.front() << endl;
    cout << "Size of queue is " << q.size() << endl;

    return 0;
}