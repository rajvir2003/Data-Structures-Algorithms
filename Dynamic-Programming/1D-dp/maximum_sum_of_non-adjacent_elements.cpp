#include<bits/stdc++.h>
using namespace std;

// with memoization
int f(int n, vector<int> &nums, vector<int> &dp){
    if(n == 0) return nums[0];
    if(n < 0) return 0;

    if(dp[n] != -1) return dp[n];
    int notPick = f(n-1,nums,dp) + 0;
    int pick = f(n-2,nums,dp) + nums[n];
    return dp[n] = max(pick, notPick);
}

// with tabulation
int f(vector<int> &nums, int n){
    vector<int> dp(n,0);
    dp[0] = nums[0];
    for(int i = 1; i < n; i++){
        int pick = nums[i];
        if(i > 1) pick += dp[i-2];
        int notPick = dp[i-1];
        dp[i] = max(pick, notPick);
    }
    return dp[n-1];
}

int main(){
    vector<int> nums = {1,2,3,1,3,5,8,1,9};
    int n = nums.size();
    vector<int> dp(n,-1);
    // int ans = f(n-1,nums,dp);
    int ans = f(nums, n);
    cout << "Maximum sum of non-adjacent elements: " << ans << endl;

    return 0;
}