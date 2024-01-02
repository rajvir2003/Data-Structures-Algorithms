#include<bits/stdc++.h>
using namespace std;

// Kadane's Algorithm to find maximum subarray sum
int maxSubarraySum(vector<int> &arr, int n){
    int maxi = INT_MIN;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum < 0){
            sum = 0;
            maxi = max(maxi, arr[i]);
        }
        else maxi = max(maxi, sum);
    }
    return maxi;
}

int main(){
    vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};
    int n = arr.size();
    int ans = maxSubarraySum(arr, n);
    cout << "Maximum sub-array sum: " << ans << endl;

    return 0;
}