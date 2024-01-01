#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int ind, int W, int val[], int wt[], vector<vector<int>> &dp){
    if(ind == 0){
        if(wt[0] <= W) return val[0]*(W/wt[0]);
        return 0;
    }

    if(dp[ind][W] != -1) return dp[ind][W];
    int pick = INT_MIN;
    if(wt[ind] <= W) pick = val[ind] + f(ind, W-wt[ind], val, wt, dp);
    int notPick = f(ind-1, W, val, wt, dp);
    return dp[ind][W] = max(pick, notPick);
}

int knapSack(int n, int W, int val[], int wt[]){
    // vector<vector<int>> dp(n, vector<int>(W+1,-1));
    // return f(n-1, W, val, wt, dp);

    // tabulation + space optimization (single array optimization)
    vector<int> prev(W+1,0);
    for(int w = 0; w <= W; w++){
        if(wt[0] <= w) prev[w] = val[0]*(w/wt[0]);
    }

    for(int ind = 1; ind < n; ind++){
        for(int w = 0; w <= W; w++){
            int pick = INT_MIN;
            if(wt[ind] <= w) pick = val[ind] + prev[w-wt[ind]];
            int notPick = prev[w];
            prev[w] = max(pick, notPick);
        }
    }
    return prev[W];
}

int main(){
    int n = 3;
    int W = 10;
    int wt[] = {2,4,6};
    int val[] = {5,11,13};

    int ans = knapSack(n, W, val, wt);
    cout << "Maximum amount that can be taken: " << ans << endl;

    return 0;
}