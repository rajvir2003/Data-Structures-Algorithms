#include<bits/stdc++.h>
using namespace std;

queue<int> reverse_K_elements(queue<int> q, int k){
    stack<int> st;
    for(int i = 0; i < k; i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    for(int i = 0; i < q.size()-k; i++){
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    queue<int> ans = reverse_K_elements(q, k);
    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;
    
    return 0;
}