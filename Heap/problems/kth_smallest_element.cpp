#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k){
    priority_queue<int> pq;
    // push first k elements into priority queue
    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }
    // process elements from k to n-1
    // if any element is smaller than pq.top() then remove pq.top() and push that element into pq
    for(int i = k; i < n; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    // now kth smallest element will be present on pq.top()
    return pq.top();
}

int main(){
    int arr[] = {7, 10, 4, 20, 15};
    int n = sizeof(arr)/sizeof(int);
    int k = 4;

    int ans = kthSmallest(arr, n, k);
    cout << "Kth element -> " << ans << endl;

    return 0;
}