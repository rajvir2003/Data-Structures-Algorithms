#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp){
    if(ind == 0){
        if(amount % coins[0] == 0) return amount/coins[0];
        return 1e9;
    }

    if(dp[ind][amount] != -1) return dp[ind][amount];
    int notPick = f(ind-1, amount, coins, dp);
    int pick = INT_MAX;
    if(amount >= coins[ind]) pick = 1 + f(ind, amount-coins[ind], coins, dp);
    return dp[ind][amount] = min(pick, notPick);
}

int coinChange(vector<int> &coins, int amount){
    int n = coins.size();
    // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    // return f(n-1, amount, coins, dp);

    // tabulation + space optimization
    vector<int> prev(amount+1, 0), curr(amount+1, 0);
    for(int target = 0; target <= amount; target++){
        prev[target] = (target%coins[0]==0) ? target/coins[0] : 1e9;
    }

    for(int ind = 1; ind < n; ind++){
        for(int target = 0; target <= amount; target++){
            int pick = INT_MAX;
            if(target >= coins[ind]) pick = 1 + curr[target-coins[ind]];
            int notPick = prev[target];
            curr[target] = min(pick, notPick);
        }
        prev = curr;
    }
    return prev[amount];
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;
    int ans = coinChange(coins, amount);
    cout << "Minimum number of coins required: " << ans << endl;

    return 0;
}