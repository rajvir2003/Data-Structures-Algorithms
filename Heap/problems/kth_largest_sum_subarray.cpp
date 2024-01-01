#include<bits/stdc++.h>
using namespace std;

int kth_Largest_sum_subarray(vector<int> &arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(pq.size() < k){
                pq.push(sum);
            }
            else if(pq.top() < sum){
                pq.pop();
                pq.push(sum);
            }
        }
    }
    return pq.top();
}

int main(){
    vector<int> arr = {4, -8, 9, 10, 1, 7};
    int n = arr.size();
    int k = 2;
    int ans = kth_Largest_sum_subarray(arr, n, k);

    cout << "Kth largest sum subarray : " << ans << endl;

    return 0;
}