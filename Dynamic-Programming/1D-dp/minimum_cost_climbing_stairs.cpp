#include<bits/stdc++.h>
using namespace std;

// with memoization
int f(int n, vector<int> &cost, vector<int> &dp){
    if(n <= 1) return cost[n];
    if(dp[n] != -1) return dp[n];
    dp[n] = cost[n] + min(f(n-1,cost,dp), f(n-2,cost,dp));
    return dp[n];
}

// with tabulation
int f2(vector<int> &cost, int n){
    vector<int> dp(n, -1);
    dp[0] = cost[0];
    for(int i = 1; i < n; i++){
        int left = dp[i-1];
        int right = INT_MAX;
        if(i > 1) right = dp[i-2];
        dp[i] = cost[i] + min(left,right);
    }
    return dp[n-1];
}

int main(){
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int n = cost.size();
    vector<int> dp(n, -1);
    // int ans = min(f(n-1,cost,dp), f(n-2,cost,dp));
    int ans = f2(cost,n);
    cout << "Minimum cost of climbing stairs is: " << ans << endl;

    return 0;
}