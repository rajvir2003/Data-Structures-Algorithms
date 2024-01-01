#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    
    for(int i = n-1; i >= 0; i--){

        while(st.top() >= arr[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }

    return ans;
}

int main(){
    vector<int> arr = {2, 1, 4, 3};
    int n = arr.size();
    vector<int> result = nextSmallerElement(arr, n);

    for(auto i : result){
        cout << i << " ";
    }
    
    return 0;
}