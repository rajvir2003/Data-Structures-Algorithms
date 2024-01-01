#include<bits/stdc++.h>
using namespace std;

int getMedian(int num, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap){
    // insert into heaps
    if(maxHeap.empty() || maxHeap.top() > num){
        maxHeap.push(num);
    }
    else{
        minHeap.push(num);
    }
    // balance heaps
    if(maxHeap.size() > minHeap.size()+1){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if(minHeap.size() > maxHeap.size()+1){
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
    // return median
    if(minHeap.size() == maxHeap.size()){
        return (minHeap.top()+maxHeap.top())/2;
    }
    else{
        if(minHeap.size() > maxHeap.size()){
            return minHeap.top();
        }
        else{
            return maxHeap.top();
        }
    }
}

int main(){
    vector<int> arr = {5,2,3,1,6};
    int n = arr.size();

    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 0; i < n; i++){
        int median = getMedian(arr[i], maxHeap, minHeap);
        ans.push_back(floor(median));
    }

    for(auto i: ans){
        cout << i << " ";
    } cout << endl;

    return 0;
}