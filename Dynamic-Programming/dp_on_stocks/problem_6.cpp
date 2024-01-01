#include<bits/stdc++.h>
using namespace std;

// find maximum profit by buying and selling stock unlimited times but with transaction fee.
// note -> you need to pay transaction fee after selling the stock.

// memoization
int f(int ind, int buy, vector<int> &prices, int n, int fee, vector<vector<int>> &dp){
    if(ind == n) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];

    if(buy) return dp[ind][buy] = max(-prices[ind] + f(ind+1,0,prices,n,fee,dp), f(ind+1,1,prices,n,fee,dp));
    return dp[ind][buy] = max(prices[ind]-fee + f(ind+1,1,prices,n,fee,dp), f(ind+1,0,prices,n,fee,dp));
}

int maxProfit(vector<int> &prices, int n, int fee){
    // vector<vector<int>> dp(n, vector<int>(2,-1));
    // return f(0,1,prices,n,fee,dp);

    // tabulation + space optimization
    int currBuy, currNotBuy, frontBuy, frontNotBuy;
    frontBuy = frontNotBuy = 0;
    for(int ind = n-1; ind >= 0; ind--){
        currBuy = max(-prices[ind] + frontNotBuy, frontBuy);
        currNotBuy = max(prices[ind]-fee + frontBuy, frontNotBuy);
        frontBuy = currBuy;
        frontNotBuy = currNotBuy;
    }
    return frontBuy;
}

int main(){
    vector<int> prices = {1,3,7,5,10,3};
    int n = prices.size();
    int fee;
    cout << "Enter fee: ";
    cin >> fee;
    int ans = maxProfit(prices, n, fee);
    cout << "Maximum profit by buying and selling stock with transaction fee: " << ans << endl;

    return 0;
}