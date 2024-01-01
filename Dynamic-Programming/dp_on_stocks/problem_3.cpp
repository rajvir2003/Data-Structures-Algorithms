#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int ind, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp){
    if(ind == n || cap == 0) return 0;
    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    int profit = 0;
    if(buy){
        profit = max(-prices[ind] + f(ind+1,0,cap,prices,n,dp), f(ind+1,1,cap,prices,n,dp));
    }
    else{
        profit = max(prices[ind] + f(ind+1,1,cap-1,prices,n,dp), f(ind+1,0,cap,prices,n,dp));
    }
    return dp[ind][buy][cap] = profit;
}

// buy and sell a share at most twice
int maxProfit(vector<int> prices, int n){
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
    // return f(0, 1, 2, prices, n, dp);

    // tabulation + space optimization
    vector<vector<int>> front(2,vector<int>(3,0)), curr(2,vector<int>(3,0));
    for(int ind = n-1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= 2; cap++){
                int profit = 0;
                if(buy) profit = max(-prices[ind] + front[0][cap], front[1][cap]);
                else profit = max(prices[ind] + front[1][cap-1], front[0][cap]);
                curr[buy][cap] = profit;
            }
        }
        front = curr;
    }
    return front[1][2];
}

int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int n = prices.size();
    int ans = maxProfit(prices, n);
    cout << "Maximum profit by buying and selling at most twice: " << ans << endl;
    
    return 0;
}