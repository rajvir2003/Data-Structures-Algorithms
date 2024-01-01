#include<bits/stdc++.h>
using namespace std;

// with memoization
int f(int n, vector<int> &heights, vector<int> &dp){
    if(n <= 0) return 0;
    if(dp[n] != -1) return dp[n];

    int left = f(n-1,heights,dp) + abs(heights[n] - heights[n-1]);
    int right = f(n-2,heights,dp) + abs(heights[n] - heights[n-2]);
    return dp[n] = min(left,right);
}

// with tabulation
int f1(int n, vector<int> &heights){
    vector<int> dp(n,0);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int left = dp[i-1] + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i > 1) right = dp[i-2] + abs(heights[i] - heights[i-2]);
        dp[i] = min(left,right);
    }
    return dp[n-1];
}

int main(){
    vector<int> heights = {4,8,3,10,4,4};
    int n = heights.size();
    vector<int> dp(n, -1);
    int ans = f(n-1, heights, dp);
    cout << "Total energy lost by frog: " << ans << endl;

    return 0;
}