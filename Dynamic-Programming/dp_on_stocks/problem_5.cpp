#include<bits/stdc++.h>
using namespace std;

// find maximum profit by buying and selling stock unlimited time (but with cooldown)
// note* -> cooldown means you cannot buy a stock on next day after selling it.

// memoization
int f(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp){
    if(ind >= n) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];

    if(buy) return dp[ind][buy] = max(-prices[ind] + f(ind+1,0,prices,n,dp), f(ind+1,1,prices,n,dp));
    return dp[ind][buy] = max(prices[ind] + f(ind+2,1,prices,n,dp), f(ind+1,0,prices,n,dp));
}

int maxProfit(vector<int> &prices, int n){
    // vector<vector<int>> dp(n+1,vector<int>(2,-1));
    // return f(0,1,prices,n,dp);

    // tabulation + space optimization
    int currBuy, currNotBuy, frontBuy, frontNotBuy, front2Buy;
    frontBuy =  frontNotBuy = front2Buy = 0;
    for(int ind = n-1; ind >= 0; ind--){
        currBuy = max(-prices[ind] + frontNotBuy, frontBuy);
        currNotBuy = max(prices[ind] + front2Buy, frontNotBuy);
        front2Buy = frontBuy;
        frontBuy = currBuy;
        frontNotBuy = currNotBuy;
    }
    return frontBuy;
}

int main(){
    vector<int> prices = {4,9,0,4,10};
    int n = prices.size();
    int ans = maxProfit(prices, n);
    cout << "Maximum profit by buying and selling (with cooldown): " << ans << endl;

    return 0;
}