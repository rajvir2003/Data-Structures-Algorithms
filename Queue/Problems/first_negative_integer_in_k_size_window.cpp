#include<bits/stdc++.h>
using namespace std;

vector<int> first_negative_integers(int arr[], int n, int k){
    vector<int> v;
    queue<int> q;
    // process first window
    for(int i = 0; i < k; i++){
        if(arr[i] < 0){
            q.push(i);
        }
    }

    if(!q.empty()){
        v.push_back(arr[q.front()]);
    }
    else{
        v.push_back(0);
    }

    // process remaining windows
    for(int i = k; i < n; i++){
        if(!q.empty() && i-q.front() >= k){
            q.pop();
        }
        if(arr[i] < 0){
            q.push(i);
        }
        if(!q.empty()){
            v.push_back(arr[q.front()]);
        }
        else{
            v.push_back(0);
        }
    }

    return v;
}

int main(){
    int arr[] = {-8, 2, 3, -6, 10};
    int n = sizeof(arr)/sizeof(int);
    int windowSize = 2;
    vector<int> ans = first_negative_integers(arr, n, windowSize);

    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}