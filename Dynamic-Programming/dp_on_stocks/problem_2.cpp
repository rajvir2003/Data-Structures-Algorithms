#include<bits/stdc++.h>
using namespace std;

// find maximum profit by buying and selling stock unlimited times
// note* -> you can't hold stock (means you cannot buy before selling a stock).

// memoization
int f(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp){
    if(ind == n) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];

    int profit = 0;
    if(buy){
        profit = max(-prices[ind] + f(ind+1, 0, prices, n, dp), f(ind+1, 1, prices, n, dp));
    }
    else{
        profit = max(prices[ind] + f(ind+1, 1, prices, n, dp), f(ind+1, 0, prices, n, dp));
    }
    return dp[ind][buy] = profit;
}

int maxProfit(vector<int> &prices){
    int n = prices.size();
    // vector<vector<int>> dp(n, vector<int>(2,-1));
    // return f(0, 1, prices, n, dp);

    // tabulation
    vector<vector<int>> dp(n+1, vector<int>(2,0));
    dp[n][0] = dp[n][1] = 0;

    for(int ind = n-1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            int profit = 0;
            if(buy) profit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
            else profit = max(prices[ind] + dp[ind+1][1], dp[ind+1][0]);
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    int ans = maxProfit(prices);
    cout << "Maximum profit: " << ans << endl;

    return 0;
}