#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> arr, int n){
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for(int i = n-1; i >= 0; i--){
        while(st.top() != -1 && arr[st.top()] >= arr[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmaller(vector<int> arr, int n){
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for(int i = 0; i < n; i++){
        while(st.top() != -1 && arr[st.top()] >= arr[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights){
    int n = heights.size();

    vector<int> next(n);
    next = nextSmaller(heights, n);

    vector<int> prev(n);
    prev = prevSmaller(heights, n);

    int area = -1;
    for(int i = 0; i < n; i++){
        int length = heights[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int breadth = next[i] - prev[i] - 1;

        int newArea = length*breadth;
        area = max(area, newArea);
    }
    return area;
}

int main(){
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int area = largestRectangleArea(heights);
    cout << "Largest Rectangle Area is " << area << endl;

    return 0;
}