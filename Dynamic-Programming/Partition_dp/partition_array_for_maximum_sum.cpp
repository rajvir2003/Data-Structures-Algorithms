#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int i, int k, int n, vector<int> &arr, vector<int> &dp){
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];

    int maxSum = INT_MIN;
    int maxi = INT_MIN;
    for(int ind = i; ind < i+k && ind < n; ind++){
        maxi = max(maxi, arr[ind]);
        int sum = maxi*(ind-i+1) + f(ind+1, k, n, arr, dp);
        maxSum = max(maxSum, sum);
    }
    return dp[i] = maxSum;
}

int maxSumAfterPartitioning(vector<int>& arr, int k){
    int n = arr.size();
    // vector<int> dp(n, -1);
    // return f(0, k, n, arr, dp);

    // tabulation
    vector<int> dp(n+1, 0);
    dp[n] = 0;
    for(int i = n-1; i >= 0; i--){
        int maxSum = INT_MIN;
        int maxi = INT_MIN;
        for(int ind = i; ind < i+k && ind < n; ind++){
            maxi = max(maxi, arr[ind]);
            int sum = maxi*(ind-i+1) + dp[ind+1];
            maxSum = max(maxSum, sum);
        }
        dp[i] = maxSum;
    }
    return dp[0];
}

int main(){
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;
    cout << "Maximum sum after partitioning: " << maxSumAfterPartitioning(arr, k) << endl;

    return 0;
}