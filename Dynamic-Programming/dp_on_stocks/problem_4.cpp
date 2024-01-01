#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int ind, int trans, vector<int> &prices, int k, int n, vector<vector<int>> &dp){
    if(ind == n || trans == k*2) return 0;
    if(dp[ind][trans] != -1) return dp[ind][trans];

    int profit = 0;
    if(trans%2 == 0){
        profit = max(-prices[ind] + f(ind+1,trans+1,prices,k,n,dp), f(ind+1,trans,prices,k,n,dp));
    }
    else{
        profit = max(prices[ind] + f(ind+1,trans+1,prices,k,n,dp), f(ind+1,trans,prices,k,n,dp));
    }
    return dp[ind][trans] = profit;
}

int maxProfit(vector<int> &prices, int k, int n){
    // vector<vector<int>> dp(n, vector<int>(k*2,-1));
    // return f(0,0,prices,k,n,dp);

    // tabulation + space optimization
    vector<int> front(2*k+1,0), curr(2*k+1,0);
    for(int ind = n-1; ind >= 0; ind--){
        for(int trans = k*2-1; trans >= 0; trans--){
            int profit = 0;
            if(trans%2 == 0) profit = max(-prices[ind] + front[trans+1], front[trans]);
            else profit = max(prices[ind] + front[trans+1], front[trans]);
            curr[trans] = profit;
        }
        front = curr;
    }
    return front[0];
}

int main(){
    vector<int> prices = {9,3,2,6,1,9,8,4,10};
    int k;
    cout << "Enter value of k: ";
    cin >> k;
    int n = prices.size();
    int ans = maxProfit(prices, k, n);
    cout << "Maximum profit by buying and selling atmost k times: " << ans << endl;

    return 0;
}