#include<bits/stdc++.h>
using namespace std;

vector<int> previousSmallerElement(vector<int> arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        while(st.top() >= arr[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    int n = v.size();
    vector<int> result = previousSmallerElement(v, n);

    for(auto i : result){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}