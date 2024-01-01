#include<bits/stdc++.h>
using namespace std;

bool knows(int a, int b, vector<vector<int>> M){
    if(M[a][b] == 1)
        return true;
    else
        return false;
}

int celebrity(vector<vector<int>> &M, int n){
    stack<int> st;
    
    for(int i = 0; i < n; i++){
        st.push(i);
    }

    while(st.size() != 1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if(knows(a, b, M)){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }

    int candidate = st.top();
    // check row -> check if candidate does'nt know anyone
    // or it checks all elements in row are zero
    int ans = -1;
    int count0 = 0;
    for(int i = 0; i < n; i++){
        if(M[candidate][i] == 0){
            count0++;
        }
    }
    if(count0 == n){
        ans = candidate;
    }

    // check col -> check if everyone knows candidate
    // or it checks all elements in column are 1 (except itself)
    int count1 = 0;
    int ans1 = -1;
    for(int i = 0; i < n; i++){
        if(M[i][candidate] == 1){
            count1++;
        }
    }
    if(count1 == n-1){
        ans1 = candidate;
    }

    if(ans == ans1){
        return candidate;
    }
    else{
        return -1;
    }
}

int main(){
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n = M.size();

    int celeb = celebrity(M, n);
    cout << "Celebrity is " << celeb << endl;

    return 0;
}