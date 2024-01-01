#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);

    cout << "front -> " << q.front() << endl;
    q.pop();
    cout << "front -> " << q.front() << endl;

    if(q.empty()){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Queue is not empty" << endl;
    }

    cout << "Size -> " << q.size() << endl;

    return 0;
}