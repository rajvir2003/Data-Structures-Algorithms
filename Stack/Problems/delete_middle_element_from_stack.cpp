#include<bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &s, int size, int count){
    if(count == size/2){
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();
    deleteMiddle(s, size, count+1);
    s.push(num);
}

int main(){
    stack<int> st;
    st.push(4);
    st.push(9);
    st.push(2);
    st.push(10);
    st.push(7);
    int size = st.size();
    deleteMiddle(st, size, 0);

    while(!st.empty()){
        int num = st.top();
        cout << num << " ";
        st.pop();
    }

    return 0;
}