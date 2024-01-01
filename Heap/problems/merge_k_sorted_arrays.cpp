#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKarrays(vector<vector<int>> &arr, int k){
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(auto i: arr){
        for(auto j: i){
            minHeap.push(j);
        }
    }

    while(!minHeap.empty()){
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {
        {6,7,9},
        {1,3,5},
        {2,4,8}
    };
    int k = arr.size();

    vector<int> result = mergeKarrays(arr, k);
    for(auto i: result){
        cout << i << " ";
    } cout << endl;

    return 0;
}