#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int ind, int W, int wt[], int val[], vector<vector<int>> &dp){
    if(ind == 0){
        if(W >= wt[0]) return val[0];
        return 0;
    }

    if(dp[ind][W] != -1) return dp[ind][W];
    int pick = INT_MIN;
    if(W >= wt[ind]) pick = val[ind] + f(ind-1, W-wt[ind], wt, val, dp);
    int notPick = f(ind-1, W, wt, val, dp);
    return dp[ind][W] = max(pick, notPick);
}

int knapsack(int W, int wt[], int val[], int n){
    // vector<vector<int>> dp(n, vector<int>(W+1,-1));
    // return f(n-1, W, wt, val, dp);

    // tabulation + space optimization
    vector<int> prev(W+1,0), curr(W+1,0);
    for(int i = wt[0]; i <= W; i++) prev[i] = val[0];

    for(int ind = 1; ind < n; ind++){
        for(int weight = 0; weight <= W; weight++){
            int pick = INT_MIN;
            if(weight >= wt[ind]) pick = val[ind] + prev[weight-wt[ind]];
            int notPick = prev[weight];
            curr[weight] = max(pick, notPick);
        
        }
        prev = curr;
    }
    return prev[W];
}

int main(){
    int n = 3;
    int wt[] = {3,2,5};
    int val[] = {30,40,60};
    int W = 6;

    int ans = knapsack(W, wt, val, n);
    cout << "Maximum value with weight " << W << ": " << ans << endl;

    return 0;
}